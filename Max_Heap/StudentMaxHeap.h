#pragma once
#ifndef STUDENTMAXHEAP_H
#define STUDENTMAXHEAP_H
#include<iostream>
using namespace std;
class StudentMaxHeap;
class Student {
	friend class StudentMaxHeap;
private:
	int rollNo; // Student’s roll number
	double cgpa; // Student’s CGPA
};
class StudentMaxHeap {
private:
	Student* st; // Array of students which will be arranged like a Max Heap
	int currSize; // Current number of students present in the heap
	int maxSize; // Maximum number of students that can be stored in the heap
public:
	StudentMaxHeap(int size); // Constructor
	~StudentMaxHeap(); // Destructor
	bool isEmpty(); // Checks whether the heap is empty or not
	bool isFull(); // Checks whether the heap is full or not
	bool insert(int rollNo, double cgpa);
	bool removeBestStudent(int& rollNo, double& cgpa);
	void swap(Student a, Student b);
	int height();
	void levelOrder();
	void heapify(int i);
	void buildHeap(Student* a, int n);
	void heapSort(Student* st, int n);




};
#endif