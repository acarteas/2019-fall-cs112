#pragma once
#include <exception>
#include "ListNode.hpp"
using namespace std;
template <typename DATA_TYPE>
class LinkedList
{
private:
	ListNode<DATA_TYPE>* _front = nullptr;

public:
	LinkedList()
	{

	}

	//to disallow copy of objects, we need to "delete" the 
	//associated function
	//LinkedList(const LinkedList<DATA_TYPE>& to_copy) = delete;
	LinkedList(const LinkedList<DATA_TYPE>& to_copy)
	{
		ListNode<DATA_TYPE>* current = to_copy._front;

		while (current->getNext() != nullptr)
		{
			addValue(current->getValue());
			current = current->getNext();
		}
	}

	//lecture TODO: find smallest item in linked list
	DATA_TYPE& findSmallest()
	{
		ListNode<DATA_TYPE>* current = _front;
		DATA_TYPE current_smallest = current->getValue();
		while (current->getNext() != nullptr)
		{
			if (current_smallest > current->getValue())
			{
				current_smallest = current->getValue();
			}
			current = current->getNext();
		}
		return current_smallest;
	}

	//lecture TODO: calculate average value in linked list
	double calculateAverage()
	{
		if (_front == nullptr)
		{
			return 0.0;
		}
		ListNode<DATA_TYPE>* current = _front;
		double sum = 0.0;
		int counter = 0;
		for (; current->getNext() != nullptr; counter++)
		{
			sum += current->getValue();
			current = current->getNext();
		}
		return sum / (double)counter;
	}

	//lecture TODO: remove Nth item from LL
	void removeElementAt(int location)
	{
		ListNode<DATA_TYPE>* current = _front;
		ListNode<DATA_TYPE>* next = nullptr;
		int counter = 0;
		for (int i = 0; current != nullptr && i < location - 1; i++)
		{
			current = current->getNext();
		}
		if (current != nullptr && current->getNext() != nullptr)
		{
			next = current->getNext();
			current->setNext(next->getNext());
			delete next;
		}
		else
		{
			throw exception{ "Invalid location" };
			return;
		}
	}

	LinkedList<DATA_TYPE> mergeSorted(
		const LinkedList<DATA_TYPE>& first, 
		const LinkedList<DATA_TYPE>& second
		)
	{
		ListNode<DATA_TYPE>* first_pointer = first._front;
		ListNode<DATA_TYPE>* second_pointer = second._front;
		LinkedList<DATA_TYPE> result{};
		while(first_pointer != nullptr && second_pointer != nullptr)
		{
			if(first_pointer->getValue() < second_pointer->getValue())
			{
				result->addValue(first_pointer->getValue());
				first_pointer = first_pointer->getNext();
			}
			else
			{
				result->addValue(second_pointer->getValue());
				second_pointer = second_pointer->getNext();
			}
		}

		//possible that one LL still has values
		while(second_pointer != nullptr)
		{
			result->addValue(second_pointer->getValue());
			second_pointer = second_pointer->getNext();
		}
		while(first_pointer != nullptr)
		{
			result->addValue(first_pointer->getValue());
			first_pointer = first_pointer->getNext();
		}
		
	}


	//this is the copy operator
	//in this version, we don't start off blank
	LinkedList<DATA_TYPE>& operator=(const LinkedList<DATA_TYPE>& to_copy)
	{
		//because we already have data inside, we must first
		//resest our self to factory standard (blank)
		while (_front != nullptr)
		{
			removeValue(_front->getValue());
		}

		ListNode<DATA_TYPE>* current = to_copy._front;

		while (current->getNext() != nullptr)
		{
			addValue(current->getValue());
			current = current->getNext();
		}
		return *this;
	}


	//delete all nodes in linked list when the variable
	//goes out of scope
	~LinkedList()
	{
		while (_front != nullptr)
		{
			ListNode<DATA_TYPE>* next = _front->getNext();
			delete _front;
			_front = next;
		}
	}

	void reverse()
	{
		//count # of nodes in list
		int counter = 0;
		ListNode<DATA_TYPE>* current = _front;
		while (current->getNext() != nullptr)
		{
			counter++;
			current = current->getNext();
		}

		//make a mirror
		for (int i = counter; i >= 0; i--)
		{
			//start at beginning of list every time
			current = _front;
			for (int j = 0; j < i; j++)
			{
				current = current->getNext();
			}
			addValue(current->getValue());
		}

		//remove original items
		for (int i = 0; i <= counter; i++)
		{
			removeValue(_front->getValue());
		}
	}

	//AT HOME TASK: try writing 
	//void addAfter(const DATA_TYPE& value, const DATA_TYPE& after)
	//Add "value" after the box that contains the value "after"
	bool removeValue(const DATA_TYPE& value)
	{
		//pre check: is the value to be deleted the first item in the list?
		if (_front != nullptr && _front->getValue() == value)
		{
			ListNode<DATA_TYPE>* new_front = _front->getNext();
			delete _front;
			_front = new_front;
			return true;
		}

		ListNode<DATA_TYPE>* current = _front;
		ListNode<DATA_TYPE>* before = nullptr;
		while (current != nullptr && current->getValue() != value)
		{
			before = current;
			current = current->getNext();
		}

		//non-null current means that we found a value to delete
		if (current != nullptr)
		{
			//current is now the box to delete
			//before is the box that will "jump" over current
			before->setNext(current->getNext());

			//delete unneeded node
			delete current;

			return true;
		}
		else
		{
			return false;
		}

	}

	//12/5 TODO
	//remove all duplicate values from the LL
	void removeDuplicats()
	{

	}

	//12/5 TODO
	//sorts all items in the LL from smallest to largest
	void sort()
	{

	}

	//12/5 TODO
	//sorts all items in staircase order.  E.g. if the list is 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7,
	//the result would be
	//1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4
	void staircaseSort()
	{

	}

	//returns the number of items that are smaller than the supplied value
	int smallerThan(const DATA_TYPE& value)
	{

	}

	void addValue(const DATA_TYPE& value)
	{
		//empty list?
		if (_front == nullptr)
		{
			_front = new ListNode<DATA_TYPE>(value);
		}
		else
		{
			//one or more boxes already in our list
			//go to end of list to add new value
			ListNode<DATA_TYPE>* current = _front;

			//go to end of list
			while (current->getNext() != nullptr)
			{
				current = current->getNext();
			}

			//create a new box for our data
			ListNode<DATA_TYPE>* new_box =
				new ListNode<DATA_TYPE>{ value };

			//add the box to the linked list
			current->setNext(new_box);
		}
	}
};