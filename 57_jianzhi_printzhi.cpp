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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<int> v;
        vector<vector<int>> vec;
        if(pRoot == NULL)
            return vec;
        stack<TreeNode*> s[2];
        
        int cur = 0, next = 1;
        s[cur].push(pRoot);
        while(!s[0].empty() || !s[1].empty()){
            TreeNode* node = s[cur].top();
            v.push_back(node->val);
            s[cur].pop();
            if(cur == 0){
                if(node->left)
                    s[next].push(node->left);
                if(node->right)
                    s[next].push(node->right);                
            }
            else{
                if(node->right)
                    s[next].push(node->right);
                if(node->left)
                    s[next].push(node->left);
            }
            if(s[cur].empty()){
                cur = 1-cur;
                next = 1-next;
                vec.push_back(v);
                v.clear();
            }
        }
        return vec;
        
    }
    
};