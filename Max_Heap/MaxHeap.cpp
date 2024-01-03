#include"MaxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap(int n)
{
	maxSize = n;
	currSize = 0;
	h = new int[maxSize + 1];
}
MaxHeap:: ~MaxHeap()
{
	delete[] h;
	h = nullptr;
}
bool MaxHeap::isEmpty()
{
	if (currSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MaxHeap::isFull()
{
	if (currSize == maxSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MaxHeap::insert(int val)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		currSize = currSize + 1;
		int i = currSize;
		while (i > 1 && val > h[i / 2]) //if value of new inserted  greater then parent then new inserted node=parent and stop when val<parent
		{
			h[i] = h[i / 2];
			i = i / 2;
		}
		h[i] = val;
		return true;
	}
}
bool  MaxHeap::removeMax(int& maxVal)
{
	if (isEmpty())
	{

		return false;
	}
	else
	{
		maxVal = h[1];
		h[1] = h[currSize];
		currSize--;
		int largest, left, right, i = 1;
		bool flag = true;
		while (flag == true && 2 * i <= currSize)
		{
			largest = i;
			left = 2 * i;
			right = 2 * i + 1;
			if (left <= currSize && h[left] > h[largest])
			{
				largest = left;
			}
			if (right <= currSize && h[right] > h[largest])
			{
				largest = right;
			}
			if (largest == i) //if i already is largest
			{
				flag = false;
			}
			else
			{
				swap(h[i], h[largest]);
				i = largest;
			}
		}

		return true;
	}
}
void MaxHeap::swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void MaxHeap::heapify(int i)
{
	int largest, left, right;
	bool flag = true;
	while (flag == true && 2 * i <= currSize)
	{
		largest = i;
		left = 2 * i;
		right = 2 * i + 1;
		if (left <= currSize && h[left] > h[largest])
		{
			largest = left;
		}
		if (right <= currSize && h[right] > h[largest])
		{
			largest = right;
		}
		if (largest == i) //if i already is largest
		{
			flag = false;
		}
		else
		{
			swap(h[i], h[largest]);
			i = largest;
		}
	}
}
void MaxHeap::buildHeap(int* a, int n)
{
	if (h)
	{
		delete[]h;
		h = nullptr;
	}
	h = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		h[i + 1] = a[i];   //all elements of array are shifted in heap but now it is not max heap
	}
	currSize = n;
	maxSize = n;
	for (int i = n / 2; i >= 1; i--)
	{
		heapify(i);
	}
}
void heapSort(int* a, int n)
{
	MaxHeap mh(n);
	mh.buildHeap(a, n);
	for (int i = n - 1; i >= 0; i--)
	{
		int val;
		mh.removeMax(val);
		a[i] = val;
	}
}
MaxHeap::MaxHeap(const MaxHeap& orig)
{
	if (orig.h == nullptr)
	{
		h = nullptr;
	}
	else
	{
		h = new int[maxSize + 1];
		for (int i = 1; i <= currSize; i++)
		{
			h[i] = orig.h[i];
		}
	}
}
const MaxHeap& MaxHeap:: operator=(const MaxHeap& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	else
	{
		if (h != nullptr)
		{
			delete h;
			h = nullptr;
		}
		h = new int[maxSize + 1];
		for (int i = 1; i <= currSize; i++)
		{
			h[i] = rhs.h[i];
		}

	}
}


