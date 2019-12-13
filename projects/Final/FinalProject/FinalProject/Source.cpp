#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "ListNode.H"
#include "Animals.h"

using namespace std;
//Question 1
int deleteNode(ListNode* front, int value) {
	int counter = 1;
	ListNode* current = front;
	ListNode* prev = front;
	bool removed = false;
	if (current == nullptr) {
		return -1;
	}
	while (current != nullptr) {
		if (current->value == value && removed == false) {
			current = current->next;
			prev->next = current;
			removed = true;
		}
		else if (removed == false) {
			prev = current;
			current = current->next;
			counter++;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	if (removed == true) {
		return counter;
	}
	else {
		return -1;
	}
}
// Question 2
vector<int> toArray(ListNode* front) {
	vector<int> array{};
	ListNode* current = front;
	while (current != nullptr) {
		array.push_back(current->value);
		current = current->next;
	}
	return array;
}
//Question 3
ListNode reverse(ListNode* head) {
	ListNode* current = head;
	ListNode* prev = nullptr;
	ListNode* next = head;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return *prev;
}
//Question 4
string flipText(string text) {
	string str = text;

	char temp;
	int counter = 0;
	for (int i = text.length() - 1; i >= 0; i--) 
	{
		temp = text[i];
		str[counter] = temp;
		counter++;
	}
	cout << str << endl;;
	return str;
}



//Question 5 

//using namespace std;
//class Animals 
//{
//public:
//	
//	void setlocation(string locator);
//	void setbrith_place(string home);
//	void setid_num(int id);
//	string name;
//	int age;
//
//
//private:
//	string location;
//	string brith_place;
//	int id_num;
//};
//void Animals ::setlocation(string locator)
//{
//	locator = location;
//}
//
//void Animals ::setbrith_place(string home)
//{
//	home = brith_place;
//}
//void Animals::setid_num(int id)
//{
//	id = id_num;
//}


//Question 6
vector<int> difference(vector<int> first, vector<int> second) {
	vector<int> vect2{};

	for (int i = 0; i < first.size(); i++) {
		bool found = false;
		for (int j = 0; j < second.size(); j++) {
			if (first[i] == second[j] && found == false) {
				found = true;
			}
			else if (found == true) {
				found == true;
			}
		}
		if (found == false)
		{
		 vect2.push_back(first[i]);
		}
	}
	return vect2;
}


//Question 7
char toUpper(char ch) {
	int ascii_value = int(ch);
	if (ascii_value >= 97 && ascii_value <= 122) {
		return char(ascii_value - 32);
	}
	else {
		return ch;
	}

}


//Question 8
int findMode(string input_file) 
{
	ifstream stream{ input_file };
	vector<int> vect{};
	int great_count = 0;

	while (stream.good() == true) {
		int i = 0;
		stream >> i;
		vect.push_back(i);
	}
	stream.close();

	for (int i = 0; i < vect.size(); i++) {
		int count = 1;
		for (int j = i + 1; j < vect.size(); j++) {
			if (vect[i] == vect[j]) {
				count++;
			}
		}
		if (count > great_count) {
			great_count = count;
		}
	}
	for (int i = 0; i < vect.size(); i++) {
		int count = 1;
		for (int j = i + 1; j < vect.size(); j++) {
			if (vect[i] == vect[j]) {
				count++;
			}
		}
		if (count == great_count) {
			return vect[i];
		}
	}
}
//Question 9
void findLongSentences(string input_file, int sentence_length) {
	ifstream stream{ input_file };
	vector<vector<string>> wordsandsents{};
	while (stream.good() == true) {
		string temp;
		getline(stream, temp);
		istringstream words{ temp };
		vector<string> temp_vect{};
		while (words.good() == true) {
			string word;
			words >> word;
			temp_vect.push_back(word);
		}
		wordsandsents.push_back(temp_vect);
		temp_vect.clear();
	}
	for (int i = 0; i < wordsandsents.size(); i++) {
		if (wordsandsents[i].size() > sentence_length) {
			for (int j = 0; j < wordsandsents[i].size(); j++) {
				cout << wordsandsents[i][j] << " ";
			}
			cout << endl;
		}
	}
}

int main() {

	// Question 1:
	ListNode start;
	start.value = 6;
	ListNode two;
	two.value = 3;
	ListNode three;
	three.value = 4;
	ListNode* hello = &start;
	ListNode* hello2 = &two;
	ListNode* hello3 = &three;
	hello->next = &two;
	hello2->next = &three;



	cout << deleteNode(hello, 3) << endl;


	// Question 2:

	//vector<int> array1 = toArray(hello);
	//for(int i = 0; i < array1.size(); i++) {
	//	cout << array1[i] << " ";
	//}
	//cout << endl;

	// Question 3:
	ListNode newll = reverse(hello);
	cout << newll.value << endl;


	// Question 4:
	string newtext = flipText("Hello");

	// Question 5:
	

	// Question 6:
	vector<int> first{ 2, 3, 4, 5, 6 };
	vector<int> second{ 9, 4, 2, 10, 100, 6, 7, 9, 3 };
	vector<int> difference_vect = difference(first, second);
	for (int i = 0; i < difference_vect.size(); i++) {
		cout << difference_vect[i];
	}
	cout << endl;

	// Question 7:
	int integer = findMode("something.txt");
	cout << integer << endl;

	// Question 8:
	char cha = toUpper('z');
	cout << cha << endl;

	// Question 9:

	findLongSentences("sents.txt", 5);
}