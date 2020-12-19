#include<iostream>
#include<conio.h>

using namespace std;

// The class is called QuickFind because the complexity for 
// find_ is O(1) which is quick
// union_ is O(N) which is bad
class QuickFind
{
	int* nodes;
	int size;
public:
	QuickFind(int n)
	{
		nodes = new(nothrow) int[n];
		if (!nodes)
		{
			cout << "mem alloc failed" << endl;
			exit(0);
		}
		for (int i=0; i<n; i++)
		{
			nodes[i] = i;
		}
		size = n;
	}
	~QuickFind()
	{
		delete []nodes;
	}
	// complexity for N inputs and N union_ is O(N2)
	// O(N2) does not scale like O(logN)
	// if number of inputs double, then the complexity becomes 4 times 
	// not good
	void union_(int n1, int n2)
	{
		if (n1 > size-1 || n2 > size-1)
		{
			cout << "node not found !!" << endl;
		}
		if (n1 == n2)
		{
			cout << "connect " << n1 << " with " << n2 << endl;
		}
		else
		{
			// this part executes for each element of array with O(N)
			// since every element needs to be checked
			cout << "connect " << n1 << " with " << n2 << endl;
			int n1_id = nodes[n1];
			for (int i = 0; i < size; i++)
			{
				if (nodes[i] == n1_id)
				{
					nodes[i] = nodes[n2];
				}
			}
			cout << endl;
		}
	}

	bool find_(int n1, int n2)
	{
		return nodes[n1] == nodes[n2];
	}

	void print()
	{
		for (int i=0; i<size; i++)
		{
			cout << nodes[i] << " ";
		}
		cout << endl;
	}
};

int main(int argc, char *args[])
{
	QuickFind obj(10);

	obj.union_(1, 2);
	obj.union_(4, 5);
	obj.union_(5, 2);
	cout << obj.find_(1, 5) << endl;
	obj.print();
	obj.union_(9, 8);
	obj.union_(4, 8);
	obj.print();
	cout << obj.find_(5, 8) << endl;
	_getch();
	return 0;
}