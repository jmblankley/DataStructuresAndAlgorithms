#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Function: bubbleSort
// Parameters: -- list<string> arr - list that will be sorted
//			   -- int size - integer representing the size of the array (length)
// Purpose: Use the bubble sort algorithm to sort the array in alphabetical order
void bubbleSort(list<string> &arr, int size)
{
	for (auto i = arr.begin(); i != arr.end(); ++i)
	{
		for (auto j = arr.begin(); j != prev(arr.end()); ++j)
		{
			if (*j > *(next(j)))
			{
				iter_swap(j, next(j));
			}
		}
	}
}

// Function: mergeHelper
// Parameters: -- list<string> arr - original list that needs sorting
//			   -- list<string>::iterator left - iterator pointing to the beginning of the current sublist
//			   -- list<string>::iterator middle - iterator pointing to the middle
//			   -- list<string>::iterator right - iterator pointing to the end
// Purpose: Merges the two sorted sublists created from the original list. Then copies the mergedList back into the original list.
void mergeHelper(list<string> &arr, list<string>::iterator left, list<string>::iterator middle, list<string>::iterator right)
{
	list<string> mergedList;

	auto i = left;
	auto j = middle;

	while (i != middle && j != right)
	{
		if (*i <= *j)
		{
			mergedList.push_back(*i);
			++i;
		}
		else
		{
			mergedList.push_back(*j);
			++j;
		}
	}

	// Copy first sublist
	while (i != middle)
	{
		mergedList.push_back(*i);
		++i;
	}

	// Copy second sublist
	while (j != right)
	{
		mergedList.push_back(*j);
		++j;
	}

	// Copy all elements back into original list
	auto k = left;
	for (const auto &element : mergedList)
	{
		*k = element;
		++k;
	}
}

// Function: mergeSort
// Parameters: -- list<string> arr - array that will be sorted
//			   -- list<string>::iterator left - iterator pointing to the beginning
//			   -- list<string::iterator right - iterator pointing to the end
// Purpose: Uses the merge sort algorithm to sort the input array
void mergeSort(list<string> &arr, list<string>::iterator left, list<string>::iterator right)
{
	if (distance(left, right) > 1)
	{
		auto mid = next(left, distance(left, right) / 2);

		mergeSort(arr, left, mid);
		mergeSort(arr, mid, right);

		mergeHelper(arr, left, mid, right); // call mergeHelper to merge the list back into one
	}
}

// Function: partionHelper
// Parameters: -- vector<string> vec - vector that partition is being taken from
//			   -- int start - integer representing the first index in the vector
// 			   -- int end - integer representing the last index in the vector
// Purpose: Assists in the quick sort algorithm by creating a pivot point and placing all elements less than it on the left side and all elements greater than on the right side.
int partionHelper(vector<string> &vec, int start, int end)
{
	string pivot = vec[end];

	int i = start - 1;

	for (int j = start; j <= end - 1; j++)
	{
		if (vec[j] < pivot)
		{
			i++;
			swap(vec[i], vec[j]);
		}
	}
	swap(vec[i + 1], vec[end]);
	return (i + 1);
}

// Function: quickSort
// Parameters: -- vector<string> vec - vector that will be sorted
//   		   -- int start - integer representing the first index of the vector
//			   -- int end - integer representing the last index of the vector
// Purpose: Uses the quick sort algorithm to sort the input array. Uses recursion and the partionHelper function to accomplish this.
void quickSort(vector<string> &vec, int start, int end)
{

	if (start < end)
	{
		int partition = partionHelper(vec, start, end);

		quickSort(vec, start, partition - 1);
		quickSort(vec, partition + 1, end);
	}
}

// Function: heapSortHelper
// Parameters: -- vector<string> arr - vector that will be sorted
//			   -- int n - the size of the given vector(heap)
//			   -- int i - the index of the root of the subtree
// Purpose: Assists the heapSort function by maintaining the max heap properties and iterating through each node
void heapSortHelper(vector<string> &arr, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// check if left child is bigger than the root
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// check if the right child is bigger than the root or the left child
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// if the largest element is not the root, swap and use recusion
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		heapSortHelper(arr, n, largest);
	}
}

// Function: heapSort
// Parameters: array that will be sorted, integer representing the size of the array (length)
// Purpose: Uses the heap sort algorithm to sort the input array
void heapSort(vector<string> &arr, int size)
{
	// construct the heap from the vector
	for (int i = size - 2 / 1; i >= 0; i--)
	{
		heapSortHelper(arr, size, i);
	}

	// extract each element from the heap
	for (int j = size - 1; j > 0; j--)
	{
		swap(arr[0], arr[j]);	   // move root to the end
		heapSortHelper(arr, j, 0); // call heapSortHelper on smaller heap
	}
}

// Function: sysSort
// Parameters: array that will be sorted, integer representing the size of the array (length)
// Purpose: Uses the systems default sorting method to sort the array
void sysSort(list<string> &arr)
{
	arr.sort();
}

int main(int argc, char *argv[])
{
	// values from the use input
	const char *filename = argv[1];
	const char *sortingtype = argv[2];
	const char *printQuery = argv[3];

	// usage error
	if (argc < 3)
	{
		cout << "Usage: " << argv[0] << " <filename> <sortingtype>" << endl;
	}

	// create ifstream object from users filename
	ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		cout << "Error opening file: " << filename << endl;
		return 1;
	}

	// get the list size from the top of the list
	int arrSize;
	inputFile >> arrSize;

	// push the values from the input file into the list
	list<string> inputArr;
	string line;
	while (getline(inputFile >> ws, line)) // ws trims any leading or trailing whitespace from the line
	{
		inputArr.push_back(line);
	}

	if ((string)sortingtype == "bubble")
	{
		bubbleSort(inputArr, arrSize);
	}
	else if ((string)sortingtype == "merge")
	{
		mergeSort(inputArr, inputArr.begin(), inputArr.end());
	}
	else if ((string)sortingtype == "quick")
	{
		vector<string> vec(inputArr.begin(), inputArr.end());

		int start = 0;
		int end = vec.size() - 1;
		quickSort(vec, start, end);

		inputArr.clear();

		for (int i = 0; i < vec.size(); i++)
		{
			inputArr.push_back(vec[i]);
		}
	}
	else if ((string)sortingtype == "heap")
	{
		vector<string> vec(inputArr.begin(), inputArr.end());

		heapSort(vec, arrSize);

		inputArr.clear();

		for (int i = 0; i < vec.size(); i++)
		{
			inputArr.push_back(vec[i]);
		}
	}
	else if ((string)sortingtype == "sys")
	{
		sysSort(inputArr);
	}
	else
	{
		cout << "Sorry that is not a valid sorting algorithm." << endl;
		return 0;
	}

	if (printQuery != nullptr && (string)printQuery == "-print")
	{
		for (const auto &str : inputArr)
		{
			std::cout << str << std::endl;
		}
	}

	inputFile.close();

	return 0;
}
