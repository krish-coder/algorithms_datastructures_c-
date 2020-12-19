#include<iostream>
#include<conio.h>

using namespace std;

class SORT
{
	int* arr;
	int size;
public:
	SORT(int* arr, int n);
	~SORT();
	void bubbleSort1();
	void bubbleSort2();
	int* sortedArray();
};

SORT::SORT(int* arr, int n)
{
	this->arr = (int*)malloc(sizeof(arr[0])*n);
	for (int i=0; i < n; i++)
	{
		this->arr[i] = arr[i];
	}
	size = n;
}

SORT::~SORT()
{
	free(this->arr);
}

void SORT::bubbleSort1()
{
	for (int j=0; j<size-1; j++)
	{
		for (int i = 0; i < size - 1 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				arr[i] = arr[i] + arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] = arr[i] - arr[i + 1];
			}
		}
	}
}

void SORT::bubbleSort2()
{
	for (int j = size-1; j>1; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				arr[i] = arr[i] + arr[i + 1];
				arr[i + 1] = arr[i] - arr[i + 1];
				arr[i] = arr[i] - arr[i + 1];
			}
		}
	}
}

int* SORT::sortedArray()
{
	for (int i = 0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return arr;
}

class BinSearch
{
	int* arr;
	int size;
public:
	BinSearch(int *arr, int n);
	~BinSearch();
	int search(int key);
};

BinSearch::BinSearch(int* arr, int n)
{
	this->arr = (int*)malloc(sizeof(arr[0])*n);
	for (int i = 0; i < n; i++)
	{
		this->arr[i] = arr[i];
	}
	size = n;
}

BinSearch::~BinSearch()
{
	free(this->arr);
}

int BinSearch::search(int key)
{
	int lo = 0;
	int hi = size - 1;
	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] == key) return mid;
		else if (key > arr[mid]) lo = mid + 1;
		else hi = mid - 1;
	}
	return -1;
}

int main(int argc, char* args[])
{
	int arr[] = {97,8,1,45,32,23,11,67,89,12,90};
	int n = sizeof(arr) / sizeof(arr[0]);
	SORT obj(arr, n);
	obj.sortedArray();
	obj.bubbleSort2();
	int* arr1 = obj.sortedArray();
	BinSearch obj1(arr1, n);
	cout << obj1.search(90) << endl;
	_getch();
	return 0;
}