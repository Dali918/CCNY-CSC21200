#include <iostream>
using namespace std;
int TotalCnt = 0;

struct ListNode
{
    string Item;
    int count;
    ListNode *link; // LinkList pointer
};

ListNode *createLink(string item, int count)
{

    ListNode *current = new ListNode; // create 1st node
    current->Item = item;             // set link item
    current->count = count;           // set link count / node ID
    current->link = NULL;             // set link pointer to NULL

    // cout << "Enter Item Name" << endl;
    // cin >> current->Item;
    // cout << "Enter count" << endl;
    // cin >> current->count;

    // TotalCnt++; // increment total count

    return current; // return address of 1st node
}

ListNode *addLink(ListNode *head, string name, int count)
{
    ListNode *current = createLink(name, count); // create a new link
    current->link = head;                        // add as a first node
    head = current;                              // update head address to current
    return head;                                 // return new head address
} // end of addLink

void PrintLink(ListNode *node) // Added Print Link function
{
    cout << "Node->Item = " << node->Item;
    cout << ", Node->count = " << node->count << endl;
}

void PrintList(ListNode *head)
{
    ListNode *temp = head; // copy head address to temp

    cout << " ----------- " << endl;

    if (temp == NULL)
    {
        cout << "Empty List " << endl;
    }
    else
    {
        cout << "Total Count: " << TotalCnt << endl;
        while (temp != NULL)
        {
            PrintLink(temp);   // print the current link
            temp = temp->link; // move to next node
        }
    }

    return;
}

int findList(ListNode *head, string Object)
{
    ListNode *temp = head;
    int NodeId = 1; // init NodeId

    cout << " ----------- " << endl;

    while (temp != NULL)
    {
        if (temp->Item == Object)
        {
            cout << "Object found at Node #" << NodeId << endl;
            cout << "temp->Item = " << temp->Item << endl;
            cout << "temp->count = " << temp->count << endl;
            return NodeId;
        }
        NodeId++;
        temp = temp->link; // move to next node
    }
    return -1; // return -1 if node not found

} // end of findList( )

ListNode *deleteLink(ListNode *head, int Link) // changed delete to be nonvoid (returns head)
{
    ListNode *temp = head; // copy head address
    ListNode *prev = head; // pointer to previous node

    int NodeId = 1;

    cout << " ----------- " << endl;

    while (temp != NULL)
    {

        if (NodeId == Link)
        {
            (temp == head) ? head = temp->link : prev->link = temp->link; // change head or =rewire previous's link pointer

            cout << "Deleting Node from list:" << endl;
            PrintLink(temp);
            cout << "------------------------------" << endl;
            delete temp;
            return head;
        }
        NodeId++;
        prev = temp;
        temp = temp->link; // move to next node
    }                      // end of while loop

    cout << "Could not find Node to Delete" << endl;
    cout << "---------------------------------" << endl;
    return head;
} // end of  deleteList()
void insertLink(ListNode *head, int Link)
{
    ListNode *temp = head;
    ListNode *prev = head;
    ListNode *current = NULL;
    bool flag = 0;

    cout << "+ +-+-+-+-+ " << endl;
    int NodeId = 1;
    int counter = 0;
    while (temp != NULL)
    { // count how many existing nodes
        temp = temp->link;
        counter++;
    }

    cout << "counter = " << counter << endl;

    // create new link
    current = new ListNode;
    cout << "Enter Item" << endl; // fill it up
    cin >> current->Item;
    cout << "Enter count" << endl;
    cin >> current->count;

    if (Link > 1 && Link <= counter)
    { // test range
        temp = head;
        for (int i = 0; i < Link; i++)
        {
            prev = temp;       // save present address
            temp = temp->link; // advance to next node
        }
        prev->link = current; // assign prev node with current address
        current->link = temp; // assign temp address to current  link addr
    }

    TotalCnt++;

    return;
}

/******************************************/
// 1) bool Stack_Empty(Stack_ptr) - which informs user if the Stack is empty/full
bool Stack_Empty(ListNode *node)
{
    return (node == NULL);
}
// 2) Stack_ptr Push(Stack_ptr) - which allows to push a new node into the Stack
//    and fills the appropriate fruit name and corresponding count.
ListNode *Push(ListNode *node, string name, int count)
{
    TotalCnt++; // increment total count
    return addLink(node, name, count);
}
// 3) StacK_ptr Pop(Stack_ptr) - which removes the most recent node
ListNode *Pop(ListNode *node)
{
    if (!Stack_Empty(node))
    {

        TotalCnt--;                 // decrement total count
        node = deleteLink(node, 1); // remove current head
    }
    else
    {
        cout << "Stack is Empty!" << endl;
    }

    return node; // return head
}
// 4) string Stack_Peak(Stack_ptr) - which returns the fruit name of the top node
string Stack_Peak(ListNode *node)
{
    return (Stack_Empty(node)) ? "Stack is Empty!" : node->Item;
}
// 5) The number of nodes in the Stack should be stored in a global variable
//    TotalNodeCnt

// 6) void Print(Stack_ptr) function that allows the user to print the fruits in the Stack
//    without popping them.
void Print(ListNode *node)
{
    PrintList(node);
}

int main()
{
    string Name;
    /*****************************************/
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /*****************************************/

    const int len = 10;
    int count = 0;
    ListNode *head = NULL;
    /*
a) The problem should fill the stack with the following list of fruits with
   corresponding counts
    Apple - 10
    Bananas - 20
    Cherry - 30
    Date - 40
    Endive - 50
    Fig - 60
    Guava - 70
    Herb - 80
    Iacamolo - 90
    Java  - 100
*/
    string entries[len] = {"Apple", "Bananas", "Cherry", "Date", "Endive",
                           "Fig", "Guava", "Herb", "Iacamolo", "Java"};

    for (int i = 0; i < len; i++)
    {
        head = Push(head, entries[i], count += 10);
    }
    // b) Print the entire list of stuffed fruits
    Print(head);
    // c) Remove 3 fruits and Print the remaining list of fruits
    for (int i = 0; i < 3; i++)
    {
        head = Pop(head); // takes double pointer arguments
    }
    Print(head);
    // d) Peak into the Stack and print the corresponding fruit/count
    cout << "--------Peak------------" << endl;
    cout << Stack_Peak(head) << endl;
    //    d) Remove all fruits
    while (Stack_Empty(head) == 0)
    {
        head = Pop(head);   
    }
    // e) Check that the Stack is empty
    cout << "--------Peak After Clearing List------------" << endl;
    cout << Stack_Peak(head) << endl;
    return 0;
}
