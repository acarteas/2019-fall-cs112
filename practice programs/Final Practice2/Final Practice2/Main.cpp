#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
#include "ListNode.hpp"
using namespace std;

// Problem 1:

int deleteNode(ListNode* front, int value) {
	int counter = 1;
	bool flag = false;
	ListNode* current = front;
	ListNode* prev = nullptr;
	if (current == nullptr) {
		return -1;
	}
	while (current != nullptr) {
		if (current->value == value && flag == false) {
			current = current->next;
			prev->next = current;
			flag = true;
		}
		else if (flag == false) {
			prev = current;
			current = current->next;
			counter++;
		}
	}
	if (flag == true) {
		return counter;
	}
	else {
		return -1;
	}
}

vector<int> toArray(ListNode* front) {
	vector<int> vect{};
	ListNode* current = front;
	while (current != nullptr) {
		vect.push_back(current->value);
		current = current->next;
	}
	return vect;
}

ListNode reverse(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* current = head;
	ListNode* next = head;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return *prev;
}

string flipText(string text) {
	string str = text;
	char temp;
	int counter = 0;
	for (int i = str.length(); i >= 0; i--) {
		temp = text[i];
		str[counter] = temp;
		counter++;
	}
	return str;
}

vector<int> difference(vector<int> first, vector<int> second) {
	vector<int> vect{};
	for (int i = 0; i < first.size(); i++) {
		bool flag = false;
		for (int j = 0; j < second.size(); j++) {
			if (first[i] == second[j] && flag == false) {
				flag = true;
			}
		}
		if (flag == true) {
			vect.push_back(first[i]);
		}
	}
	return vect;
}

char toUpper(char ch) {
	if (ch >= 97 && ch <= 122) {
		ch = (char)((int)ch - 32);
	}
	return ch;
}

int main() 
{
	cout << toUpper('z') << endl;
	cout << toUpper('a') << endl;
}