#include <iostream>
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

struct Car
{
    string m_model, m_owner;
    int m_price;
};
// Car Class Operator Overload Definitions
ostream &operator<<(ostream &out, const Car &car)
{
    out << "Car Model: " << car.m_model << endl;
    out << "Car Owner: " << car.m_owner << endl;
    out << "Car Price: $" << car.m_price << endl;
    return out;
}

// Node wrapper class
class Node
{
private:
    int nodeID;
    Car car;
    Node *next_ptr;

public:
    // constructors
    Node(int id = 0) : next_ptr(nullptr), nodeID(id), car{"none", "none", 0} {} // default constructor
    Node(int id, string model = "none", string owner = "none", int price = 0) : nodeID(id), car{model, owner, price} {}
    Node(const Car &car);   // constructor with car argument
    Node(const Node &node); // constructor with node argument
    ~Node();                // destructor
    // getters
    Node *getNext() const { return next_ptr; }
    int getNodeID() const { return nodeID; }
    Car getCar() const { return car; }
    // setters
    void setNext(Node *next) { this->next_ptr = next; }
    void setNodeID(int id) { this->nodeID = id; }
    void setCar(const Car &car) { this->car = car; }
    // overloaded operators
    friend ostream &operator<<(ostream &out, const Node &node);
    Node &operator=(const Node &node);
    // print member car
    inline void printCar() { cout << this->car; }
    friend class LinkedList;
};

Node::Node(const Node &node)
{
    Node();
    this->car = node.car;
}

Node::Node(const Car &car)
{
    Node();
    this->car = car;
}

Node::~Node()
{
    cout << "Node " << nodeID << " ";
}
// Node class Operator Overload Definitions
Node &Node::operator=(const Node &node)
{
    if (this != &node)
    {
        delete this->next_ptr; // d
        this->next_ptr = nullptr;
        this->nodeID = node.nodeID;
        this->car = node.car;
    }
    return *this;
}

ostream &operator<<(ostream &out, const Node &node)
{
    out << "Node - " << node.nodeID << endl;
    out << node.car << endl;
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
    // LinkedList(const LinkedList &list);
    LinkedList(Node &node);
    ~LinkedList();
    void setHead(Node &node) { this->head = &node; }
    Node *getHead() { return this->head; }
    // public methods
    void insertFirst(Node &node);
    void traverse();
};

LinkedList::LinkedList(Node &node)
{
    LinkedList();
    l_size++;
    node.nodeID = l_size;
    this->head = &node;
}

void LinkedList::insertFirst(Node &node)
{
    node.setNodeID(++l_size);
    node.setNext(this->head);
    this->head = &node;
}
// LinkedList::LinkedList(const LinkedList &list)
// {
//     LinkedList(); // make default linked list with head set to null,
//     if (list.head != NULL)
//     {
//         this->head->car = list.head->car;
//         Node *current = list.head->next_ptr;
//         Node node;
//         while (current != NULL)
//         {
//             node = *current;
//         }
//     }
// }

void LinkedList::traverse()
{
    Node *current = this->head;
    while (current != NULL)
    {
        cout << *current << endl;
        current = current->next_ptr;
    }
}

LinkedList::~LinkedList()
{
    Node *current = this->head;
    Node *next = current->next_ptr;
    while (current != NULL)
    {
        delete current;
        current = next;
        next = (next != NULL) ? next->next_ptr : NULL;
        cout << "Deleting node" << endl;
    }

    cout << "DONE DELETING LINKED LIST" << endl;
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
    Car car;
    int len = 2;
    cout << "Populate linked list" << endl;
    string model, owner;
    int price;
    for (int i = 0; i < len; i++)
    {
        cout << "Enter the model, owner's name and price of the car ($2500 – $12,500) to the nearest whole number" << endl;
        cout << "Use the format \"model\" __ \"name\" __ \"price\"" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> model >> owner >> price;
        cout << "You entered: " << endl;
        cout << "Model: " << model << " Owner: " << owner << " Price: " << price << endl;
        cout << "----------------------------------------------\n" << endl;
        // creating node
        car.m_model = model;
        car.m_owner = owner;
        car.m_price = price;
        // dynamically allocate memory
        Node *node = new Node(0, model, owner, price);
        list.insertFirst(*node);
    }

    cout << endl;

    list.traverse();
}