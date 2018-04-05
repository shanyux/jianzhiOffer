#include <iostream>
#include <cstdlib>
#include <exception>
#include <stdexcept>

using namespace std;
struct bTreeNode
{
    int value;
    bTreeNode *left;
    bTreeNode *right;
};
bTreeNode* construct(int *prestart, int *preend, int *instart, int *inend)
{
    int rootvalue = prestart[0];
    bTreeNode *root = new bTreeNode();
    root->value = rootvalue;
    root->left =0;
    root->right = 0;
    if(prestart == preend)
    {
        if(instart == inend && *prestart == *instart)
            return root;
        else
        {
            cout << "1invalid input";
            exit(1);
        }
    }
    int *rootinorder = instart;
    while(rootinorder <= inend && *rootinorder != rootvalue)
        rootinorder++;
    if(rootinorder > inend)
        throw std::exception(logic_error("2invalid input"));
    int leftlen = rootinorder - instart;
    if(leftlen > 0)
        root->left = construct(prestart+1, prestart+leftlen,instart, rootinorder-1);
    if(leftlen < inend-instart)
        root->right = construct(prestart+leftlen+1, preend, rootinorder+1, inend);

    return root;
}
bTreeNode* construct(int preorder[], int inorder[], int n)
{
    if(preorder == 0 || inorder == 0 || n == 0)
    {
        return 0;
    }
    return construct(preorder, preorder+n-1, inorder, inorder+n-1);
}
void bacorder(bTreeNode *root)
{
    if(root != 0){
        bacorder(root->left);
        bacorder(root->right);
        cout << root->value << " ";
    }
}

int main()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    bTreeNode *root = construct(preorder,inorder,length);
    bacorder(root);

    return 0;
}
