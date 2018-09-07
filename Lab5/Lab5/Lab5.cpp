#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>

using namespace std;

bool fexists(const string& filename) 
{
  ifstream ifile(filename.c_str());
  return (bool)ifile;
}

void main()
{
	char answer;
	string phrase;
	if (fexists("./example.txt"))
	{
		cout << "This file exists, would you like to overwrite it? (y/n)" << endl;
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			ofstream newFile("./example.txt");
			cout << "Write what you would like to enter: " << endl;
			cin.ignore();
			getline(cin,phrase);
			newFile << phrase;
			
		}

	}
	else
	{
		cout << "This file does not exist, creating a new file..." << endl;
		ofstream newFile("./example.txt");
		cout << "Write what you would like to enter: " << endl;
		getline(cin,phrase);
		newFile << phrase;
	}

}