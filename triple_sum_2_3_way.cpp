#include<iostream>
#include<conio.h>
using namespace std;

class ThreeSum
{
	int *arr;
	int size;
public:
	ThreeSum(int* in, int n)
	{
		arr = new int[n];
		//memcpy(arr, in, n);
		for (int i=0; i<n; i++)
		{
			cout << in[i] << " " ;
			arr[i] = in[i];
		}
		cout << endl;
		size = n;
	}
	~ThreeSum()
	{
		delete[]arr;
	}
	int brute_force_count()
	{
		int count = 0;
		for (int i=0; i < size; i++)
		{
			for (int j=i+1; j < size; j++)
			{
				for (int k=j+1; k < size; k++)
				{
					cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
					if (arr[i] + arr[j] + arr[k] == 0)
					{
						count++;
					}
				}
			}
		}
		return count;
	}

};

class ThreeSum_2Way
{
	int *arr;
	int size;
public:
	ThreeSum_2Way(int* in, int n)
	{
		arr = new int[n];
		//memcpy(arr, in, n);
		for (int i = 0; i<n; i++)
		{
			cout << in[i] << " ";
			arr[i] = in[i];
		}
		cout << endl;
		size = n;
		sortArray();
	}
	~ThreeSum_2Way()
	{
		delete[]arr;
	}
	void sortArray()
	{
		for (int j=0; j<size-1; j++)
		{
			for (int i=0; i<size-1-j; i++)
			{
				if (arr[i] > arr[i+1])
				{
					arr[i] = arr[i] + arr[i + 1];
					arr[i + 1] = arr[i] - arr[i + 1];
					arr[i] = arr[i] - arr[i+1];
				}
			}
		}
	}

	int bin_search(int key, int lo)
	{
		int hi = size - 1;
		while (lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if (key == arr[mid])
			{
				return mid;
			}
			else if (key > arr[mid])
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		return -1;
	}
	int binary_search_count()
	{
		int count = 0;
		for (int i = 0; i<size; i++)
		{
			for (int j = i + 1; j<size; j++)
			{
				int key = -(arr[i] + arr[j]);
				int idx = bin_search(key, j+1);
				cout << "key " << key << " " << arr[i] << " " << arr[j] << " " << endl;
				if (idx != -1)
				{
					cout << "inc" << endl;
					count++;
				}
			}
		}
		return count;
	}

	void print()
	{
		cout << "sorted array" << endl;
		for (int i=0; i<size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

class ThreeSum_2Ptr
{
	int *arr;
	int size;
public:
	ThreeSum_2Ptr(int* in, int n)
	{
		arr = new int[n];
		//memcpy(arr, in, n);
		for (int i = 0; i<n; i++)
		{
			cout << in[i] << " ";
			arr[i] = in[i];
		}
		cout << endl;
		size = n;
		sortArray();
	}
	~ThreeSum_2Ptr()
	{
		delete[]arr;
	}
	void sortArray()
	{
		for (int j = 0; j<size - 1; j++)
		{
			for (int i = 0; i<size - 1 - j; i++)
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

	int three_sum_find()
	{
		int count = 0;
		for (int i=0; i<size-2; i++)
		{
			int lo = i + 1;
			int hi = size - 1;
			while (lo < hi)
			{
				int val = arr[i] + arr[lo] + arr[hi];
				if (val == 0)
				{
					lo++;
					count++;
				}
				else if (val > 0)
				{
					hi--;
				}
				else
				{
					lo++;
				}
			}
		}
		return count;
	}

};

int main(int argc, char* args[])
{
	int arr[] = {-40,30,0, -15, 5, 10, 30};
	int s = 7;
	ThreeSum obj(arr, s);
	ThreeSum_2Way obj1(arr, s);
	ThreeSum_2Ptr obj2(arr, s);
	cout << "count = " << obj.brute_force_count() << endl;
	obj1.print();
	cout << obj1.bin_search(-40, 0) << endl;
	cout << "count = " << obj1.binary_search_count() << endl;
	cout << "count = " << obj2.three_sum_find() << endl;
	cout << "end" << endl;
	_getch();
	return 0;
}