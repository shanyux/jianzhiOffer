/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k <=0)
            return NULL;
        return KthcoreNode(pRoot, k);
    }
    TreeNode* KthcoreNode(TreeNode* pRoot, int& k)
    {
        TreeNode* target = NULL;
        if(pRoot->left)
            target = KthcoreNode(pRoot->left, k);
        if(target == NULL){
            if(k == 1)
                return pRoot;
            k--;
        }
        if(target == NULL && pRoot->right)
            target = KthcoreNode(pRoot->right, k);
        return target;
        
    }

    
};