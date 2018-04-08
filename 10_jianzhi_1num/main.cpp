#include <iostream>

using namespace std;

int Numberof1_1(int n)
{
    int flag = 1;
    int count = 0;
    while(flag)
    {
        if(flag & n)
            count++;
        flag <<= 1;
    }
    return count;
}
int Numberof1_2(int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n *= n-1;

    }
    return count;
}
int main()
{
    int value = 0;
    cout << Numberof1_1(value) <<" " << Numberof1_1(value)  << endl;
    value = 1;
    cout << Numberof1_1(value) <<" " << Numberof1_1(value)  << endl;
    value = 2;
    cout << Numberof1_1(value) <<" " << Numberof1_1(value)  << endl;
    value = 7;
    cout << Numberof1_1(value) <<" " << Numberof1_1(value)  << endl;
    value = 15;
    cout << Numberof1_1(value) <<" " << Numberof1_1(value)  << endl;
    cout << Numberof1_1(0xffff) <<" " << Numberof1_1(0xffffffff)  << endl;
    return 0;
}
