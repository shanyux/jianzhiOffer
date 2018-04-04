#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    //getline(cin, str);
    str = " a b c d eee";
    size_t oldsize = str.size();
    int num = 0;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
            num++;
    }
    str.append(num*2, ' ');
    size_t newsize = str.size();
    int k = 0;
    for(size_t i = oldsize-1; i >=0; i--)
    {
        k++;
        if(str[i] == ' ')
        {
            str[--newsize]='0';
            str[--newsize]='2';
            str[--newsize]='%';
        }
        else
            str[--newsize] = str[i];
        if(newsize == i)
            break;

    }
    cout << k << " " << str << endl;
    return 0;
}
