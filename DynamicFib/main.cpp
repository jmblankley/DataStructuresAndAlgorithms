#include <iostream>
using namespace std;

#define MAXVAL 100

long unsigned int M[MAXVAL];

long unsigned int fibonacci(long unsigned int n)
{
    M[0] = 1;
    M[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        M[i] = M[i - 1] + M[i - 2];
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