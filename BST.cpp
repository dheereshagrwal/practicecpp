#include <iostream>
#include <queue>
#include <stack>
#include <limits>
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
    void LevelOrder(Node *p);
    int Height(Node *p);
    Node *RSearch(Node *p, float key);
    Node *SearchIterative(Node *p, float key);
    void Insert(Node *p, float key);
    Node *RInsert(Node *p, float key);
    Node *Delete(Node *p, float key);
    Node *InOrderPredecessor(Node *p);
    Node *InOrderSuccessor(Node *p);
    Node *CreateBSTFromPreOrder(float pre[], int n);
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

Node *Tree::RSearch(Node *p, float key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    else if (key < p->data)
        return RSearch(p->lchild, key);
    else
        return RSearch(p->rchild, key);
}
Node *Tree::SearchIterative(Node *p, float key)
{
    while (p)
    {
        if (key == p->data)
            return p;
        else if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}

void Tree::Insert(Node *p, float key)
{
    Node *r = NULL;
    Node *t;
    if (root == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        root = t;
        return;
    }
    while (p)
    {
        r = p;
        if (key == p->data)
            return;
        else if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (t->data < r->data)
        r->lchild = t;
    else
        r->rchild = t;
}
int Tree::Height(Node *p)
{
    int x = 0, y = 0;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node *Tree::InOrderPredecessor(Node *p)
{
    while (p && p->rchild)
        p = p->rchild;
    return p;
}

Node *Tree::InOrderSuccessor(Node *p)
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

Node *Tree::RInsert(Node *p, float key)
{
    if (p == NULL)
    {
        Node *t;
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (p->data < key)
        p->rchild = RInsert(p->rchild, key);
    return p;
}
Node *Tree::Delete(Node *p, float key)
{
    Node *q;
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        delete p;
        return NULL;
    }
    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (p->data < key)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InOrderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InOrderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

Node *Tree::CreateBSTFromPreOrder(float pre[], int n)
{
    stack<Node *> st;
    Node *t, *p, *maxFloat;
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;
    float maxFloatValue = numeric_limits<float>::max();
    maxFloat = new Node;
    maxFloat->data = maxFloatValue;
    maxFloat->lchild = maxFloat->rchild = NULL;

    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            st.push(p);
            p = t;
        }
        else
        {
            if (st.empty())
                st.push(maxFloat);
            if (pre[i] > p->data && pre[i] < (st.top())->data)
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = st.top();
                st.pop();
            }
        }
    }
    return root;
}

int main(void)
{
    Node *root = NULL;
    Node *temp;
    Tree T;
    // float pre[] = {10, 5, 20, 8, 30};
    // root = T.CreateBSTFromPreOrder(pre, 5);
    root = T.RInsert(root, 10);
    T.RInsert(root, 5);
    temp = T.RInsert(root, 2);
    // T.RInsert(root, 8);
    // T.RInsert(root, 30);

    // T.InOrder(root);
    // cout << endl;
    // T.Delete(root, 20);
    T.InOrder(root);
    cout << endl;

    // temp = T.RSearch(root, 5);
    cout << temp->data << endl;

    // T.Insert(T.root, 55);
    // T.Insert(T.root, 58);
    // T.Insert(T.root, 5);
    // T.PreOrder(T.root);
}