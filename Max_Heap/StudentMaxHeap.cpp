#include"StudentMaxHeap.h"
#include <math.h>
StudentMaxHeap::StudentMaxHeap(int size)
{
	maxSize = size;
	currSize = 0;
	st = new Student[maxSize + 1];

}
StudentMaxHeap:: ~StudentMaxHeap()
{
	delete[]st;
	st = nullptr;
}
bool StudentMaxHeap::isEmpty()
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
bool StudentMaxHeap::isFull()
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
/*bool StudentMaxHeap::insert(int rollNo, double cgpa)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		currSize = currSize + 1;
		int i = currSize, j;
		while (i > 1 && cgpa >= st[i / 2].cgpa)
		{

			j = i;
			i = i / 2;
		}

		st[i].rollNo = rollNo;
		st[i].cgpa = cgpa;

		if (st[i].rollNo > st[j].rollNo)
		{
			swap(st[i].rollNo, st[j].rollNo);
			swap(st[i].cgpa, st[j].cgpa);
		}
		return true;
	}
}*/
bool StudentMaxHeap::insert(int rollNo, double cgpa)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		currSize = currSize + 1;
		int i = currSize;
		while (i > 1 && cgpa > st[i / 2].cgpa || (cgpa == st[i / 2].cgpa && rollNo < st[i / 2].rollNo))
		{
			st[i] = st[i / 2];
			i = i / 2;
		}
		st[i].rollNo = rollNo;
		st[i].cgpa = cgpa;
		return true;
	}
}
bool StudentMaxHeap::removeBestStudent(int& rollNo, double& cgpa)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		rollNo = st[1].rollNo;
		cgpa = st[1].cgpa;
		st[1] = st[currSize];
		currSize--;
		int largest, left, right, i = 1;
		bool flag = true;
		while (flag == true && 2 * i <= currSize)
		{
			largest = i;
			left = 2 * i;
			right = 2 * i + 1;
			if (left <= currSize && st[left].cgpa > st[largest].cgpa || st[left].cgpa == st[largest].cgpa && st[left].rollNo < st[largest].rollNo)
			{
				largest = left;
			}
			if (right <= currSize && st[right].cgpa > st[largest].cgpa || st[left].cgpa == st[largest].cgpa && st[right].rollNo < st[largest].rollNo)
			{
				largest = right;
			}
			if (largest == i)
			{
				flag = false;
			}
			else
			{
				swap(st[i], st[largest]);
				i = largest;
			}
		}
		return true;
	}
}
void StudentMaxHeap::swap(Student a, Student b)
{
	Student temp;
	temp = a;
	a = b;
	b = temp;
}
void  StudentMaxHeap::levelOrder()
{
	for (int i = 1; i <= currSize; i++)
	{
		cout << "\n************Student Data****************\n";
		cout << "Rollno is : " << st[i].rollNo;
		cout << "Cgpa is : " << st[i].cgpa;
	}
}
int StudentMaxHeap::height()
{
	return ceil(log2(currSize + 1));
}
void  StudentMaxHeap::heapify(int i)
{
	int largest, left, right;
	bool flag = true;
	while (flag == true && 2 * i <= currSize)
	{
		largest = i;
		left = 2 * i;
		right = 2 * i + 1;
		if (left <= currSize && st[left].cgpa > st[largest].cgpa || st[left].cgpa == st[largest].cgpa && st[left].rollNo < st[largest].rollNo)
		{
			largest = left;
		}
		if (right <= currSize && st[right].cgpa > st[largest].cgpa || st[left].cgpa == st[largest].cgpa && st[right].rollNo < st[largest].rollNo)
		{
			largest = right;
		}
		if (largest == i)
		{
			flag = false;
		}
		else
		{
			swap(st[i], st[largest]);
			i = largest;
		}
	}
}
void  StudentMaxHeap::buildHeap(Student* a, int n)
{
	if (st)
	{
		delete[]st;
		st = nullptr;
	}
	st = new Student[n + 1];
	for (int i = 0; i < n; i++)
	{
		st[i + 1] = a[i];
	}
	currSize = n; maxSize = n;
	for (int i = n / 2; i >= 1; i--)
	{
		heapify(i);
	}
}
void StudentMaxHeap::heapSort(Student* st, int n)
{
	StudentMaxHeap stuSort(n);
	stuSort.buildHeap(st, n);
	for (int i = n - 1; i >= 0; i--)
	{
		int rn = 0;
		double cgp = 0;
		stuSort.removeBestStudent(rn, cgp);
		st[i].rollNo = rn;
		st[i].cgpa = cgp;
	}
}


