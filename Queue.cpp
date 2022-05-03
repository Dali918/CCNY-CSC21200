#include <iostream>
using namespace std;

struct Node // Node Structure
{
    string data;
    int id;
    Node *next;
};
void printNode(Node *node)
{
    cout << "Node: " << node->id << " Node Data: " << node->data << endl;
    cout << "----------" << endl;
}
//---------------------------
bool isEmpty(Node *front, Node *end)
{
    return (front == NULL || end == NULL); // helper function to determine if queue is empty
}

void push(Node *&front, Node *&end, Node *node)
{
    // check if queue is empty
    if (front == NULL)
    {
        // adding the first item
        cout << "pushing front" << endl;
        // set front and end to the same node
        front = node;
        end = node;
    }
    else
    {

        cout << "PUSHING " << endl;
        // update front
        end->next = node;
        end = node;
    }
}

void pop(Node *&front, Node *&end)
{
    Node *temp;
    if (isEmpty(front, end))
    {
        cout << "Queue is Empty, Nothing to Pop!" << endl; // check if queue is empty
    }
    else
    {
        cout << "POPPING: ";
        printNode(front);
        temp = front;
        front = front->next; // set front to next
        delete temp;         // deallocate memory
    }
}

void peek(Node *front, Node *end)
{
    if (front != NULL)
    {
        cout << " Front is: ";
        printNode(front);
        cout << " End is: ";
        printNode(end);
    }
    else
    {
        cout << "Queue is Empty!" << endl;
    }
}

Node *createNode(int id, string data)
{
    Node *node = new Node;
    node->id = id;
    node->data = data;
    node->next = NULL;

    return node;
}

void print(Node *front)
{
    Node *curr = front;
    while (curr != NULL)
    {
        if (curr == front)
        {
            cout << "FRONT: "; // print when printing first node
        }
        if (curr->next == NULL)
        {
            cout << "END: "; // print when printing last node
        }

        printNode(curr);

        curr = curr->next;
    }
}

int main()
{
    Node *front = NULL;
    Node *end = NULL;
    Node *node = NULL;
    // Test Bench
    string string_array[] = {"apple", "grape", "banana", "pen", "book", "mouse"};
    int id_array[] = {2, 4, 6, 8, 10, 12};
    const int len = 6;

    cout << "CURRENT TEST BENCH" << endl;
    cout << "{ ";
    for (int i = 0; i < len; i++)
    {
        cout << "( id: " << id_array[i] << ", item: " << string_array[i] << ") ";
    }
    cout << "} "<<endl;

    // Testing Push
    for (int i = 0; i < len; i++)
    {
        // loop through test benche(s) and make node (id and item name)
        node = createNode(id_array[i], string_array[i]);
        push(front, end, node);
    }
    // Printing After Pushing
    cout<<"**************"<<endl;
    cout<<"Current Queue:\n-------------------"<<endl;
    print(front);
    cout << "***************************************************\n"
         << endl;
    // Testing Pop and Peek
    while (!isEmpty(front, end))
    {
        // peek stack
        peek(front, end);
        // pop
        cout << "Now Pop" << endl;
        pop(front, end);
    }

    return 0;
}