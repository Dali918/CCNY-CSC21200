#include <iostream>
#include <random>
#include <vector>
#include <string>
using namespace std;

/*Write a program that creates a singly link list of used automobiles containing Cars that
describe the model name (string), price(int) and owner’s name. The program should create a
list containing 12 Cars created by the user. There are only three types of models (BMW,
Cadillac, Toyota) and the prices range from $2500 – $12,500. The program should allow the
user to provide
• Print a printout of all cars contained in the list (model, price, owner)
Provide a histogram(global array) of all cars in the list portioned into
$500 buckets
• Calculate the average price of the cars contained in the list
• Provide the details for all cars more expensive than the average price
• Remove all Cars having a price less than 25% of average price
• Print a printout of all cars contained in the updated list (model, price,
owner)*/

struct Node
{
    Node *next = NULL;
    string m_model;
    string m_owner;
    int m_price;
};

Node *copyNode(Node *node)
{
    Node *newNode = new Node;
    newNode->m_model = node->m_model;
    newNode->m_owner = node->m_owner;
    newNode->m_price = node->m_price;
    newNode->next = NULL;
    return newNode;
}

void print(Node *node)
{
}

Node *insertFirst(Node *head, Node *node) // function that inserts at beginning of linked list
{

    // reassign head
    node->next = head;
    head = node;
    return head;
}

// Car Class Operator Overload Definitions
ostream &operator<<(ostream &out, Node *car)
{
    out << "Car Model: " << car->m_model;
    out << " | Car Owner: " << car->m_owner;
    out << " | Car Price: $" << car->m_price << endl;
    cout << "------------------------------------------" << endl;
    return out;
}

// LinkedList Class
class LinkedList
{
private:
    Node *head;
    int l_size;

public:
    LinkedList() : head(NULL), l_size(0) {} // default constructor
    LinkedList(LinkedList &list);
    // LinkedList(const LinkedList &list);
    LinkedList(Node *node);
    ~LinkedList();
    void setHead(Node *node) { this->head = node; }
    Node *getHead() { return this->head; }
    int getSize() { return this->l_size; }
    // public methods
    void insertFirst(Node *node);
    void removeNode(Node *node);
    void PrintList();
};

LinkedList::LinkedList(Node *node)
{
    node->next = NULL;
    this->head = node;
    l_size = 1;
}
LinkedList::LinkedList(LinkedList &list)
{
    if (this != &list && list.getHead() != NULL) // make sure list is not empty
    {
        // shallow copy but make next == NULL
        this->head = new Node;
        this->head = list.getHead();
        this->head->next = NULL;

        Node *curr_this = this->head;      // start current this at head
        Node *curr_list = list.head->next; // start current list at head

        while (curr_list != NULL)
        {
            curr_this->next = new Node; // make new node and add it to this list for copy
            curr_this = curr_this->next;
            // deep copy values
            curr_this->m_model = curr_list->m_model;
            curr_this->m_owner = curr_list->m_owner;
            curr_this->m_price = curr_list->m_price;
            // copy the next
            curr_list = curr_list->next;
        }
    }
}

void LinkedList::insertFirst(Node *node)
{
    node->next = this->head;
    this->head = node;
    l_size++;
}

void LinkedList::removeNode(Node *node)
{
    Node *curr = this->head;
    Node *prev = this->head;
    while (curr != NULL)
    {
        if (curr == node)
        {
            (curr == this->head) ? (head = curr->next) : prev->next = curr->next; // Reassign accordingly
            delete curr;
            l_size--;
            break;
        }

        prev = curr; // Check next node
        curr = curr->next;
    }
}

void LinkedList::PrintList()
{
    Node *curr = this->head;

    cout << "Linked List Size: " << this->l_size << endl;
    while (curr != NULL)
    {
        cout << curr;
        curr = curr->next;
    }
    cout << "************************************" << endl;
}

LinkedList::~LinkedList()
{

    while (this->head != NULL)
    {
        removeNode(this->head);
    }

    cout << "DONE DELETING LINKED LIST" << endl;
}

// Calculate the average price of the cars contained in the list
int calcAverage(LinkedList &list)
{
    int sum = 0;
    Node *curr = list.getHead();
    while (curr != NULL)
    {
        sum += curr->m_price; // add car price to sum
        curr = curr->next;    // go to next node in list
    }

    return sum / list.getSize(); // return average
}

// Provide the details for all cars more expensive than the average price
void printAboveAverage(LinkedList &list)
{
    int average = calcAverage(list); // get average
    Node *curr = list.getHead();     // get head

    cout << "Linked List Size: " << list.getSize() << endl;
    while (curr != NULL)
    {

        if (curr->m_price > average)
            cout << curr;  // print node above average
        curr = curr->next; // go to next node in list
    }
    cout << "************************************" << endl;
}

int getIndex(int number, int step, int lower, int len)
{
    int index = 0;

    while (index < len)
    {
        if (number < index * step + lower)
        {
            return index;
        }

        index++;
    }

    return -1;
}

int main()
{
    // string Name;
    // /*****************************************/
    // cout << "Student Enter Name" << endl;
    // cin >> Name;
    // cout << "---------  -------------------------------------" << endl;
    // cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    // cout << "Student Name: " << Name << endl;
    // cout << "----------------------------------------------" << endl;
    /*****************************************/
    LinkedList list;
    Node *node = NULL;
    int step = 500;
    int upperLimit = 12500;
    int lowerLimit = 3000;
    int len = 20;
    int inputLen=2;
    cout << "Populate linked list" << endl;
    string model, owner;
    int price, average;

    string names[] = {"Mambo", "Jambo", "Hambo"};
    string cars[] = {"BMW", "Toyoya", "Lexus"};
    for (int i = 0; i < inputLen; i++)
    {
        node = new Node;
        cout << "Enter the model, owner's name and price of the car ($2500 – $12,500) to the nearest whole number" << endl;
        cout << "Use the format \"model\" __ \"name\" __ \"price\"" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> model >> owner >> price;

        if (price < 2500 || price > 12500)
        {
            while (true)
            {
                cout << "Enter a Price within the range $2,500 and $12,500" << endl;
                cin >> price;
                if (price >= 2500 || price <= 12500)
                {
                    break;
                }
            }
        }

        cout << "You entered: " << endl;
        cout << "Model: " << model << " Owner: " << owner << " Price: " << price << endl;
        cout << "----------------------------------------------\n"
             << endl;
        // creating node
        node->m_model = model;
        node->m_owner = owner;
        node->m_price = price;
        // dynamically allocate memory
        list.insertFirst(node);
    }

    cout << endl;

    list.PrintList();
    // Provide a histogram(global array) of all cars in the list portioned into $500 buckets
    cout << "\n**********MAKING HISTOGRAM *******" << endl;
    Node **HashTable = new Node *[len];
    for (int i = 0; i < len; i++)
    {
        HashTable[i] = NULL;
    }

    Node *head = list.getHead();

    while (head != NULL)
    {
        int index = getIndex(head->m_price, step, lowerLimit, 21);
        if (index != -1)
        {
            node = copyNode(head);
            HashTable[index] = insertFirst(HashTable[index], node);
        }

        head = head->next;
    }

    int limit = lowerLimit;
    for (int i = 0; i < len; i++)
    {
        cout << "Cars less than: " << limit << endl;
        node = HashTable[i];
        while (node != NULL)
        {
            cout << "Model: " << node->m_model << " Owner: " << node->m_owner << " Price: " << node->m_price << endl;
            node = node->next;
        }
        cout << "-------------------" << endl;
        limit+=step;
    }
    cout << endl;

    delete[] HashTable;

    // TODO: For this step you could try using (price - lower limit / step) but still need to account for edge cases

    // LinkedList **LinkedListArray = new LinkedList *[20];

    // Calculate the average price of the cars contained in the list
    average = calcAverage(list);
    cout << "The average price is: $" << average << endl;
    cout << endl;
    cout << "The following are above average: " << endl;
    // Provide the details for all cars more expensive than the average price
    printAboveAverage(list);
    // Remove all Cars having a price less than 25% of average price
    cout << "Printing all above 25% of average (" <<average*0.25<<")"<< endl;
    node = list.getHead();
    while (node != NULL)
    {
        Node *next = node->next;
        if (node->m_price > 0.25 * average)
            list.removeNode(node);

        node = next;
    }

    list.PrintList();
    // // Print new list
    // cout << "Updated list (cars over 25% of average)" << endl;
    // list.traverse();
}