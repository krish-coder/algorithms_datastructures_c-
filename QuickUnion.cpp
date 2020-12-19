#include<iostream>
#include<conio.h>
using namespace std;

class QuickUnion
{
	int* nodes;
	int size;
	int root(int node)
	{
		if (node == nodes[node])
		{
			return node;
		}
		return root(nodes[node]);
	}
public:
	QuickUnion(int n)
	{
		nodes = new int[n];
		size = n;
		for (int i=0; i<n; i++)
		{
			nodes[i] = i;
		}
	}
	~QuickUnion()
	{
		delete[]nodes;
	}
	// It also has worst complexity since finding root is O(N)
	bool find_(int n1, int n2)
	{
		return root(n1) == root(n2);
	}
	// O(N) including finding roots
	void union_(int n1, int n2)
	{
		int r1 = root(n1);
		int r2 = root(n2);
		if (r1 == r2)
		{

		}
		else
		{
			nodes[r2] = r1;
		}
	}

	void print()
	{
		for (int i=0; i< size; i++)
		{
			cout << nodes[i] << " ";
		}
		cout << endl;
	}

};
int main(int argc, char* args[])
{
	QuickUnion obj(10);

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