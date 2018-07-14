#include <iostream>
using namespace std;

class Node
{
public:
	Node * next;
	int val;
	Node() {next = nullptr;}
	Node(int value, Node * nextNode) :val(value), next(nextNode) {}
	void printNode() {cout << "val:" << val << ", next:" << next;}
};


class LinkedList
{
public:
	Node * head;
	LinkedList() { head = nullptr; }
	void print()
	{
		if (head == nullptr)
		{
			cout << "Empty List\n";
			return;
		}
			
		Node *iter = head;
		while (iter != nullptr)
		{
			if (iter->next != nullptr)
				cout << iter->val << " --> ";
			else
				cout << iter->val<<"\n";
			iter = iter->next;
		}
	}

	void addFront(int val) 
	{
		if (head == nullptr)
		{
			head = new Node(val, nullptr);
		}
		else
		{
			head = new Node(val, head);
		}
		//head->printNode();
	}
	void addRear(int val)
	{
		Node * iter = head;
		if (isEmpty())
		{
			head = new Node(val, nullptr);
		}
		else
		{
			while(1)
			{
				if (iter->next == nullptr)
				{
					iter->next = new Node(val, nullptr);
					return;
				}
				else
				{
					iter = iter->next;
				}
					
			}
		}
		return;
	}
	void remove(int key) 
	{	
		Node * iter = head;
		Node * del = nullptr;
		//Handle the case where Linked List is empty'
		if (isEmpty())
		{
			cout << "Empty List" << endl;
			return;
		}
		else if (head->val == key)
		{
			del = head;
			head = head->next;
			delete del;
		}
		else
		{
			while (iter->next != nullptr)
			{
				if (iter->next->val == key)
				{
					del = iter->next;
					iter->next = iter->next->next;
					delete del;
				}
				iter = iter->next;
				if (iter == nullptr)
					return;
			}
		}
		return;
	}

	bool isEmpty()
	{
		return(head == nullptr);
	}
};

int main()
{
	//Node node2;
	//node2.printNode();
	//cout << endl;
	//Node node1(1, nullptr);
	//node1.printNode();
	//cout << endl;

	LinkedList list;
	cout << "Printing list" << endl;
	list.print();
	cout << endl;
	list.addFront(1);
	list.addFront(2);
	list.addFront(3);
	cout << "Printing list" << endl;
	list.print();

	list.remove(2);
	cout << "Printing list after deleting 2" << endl;
	list.print();

	list.remove(1);
	cout << "Printing list after deleting 1" << endl;
	list.print();

	list.remove(3);
	cout << "Printing list after deleting 3" << endl;
	list.print();

	list.addRear(1);
	list.addRear(2);
	list.addRear(3);
	cout << "Printing list after adding to rear" << endl;
	list.print();
	cout << endl;

	return 0;
}