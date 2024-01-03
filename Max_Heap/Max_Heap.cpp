#include<iostream>
using namespace std;
#include"StudentMaxHeap.h"
int main()
{
	StudentMaxHeap stHeap(6);
	//stHeap.insert(3, 3.2);
	//stHeap.insert(5, 3.2);
	//stHeap.insert(7, 3.8);
	//stHeap.insert(9, 3.1);
	//stHeap.insert(12, 4.0);
	//stHeap.levelOrder();
	int choice;
	int rn;
	double cgpaa;

	//cout << "Height of heap is : " << stHeap.height();
	cout << "1. Insert a new student\n";
	cout << "2. Remove(and display) the student with the Max CGPA\n";
	cout << "3. Display the list of students(Level - order traversal)\n";
	cout << "4. Display the height of the heap\n";
	cout << "5. Exit\n";
	do
	{
		cout << "Enter your choice :";
		cin >> choice;
		if (choice == 1)
		{

			cout << "Enter rollNo : ";
			cin >> rn;
			cout << "Enter cgpa : ";
			cin >> cgpaa;
			if (stHeap.insert(rn, cgpaa))
			{
				cout << "Succesfully inserted\n";
			}
			else
			{
				cout << "Not inserted\n";

			}

		}
		else if (choice == 2)
		{
			stHeap.removeBestStudent(rn, cgpaa);
			cout << "\n\nRollno of removing student is : " << rn << endl;
			cout << "cgpa of removing student is : " << cgpaa << endl;
		}
		else if (choice == 3)
		{
			stHeap.levelOrder();
			cout << endl;
		}
		else if (choice == 4)
		{
			cout << "Height of heap is : " << stHeap.height() << endl;
		}
		else if (choice == 5)
		{


		}
	} while (choice != 5);
	return 0;
}