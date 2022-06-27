#include "Words.h"
#include "AVLTree.h"
#include <random>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//prototype functions
bool openFile(fstream& dataFile, string name);
void addFile(fstream& file, AVLTree<Words>& words);
void instruction();

int main()
{
	AVLTree<Words> avl;
	fstream getFile;
  string fileName;
	int input = 0;

    cout << "Please enter the name of your file: " << endl;
    cout << "Your file name: ";
    cin >> fileName;
    if (openFile(getFile, fileName)) {
        addFile(getFile, avl);
    } else {
			return 0;
		}
  
    while (true) {
        instruction();
        cout << "Your input: ";
        cin >> input;

        if (!cin) {
            input = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (input) {
            case 1:
            {
                string search = "";
                cout << "Enter a word you would like to search for: ";
                cin >> search;
                cout << endl;
                Words *word = new Words(search);
                if (avl.findTree(*word)) {
                    // print out the word
										cout << "Your word: \'" << avl.findTree(*word)->val.getWords() << "\' is found!" << endl;
                    cout << "Its frequency: " <<  avl.findTree(*word)->val.getWordsNum() << endl << endl;
                }
                else {
                    cout << "That word is not in the file!" << endl << endl;
                }
                break;
            }
            case 2:
                avl.getAllAscending();
                cout << endl << endl;
                break;
            case 3:
                avl.getAllDescending();
                cout << endl << endl;
                break;
            case 4: // exit
                cout << "Bye!" << endl;
                return 0;
        }
    }
}


// open file function
bool openFile(fstream& dataFile, string name)
{
    cout << "Opening file..." << endl << endl;
    dataFile.open(name, ios::in | ios::binary);

    // if data fail to open, throw error
    if (dataFile.fail())
    {
        cout << "Error: File Not Found. Please Try Again." << endl;
        return false;
    }
    return true;
}

void addFile(fstream& file, AVLTree<Words>& words) {

    string data;
    while (!file.eof()) {
        file >> data;
        
        for (int i = 0; i < data.size(); i++) {
            if (ispunct(data[i])) { // check if contains punctuation
                data.erase(data.begin() + i); // remove punctuation of that string
            }
            if (isupper(data[i])) { // check if is capital leters
                data[i] = tolower(data[i]); // change to lowercases data
            }
            if (data[i] == ' ') {
                data.erase(data.begin() + 1);
            }
        }
        Words *word = new Words(data); 
        if (words.findTree(*word) != nullptr) {
            words.findTree(*word)->val.increaseWords();
        }
        else {     
            words.insert(*word);
						// words.findTree(*word)->val.increaseWords();
        }
    }
}

// print out the instruction for the users
void instruction() {

    cout << "--------------------------------------" << endl;
    cout << "List of Actions" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Search a word and its specific frequency" << endl;
    cout << "2. List of all words in ascending order" << endl;
    cout << "3. List of all words in descending order" << endl;
    cout << "4. Exit" << endl << endl;
}