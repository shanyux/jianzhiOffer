#include <iostream>
#include <Windows.h>
#include <stack>
using namespace std;

template <class T>
struct BinaryTreeNode
{
    int _data;
    BinaryTreeNode<T>* _left; //����
    BinaryTreeNode<T>* _right;  //�Һ���
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

    void PreOrderR()  //ǰ����� �ݹ�
    {
        _PreOrderR(_root);
    }

    void PreOrder()  //ǰ����� �ǵݹ�
    {
        _PreOrder(_root);
    }

    void InOrderR() //������� �ݹ�
    {
        _InOrderR(_root);
    }

    void InOrder()   //�������  �ǵݹ�
    {
        _InOrder(_root);
    }

    void PostOrderR()  //������� �� �� ��  �ݹ�
    {
        _PostOrderR(_root);
    }

    void PostOrder()  //������� �� �� ��  �ǵݹ�
    {
        _PostOrder(_root);
    }

    ~BinaryTree()
    {}

protected:
//���� arr:����ʹ�õ����� n�������С invalid:�Ƿ�ֵ index:��ǰ�±�
    Node* _CreatTree(T* arr, size_t n, const T& invalid, size_t& index)
    {
        Node* root = NULL;
        if (index < n && arr[index] != invalid)
        {
            root = new Node(arr[index]); //���ڵ�
            root->_left = _CreatTree(arr, n, invalid, ++index);
            root->_right = _CreatTree(arr, n, invalid, ++index);
        }
        return root;
    }

    void _PreOrderR(Node* root)  //ǰ����� �ݹ�
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->_data << " ";
        _PreOrderR(root->_left);
        _PreOrderR(root->_right);
    }

    void _PreOrder(Node* root)  //ǰ����� �ǵݹ�
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

    void _InOrderR(Node* root) //������� �ݹ�
    {
        if (root == NULL)
        {
            return;
        }
        _InOrderR(root->_left);
        cout << root->_data << " ";
        _InOrderR(root->_right);
    }

    void _InOrder(Node* root) //������� �ǵݹ�
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
            //��ʱ����ѭ���ߵ�������Ҷ�ӽڵ�
            Node* temp = tty.top();
            tty.pop();
            cout << temp->_data << " ";
            root = temp->_right;
        }
    }

    void _PostOrderR(Node* root)  //������� �� �� ��  �ݹ�
    {
        if (root == NULL)
        {
            return;
        }
        _PostOrderR(root->_left);
        _PostOrderR(root->_right);
        cout << root->_data << " ";
    }

    void _PostOrder(Node* root)  //������� �� �� ��  �ǵݹ�
    {
        if (root == NULL)
        {
            return;
        }
        stack<Node*> tty;
        Node* PreNode = NULL; //��һ�����ʵĽ��
        tty.push(root);
        while (!tty.empty())
        {
            Node* cur = tty.top();
            //���ʵĵ�ǰ�ڵ����Һ��Ӿ�Ϊ�ջ��ߵ�ǰ�ڵ������������Ѿ����ʹ�
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
    cout << "ǰ��ݹ������ " << "";
    p.PreOrderR();
    cout << endl;

    cout << "ǰ��ǵݹ������ " << "";
    p.PreOrder();
    cout << endl;

    cout << "����ݹ������ " << "";
    p.InOrderR();
    cout << endl;

    cout << "����ǵݹ������ " << "";
    p.InOrder();
    cout << endl;

    cout << "����ݹ������ " << "";
    p.PostOrderR();
    cout << endl;

    cout << "����ǵݹ������ " << "";
    p.PostOrder();
    cout << endl;
}

int main()
{
    Test();
    system("pause");
    return 0;
}
