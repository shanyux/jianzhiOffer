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
    vector<vector<int>> paths;
    vector<int> path;
public:
    /*vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> paths;
        vector<int> path;
        stack<TreeNode*> nodeS;
        while(root || !nodeS.empty()){
            while(root){
                nodeS.push(root);
                expectNumber = expectNumber - root->val;
                path.push_back(root->val);
                root = root->left? root->left : root->right;
            }
            root = nodeS.top();
            if(root->left == NULL && root->right == NULL && expectNumber == 0){
                paths.push_back(path);
            }
            expectNumber += root->val;
            nodeS.pop();
            path.pop_back();
            if(!nodeS.empty() && nodeS.top()->left == root)
                root = nodeS.top()->right;
            else
                root = NULL;
        }
        return paths;
        
    }*/
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        dfsFindPath(root,expectNumber);
        return paths;
    }
    void dfsFindPath(TreeNode* root,int expectNumber) {
        //stack<TreeNode*> s;
        if(root == NULL)
            return;
        path.push_back(root->val);
        expectNumber -= root->val;
        if(expectNumber == 0 && root->left == NULL && root->right == NULL)
            paths.push_back(path);
        else{         
            if(root->left)
                dfsFindPath(root->left, expectNumber);
            if(root->right)
                dfsFindPath(root->right, expectNumber);          
            
        }
        path.pop_back();
        expectNumber += root->val;

        
    }
    
    
    
    
};