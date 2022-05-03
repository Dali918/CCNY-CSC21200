/**********************************************
program: LinkListC.cpp
author: Y. Solow
date: July 4, 2016
synopsis: to program a singly link list using C
**********************************************/
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
ListNode *createLink()
{

	ListNode *current = new ListNode; // create 1st node
	current->link = NULL;			  // set link pointer to NULL

	cout << "Enter Item Name" << endl;
	;
	cin >> current->Item;
	cout << "Enter count" << endl;
	cin >> current->count;

	TotalCnt++; // increment total count

	return current; // return address of 1st node
}

ListNode *addLink(ListNode *head)
{
	ListNode *current = new ListNode; // create new node

	cout << "Enter Item Name" << endl; // fill it up  â€¦.!!!!
	cin >> current->Item;
	cout << "Enter count" << endl;
	cin >> current->count;

	current->link = head; // add as a first node
	head = current;		  // update head address to bucrrent
#ifdef DEBUG
	cout << "addLink:  head = " << head << endl;
	cout << "addLink:  current->link= " << current->link << endl;
#endif

	TotalCnt++;

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

void deleteLink(ListNode **head, int Link)
{
	ListNode *temp = *head; // copy head address
	ListNode *out = *head;	// address of node to be killed
	ListNode *prev = *head; // pointer to previous node

	int NodeId = 1;

	cout << " ----------- " << endl;

	while (temp != NULL)
	{
		prev = temp;
#ifdef DEBUG
		cout << "prev = " << prev << endl;
#endif
		if (NodeId == Link)
		{
			out = temp;
			if(temp==*head){
				*head = temp->link;
			}
			else{
				prev->link = temp->link;

			}

			delete out;
			break;
		}

		if (NodeId == Link)
			// 		{
			// 			cout << "NodeId = " << NodeId << endl;
			// 			out = temp->link;  // save present link
			// 			temp = temp->link; // move to next node
			// #ifdef DEBUG
			// 			cout << "temp->link = " << temp->link << endl;
			// #endif
			// 			prev->link = temp->link; // assign previous link to next link
			// 			delete out;				 // remove link from heap
			// 			break;
			// 		} // end of if loop
			NodeId++;

		temp = temp->link; // move to next node
	}					   // end of while loop

	TotalCnt--;

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
			prev = temp;	   // save present address
			temp = temp->link; // advance to next node
		}
		prev->link = current; // assign prev node with current address
		current->link = temp; // assign temp address to current  link addr
	}

	TotalCnt++;

	return;
}

int main()
{
	ListNode *head; // LinkList pointer - will point to entry to list
	bool flag;
	string Object;
	int LinkCnt = -1;

	head = createLink(); // create first node
	cout << "head(post create) = " << head << endl;

	// print List
	PrintList(head);

	// add new nodes
	flag = 1;
	while (flag)
	{
		head = addLink(head); // add new nodes from front
		cout << "add another node; yes(1) no(0)" << endl;
		cin >> flag;
	}
	cout << "TotalCnt = " << TotalCnt;

	// print List
	cout << "head = " << head << endl;
	PrintList(head);

	// find item
	cout << "Enter Object Item to find" << endl;
	cin >> Object;
	cout << "Object found at: " << findList(head, Object) << endl;
	;

	// delete link
	cout << "Enter Link to be removed: ";
	cin >> LinkCnt;
	deleteLink(&head, LinkCnt);

	// print List
	PrintList(head);

	// insert link
	cout << "Enter Link to be inserted: ";
	cin >> LinkCnt;
	insertLink(head, LinkCnt);
	// print List
	PrintList(head);

	cout << "TotalCnt = " << TotalCnt << endl;

	return 0;
}
/************* Results ************
./a.out
Enter Item Name
Apple
Enter count
1
head(post create) = 0x7fd376c05870
 -----------
temp->Item = Apple
temp->count = 1
Enter Item Name
Banana
Enter count
2
add another node; yes(1) no(0)
1
Enter Item Name
Cherry
Enter count
3
add another node; yes(1) no(0)
1
Enter Item Name
Date
Enter count
4
add another node; yes(1) no(0)
1
Enter Item Name
Endive
Enter count
5
add another node; yes(1) no(0)
1
Enter Item Name
Fig
Enter count
6
add another node; yes(1) no(0)
1
Enter Item Name
Guava
Enter count
7
add another node; yes(1) no(0)
1
Enter Item Name
Herbs
Enter count
8
add another node; yes(1) no(0)
1
Enter Item Name
Iceberg
Enter count
9
add another node; yes(1) no(0)
1
Enter Item Name
Jam
Enter count
10
add another node; yes(1) no(0)
0
head = 0x7fd376e04110
 -----------
temp->Item = Jam
temp->count = 10
temp->Item = Iceberg
temp->count = 9
temp->Item = Herbs
temp->count = 8
temp->Item = Guava
temp->count = 7
temp->Item = Fig
temp->count = 6
temp->Item = Endive
temp->count = 5
temp->Item = Date
temp->count = 4
temp->Item = Cherry
temp->count = 3
temp->Item = Banana
temp->count = 2
temp->Item = Apple
temp->count = 1
Enter Object Item to find
Fig
Object found at:  -----------
Object found at Node #4
temp->Item = Fig
temp->count = 6
10
Enter Link to be removed: 6
 -----------
NodeId = 6
 -----------
temp->Item = Jam
temp->count = 10
temp->Item = Iceberg
temp->count = 9
temp->Item = Herbs
temp->count = 8
temp->Item = Guava
temp->count = 7
temp->Item = Fig
temp->count = 6
temp->Item = Endive
temp->count = 5
temp->Item = Cherry
temp->count = 3
temp->Item = Banana
temp->count = 2
temp->Item = Apple
temp->count = 1
Enter Link to be inserted: 4
+ +-+-+-+-+
counter = 9
Enter Item
Mellon
Enger count
4
 -----------
temp->Item = Jam
temp->count = 10
temp->Item = Iceberg
temp->count = 9
temp->Item = Herbs
temp->count = 8
temp->Item = Guava
temp->count = 7
temp->Item = Mellon
temp->count = 4
temp->Item = Fig
temp->count = 6
temp->Item = Endive
temp->count = 5
temp->Item = Cherry
temp->count = 3
temp->Item = Banana
temp->count = 2
temp->Item = Apple
temp->count = 1


*****************/