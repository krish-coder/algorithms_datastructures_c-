#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

// Singly linked list structure
struct Node
{
	string data;
	Node* next;
};

// double linked list structure
struct Node_1
{
	string data;
	Node_1* next;
	Node_1* prev;
};

class Interface
{
	Node* head;
	Node* tail;
	int size;
public:
	Interface()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	~Interface()
	{

	}
	// Insert node functions
	// insert in the beginning
	void front(string s)
	{
		Node* tmp = new(nothrow) Node;
		if (!tmp)
		{
			cout << "mem alloc failed on heap" << endl;
			exit(0);
		}
		tmp->data = s;
		if (head == NULL)
		{
			tmp->next = NULL;
			head = tmp;
			tail = tmp;
		}
		else
		{
			tmp->next = head;
			head = tmp;
		}
		size++;
	}
	// insert node end
	void end(string s)
	{
		Node* tmp = new(nothrow) Node;
		if (!tmp)
		{
			cout << "mem alloc failed on heap" << endl;
			exit(0);
		}
		tmp->data = s;
		tmp->next = NULL;
		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		
		size++;
	}
	// insert node after node
	void insert_after(Node* node_before, string s)
	{
		if (node_before == NULL)
		{
			cout << "NULL node in insert after input" << endl;
			exit(0);
		}
		Node* tmp = new(nothrow) Node;
		if (!tmp)
		{
			cout << "mem alloc failed on heap" << endl;
			exit(0);
		}
		tmp->data = s;
		tmp->next = node_before->next;
		node_before->next = tmp;
		if (node_before == tail)
		{
			tail = tmp;
		}
		size++;
	}
	
	// Traverse through the linked list
	void traverse()
	{
		Node *it = head;
		while (it != NULL)
		{
			cout << it->data << endl;
			it = it->next;
		}
	}

	// concatenate linked lists
	void concatenate(Node* n1, Node* n2)
	{
		if (n1 == NULL || n2 == NULL)
		{
			cout << "NULL input in concatenate" << endl;
			exit(0);
		}
		Node* tmp = n1;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = n2;
	}

	// delete node after
	void delete_after(Node* node_before)
	{
		if (node_before == NULL)
		{
			cout << "NULL input in delete" << endl;
			exit(0);
		}
		Node* tmp = node_before->next;
		node_before->next = tmp->next;
		delete tmp;
	}

	// clear all
	void clear()
	{
		int i = size;
		Node* tmp = head;
		while (tmp != NULL)
		{
			Node* tmp1 = tmp->next;
			delete tmp;
			tmp = tmp1;
		}
	}

};


int main()
{
	Interface* o1 = new Interface;

	delete o1;
	return 0;
}