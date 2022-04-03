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

class Car
{
private:
    string m_model, m_owner;
    int m_price;

public:
    Car() : m_model("No Brand Name"), m_owner("No Owner"), m_price(0) {}
    Car(string model, string name, int price) : m_model(model), m_owner(name), m_price(price) {}
    ~Car() { cout << "Destructing Car"; }
    // Getters
    string getModel() const { return m_model; }
    string getOwner() const { return m_owner; }
    int getPrice() const { return m_price; }
    // Setters
    void setModel(string model) { m_model = model; }
    void setOwner(string owner) { m_owner = owner; }
    void setPrice(int price) { m_price = price; }
    // Operator Overloading
    friend ostream &operator<<(ostream &out, const Car &car);
    Car &operator=(const Car &car);
};
// Car Class Operator Overload Definitions
ostream &operator<<(ostream &out, const Car &car)
{
    out << "Car Model: " << car.m_model << endl;
    out << "Car Owner: " << car.m_owner << endl;
    out << "Car Price: $" << car.m_price << endl;
    return out;
}
Car &Car::operator=(const Car &car)
{
    if (this != &car)
    {
        this->m_model = car.m_model;
        this->m_owner = car.m_owner;
        this->m_price = car.m_price;
    }
    return *this;
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
    Node(int id = 0) : next_ptr(nullptr), nodeID(id){};
    Node(const Car &car);
    Node(const Node &node);
    ~Node();
    // getters
    Node *getNext() const { return next_ptr; }
    int getNodeID() const { return nodeID; }
    // setters
    void setNext(Node *next) { this->next_ptr = next; }
    void setNodeID(int id) { this->nodeID = id; }
    // overloaded operators
    friend ostream &operator<<(ostream &out, const Node &node);
    Node &operator=(const Node &node);
    // special functions
    inline void printCar() { cout << this->car << endl; }
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
    delete this->next_ptr;
    this->next_ptr = nullptr;
    cout << "Destructing Node" << endl;
}
// Node class Operator Overload Definitions
Node &Node::operator=(const Node &node)
{
    if (this != &node)
    {
        delete this->next_ptr;
        this->nodeID = node.nodeID;
        this->car = node.car;
    }
    return *this;
}

ostream &operator<<(ostream &out, const Node &node)
{
    out<<"Node - "<<node.nodeID<<endl;
    out << node.car<<endl;
    return out;
}

// LinkedList Class
class LinkedList
{
private:
    Node* head;

public:
    LinkedList():head(NULL) {}
    LinkedList(const LinkedList& list){*(this->head) = *(list.head);}
    LinkedList(const Node &node) { this->head = node; }
    ~LinkedList() { cout << "Destructing Linked List" << endl; }
    void setHead(const Node &node) { this->head = node; }
    Node &getHead() { return this->head; }
};

void TraverseLinkedList(LinkedList& list){
    Node current = list.getHead();

    while(&current!=NULL){
        cout<<current<<endl;
        current = *current.getNext();
    }
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
    Node node;
    Car car;
    int len = 2;
    cout<<"Populate linked list"<<endl;
    string model, owner;
    int price;
    for(int i=0; i<len;i++){
        cout<<"Enter the model, owner's name and price of the car ($2500 – $12,500) to the nearest whole number"<<endl;
        cout<<"Use the format \"model\" __ \"name\" __ \"price\""<<endl;
        cin>>model>>owner>>price;
        cout<<"You entered: "<<end;
        cout<<"Model: "<<model<<" Owner: "<<owner<<" Price: "<<price<<endl;
        //creating node
        if(&list.head == NULL){

        }



    }



    cout << "Hello" << endl;
}