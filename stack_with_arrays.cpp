#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

// Stack implementation
// push, pop, isEmpty, display
// static memory based
class FixedStack
{
	string arr[50];
	int size;
public:
	FixedStack()
	{
		for (int i=0; i<50; i++)
		{
			arr[i].erase();
		}
		size = 0;
	}
	~FixedStack()
	{

	}
	void push(string s)
	{
		if (size < 50)
		{
			arr[size] = s;
			size++;
		}
		else
		{
			cout << "cant push !! stack overflow !!" << endl;
		}
	}

	string pop()
	{
		if (size > 0)
		{
			string s = arr[size];
			arr[size].erase();
			size--;
			return s;
		}
		else
		{
			string s;
			cout << "Nothing to pop" << endl;
			return s.erase();
		}
		
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void display()
	{
		cout << "size of stack: " << size << endl << "--------------------" << endl;
		for (int i=0; i<size; i++)
		{
			cout << arr[i] << endl;
		}
	}
};

class VariableStack
{
	string* arr;
	int size;
public:
	VariableStack()
	{

	}
	~VariableStack()
	{

	}

};

int main()
{
	FixedStack* obj = new FixedStack;
	string s;
	cout << "Enter the strings: " << endl;
	getline(cin, s);
	while (s[0] != 0)
	{
		if (s=="-")
		{
			cout << "popped: " << obj->pop() << endl;
		}
		else
		{
			obj->push(s);
			cout << "pushed: " << s << endl;
		}
		getline(cin, s);
	}
	return 0;
}