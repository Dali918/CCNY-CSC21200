#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Node // Node Structure
{
    string data;
    int id;
    int charSum;
    int hash;
    Node *next;
};

int computeCharSum(string phrase)
{
    int sum = 0;
    for (char i : phrase)
    {
        sum += static_cast<int>(i);
    }

    return sum;
}

int computeHash(string phrase, int key) // function to compute hash
{

    return computeCharSum(phrase) % key;
}
/************************LinkedList***************************/
Node *createNode(string phrase, int id) // function that creates and returns objects of type Node*
{
    Node *node = new Node;
    node->data = phrase;
    node->id = id;
    node->charSum = computeCharSum(phrase);
    node->hash = computeHash(phrase, 13);
    node->next = NULL;
    return node;
}

void PrintNode(Node *node) // function that prints Node data
{
    cout << "Node data: " << node->data << endl;
    cout << "Node id: " << node->id << endl;
    cout << "Character Sum: " << node->charSum << endl;
    cout << "Node Hash: " << node->hash << endl;
    cout << "------------------" << endl;
}

void PrintList(Node *head) // function that prints linked list
{
    Node *temp = head;
    while (temp != NULL)
    {
        PrintNode(temp);
        temp = temp->next;
    }
}

Node *insertFirst(Node *head, string phrase, int id) // function that inserts at beginning of linked list
{
    Node *node = createNode(phrase, id); // make new node
    // reassign head
    node->next = head;
    head = node;
    return head;
}

Node *removeNode(Node *head, int id) // function that removes node
{
    Node *curr = head;
    Node *prev = head;

    while (curr != NULL)
    {
        if (curr->id == id)
        {
            (curr == head) ? head = curr->next : prev->next = curr->next; // remove node based on head
            cout << "Deleting: " << endl;
            PrintNode(curr);
            delete curr;
            return head;
        }
        // Go to next node
        prev = curr;
        curr = curr->next;
    }

    cout << "Node not found - Could not Delete!" << endl;
    cout << "-----------------" << endl;
    return head;
}

void deleteLinkedList(Node *head) // function to delete linked list
{
    while (head != NULL)
    {
        head = removeNode(head, head->id);
    }
}
/******************Code/Phrase Generator*********************/
vector<string> createWords() // function to make vector of phrases
{
    const int len = 26;
    const int phrase_size = 5;

    string list = "";
    vector<string> phrases;
    for (int i = 0; i < len; i++) // add upper case
    {
        list += static_cast<char>(i + 65);
    }
    for (int i = 0; i < len; i++) // add lower case
    {
        list += static_cast<char>(i + 97);
    }

    for (int i = 0; i < list.length() - phrase_size + 1; i++) // create phrases
    {
        string phrase = "";
        for (int j = i; j < i + phrase_size; j++)
        {
            phrase += list.at(j);
        }

        phrases.push_back(phrase); // add phrase to string vector
        // count++;
    }

    return phrases; // return phrases
}

/********************************************/

int main()
{
    const int len = 13;
    vector<string> words = createWords();
    Node **HashTable = new Node *[len]
    { NULL };
    int linkedListCount[len]{0};
    int count = 0;

    /******Test Linked List and phrase Generator******/
    // Node *head = createNode(words.at(0), ++count);
    // for (int i = 1; i < words.size(); i++)
    // {
    //     head = insertFirst(head, words.at(i), ++count);
    // }

    // PrintList(head);
    // deleteLinkedList(head);

    /****************/

    for (string phrase : words)
    {
        // Populate Hash Table
        int index = computeHash(phrase, len);
        // insert with head@index, phrase, increment linked list size
        HashTable[index] = insertFirst(HashTable[index], phrase, ++linkedListCount[index]);
    }
    {
    }

    // Print Hash Table List
    for (int i = 0; i < len; i++)
    {
        cout << "Linked List at Index: " << i << " LL size: " << linkedListCount[i] << endl;
        PrintList(HashTable[i]);
        cout << "**************************************" << endl;
    }

    for (int i = 0; i < len; i++)
    {
        deleteLinkedList(HashTable[i]);
    }
    delete HashTable;
}