#include <iostream>

using namespace std;
struct Listnode
{
    int value;
    Listnode *next;
};
void addnode(Listnode **p, int value)
{
    Listnode *pnew = new Listnode;
    pnew->value = value;
    pnew->next = 0;
    if(*p == 0)
        *p = pnew;
    else
    {
        Listnode *pnode = *p;
        while(pnode->next != 0)
            pnode = pnode->next;
        pnode->next = pnew;
    }
}
void deletenode(Listnode **p, int value)
{
    if(p == 0 || *p == 0)
        return;
    Listnode *pdeletenode = 0;
    if((*p)->value == value)
    {
        pdeletenode = *p;
        *p = pdeletenode->next;
    }
    else
    {
        Listnode *pnode = *p;
        while(pnode->next != 0 && pnode->next->value != value)
            pnode = pnode->next;
        if(pnode->next!= 0 && pnode->next->value == value)
        {
            pdeletenode = pnode->next;
            pnode->next = pnode->next->next;
        }
        if(pdeletenode != 0)
        {
            delete pdeletenode;//告诉编译器可以把这个指针指向的对象析构，然后把这个指针指向的内存回收
            pdeletenode = 0;
        }


    }
}

    int main()
    {

        return 0;
    }
