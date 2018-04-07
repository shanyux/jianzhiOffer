#include <iostream>

using namespace std;

long long fib1(size_t n)
{
    if(n == 0)
        return 0;
    if(n==1)
        return 1;
    return
        fib1(n-1)+fib1(n-2);
}
long long fib2(size_t n)
{
    if(n == 0)
        return 0;
    if(n==1)
        return 1;
    int left = 0;
    int right = 1;
    int value = 0;

    for(size_t i = 2; i <= n; i++)
    {
        value = left+right;
        left = right;
        right = value;
    }
    return value;
}
int main()
{
    size_t value = 0;
    cout << fib1(value) << " " << fib2(value)<< endl;
    value = 1;
    cout << fib1(value) << " " << fib2(value)<< endl;
    value = 2;
    cout << fib1(value) << " " << fib2(value)<< endl;
    value = 3;
    cout << fib1(value) << " " << fib2(value)<< endl;
    value = 4;
    cout << fib1(value) << " " << fib2(value)<< endl;
    value = 5;
    cout << fib1(value) << " " << fib2(value)<< endl;
    value = 6;
    cout << fib1(value) << " " << fib2(value)<< endl;
    value = 7;
    cout << fib1(value) << " " << fib2(value)<< endl;
    return 0;
}
