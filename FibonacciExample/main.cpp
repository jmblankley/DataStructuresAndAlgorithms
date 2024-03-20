#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }

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
            cout << "Input number for fibonacci sequence: ";
            cin >> nVal;
            cout << "Sequenced number: " << fibonacci(nVal) << endl;
        }
    }

    return 0;
}