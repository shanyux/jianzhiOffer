#include <iostream>
#include <Windows.h>
#include <stack>
using namespace std;

template <class T>
struct BinaryTreeNode
{
    int _data;
    BinaryTreeNode<T>* _left; //左孩子
    BinaryTreeNode<T>* _right;  //右孩子
    BinaryTreeNode(const T& data)
        :_data(data)
        , _left(NULL)
        , _right(NULL)
    {}
};

template <class T>
class BinaryTree
{
    typedef BinaryTreeNode<T> Node;
public:
    BinaryTree()
        :_root(NULL)
    {}

    BinaryTree(T* arr, size_t n, const T& invalid=T())
    {
        size_t index = 0;
        _root = _CreatTree(arr, n, invalid, index);
    }

    void PreOrderR()  //前序遍历 递归
    {
        _PreOrderR(_root);
    }

    void PreOrder()  //前序遍历 非递归
    {
        _PreOrder(_root);
    }

    void InOrderR() //中序遍历 递归
    {
        _InOrderR(_root);
    }

    void InOrder()   //中序遍历  非递归
    {
        _InOrder(_root);
    }

    void PostOrderR()  //后序遍历 左 右 根  递归
    {
        _PostOrderR(_root);
    }

    void PostOrder()  //后序遍历 左 右 根  非递归
    {
        _PostOrder(_root);
    }

    ~BinaryTree()
    {}

protected:
//建树 arr:建树使用的数组 n：数组大小 invalid:非法值 index:当前下标
    Node* _CreatTree(T* arr, size_t n, const T& invalid, size_t& index)
    {
        Node* root = NULL;
        if (index < n && arr[index] != invalid)
        {
            root = new Node(arr[index]); //根节点
            root->_left = _CreatTree(arr, n, invalid, ++index);
            root->_right = _CreatTree(arr, n, invalid, ++index);
        }
        return root;
    }

    void _PreOrderR(Node* root)  //前序遍历 递归
    {
        if(root == NULL)
            return;
        cout << root->_data << " ";
        _PreOrderR(root->_left);
        _PreOrderR(root->_right);

    }

    void _PreOrder(Node* root)  //前序遍历 非递归
    {
        if(root==NULL)
            return;
        stack<Node*> s;
        while(root || !s.empty())
        {
            while(root)
            {
                cout << root->_data << " ";
                s.push(root);
                root = root->_left;
            }
            root = s.top()->_right;
            s.pop();


        }



    }

    void _InOrderR(Node* root) //中序遍历 递归
    {
        if(root == NULL)
            return;
        _InOrderR(root->_left);
        cout << root->_data << " ";
        _InOrderR(root->_right);

    }

    void _InOrder(Node* root) //中序遍历 非递归
    {
        if(root == NULL)
            return;
        stack<Node*> s;
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root->_left;
            }
            root = s.top();
            s.pop();
            cout << root->_data <<" ";
            root = root->_right;
        }

    }

    void _PostOrderR(Node* root)  //后序遍历 左 右 根  递归
    {
        if(root == NULL)
            return;
        _PostOrderR(root->_left);

        _PostOrderR(root->_right);
        cout << root->_data << " ";

    }

    /* void _PostOrder(Node* root)  //后序遍历 左 右 根  非递归
     {
         if(root == NULL)
             return;
         stack<Node*> s;
         stack<int> v;
         while(root || !s.empty())
         {
             while(root)//第一种做法另一种方法是再建立一个栈作为辅助数据结构，其中的内容记录每个节点在栈顶出现的次数。这个栈必须和二叉树节点栈保持同步，即每次一起出栈进栈
             {
                 s.push(root);
                 v.push(0);
                 root = root->_left;
             }
             if(v.top() == 1)
             {
                 cout << s.top()->_data << " ";
                 s.pop();
                 v.pop();
             }
             else
             {
                 root = s.top();
                 root = root->_right;
                 v.top() = 1;
             }

             while(root)//第二种做法没有辅助变量
             {
                 s.push(root);
                 root = root->_left? root->_left : root->_right;

             }
             root = s.top();
             cout << root->_data <<" ";
             s.pop();
             if(!s.empty() && s.top()->_left == root)
                 root = s.top()->_right;
             else
                 root = NULL;
         }
     }*/
    void _PostOrder(Node* root)  //第三种非递归要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
    {
        if(root == NULL)
            return;
        stack<Node*> s;
        Node *pre = NULL;
        Node *cur;
        s.push(root);
        while(!s.empty())
        {
            cur = s.top();
            if((cur->_left == NULL && cur->_right == NULL) || (pre !=NULL && (pre == cur->_left || pre == cur->_right)))
            {
                cout << cur->_data << " ";
                s.pop();
                pre = cur;
            }
            else
            {

                if(cur->_right)
                    s.push(cur->_right);
                if(cur->_left)
                    s.push(cur->_left);


            }

        }
    }

protected:
    Node* _root;
};

void Test()
{
    int array[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
    BinaryTree<int> p(array, sizeof(array) / sizeof(array[0]), '#');
    cout << "前序递归遍历： " << "";
    p.PreOrderR();
    cout << endl;

    cout << "前序非递归遍历： " << "";
    p.PreOrder();
    cout << endl;

    cout << "中序递归遍历： " << "";
    p.InOrderR();
    cout << endl;

    cout << "中序非递归遍历： " << "";
    p.InOrder();
    cout << endl;

    cout << "后序递归遍历： " << "";
    p.PostOrderR();
    cout << endl;

    cout << "后序非递归遍历： " << "";
    p.PostOrder();
    cout << endl;
}


int main()
{
    Test();
    system("pause");
    return 0;
}
