#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#define pow2(n) (1 << (n))
using namespace std;
struct avl
{
    int d;
    struct avl *l;
    struct avl *r;
} *r;
class avl_tree
{
public:
    int height(avl *);
    int difference(avl *);
    avl *rr_rotat(avl *);
    avl *ll_rotat(avl *);
    avl *lr_rotat(avl *);
    avl *rl_rotat(avl *);
    avl *balance(avl *);
    avl *insert(avl *, int);
    void inorder(avl *);
    void search(avl *);
    avl_tree()
    {
        r = NULL;
    }
};
int avl_tree::height(avl *t)
{
    int h = 0;
    if (t != NULL)
    {
        int l_height = height(t->l);
        int r_height = height(t->r);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int avl_tree::difference(avl *t)
{
    int l_height = height(t->l);
    int r_height = height(t->r);
    int b_factor = l_height - r_height;
    return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent)
{
    avl *t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout << "\nRight-Right Rotation";
    return t;
}
avl *avl_tree::ll_rotat(avl *parent)
{
    avl *t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
    cout << "\nLeft-Left Rotation";
    return t;
}
avl *avl_tree::lr_rotat(avl *parent)
{
    avl *t;
    t = parent->l;
    parent->l = rr_rotat(t);
    cout << "\nLeft-Right Rotation";
    return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent)
{
    avl *t;
    t = parent->r;

    parent->r = ll_rotat(t);
    cout << "\nRight-Left Rotation";
    return rr_rotat(parent);
}
avl *avl_tree::balance(avl *t)
{
    int bal_factor = difference(t);
    if (bal_factor > 1)
    {
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }
    else if (bal_factor < -1)
    {
        if (difference(t->r) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}
avl *avl_tree::insert(avl *r, int v)
{
    if (r == NULL)
    {
        r = new avl;
        r->d = v;
        r->l = NULL;
        r->r = NULL;
        return r;
    }
    else if (v < r->d)
    {
        r->l = insert(r->l, v);
        r = balance(r);
    }
    else if (v >= r->d)
    {
        r->r = insert(r->r, v);
        r = balance(r);
    }
    return r;
}
void avl_tree::inorder(avl *t)
{
    if (t == NULL)
        return;
    inorder(t->l);
    cout << t->d << " ";
    inorder(t->r);
}
void avl_tree::search(avl *t)
{
    cout << "Enter data you want to search: ";
    int k, f = 0;
    cin >> k;
    if (t == nullptr)
    {
        cout << "No tree available.";
    }
    else
    {
        while (t != nullptr)
        {
            if (t->d == k)
            {
                f = 1;
                break;
            }
            else if (t->d > k)
            {
                t = t->l;
            }
            else
            {
                t = t->r;
            }
        }
        if (f == 1)
        {
            cout << "Data found";
        }
        else
        {
            cout << "Data not found";
        }
    }
}

int main()
{
    int c, i;
    avl_tree avl;
    while (1)
    {
        cout << "\nMenu" << endl;
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.InOrder traversal" << endl;
        cout << "3.search" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = avl.insert(r, i);
            break;
        case 2:
            if (r == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            else
            {
                cout << "Inorder Traversal:" << endl;
                avl.inorder(r);
                cout << endl;
            }

            break;
        case 3:
            cout << "Search node:" << endl;
            avl.search(r);
            cout << endl;
            break;
        case 4:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}
