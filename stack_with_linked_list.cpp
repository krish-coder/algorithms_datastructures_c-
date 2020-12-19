#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

// Stack Implementation
// push, pop, isEmpty, display
// Complexity is constant since there are no loops for
// stack implementation using linked list
class StackOfStrings
{
	struct LinkedListNode
	{
		string data;
		LinkedListNode* next;
	};
	LinkedListNode* head;
	int size;
public:
	StackOfStrings()
	{
		head = NULL;
		size = 0;
	}
	~StackOfStrings()
	{
		cout << "Destructor called" << endl;
		LinkedListNode* tmp = this->head;
		while (tmp != NULL)
		{
			LinkedListNode* next = tmp->next;
			delete tmp;
			size--;
			tmp = next;
		}
	}
	string pop()
	{
		if (head == NULL)
		{
			string s;
			return s.erase();
		}
		else
		{
			string s = head->data;
			LinkedListNode* old_head = head;
			head = head->next;
			delete old_head;
			size--;
			return s;
		}
	}

	void push(string s)
	{
		LinkedListNode* tmp = new(nothrow) LinkedListNode;
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
			size++;
		}
		else
		{
			LinkedListNode* old_head = head;
			tmp->next = old_head;
			head = tmp;
			size++;
		}
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void display()
	{
		LinkedListNode* tmp = head;
		cout << "size of stack : " << size << endl << "-------------------" << endl;
		while (tmp != NULL)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
};

int main()
{
	StackOfStrings* obj = new StackOfStrings;
	string s;
	cout << "Enter the string : " << endl;
	getline(cin, s);
	while (s[0] != 0)
	{
		if(s=="-")
		{
			cout << "popped item: " << obj->pop() << endl;
		}
		else
		{
			obj->push(s);
			cout << "pushed: " << s << endl;
		}
		getline(cin, s);
		obj->display();
	}
	
	delete obj;
	_getch();
	return 0;
}