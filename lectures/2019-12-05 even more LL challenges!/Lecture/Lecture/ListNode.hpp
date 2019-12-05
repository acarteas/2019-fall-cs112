#pragma once

template <typename DATA_TYPE>
class ListNode
{
private:
	DATA_TYPE _value;
	ListNode<DATA_TYPE>* _next = nullptr;

public:
	ListNode(const DATA_TYPE& value) 
		: _value(value) //using an initialization list is
		                //faster under certain situations
	{}

	ListNode(const DATA_TYPE& value, 
		ListNode<DATA_TYPE>* next)
		: _value(value),
		_next(next)
	{

	}

	ListNode()
	{
	}

	DATA_TYPE& getValue()
	{
		return _value;
	}

	const DATA_TYPE& getValue() const
	{
		return _value;
	}

	void setValue(const DATA_TYPE& v)
	{
		_value = v;
	}

	ListNode<DATA_TYPE>* getNext()
	{
		return _next;
	}

	void setNext(ListNode<DATA_TYPE>* next)
	{
		_next = next;
	}
};