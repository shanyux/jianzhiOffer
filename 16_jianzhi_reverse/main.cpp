#include <iostream>

using namespace std;
struct listnode
{
    int value;
    listnode *next;
};
listnode* reverse(listnode *head)
{
    if(head == 0)
        return;
    listnode *cnode = head;
    listnode *prenode = 0;
    listnode *nextnode = 0;
    while(cnode->next != 0)
    {
        nextnode = cnode->next;
        cnode->next = prenode;
        prenode = cnode;
        cnode = nextnode;
    }
    cnode->next = prenode;
    return cnode;


}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
