// Program for threaded binary tree
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    int lth, rth;
};
class tb_tree
{
public:
    node *nn,
        *root,
        *dummy;
    tb_tree()
    {
        nn = nullptr;
        root = nullptr;
        dummy = new node;
        dummy->data = -1;
        dummy->left = dummy->right = nullptr;
        dummy->rth = dummy->lth = 0;
    }
    // functions
    void insert_inorder();
    int display_inorder();
    int display_preorder();
};
void tb_tree::insert_inorder()
{
    // new node creation
    nn = new node;
    nn->left = nn->right = nullptr;
    nn->lth = nn->rth = 0;
    cout << "Enter dat: ";
    cin >> nn->data;
    if (root == nullptr)
    {
        root = nn;
        nn->left = nn->right = dummy;
        dummy->left = root;
        dummy->lth = 1;
    }
    else
    {
        node *temp = root, *parent;
        while (temp != nullptr)
        {
            parent = temp;
            if (nn->data < temp->data)
            {
                if (temp->lth == 1)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = nullptr;
                }
            }
            else
            {
                if (temp->rth == 1)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = nullptr;
                }
            }
        }
        if (nn->data < parent->data)
        {
            nn->left = parent->left;
            nn->right = parent;
            parent->left = nn;
            parent->lth = 1;
        }
        else
        {
            nn->right = parent->right;
            nn->left = parent;
            parent->right = nn;
            parent->rth = 1;
        }
    }
}
int tb_tree::display_inorder()
{
    node *temp = root;
    while (1)
    {
        while (temp->lth == 1)
        {
            temp = temp->left;
        }
        cout << temp->data << " ";
        while (temp->rth == 0)
        {
            if (temp->right == dummy)
            {
                return 0;
            }
            else
            {
                temp = temp->right;
                cout << temp->data << " ";
            }
        }
        temp = temp->right;
    }
}
int tb_tree::display_preorder()
{
    node *temp = root;
    while (1)
    {
        while (temp->lth == 1)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
        cout << temp->data << " ";
        while (temp->rth == 0)
        {
            if (temp->right == dummy)
            {
                return 0;
            }
            else
            {
                temp = temp->right;
            }
        }
        temp = temp->right;
    }
}
    int main()
    {
        // Write C++ code here
        int op, c;
        tb_tree b;
        do
        {
            cout << "\nMenu\n 1.insert\n 2.Inorder_dispaly\n 3.Preorder_display\n 4.Exit\n option: ";
            cin >> op;
            switch (op)
            {
            case 1:
                while (c)
                {
                    b.insert_inorder();
                    cout << "insert another y/n(1/0):";
                    cin >> c;
                }
                break;
            case 2:
                b.display_inorder();
                break;
            case 3:
                b.display_preorder();
                break;
            default:
                cout << "terminated";
                break;
            }
        } while (op < 4);
        return 0;
    }
