#include <iostream>
using namespace std;
// Node structure
struct node
{
    int data;   // data section of node.
    node *next; // pointer section of node.
};
// Class For node
class list
{
public:
    node *header = nullptr, *nn = nullptr;
    // function1
    void display();
    // insert
    void insert(int op);
    void insert_end(node *nn, node *cn);
    void insert_beg(node *nn);
    void insert_pos(node *nn, node *cn);
    // delete
    void del_end();
    void del_beg();
    void del_pos();
    void reverse();
    void search();
};
void list::display()
{
    node *cn = header;
    if (header == nullptr)
    {
        cout << "\n[X]-No Linked-List in Data based\n";
    }
    else
    {
        cout << "\n----------------------------------------------------------------"
                "----------------------------------------------\n";
        while (cn != nullptr)
        {
            cout << cn->data << " -> ";
            cn = cn->next;
        }
        cout << "X";
        cout << "\n----------------------------------------------------------------"
                "----------------------------------------------\n";
    }
};
// Insert oprations
void list::insert(int op)
{
    node *cn = header;
    // insertion;
    // node creation
    nn = new node;
    cout << "Enter data For your node: ";
    cin >> nn->data;
    nn->next = nullptr;
    switch (op)
    {
    case 1:
        insert_end(nn, cn);
        break;
    case 2:
        insert_beg(nn);
        break;
    case 3:
        insert_pos(nn, cn);
        break;
    default:
        cout << "aise hi band ho gaya";
        break;
    }
    display();
};
void list::insert_end(node *nn, node *cn)
{
    // Insert at end
    cn = header;
    if (cn == nullptr)
    {
        header = nn;
    }
    else
    {
        while (cn->next != nullptr)
        {
            cn = cn->next;
            cout << "\nlooping cn";
        }
        cn->next = nn;
        cout << "\n node inserted";
    }
};
void list::insert_beg(node *nn)
{
    nn->next = header;
    header = nn;
};
void list::insert_pos(node *nn, node *cn)
{
    int count = 0, pos;
    while (cn != nullptr)
    {
        cn = cn->next;
        count++;
    }
    cout << "\nno of elements: " << count;
    cout << "\nEnter position you want to add element: ";
    cin >> pos;
    if (pos > count + 1)
    {
        cout << "\n[X]-invalid position\n";
    }
    else if (pos == count + 1)
    {
        insert_end(nn, cn);
    }
    else if (pos == 1)
    {
        insert_beg(nn);
    }
    else
    {
        int i;
        cn = header;
        for (i = 1; i < pos - 1; i++)
        {
            cn = cn->next;
        }
        nn->next = cn->next;
        cn->next = nn;
    }
};
// Delation opertions
void list::del_end()
{
    node *cn = header;
    while ((cn->next)->next != nullptr)
    {
        cn = cn->next;
    }
    delete cn->next;
    cn->next = nullptr;
    display();
};
void list::del_beg()
{
    node *temp = header;
    header = header->next;
    delete temp;
    display();
};
void list::del_pos()
{
    node *cn = header;
    int count = 0, pos;
    while (cn != nullptr)
    {
        cn = cn->next;
        count++;
    }
    cout << "\nno of elements: " << count;
    cout << "\nEnter position you want to delete element: ";
    cin >> pos;
    if (pos > count + 1)
    {
        cout << "\n[X]-invalid position\n";
    }
    else if (pos == count + 1)
    {
        del_end();
    }
    else if (pos == 1)
    {
        del_beg();
    }
    else
    {
        int i;
        cn = header;
        for (i = 1; i < pos - 1; i++)
        {
            cn = cn->next;
        }
        node *temp = cn->next;
        cn->next = (cn->next)->next;
        delete temp;
    }
    display();
};
// Reverse operation
void list::reverse()
{
    node *cn = header; // current pointer
    node *prev = NULL; // previous pointer
    while (cn)
    {
        node *temp = cn->next;
        cn->next = prev;
        prev = cn;
        header = prev;
        cn = temp;
    }
    display();
};
// search
void list::search()
{
    int key, count = 0, flag = 0;
    cout << "\nEnter Data you want to search: ";
    cin >> key;
    node *cn = header;
    while (cn)
    {
        count++;
        if (cn->data == key)
        {
            cout << "\nData found at: " << count << " position";
            flag = 1;
        }
        cn = cn->next;
    }
    if (flag == 0)
    {
        cout << "Data not found ----[X]";
    }
};
// Driver function
int main()
{
    cout << "Lets play with link list :)\n";
    list l1;
    // menu
    int op, opi;
    do
    {
        cout
            << "\n-Menu-\n\n 1.Dispaly list\n 2.Inset element\n 3.Delete element\n "
               "4.Reverse list\n 5.Search\n 6.Exit\n\nChoose desired option > ";
        cin >> op;
        switch (op)
        {
        case 1:
            l1.display();
            break;
        case 2:
            cout << "\n-Menu insertion-\n\n 1.Insert at End\n 2.Insert at "
                    "Begaining\n 3.Insert at custom position\n\n-Choose > ";
            cin >> opi;
            switch (opi)
            {
            case 1:
                l1.insert(1);
                break;
            case 2:
                l1.insert(2);
                break;
            case 3:
                l1.insert(3);
                break;
            default:
                cout << "\n [X]-galat button\n";
                break;
            };
            break;
        case 3:
            if (l1.header == nullptr)
            {
                cout << "\n[X]-No Linked-List in Data based\n";
            }
            else
            {
                cout << "\n-Menu insertion-\n\n 1.Delete at End\n 2.Delete at "
                        "Begaining\n 3.Delete at custom position\n\n-Choose > ";
                cin >> opi;
                switch (opi)
                {
                case 1:
                    l1.del_end();
                    break;
                case 2:
                    l1.del_beg();
                    break;
                case 3:
                    l1.del_pos();
                    break;
                default:
                    cout << "\n [X]-galat button\n";
                    break;
                };
            }
            break;
        case 4:
            l1.reverse();
            break;
        case 5:;
            l1.search();
            break;
        default:
            cout << "Program Terminated";
            break;
        }
    } while (op < 6);

    return 0;
}
