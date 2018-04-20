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
        if(root == NULL)
            return;
        cout << root->_data << " ";
        _PreOrderR(root->_left);
        _PreOrderR(root->_right);

    }

    void _PreOrder(Node* root)  //ǰ����� �ǵݹ�
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

    void _InOrderR(Node* root) //������� �ݹ�
    {
        if(root == NULL)
            return;
        _InOrderR(root->_left);
        cout << root->_data << " ";
        _InOrderR(root->_right);

    }

    void _InOrder(Node* root) //������� �ǵݹ�
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

    void _PostOrderR(Node* root)  //������� �� �� ��  �ݹ�
    {
        if(root == NULL)
            return;
        _PostOrderR(root->_left);

        _PostOrderR(root->_right);
        cout << root->_data << " ";

    }

    /* void _PostOrder(Node* root)  //������� �� �� ��  �ǵݹ�
     {
         if(root == NULL)
             return;
         stack<Node*> s;
         stack<int> v;
         while(root || !s.empty())
         {
             while(root)//��һ��������һ�ַ������ٽ���һ��ջ��Ϊ�������ݽṹ�����е����ݼ�¼ÿ���ڵ���ջ�����ֵĴ��������ջ����Ͷ������ڵ�ջ����ͬ������ÿ��һ���ջ��ջ
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

             while(root)//�ڶ�������û�и�������
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
    void _PostOrder(Node* root)  //�����ַǵݹ�Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ�����P���������Ӻ��Һ��ӣ������ֱ�ӷ�����������P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣�������������������P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
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
