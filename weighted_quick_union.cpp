#include <iostream>
#include<conio.h>
using namespace std;

class WeightedQuickUnion
{
	int* nodes;
	int size;
	int* node_s;
	int root(int node)
	{
		int i = node;
		while (i != nodes[i])
		{
			// not as good as total flattening
			// But pointing to grand parent is as good
			nodes[i] = nodes[nodes[i]];
			i = nodes[i];
		}
		return i;
	}
public:
	WeightedQuickUnion(int n)
	{
		nodes = new int[n];
		node_s = new int[n];
		size = n;
		for (int i=0; i<n; i++)
		{
			nodes[i] = i;
			node_s[i] = 1;
		}
	}
	~WeightedQuickUnion()
	{
		delete[]nodes;
		delete[]node_s;
	}
	bool find_(int n1, int n2)
	{
		if (n1 >= size || n2 >= size || n1 < 0 || n2 < 0)
		{
			cout << "invalid node" << endl;
			return false;
		}
		return root(n1) == root(n2);
	}
	void union_(int n1, int n2)
	{
		if (n1 >= size || n2 >= size || n1 < 0 || n2 < 0)
		{
			cout << "invalid node" << endl;
		}
		else if (n1 == n2)
		{

		}
		else
		{
			int r1 = root(n1);
			int r2 = root(n2);
			if (node_s[r1] >= node_s[r2])
			{
				nodes[r2] = r1;
				node_s[r1] += node_s[r2];
			}
			else
			{
				nodes[r1] = r2;
				node_s[r2] += node_s[r1];
			}
		}
	}
	void print()
	{
		for (int i = 0; i<size; i++)
		{
			cout << nodes[i] << " ";
		}
		cout << endl;
	}
};

int main(int argc, char* args[])
{
	WeightedQuickUnion obj(10);
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