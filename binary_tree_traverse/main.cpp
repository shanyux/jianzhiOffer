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
        if (root == NULL)
        {
            return;
        }
        cout << root->_data << " ";
        _PreOrderR(root->_left);
        _PreOrderR(root->_right);
    }

    void _PreOrder(Node* root)  //前序遍历 非递归
    {
        stack<Node*> tty;
        while (root != NULL || !tty.empty())
        {
            if (root)
            {
                cout << root->_data << " ";
                tty.push(root);
                root = root->_left;
            }
            else
            {
                Node* temp = tty.top();
                tty.pop();
                root = temp->_right;
            }
        }
    }

    void _InOrderR(Node* root) //中序遍历 递归
    {
        if (root == NULL)
        {
            return;
        }
        _InOrderR(root->_left);
        cout << root->_data << " ";
        _InOrderR(root->_right);
    }

    void _InOrder(Node* root) //中序遍历 非递归
    {
        if (root == NULL)
        {
            return;
        }
        stack<Node*> tty;
        while (root != NULL || !tty.empty())
        {
            while (root)
            {
                tty.push(root);
                root = root->_left;
            }
            //此时出了循环走到了最左叶子节点
            Node* temp = tty.top();
            tty.pop();
            cout << temp->_data << " ";
            root = temp->_right;
        }
    }

    void _PostOrderR(Node* root)  //后序遍历 左 右 根  递归
    {
        if (root == NULL)
        {
            return;
        }
        _PostOrderR(root->_left);
        _PostOrderR(root->_right);
        cout << root->_data << " ";
    }

    void _PostOrder(Node* root)  //后序遍历 左 右 根  非递归
    {
        if (root == NULL)
        {
            return;
        }
        stack<Node*> tty;
        Node* PreNode = NULL; //上一个访问的结点
        tty.push(root);
        while (!tty.empty())
        {
            Node* cur = tty.top();
            //访问的当前节点左右孩子均为空或者当前节点左右子树均已经访问过
            if ((cur->_left == NULL && cur->_right == NULL) || ((PreNode != NULL) && (PreNode == cur->_left || PreNode == cur->_right)))
            {
                cout << cur->_data << " ";
                tty.pop();
                PreNode = cur;
            }
            else
            {
                if (cur->_right != NULL)
                {
                    tty.push(cur->_right);
                }
                if (cur->_left != NULL)
                {
                    tty.push(cur->_left);
                }
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
