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
    /*int TreeDepth(TreeNode* pRoot)//递归
    {
        if(pRoot == NULL)
            return 0;
        int leftlen = TreeDepth(pRoot->left);
        int rightlen = TreeDepth(pRoot->right);
        return (leftlen > rightlen)? (leftlen+1) : (rightlen+1);
    }*/
    int TreeDepth(TreeNode* pRoot){//层序遍历
        if(pRoot == NULL)
            return 0;
        queue<TreeNode*> q;
        int depth = 0;
        q.push(pRoot);
        int nextLayerCount = 1;
        int count = 0;
        while(!q.empty()){
            TreeNode* top = q.front();
            count++;
            q.pop();
            if(top->left){
                q.push(top->left);
            }
            if(top->right){
                q.push(top->right);
            }
            if(count == nextLayerCount){
                count =0;
                nextLayerCount = q.size();
                depth++;
            }
            
        }
        return depth;
    }
};