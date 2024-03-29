#include <iostream>
using namespace std;

int fibonacci(int n)
{
    long unsigned int answer;
    if(n <= 1)
    {
        answer = 1;
    }
    else
    {
        answer = fibonacci(n-1) + fibonacci(n-2);
    }

    return answer;
}

int main (int argc, char *argv[])
{
    int nVal;
    while(true)
    {
        if(nVal == -1)
        {
            return 0;
        }
        else
        {
            cout << "Input number for fibonacci sequence (-1 to quit): ";
            cin >> nVal;
            cout << "Result: " << fibonacci(nVal) << endl;
        }
    }

    return 0;
}