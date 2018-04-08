#include <iostream>
#include <cstring>

using namespace std;
bool increment(char *number);
void print(char *number);
void printTOMax(int n)
{
    if(n <=0)
        return;
    else
    {
        char *number = new char[n+1];
        memset(number,'0',n);
        number[n] = '\0';
        while(!increment(number))
        {
            print(number);
        }
    }
}
bool increment(char *number)
{
    bool flag = false;
    int ntakeover = 0;//½øÎ»
    int n = strlen(number);
    //cout << n;
    //int x = 0;
    for(int i = n-1; i >=0; i--)
    {
        // x/++;
        //cout << i << endl;
        int num = number[i] - '0' + ntakeover;
        ntakeover = 0;
        if(i == n-1)
            num++;
        if(num >=10)
        {
            if(i ==0)
            {
                flag = true;
                num = num-10;
            }
            else
            {
                ntakeover = 1;
                num = num-10;
                number[i] = num + '0';
            }
        }
        else
        {
            number[i] = num + '0';
            break;
        }

    }
    return flag;
}
void print(char *number)
{
    bool isbegin = true;

    size_t n = strlen(number);
    for(size_t i = 0; i < n; i++)
    {
        if(isbegin && number[i] != '0')
            isbegin = false;
        if(!isbegin)
            cout << number[i];

    }
    cout << "  ";
}

int main()
{
    int n =2;
    printTOMax(n);
    n =4;
    printTOMax(n);
    //n =4;
    //printTOMax(n);



    return 0;


}
