#include <iostream>
#include <limits>
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
    out << "Car Owner: " << car->m_owner;
    out << " | Car Model: " << car->m_model;
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
    while (curr != NULL)
    {
        if (curr->m_price > average)
            cout << curr;  // print node above average
        curr = curr->next; // go to next node in list
    }
    cout << "************************************" << endl;
}

// Get index function for creating car buckets
int getIndex(int number, int step, int lower, int bucketLen)
{
    // start at index =0;
    int index = 0;

    while (index < bucketLen) // stop when the index is greateer than the size of array
    {
        if (number <= index * step + lower)
        {
            return index; // return index if the price is less than the limit (in step = $500 increments)
        }

        index++;
    }

    return -1; // return negative 1 if an appropraite index is not found
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
    LinkedList list;
    Node *node = NULL;
    const int step = 500;
    const int upperLimit = 12500;
    const int lowerLimit = 2500;
    const int bucketLen = 20;
    const int inputLen = 3;
    string model, owner;
    int price, average;

    for (int i = 0; i < inputLen; i++)
    {

        cout << "Enter: Owner, Car Model, and Car Price($2500 to $12,500)" << endl;
        cout << "Use the format: \"Owner\" __ \"Model\" __ \"Price\"" << endl;
        cin >> owner >> model >> price;

        do
        {

            try
            {
                if (price < lowerLimit || price > upperLimit || cin.fail())
                {
                    throw -1;
                }

                break;
            }
            catch (int x)
            {
                cout << "Enter a Price within the range $2,500 and $12,500" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cin >> price;
            }

        } while (true);

        // while (price < 2500 || price > 12500) // Check for Appropriate Price Range
        // {
        // }

        cout << "You entered: " << endl;
        cout << "Owner: " << owner << " Model: " << model << " Price: " << price << endl;
        cout << "----------------------------------------------\n"
             << endl;

        node = new Node; // create node
        node->m_model = model;
        node->m_owner = owner;
        node->m_price = price;
        list.insertFirst(node); // add to list
    }

    cout << "\n*********************PRINTING LINKED LIST********************\n";

    list.PrintList();
    // Provide a histogram(global array) of all cars in the list portioned into $500 buckets
    cout << "\n**********MAKING HISTOGRAM *******" << endl;
    // Make Empty Hash Table
    Node **HashTable = new Node *[bucketLen];
    for (int i = 0; i < bucketLen; i++)
    {
        HashTable[i] = NULL;
    }

    Node *head = list.getHead(); // get head
    while (head != NULL)
    {
        int index = getIndex(head->m_price, step, lowerLimit + step, 21); // get index
        if (index != -1)                                                  // check if index invalid
        {
            node = copyNode(head);                                  // make node copy
            HashTable[index] = insertFirst(HashTable[index], node); // insert copy in hash table
        }

        head = head->next; // go to next node
    }

    // Print Buckets
    int limit = lowerLimit + step; // first range upper bound is $3000
    for (int i = 0; i < bucketLen; i++)
    {
        node = HashTable[i];
        if (node != NULL) // only print bucket if not empty
        {
            cout << "Cars in Range: $" << limit - step + 1 << " to $" << limit << endl;
            while (node != NULL)
            {
                cout << node;
                node = node->next;
            }
        }
        limit += step;
    }
    cout << endl;

    delete[] HashTable;

    // Calculate the average price of the cars contained in the list
    average = calcAverage(list);
    cout << "AVERAGE PRICE: $" << average << endl;
    cout << endl;
    cout << "***PRINTING ABOVE AVERAGE:*****" << endl;
    // Provide the details for all cars more expensive than the average price
    printAboveAverage(list);
    // Remove all Cars having a price less than 25% of average price
    int threshold = average * 0.25;
    cout << "****UPDATED LIST - REMOVED CARS BELOW 25% of average ($" << threshold << ")" << endl;
    node = list.getHead();
    while (node != NULL)
    {
        Node *next = node->next;
        if (node->m_price < threshold)
            list.removeNode(node);

        node = next;
    }

    list.PrintList();
}