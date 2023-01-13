
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left, *right;
};
class stack
{
public:
    int top;
    stack() { top = -1; }

    node *stack_arr[10];
    // function
    void push(node *temp)
    {
        if (top == 9)
        {
            cout << "stack is full---[X]";
        }
        else
        {
            top++;
            stack_arr[top] = temp;
        }
    }

    node *pop()
    {
        if (top == -1)
        {
            cout << "stack is empty";
        }
        else
        {
            node *temp;
            temp = stack_arr[top];
            top--;
            return temp;
        }
    }
};
class bs_tree
{
public:
    node *nn, *root;
    bs_tree()
    {
        nn = nullptr;
        root = nullptr;
    }

    // functions
    void insert();
    void inorder_rec(node *temp);
    void preorder_rec(node *temp);
    void postorder_rec(node *temp);
    void display();
    void des(node *temp);
    void inorder();
    void preorder();
    void postorder();
    void display_nonrec();
    node *search(int data);
    node *deleteNode(node* root, int data);
};

void bs_tree::insert()
{
    // new node creation
    nn = new node;
    nn->left = nn->right = nullptr;
    cout << "Enter dat: ";
    cin >> nn->data;

    if (root == nullptr)
    {
        root = nn;
    }
    else
    {
        node *temp = root, *parent = nullptr;
        while (temp != nullptr)
        {
            parent = temp;
            if (temp->data > nn->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (parent->data > nn->data)
        {
            parent->left = nn;
        }
        else
        {
            parent->right = nn;
        }
    }
}
void bs_tree::inorder_rec(node *temp)
{
    if (temp != nullptr)
    {
        inorder_rec(temp->left);
        cout << temp->data << " ";
        inorder_rec(temp->right);
    }
}
void bs_tree::preorder_rec(node *temp)
{
    if (temp != nullptr)
    {
        cout << temp->data << " ";
        preorder_rec(temp->left);
        preorder_rec(temp->right);
    }
}
void bs_tree::postorder_rec(node *temp)
{
    if (temp != nullptr)
    {
        postorder_rec(temp->left);
        postorder_rec(temp->right);
        cout << temp->data << " ";
    }
}
void bs_tree::display()
{
    int op;
    do
    {
        cout << "\nMenu\n 1.inorder\n 2.preorder\n 3.postorder\n 4.descending\n "
                "option: ";
        cin >> op;
        switch (op)
        {
        case 1:
            inorder_rec(root);
            break;
        case 2:
            preorder_rec(root);
            break;
        case 3:
            postorder_rec(root);
            break;
        case 4:
            des(root);
        default:
            break;
        }
    } while (op < 5);
}
void bs_tree::des(node *temp)
{
    if (temp != nullptr)
    {
        des(temp->right);
        cout << temp->data << " ";
        des(temp->left);
    }
}
void bs_tree::inorder()
{
    node *temp = root;
    stack s;
    while (temp != nullptr)
    {
        s.push(temp);
        temp = temp->left;
    }

    while (s.top != -1)
    {
        temp = s.pop();
        cout << temp->data << " ";
        temp = temp->right;
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}
void bs_tree::preorder()
{
    node *temp = root;
    stack s;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        s.push(temp);
        temp = temp->left;
    }

    while (s.top != -1)
    {
        temp = s.pop();
        temp = temp->right;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            s.push(temp);
            temp = temp->left;
        }
    }
}
void bs_tree::postorder()
{
    node *temp = root;
    stack s1, s2;
    s1.push(temp);
    while (s1.top != -1)
    {
        temp = s1.pop();
        if (temp->left != nullptr)
        {
            s1.push(temp->left);
        }

        if (temp->right != nullptr)
        {
            s1.push(temp->right);
        }

        s2.push(temp);
    }

    while (s2.top != -1)
    {
        temp = s2.pop();
        cout << temp->data << " ";
    }
}
void bs_tree::display_nonrec()
{
    int op;
    if (root == nullptr)
    {
        cout << "No tree";
    }
    do
    {
        cout << "\nMenu\n 1.inorder\n 2.preorder\n 3.postorder\n 4.EXIT\n option: ";
        cin >> op;
        switch (op)
        {
        case 1:
            inorder();
            break;
        case 2:
            preorder();
            break;
        case 3:
            postorder();
            break;
        default:
            break;
        }
    } while (op < 4);
}
node *bs_tree::search(int data)
{
    if (root == nullptr)
    {
        cout << "\n No tree in existance\n";
    }
    else
    {
        int flag = 0;
        node *temp = root, *parent = nullptr;
        while (temp != nullptr)
        {
            if (data == temp->data)
            {
                flag = 1;
                break;
            }

            parent = temp;
            if (data < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (flag == 1)
        {
            cout << "data found as child of:" << parent->data << endl;
        }
        else
        {
            cout << "\nNo such data found in tree\n";
        }

        return parent;
    }
}
node* bs_tree::deleteNode(node* root, int data) {
    if (!root) return NULL;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if(root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        } else {
            node* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    // Write C++ code here
    int op, c, data;
    bs_tree b;
    do
    {
        cout << "\nMenu\n 1.insert\n 2.dispaly\n 3.display(non-recursive)\n "
                "4.Search\n 5.delete\n 6.exit\n option: ";
        cin >> op;
        switch (op)
        {
        case 1:
            while (c)
            {
                b.insert();
                cout << "insert another y/n(1/0):";
                cin >> c;
            }

            break;
        case 2:
            b.display();
            break;
        case 3:
            b.display_nonrec();
            break;
        case 4:
            cout << "\n Enter data You Want to Search:";
            cin >> data;
            b.search(data);
            break;
        case 5:
            cout << "\n Enter data You Want to delete:";
            cin >> data;
            b.deleteNode(b.root,data);
            break;
        default:
            cout << "terminated";
            break;
        }
    } while (op < 6);

    return 0;
}
