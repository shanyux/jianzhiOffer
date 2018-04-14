/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    /*TreeNode* Convert(TreeNode* pRootOfTree)//非递归
    {
        stack<TreeNode*> s;//
        TreeNode* root = pRootOfTree;
        TreeNode* pre = NULL;
        bool rootflag = true;
        while(pRootOfTree || !s.empty()){
            while(pRootOfTree){
                s.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }
            pRootOfTree = s.top();
            s.pop();
            if(rootflag){
                root = pRootOfTree;
                rootflag = false;
                pRootOfTree->left = pre;
                pre = pRootOfTree;
            }
            else{
                pRootOfTree->left = pre;
                pre->right = pRootOfTree;
                pre = pRootOfTree;
            }
            
            pRootOfTree = pRootOfTree->right;
        }
        return root;
    }*/
    TreeNode* Convert(TreeNode* pRootOfTree)//递归
    {
        if(pRootOfTree==NULL || (pRootOfTree->left == NULL && pRootOfTree->right == NULL))
            return pRootOfTree;
        TreeNode* leftnode = Convert(pRootOfTree->left);
        TreeNode* p = leftnode;
        while(p!=NULL && p->right!=NULL)
            p = p->right;
        if(leftnode != NULL){
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        TreeNode* rightnode = Convert(pRootOfTree->right);
        if(rightnode != NULL){
            pRootOfTree->right = rightnode;
            rightnode->left = pRootOfTree;
        }
        return leftnode? leftnode : pRootOfTree;
    }
};