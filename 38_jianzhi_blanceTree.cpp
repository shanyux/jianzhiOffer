class Solution {
public:
    /*bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        int diff = left-right;
        if(diff > 1 || diff < -1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    int TreeDepth(TreeNode* pRoot){
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
    }*/
    bool IsBalanced_Solution(TreeNode* pRoot) {//后序遍历！！！只需一次遍历就可同时获得节点的深度和是否平衡
        int depth = 0;
        return IsBalanced(pRoot, &depth);       
    }
    bool IsBalanced(TreeNode* pRoot, int *depth) {
        if(pRoot == NULL)
        {
            depth = 0;
            return true;
        }
        int left = 0, right = 0;
        if(IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)){
            int diff = left-right;
            if(diff < 2 && diff > -2)
            {
                *depth = (left > right? left:right) + 1;
                return true;
            }
        }
        return false;
    }
};