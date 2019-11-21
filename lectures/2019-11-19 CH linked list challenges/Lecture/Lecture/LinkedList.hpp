#pragma once
#include "ListNode.hpp"

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
		return _front->getValue();
	}

	//lecture TODO: calculate average value in linked list
	double calculateAverage()
	{
		return 0.0;
	}

	//lecture TODO: remove Nth item from LL
	void removeElementAt(int location)
	{

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
		for (int i = 0; i < counter; i++)
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