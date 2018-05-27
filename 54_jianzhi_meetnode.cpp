/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL)
            return pHead;
        ListNode* pfast = pHead, *pslow = pHead->next;
        while(pfast != NULL && pslow != NULL){
            if(pfast == pslow)
                break;
            pslow = pslow->next;
            pfast = pfast->next;
            if(pfast != NULL)
                pfast = pfast->next;
        }
        
        //pfast = pfast->next;
        if(pfast != NULL && pslow != NULL){
            int n = 1;
            while(pfast->next != pslow){
                pfast = pfast->next;
                n++;
            }
            pfast = pHead;
            pslow = pHead;
            for(int i = 0; i< n; i++)
            //ile(n>0){
                pfast = pfast->next;
            //  n--;
            //
            while(pfast != pslow){
                pfast = pfast->next;
                pslow = pslow->next;
            }
            return pfast;
        }
        return NULL;
    }
};