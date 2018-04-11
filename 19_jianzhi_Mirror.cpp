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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == 0 || (pRoot->left == 0 && pRoot->right ==0 ))
            return;
        else
        {
            TreeNode *node = node = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = node;
            if(pRoot->left != 0)
                Mirror(pRoot->left);
            if(pRoot->right != 0)
                Mirror(pRoot->right);
            
        }
            

    }
};