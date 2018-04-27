/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        int len1 = 0, len2 = 0;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        
        while(p1 != NULL)
        {
            len1++;
            p1 = p1->next; 
        }
        while(p2 != NULL)
        {
            len2++;
            p2 = p2->next; 
        }
        ListNode* plong = pHead1;
        ListNode* pshort = pHead2;
        int cha = len1-len2;
        if(len2>len1){
            plong = pHead2;
            pshort = pHead1;
            cha = len2-len1;            
        }
        while(cha !=0){
            cha--;
            plong = plong->next;
        }
        bool flag = false;
        while((plong != NULL) && (pshort != NULL)){
            if(plong->val == pshort->val){
                flag = true;
                break;
                
            }
                
            plong = plong->next;
            pshort = pshort->next;
        }
        if(flag)
            return plong;
        return NULL;
        
    }
};