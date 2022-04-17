/**********************************************
program: LinkListC.cpp
author: Y. Solow
date: July 4, 2016
synopsis: to program a singly link list using C
**********************************************/

/*
We developed in class a LinkedListC.cpp program that creates a working Singly
Linked List that contains nodes that contain the name of a fruit(string) and how
many fruits it contains  (int cnt) as well as a pointer to the next node.

Modify this LinkListC.cpp program to act as a Stack container which can stuff
as many fruits asthe user wants

The created Stack container should provide only  the following functions:
1) bool Stack_Empty(Stack_ptr) - which informs user if the Stack is empty/full
2) Stack_ptr Push(Stack_ptr) - which allows to push a new node into the Stack
   and fills the appropriate fruit name and corresponding count.
3) StacK_ptr Pop(Stack_ptr) - which removes the most recent node
4) string Stack_Peak(Stack_ptr) - which returns the fruit name of the top node
5) The number of nodes in the Stack should be stored in a global variable
   TotalNodeCnt
6) void Print(Stack_ptr) function that allows the user to print the fruits in the Stack
   without popping them.

Demonstrate:
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
b) Print the entire list of stuffed fruits
c) Remove 3 fruits and Print the remaining list of fruits
d) Peak into the Stack and print the corresponding fruit/count
d) Remove all fruits
e) Check that the Stack is empty
*/
//#define DEBUG
#include <iostream>
using namespace std;

struct ListNode
{
    string Item;
    int count;
    ListNode *link; // LinkList pointer
};
int TotalCnt = 0;
ListNode *createLink(string name, int count)
{

    ListNode *current = new ListNode; // create 1st node
    current->link = NULL;             // set link pointer to NULL

    // cout << "Enter Item Name" << endl;
    // ;
    // cin >> current->Item;
    // cout << "Enter count" << endl;
    // cin >> current->count;

    // TotalCnt++; // increment total count

    return current; // return address of 1st node
}

ListNode *addLink(ListNode *head, string name, int count)
{
    ListNode *current = new ListNode; // create new node
    current->Item = name;
    current->count = count;

    // cout << "Enter Item Name" << endl; // fill it up  â€¦.!!!!
    // cin >> current->Item;
    // cout << "Enter count" << endl;
    // cin >> current->count;

    current->link = head; // add as a first node
    head = current;       // update head address to bucrrent
#ifdef DEBUG
    cout << "addLink:  head = " << head << endl;
    cout << "addLink:  current->link= " << current->link << endl;
#endif

    // TotalCnt++;

    return head; // return new head address
} // end of addLink

void PrintList(ListNode *head)
{
    ListNode *temp = head; // copy head address to temp

    cout << " ----------- " << endl;

    if (temp == NULL)
        cout << "Empty List " << endl;

    while (temp != NULL)
    {
        cout << "temp->Item = " << temp->Item << endl;
        cout << "temp->count = " << temp->count << endl;

        temp = temp->link; // move to next node
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
        }
        NodeId++;
        temp = temp->link; // move to next node
    }
    return NodeId;

} // end of findList( )

void deleteLink(ListNode **head, int Link)  //changed delete link to take double pointers
{
    ListNode *temp = *head; // copy head address
    ListNode *out = *head;  // address of node to be killed
    ListNode *prev = *head; // pointer to previous node

    int NodeId = 1;

    cout << " ----------- " << endl;

    while (temp != NULL)
    {
        prev = temp;
        if (NodeId == Link)
        {
            out = temp;
            (temp == *head) ? *head = temp->link : prev->link = temp->link; //change head or previous link
            delete out;
            break;
        }
        NodeId++;
        temp = temp->link; // move to next node
    }                      // end of while loop

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
void Pop(ListNode **node)
{
    if (!Stack_Empty(*node))
    {
        deleteLink(node, 1);
        TotalCnt--; // decrement total count
    }
    else
    {
        cout << "Stack is Empty!" << endl;
    }
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
        Pop(&head);
    }
    Print(head);
    // d) Peak into the Stack and print the corresponding fruit/count
    cout << "--------Peak------------" << endl;
    cout << Stack_Peak(head) << endl;
    //    d) Remove all fruits
    while (Stack_Empty(head) == 0)
    {
        Pop(&head);
    }
    // e) Check that the Stack is empty
    cout << "--------Peak After Clearing List------------" << endl;
    cout << Stack_Peak(head) << endl;
    return 0;
}
