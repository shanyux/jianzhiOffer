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
    /*ListNode* deleteDuplication(ListNode* pHead)//第一种
    {
        if(pHead == NULL)
            return pHead;
        ListNode* pre = NULL;
        ListNode* cur = pHead;
        ListNode* nex = NULL;
        ListNode* del = NULL;
        while(cur != NULL){
            if(cur->next != NULL && cur->next->val == cur->val){
                nex = cur->next;
                del = nex;
                while(nex != NULL && nex->next != NULL && nex->next->val == nex->val){
                    nex = nex->next;
                    delete del;
                    del = nex;
                }
                if(cur == pHead)
                    pHead = nex->next;
                else
                    pre->next = nex->next;
                delete cur;
                cur = nex->next;
                delete nex;
            }
                    
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return pHead;

    }*/
    ListNode* deleteDuplication(ListNode* pHead){//递归
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* cur;
        if(pHead->val == pHead->next->val){
            cur = pHead->next->next;
            while(cur != NULL && cur->val == pHead->val)
                cur = cur->next;
            return deleteDuplication(cur);
            
        }
        else
        {
            cur = pHead->next;
            pHead->next = deleteDuplication(cur);
            return pHead;
        }
    }
};