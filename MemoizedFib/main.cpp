#include <iostream>
using namespace std;

#define MAXVAL 100

long unsigned int M[MAXVAL];

long unsigned int fibonacci(long unsigned int n)
{
    long unsigned int answer;
    if(M[n] == 0)
    {
        if(n <= 1)
        {
            M[n] = 1;
        }
        else
        {
            M[n] = fibonacci(n-1) + fibonacci(n-2);
        }
    }
    
    return M[n];
}

int main (int argc, char *argv[])
{

    for(int i = 0; i < MAXVAL; i++)
    {
        M[i] = 0;
    }

    long unsigned int nVal;
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