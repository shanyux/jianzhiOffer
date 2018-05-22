/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        TreeLinkNode* pnext;
        if(pNode->right != NULL){
            pnext = pNode->right;
            while(pnext->left != NULL)
                pnext = pnext->left;
            return pnext;
        }
        else{
            TreeLinkNode* pcur = pNode;
            TreeLinkNode* parent = pNode->next;
            while(parent != NULL && pcur == parent->right){
                pcur = pcur->next;
                parent = pcur->next;
            }
            pnext = parent;
            return pnext;
            
        }
        
    }
};