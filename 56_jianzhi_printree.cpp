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
            queue<TreeNode*> q;
            q.push(pRoot);
            int bedelete = 1, nextlevel = 0;
            while(!q.empty()){
                TreeNode* node = q.front();
                bedelete--;
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                    nextlevel++;
                }
                if(node->right != NULL){
                    q.push(node->right);
                    nextlevel++;
                }
                v.push_back(node->val);
                if(bedelete == 0){
                    vec.push_back(v);
                    v.clear();
                    bedelete = nextlevel;
                    nextlevel=0;
                }
                
            }
            return vec;
        
        }
    
};