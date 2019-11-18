#pragma once
#include "ListNode.hpp"

template <typename DATA_TYPE>
class LinkedList
{
private:
	ListNode<DATA_TYPE>* _front = nullptr;

public:

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

			//the arrow makes it so we don't have to type
			//out this mess every time we want to access
			//a pointer's value
			/*while ((*current).getNext() != nullptr)
			{
				current = (*current).getNext();
			}*/
			while (current->getNext() != nullptr)
			{
				current = current->getNext();
			}
		}
	}
};