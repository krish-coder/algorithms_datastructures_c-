#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class QuickFind
{
	int* nodes;
	int* con_cmp;
	int size;
public:
	QuickFind(int N)
	{
		this->size = N;
		this->nodes = (int*)malloc(sizeof(int)*N);
		this->con_cmp = (int*)malloc(sizeof(int)*N);
		for (int i = 0; i < N; i++)
		{
			this->nodes[i] = i;
			this->con_cmp[i] = i;
		}

	}

	bool is_connected(int i, int j)
	{
		if (this->con_cmp[i] == this->con_cmp[j])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void connect(int i, int j)
	{
		if (this->con_cmp[i] == this->con_cmp[j])
		{
			cout << "Already Conected !\n";
		}
		else
		{
			for (int k = 0; k < this->size; k++)
			{
				if (this->con_cmp[k] == this->con_cmp[i])
				{
					this->con_cmp[k] = this->con_cmp[j];
				}
			}
		}

	}

};

class QuickUnion
{
	int* nodes;
	int* con_cmp;
	int size;
public:
	QuickUnion(int N)
	{
		this->size = N;
		this->nodes = (int*)malloc(sizeof(int)*N);
		this->con_cmp = (int*)malloc(sizeof(int)*N);
		for (int i = 0; i < N; i++)
		{
			this->nodes[i] = i;
			this->con_cmp[i] = i;
		}
	}
	int find_root(int node)
	{
		if (this->con_cmp[node] == node)
		{
			return node;
		}
		else
		{
			find_root(this->con_cmp[node]);
		}
	}
	bool is_connected(int i, int j)
	{
		if (this->find_root(i) == this->find_root(j))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void connect(int i, int j)
	{
		if (this->find_root(i) == this->find_root(j))
		{
			cout << "Already Conected !\n";
		}
		else
		{
			this->con_cmp[this->find_root(i)] = this->find_root(j);
		}

	}
};

class WtQuickUnion
{
	int* con_cmp;
	int size;
	int* sz;
public:
	WtQuickUnion(int N)
	{
		this->size = N;
		this->con_cmp = (int*)malloc(sizeof(int)*N);
		this->sz = (int*)malloc(sizeof(int)*N);
		for (int i = 0; i < N; i++)
		{
			this->con_cmp[i] = i;
			this->sz[i] = 1;
		}
	}
	int find_root(int i)
	{
		int j = i;
		while (j != this->con_cmp[j])
		{
			j = this->con_cmp[j];
		}
		return j;
	}
	// Connected?
	bool find(int i, int j)
	{
		return find_root(i) == find_root(j);
	}
	// connect
	void union_(int i, int j)
	{
		int root_i = find_root(i);
		int root_j = find_root(j);
		if ( root_i == root_j)
		{
			cout << "Already Connected !\n";
		}
		else
		{
			if (sz[root_i] > sz[root_j])
			{
				this->con_cmp[root_j] = root_i;
				this->sz[root_i] += this->sz[root_j];
			}
			else
			{
				this->con_cmp[root_i] = root_j;
				this->sz[root_j] += this->sz[root_i];
			}
		}
	}
};
/*QuickFind client*/
/*
int main()
{
	int input;
	cout << "Enter number of nodes: ";
	cin >> input;
	QuickFind obj = QuickFind(input);
	if (obj.is_connected(1, 2))
	{
		cout << "Connected\n";
	}
	else
	{
		cout << "not connected\n";
	}
	obj.connect(1, 2);

	if (obj.is_connected(1, 2))
	{
		cout << "Connected\n";
	}
	else
	{
		cout << "not connected\n";
	}
	_getch();
	return 0;
}
*/
/*QuickUnion*/
/*
int main()
{
	int input;
	cout << "Enter number of nodes: ";
	cin >> input;
	QuickUnion obj = QuickUnion(input);
	if (obj.is_connected(1, 2))
	{
		cout << "Connected\n";
	}
	else
	{
		cout << "not connected\n";
	}
	obj.connect(1, 2);

	if (obj.is_connected(1, 2))
	{
		cout << "Connected\n";
	}
	else
	{
		cout << "not connected\n";
	}
	_getch();
	return 0;
}*/
/*WtQuickUnion*/
/*
int main()
{
	int input;
	cout << "Enter number of nodes: ";
	cin >> input;
	WtQuickUnion obj = WtQuickUnion(input);
	if (obj.find(1, 2))
	{
		cout << "Connected\n";
	}
	else
	{
		cout << "not connected\n";
	}
	obj.union_(1, 2);

	if (obj.find(1, 2))
	{
		cout << "Connected\n";
	}
	else
	{
		cout << "not connected\n";
	}
	_getch();
	return 0;
}*/

int main()
{
	_getch();
	return 0;
}