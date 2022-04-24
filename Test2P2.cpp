#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Node // Node Structure
{
    string data;
    int id;
    int hash;
    Node *next;
};
/************************LinkedList***************************/
int computeHash(string phrase);
Node *createNode(string phrase, int id) // function that creates and returns objects of type Node*
{
    Node *node = new Node;
    node->data = phrase;
    node->id = id;
    node->hash = computeHash(phrase);
    node->next = NULL;
    return node;
}

void PrintNode(Node *node) // function that prints Node data
{
    cout << "Node data: " << node->data << endl;
    cout << "Node id: " << node->id << endl;
    cout << "Node Hash (Index): " << node->hash << endl;
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
            // cout << "Deleting: " << endl;
            // PrintNode(curr);
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

/********Hash Table********/
int computeHash(string phrase) // function to compute hash
{
    const int key = 13;
    int sum = 0;
    for (char i : phrase)
    {
        sum += static_cast<int>(i);
    }

    return sum % key;
}
void find(string phrase)
{
    // int index = computeHash(phrase);
    // Node* head;
    // try{
    //     if(index<)

    // }catch(string error){
    //     cout<<"WORD CANNOT BE FOUND"<<endl;
    //     return

    // }
}
/******************Code/Phrase Generator*********************/
vector<string> createWords() // function to make vector of phrases
{
    //Makes Five letter word paritions of "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    //48 words : ABCDE BCDEF CDEFG DEFGH EFGHI FGHIJ ........ VWXYZ WXYZa XYZab YZabc Zabcd abcde  ... vwxyz

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
     string Name;
    /*****************************************/
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /*****************************************/


    const int len = 13;
    vector<string> words = createWords();   //vector with phrases
    Node **HashTable = new Node *[len]      //Hash Tabel with linked list pointers set to NULL
    { NULL };
    int linkedListCount[len]{0};            //Linked List count array 
    int count = 0;


    for (string phrase : words)
    {
        // Populate Hash Table
        int index = computeHash(phrase);
        // insert with head@index, phrase, increment linked list size
        HashTable[index] = insertFirst(HashTable[index], phrase, ++linkedListCount[index]);
    }
   

    // Print Hash Table List
    for (int i = 0; i < len; i++)
    {
        cout << "Linked List at Index: " << i << " | Linked List Length: " << linkedListCount[i] << endl;
        PrintList(HashTable[i]);
        cout << "**************************************" << endl;
    }

    // Test to find phrases
    string test_bench[6]{"BCDEF", "EFGHI", "Zabcd", "abcde", "vwxyz", "AbCdE"};     //test bench
    for (string phrase : test_bench)
    {
        int index = computeHash(phrase);        //calculate hash
        Node *node = HashTable[index];      //Get linked list head at index
        bool found = false;                 //found flag

        cout << "Test Phrase: " << phrase << endl;
        while (node != NULL) // traverse linked list for word
        {
            if (node->data == phrase) // print node details if phrase was found
            {
                cout << "Found: " << phrase;
                cout << " | Hash Index: " << index;
                cout << " | Node ID: " << node->id << endl;
                found = true;
                break;
            }

            node = node->next;
        }

        try // Check if phrase was found
        {
            if (found == false)
            {
                string error = "WORD NOT FOUND";
                throw error; // throw exception if phrase was not found
            }
        }
        catch (string error)
        {
            cout << error << endl; // print error message
        }

        cout << "----------------------" << endl;
    }

    // deallocate linked lists from memory
    for (int i = 0; i < len; i++)
    {
        deleteLinkedList(HashTable[i]);
    }
    delete HashTable;       //deallocate hash table from memory
}