#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;
/*template<typename T>
class CQueue
{
public:
    void appendTail(T c);
    T deleteHead();
private:
    stack<T> s1;
    stack<T> s2;


};
template<typename T>
void CQueue<T>::appendTail(T c)
{
    s1.push(c);
}
template<typename T>
T CQueue<T>::deleteHead()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if(s2.empty())
    {
        cout << "Queue is empty!!" << endl;
    }
    T head = s2.top();
    s2.pop();
    return head;
}

void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    cout << head << endl;
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');
    cout << head << endl;
    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');
    cout << head << endl;
    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');
    cout << head << endl;
    head = queue.deleteHead();
    Test(head, 'e');
    cout << head << endl;
    return 0;
}
*/
template<typename T>
class Cstack
{
public:
    void adddata(T c);
    T deletedata();

private:
    queue<T> q1;
    queue<T> q2;
};
template<typename T>
void Cstack<T>::adddata(T c)
{
    if(q1.empty())
    {
        q1.push(c);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    else
    {
        q2.push(c);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
    }
}
template<typename T>
T Cstack<T>::deletedata()
{
    T data = -1;
    if(!q1.empty())
    {
        data = q1.front();
        q1.pop();

    }
    else if(!q2.empty())
    {
        data = q2.front();
        q2.pop();
    }
    else
    {
        cout << "statck is empty!" << endl;
    }
    return data;
}
int main()
{
    return 0;
}
