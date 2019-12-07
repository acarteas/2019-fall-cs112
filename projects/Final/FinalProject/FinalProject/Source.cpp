#include<iostream>
#include "ListNode.h"

using namespace std;

int main()
{
	ListNode* head = new ListNode;
	head->value = 10;
	ListNode* temp = new ListNode;
	head->next = temp;
	cout << temp;
	cout << head;


	// My checker cout << "it runs";

	return 0;
}
int deleteNode(ListNode* front, int value)
{
	while (front != nullptr)
	{
		ListNode* next = front->next;
	//	delete front;
		front = next;
		delete front;
		
	}
	
	cout << value << "   has been deleted" << endl;
}