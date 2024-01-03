#pragma once
#ifndef MAXHEAP_H
#define  MAXHEAP_H
class MaxHeap
{
private:
	int* h;
	int currSize, maxSize;
public:
	MaxHeap(int n);
	bool isEmpty();
	bool isFull();
	~MaxHeap();
	bool insert(int val);
	bool removeMax(int& Maxval);
	void swap(int a, int b);
	void heapify(int i);
	void buildHeap(int* a, int n);
	MaxHeap(const MaxHeap& orig);
	const MaxHeap& operator=(const MaxHeap& rhs);
};


#endif // !1