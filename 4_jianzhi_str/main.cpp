#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    //string s("12345as8df");
    //string a = s.substr(5,18);     //获得字符串s中从第0位开始的长度为5的字符串
    int a[3][3]= {0};
    for(int i = 0; i <3; i++)
        for(int j = 0; j <3; j++)
            cout << a[i][j] << " ";
    char s1[] = "hello world";
    char s2[] = "hello world";
    char *s3 = "hello world";
    char *s4 = "hello world";
    cout << strlen(s1) << " " <<strlen(s3) << " "<<sizeof(s1)<< " " <<sizeof(s3) << endl;
    if(s1 == s2)//数组地址不一样
        cout << "s1==s2" <<endl;
    else
        cout << "s1!=s2" <<endl;
    if(s3 == s4)//常量字符串是一样的地址
        cout << "s3==s4" <<endl;
    else
        cout << "s3!=s4" <<endl;

    return 0;
}
