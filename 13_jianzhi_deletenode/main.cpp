#include <iostream>

using namespace std;

struct Listnode
{
    int value;
    Listnode* next;
};
void deletenode(Listnode** firstnode, Listnode* delnode)
{
    if(!firstnode || !deletenode)
        return;
    if(delnode->next != 0) //不是尾节点
    {
        Listnode *nextnode = delnode->next;
        delnode->value = nextnode->value;
        delnode->next = nextnode->next;
        delete nextnode;
    }
    if(delnode == *firstnode)
    {
        delete delnode;
        delnode = 0;

    }
    else
    {
        Listnode *pnode = *firstnode;
        while(ponde->next !=delnode)
            pnode = pnode->next;
        pnode->next = 0;
        delete delnode;
        delnode = 0;
    }

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
