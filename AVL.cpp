#include <iostream>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

class Node
{
public:
    float data;
    int height;
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
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *RSearch(Node *p, float key);
    Node *RInsert(Node *p, float key);
    Node *Delete(Node *p, float key);
    Node *InOrderPredecessor(Node *p);
    Node *InOrderSuccessor(Node *p);
    Node *CreateAVLFromPreOrder(float pre[], int n);
    Node *LL_Rotation(Node *p);
    Node *LR_Rotation(Node *p);
    Node *RR_Rotation(Node *p);
    Node *RL_Rotation(Node *p);
    Node *ReturnBalanceFactorNode(Node *p);
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
    root->height = 1;
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
            t->height = 1;
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
            t->height = 1;
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
int Tree::NodeHeight(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}
int Tree::BalanceFactor(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

Node *Tree::LL_Rotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if (root == p)
        root = pl;
    return pl;
}
Node *Tree::RR_Rotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if (root == p)
        root = pr;
    return pr;
}
Node *Tree::LR_Rotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;
    return plr;
}

Node *Tree::RL_Rotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;
    return prl;
}

Node *Tree::ReturnBalanceFactorNode(Node *p)
{
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LL_Rotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LR_Rotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
        return RR_Rotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return RL_Rotation(p);
    else
        return p;
}
Node *Tree::RInsert(Node *p, float key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    p->height = NodeHeight(p);
    // if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    //     return LL_Rotation(p);
    // else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    //     return LR_Rotation(p);
    // else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
    //     return RR_Rotation(p);
    // else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
    //     return RL_Rotation(p);
    p = ReturnBalanceFactorNode(p);

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
            p->height = q->height;
            p = ReturnBalanceFactorNode(p);

            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InOrderSuccessor(p->rchild);
            p->data = q->data;
            p->height = q->height;
            p = ReturnBalanceFactorNode(p);

            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

Node *Tree::CreateAVLFromPreOrder(float pre[], int n)
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
    p = ReturnBalanceFactorNode(p);
    return root;
}

int main()
{
    Node *root = NULL;
    Node *newRoot = NULL;

    // Node *temp;
    Tree T;
    // float pre[] = {10, 5, 20, 8, 30};
    // root = T.CreateBSTFromPreOrder(pre, 5);
    root = T.RInsert(root, 50);
    T.RInsert(root, 10);
    newRoot = T.RInsert(root, 20);
    T.Delete(newRoot, 20);

    T.PreOrder(newRoot);
    cout << endl;

    // temp = T.RSearch(root, 5);
    // cout << temp->data << endl;

    // T.Insert(T.root, 55);
    // T.Insert(T.root, 58);
    // T.Insert(T.root, 5);
    // T.PreOrder(T.root);
    return 0;
}