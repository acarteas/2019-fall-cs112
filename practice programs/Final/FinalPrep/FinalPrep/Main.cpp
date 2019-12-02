#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

string flipText(string text) {
	string str = text;

	char temp;
	int counter = 0;
	for (int i = text.length() - 1; i >= 0; i--) {
		temp = text[i];
		str[counter] = temp;
		counter++;
	}
	cout << str << endl;;
	return str;
}

vector<int> difference(vector<int> first, vector<int> second) {
	vector<int> new_vect{};
	
	for (int i = 0; i < first.size(); i++){
		bool flag_matched = false;
		for (int j = 0; j < second.size(); j++) {
			if (first[i] == second[j] && flag_matched == false) {
				flag_matched = true;
			}
			else if (flag_matched == true){
				flag_matched == true;
			}
		}
		if (flag_matched == true)
		{
			new_vect.push_back(first[i]);
		}
	}
	return new_vect;
}

char toUpper(char ch) {
	int ascii_value = int(ch);
	if (ascii_value >= 97 && ascii_value <= 122) {
		return char(ascii_value - 32);
	}
	else {
		return ch;
	}
	
}

int findMode(string input_file) {
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

void findLongSentences(string input_file, int sentence_length) {
	ifstream stream{ input_file };
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
		temp_vect.clear();
		// INCOMPLETE!!!!!!!!!!!!!!!!!!!!!!
	}
}

int main(){
	int integer = findMode("something.txt");
	cout << integer << endl;
	char cha = toUpper('z');
	cout << cha << endl;
	string newtext = flipText("Hello");
	vector<int> first{ 2, 3, 4, 5, 6 };
	vector<int> second{ 9, 4, 2, 10, 100, 6, 7, 9, 3 };
	vector<int> difference_vect = difference(first, second);
	for (int i = 0; i < difference_vect.size(); i++) {
		cout << difference_vect[i];
	}
}