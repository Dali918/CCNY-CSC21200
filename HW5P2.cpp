
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

void insert(Node *root, Node *node)
{
    if (root == NULL)
    {
        cout << "Inserting!" << endl;
        root = node;
    }
    else
    {
        
        cout << root << endl;
        (node->price <= node->price) ? insert(root->left, node) : insert(root->right, node);
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
        cout << "Name: " << root->name << " Price: $" << root->price << endl;
        Print(root->left);
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
    int len = 5;

    string list[] = {"apple", "banana", "grapes", "date", "ice cream"};
    int prices[] = {3, 2, 20, 6, 15};

    Node *root = createNode("bacon", 5);

    for (int i = 0; i < len; i++)
    {

        insert(root, createNode(list[i], prices[i]));
    }

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