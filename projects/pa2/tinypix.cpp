#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string file_text;
    ifstream file;

    file.open ("tinypix.txt");
    while (!file.eof() && file)
    {
        getline (file, file_text);
        cout << file_text << endl;
    }
    file.close();
    return 0;
}