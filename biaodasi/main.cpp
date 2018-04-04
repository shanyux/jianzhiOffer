#include <iostream>
#include <stack>
#include<cmath>
#include <cstdlib>

using namespace std;

stack<int> OPND;    //������
stack<char> OPTR;   //������
int priority[7][7] = {1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,1,1,1,1,1,-1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,-1,-1,0,-2,1,1,1,1,-2,1,1,-1,-1,-1,-1,-1,-2,0};    //�洢���ȼ���ϵ


void Initial();    //��ʼ��
void GetExpressionValue();          //������ʽ��ֵ
int GetPriority(const char a, const char b);    //�õ�a,b���ȼ�
int Operate(int a, const char theta, int b);    //����a theta b��ֵ

int main()
{
    cout << "biaodasi" <<endl;

//    int sum = 0;
    Initial();                   //��ʼ��
    GetExpressionValue();        //������ʽ��ֵ
    //cout << OPND.size() << " " <<OPND.top() << endl;
    return 0;
}
// 1+2*(3+4)


void Initial()
{
    //��ʼ�����������ջ��������#�����������ջ��
    while(!OPND.empty())
    {
        OPND.pop();
    }
    while(!OPTR.empty())
    {
        OPTR.pop();
    }
    //OPTR.push('#');
}

void GetExpressionValue()
{
    int data[12] = {0};    //������
    int d = 0;
    string ch;
    size_t index = 0;
    char theta;
    int a = 0;
    int b = 0;
    int i = 0;
    int j = 0;
    cin >> ch;
    while(index < ch.size())    //������=��#������ֵ����
    {

        if(isdigit(ch[index]))    //ch�ǲ�����
        {
            i = 0;
            d = 0;
            while(index < ch.size() && isdigit(ch[index]))      //���ַ��͵Ĳ�����ת��Ϊ����
            {
                //cout << "1" <<endl;
                data[i++] = ch[index] - '0';
                index++;
            }
            for(j = 0; j < i; j++)
            {
                d = d + data[j]*pow(10.0, j);
            }
            OPND.push(d);           //��������ջ

        }
        else               //ch�ǲ�����
        {
            // cout << "2" <<endl;
            //int c= ch[index] << " ";
            if(OPTR.empty())
            {
                OPTR.push(ch[index]);
            }
            else
            {

                switch(GetPriority(OPTR.top(), ch[index]))
                {
                case -1:        //ջ���Ĳ��������ȼ�С�ڵ�ǰ������
                {
                    OPTR.push(ch[index]);
                    index++;
                    break;
                }
                case 0:         //��ȣ���ȥ����
                {
                    OPTR.pop();
                    index++;
                    break;
                }
                case 1:         //ջ���Ĳ��������ȼ����ڵ�ǰ������
                {
                    cout << "char" <<ch[index] << " " << OPTR.top() <<endl;
                    cout << "stack num:" <<OPND.size() << endl;
                    cout << "stack2 num:" <<OPTR.size() << endl;
                    if(!OPTR.empty())
                    {
                        theta = OPTR.top();
                        OPTR.pop();
                    }
                    if(!OPND.empty())
                    {
                        a = OPND.top();
                        OPND.pop();
                    }
                    if(!OPND.empty())
                    {
                        b = OPND.top();
                        OPND.pop();
                    }
                    //OPTR.push(ch[index]);
                    int res = Operate(b,theta,a);
                    OPND.push(res);    //��������Ľ������������ջ��
                    cout <<  "top:"  << res << endl;
                    break;
                }
                default:
                    break;
                }
            }
            // cout << "5" <<endl;


        }
    }
    while(!OPTR.empty())
    {
        cout << "1stack num:" <<OPND.size() << endl;
        cout << "2stack num:" <<OPTR.top() << endl;

        theta = OPTR.top();
        OPTR.pop();
        if(!OPND.empty())
        {
            a = OPND.top();
            OPND.pop();
        }
        if(!OPND.empty())
        {
            b = OPND.top();
            OPND.pop();
        }

        int res = Operate(b,theta,a);
        OPND.push(res);    //��������Ľ������������ջ��
        cout <<  "top:"  << res << endl;
    }
}

int GetPriority(const char a, const char b)
{
    //cout << "6" <<endl;

    int i = -1;
    int j = -1;
    switch(a)
    {
    case ')':
        i++;
    case '(':
        i++;
    case '/':
        i++;
    case '*':
        i++;
    case '-':
        i++;
    case '+':
        i++;
    default:
        break;
    }

    switch(b)
    {
    case ')':
        j++;
    case '(':
        j++;
    case '/':
        j++;
    case '*':
        j++;
    case '-':
        j++;
    case '+':
        j++;
    default:
        break;
    }


    if(i >= 0 && j >= 0)
    {
        return priority[i][j];
    }
    else
    {
        cout << "error !";
        exit(0);
    }
}

int Operate(int a, const char theta, int b)
{

    int res = 0;
    switch (theta)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    default:
        break;
    }
    //cout << "4" <<endl;
    return res;
}
