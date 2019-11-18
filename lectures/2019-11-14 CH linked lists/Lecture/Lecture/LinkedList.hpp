#pragma once
#include "ListNode.hpp"

template <typename DATA_TYPE>
class LinkedList
{
private:
	ListNode<DATA_TYPE>* _front = nullptr;

public:

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