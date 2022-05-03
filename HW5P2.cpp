
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*Write a program that implements a binary tree having nodes that contain the following items:
(i) Fruit name (ii) price per lb.

 The program should allow the user to input any fruit name
(duplicates allowed), price. The root node should be initialized to {“Lemon” , $3.00}. The
program should be able to do the following tasks:
o create a basket of 15 fruits/prices
o list all the fruits created (name/price)
o calculate the average price of the basket
o print out all fruits having the first letter of their name >= ‘L’
*/

struct Node
{
    string name;
    int price;
    Node *left = NULL;
    Node *right = NULL;
};

Node *createNode(string name, int price)
{
    // // declare variables
    // int price;
    // string name;
    // Print messages

    Node *node = new Node; // intialize memory
    // populate data
    node->name = name;
    node->price = price;
    // make left and right pointers point to null
    node->left = NULL;
    node->right = NULL;

    return node;
}

void printNode(Node *node)
{
    cout << "Name: " << node->name << ", Price: $" << node->price << ", left: " << node->left << ", right: " << node->right << endl;
}

Node *insert(Node *root, Node *node)
{
    if (root == NULL)
    {
        cout << "Inserting!" << endl;
        root = node;
    }
    else
    {

        cout << "Root Price is $" << root->price << " address->" << root;
        if (node->price <= root->price)
        {

            cout << ", Going left!" << endl;
            root->left = insert(root->left, node);
        }
        else
        {
            cout << ", Going right!" << endl;
            root->right;
            root->right = insert(root->right, node);
        }
    }

    return root;
}

void insertVoid(Node *root, Node *node)
{

    cout << "Root Price is $" << root->price << " address->" << root;
    if (node->price <= root->price)
    {
        if (root->left == NULL)
        {
            cout<<"\nInserting!"<<endl;
            root->left = node;
        }
        else
        {
            cout << ", Going left!" << endl;
            insertVoid(root->left, node);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            cout<<"\nInserting!"<<endl;
            root->right = node;
        }
        else
        {
            cout << ", Going right!" << endl;
            insertVoid(root->right, node);
        }
    }
}

void calcAverage(Node *root, int &sum, int &count)
{

    if (root != NULL)
    {
        count++;
        sum += root->price;
        calcAverage(root->left, sum, count);
        calcAverage(root->right, sum, count);
    }
}

void Print(Node *root)
{
    if (root != NULL)
    {
        Print(root->left);
        printNode(root);
        Print(root->right);
    }
}

void PrintL(Node *root)
{
    if (root != NULL && (root->name[0] >= 'L'))
    {
        cout << "Name: " << root->name << " Price: $" << root->price << endl;
        PrintL(root->left);
        PrintL(root->right);
    }
}

int main()
{
    int len = 6;
    string list[] = {"apple", "banana", "grapes", "date", "ice cream", "Marble", "Zoinks"};
    int prices[] = {5, 3, 2, 20, 6, 15, 18};
    Node *root = createNode(list[0], prices[0]);
    Node *node = NULL;

    // Node *root = createNode("bacon", 5);

    for (int i = 0; i < len; i++)
    {
        node = createNode(list[i], prices[i]);
        printNode(node);
        // root = insert(root, node);
        insertVoid(root, node);
        cout << "-----------------" << endl;
    }
    cout << "\n***********Printing InOrder*************" << endl;
    Print(root);
    // calculate average
    int sum = 0, count = 0, average = 0;
    calcAverage(root, sum, count);
    average = sum / count;
    cout << "Calculate Average is: $" << average << endl;
    cout << "-------------Printing The Tree-------------" << endl;
    Print(root);
    cout << "***********************" << endl;
    cout << "-------------Printing Items with letter greate than 'L'-------------" << endl;
    PrintL(root);
    cout << "***********************" << endl;

    return 0;
}