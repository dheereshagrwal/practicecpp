#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    float data;
    Node *lchild;
    Node *rchild;
};
class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void CreateTree();
    void PreOrder(Node *p);
    void PostOrder(Node *p);
    void InOrder(Node *p);
    void InOrderIterative(Node *p);
    void LevelOrder(Node *p);
    int Height(Node *root);
    int Count(Node *root);
    int CountLeafNodes(Node *root);
};
void Tree::CreateTree()
{
    Node *p, *t;
    queue<Node *> q;
    float x;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

void Tree::PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}
void Tree::InOrder(Node *p)
{
    if (p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

void Tree::InOrderIterative(Node *p)
{
    stack<Node *> st;
    while (p || !st.empty())
    {
        if (p)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void Tree::PostOrder(Node *p)
{
    if (p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}
void Tree::LevelOrder(Node *p)
{
    queue<Node *> q;
    cout << root->data << " ";
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.push(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.push(root->rchild);
        }
    }
}
int Tree::Height(Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int Tree::Count(Node *root)
{
    if (root)
        return Count(root->lchild) + Count(root->rchild) + 1;
    return 0;
}

int Tree::CountLeafNodes(Node *root)
{
    int x, y;
    if (root)
    {
        x = CountLeafNodes(root->lchild);
        y = CountLeafNodes(root->rchild);
        if (root->lchild == NULL && root->rchild == NULL) //*For degree 2 change to !=NULL && !=NULL
            return x + y + 1;                             //*For both degree 2 and 1, !=NULL || !=NULL
        //*For degree 1, !=NULL ^ !=NULL
        else
            return x + y;
    }
    else
        return 0;
}
int main(void)
{
    Tree t;
    t.CreateTree();
    t.InOrderIterative(t.root);
}