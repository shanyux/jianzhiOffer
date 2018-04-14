/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        
        CloneNode(pHead);
        ConnectRandom(pHead);
        RandomListNode* clonenode = ReconnextNode(pHead);
        return clonenode;
        
    }
    void CloneNode(RandomListNode* pHead){
        if(pHead == NULL)
            return;
        while(pHead != NULL){
            RandomListNode* node = new RandomListNode(pHead->label);
            node->next = pHead->next;
            pHead->next = node;
            pHead = node->next;
        }         
    }
    void ConnectRandom(RandomListNode* pHead){
        if(pHead == NULL)
            return;
        while(pHead != NULL){
            if(pHead->random != NULL){
                pHead->next->random = pHead->random->next; 
            }
            pHead = pHead->next->next;
        }
        
    }
    RandomListNode* ReconnextNode(RandomListNode* pHead){
        if(pHead == NULL)
            return pHead;        
        RandomListNode* clonehead = pHead->next;
        RandomListNode* clonenode = pHead->next;
        pHead->next = clonenode->next;
        pHead = pHead->next;
        
        while(pHead){//一定要让pHead做条件，才不会出错
            clonenode->next = pHead->next; 
            clonenode = clonenode->next;
            pHead->next = clonenode->next;
            pHead = pHead->next;
                
            
        }
        return clonehead;
        
    }
};