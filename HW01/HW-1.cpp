/*
Data Structure 2028C - Spring 2022 - Homework 1.
Group Members: Jack Vo, Haru Chu, and Nicholas Krouse
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <math.h>
#include <fstream>
#include <vector>
#include <random>
using namespace std;

// constant variable for processing
const int NAME = 30; 

// -----------------------------!&!----------------------------- 
// declare a struct to contain data in the program
struct UserFile
{
    string title;
    string author;
    string firstName;
    string lastName;
    array <int,26>frequency;  //array with size of alphabet to count frequency
    int lineCount;
    int wordCount;
    int letterCount = 0;
};

// global variables
UserFile user;
string userFile;

// -----------------------------!&!----------------------------- 
// open file function, if fail will create that file and append data into it
bool openFile(fstream &dataFile, string name)
{
    cout << "Opening file..." << endl << endl;
    dataFile.open("J:/UC Courses/Spring 2022/Data Structure/HW01/" + name, ios::in | ios::binary);

    // if data fail to open, create and append data to it.
    if (dataFile.fail()) 
    {
        cout << "Error: File Not Found. Please Try Again." << endl;
        return false;
    }
    return true;
}

// -----------------------------!&!----------------------------- 
// create a CardCatalog file to store title, author, number of words&lines, frequency of words, lines and words count
bool createFile()
{
    fstream userfs("J:/UC Courses/Spring 2022/Data Structure/HW01/CardCatalog.txt", ios::app | ios::binary);

    if (!userfs) {
        cout << "File fail to create." << endl << endl;
        return false;
    } else {

        if (!userfs.eof()) 
        {
          userfs << "Title: " << user.title << endl;
          userfs << "Author: " << user.author << endl << endl;
          userfs << "Author First Name: " << user.firstName << endl;
          userfs << "Author Last Name: " << user.lastName << endl;
          userfs << "Word count: " << user.wordCount << endl;
          userfs << "Line count: " << user.lineCount << endl << endl;
        }
    }

    userfs.close();
    return true;
}

// -----------------------------!&!----------------------------- 
// print out the list of action for user
void instruction()
{
    cout << "----------------------------------------------------" << endl;
    cout << "This is the list of program's actions:" << endl;
    cout << "1. See letter frequency." << endl;
    cout << "2. Enter the new book/textfile name." << endl;
    cout << "3. Create a new file to store statistic." << endl;
    cout << "4. Quit the program." << endl << endl;
}

// -----------------------------!&!----------------------------- 
// this function will count the frequence of each character in the file
void frequencyCalc(fstream &myFile, string name)
{
    myFile.open("J:/UC Courses/Spring 2022/Data Structure/HW01/" + name);

    string word;
    int letterCount = 0;

    while(!myFile.eof()){
        myFile >> word;
        for (int i = 0; i < word.length(); i++) {
            if (isalpha(char(tolower(word.at(i))))) {
            int index = char(tolower(word.at(i))) - 'a';
            user.frequency[index]++;
            letterCount++;
            }
        }
    }

    cout << "Frequency of all alphabets in the string:" << endl;
    for (int i = 0; i < (user.frequency).size(); i++) {
        double freq = static_cast<double>(user.frequency[i]) / static_cast<double>(letterCount) * 100.0;
        cout << fixed << setprecision(4) << char(i + 'a') << ": " << freq << "%" << endl;
    }
    cout << endl;
    myFile.close();
}

// -----------------------------!&!----------------------------- 
// this function will split the first and last name of the author
vector<string> splitFullName(string s)
{
    stringstream ss(s);
    string word;
    vector<string> fullNameList;
    while (ss >> word) {
        fullNameList.push_back(word);
    }
    return fullNameList;
}

// -----------------------------!&!----------------------------- 
// this function will count the number of lines in the file
int lineCount(fstream &myFile, string name) {

    string line;
    int lineCount = 0;

    myFile.open("J:/UC Courses/Spring 2022/Data Structure/HW01/" + name);

    while (!myFile.eof()) {
        getline(myFile, line);
        lineCount++;
    }
    myFile.close();
    return lineCount;
}

// -----------------------------!&!----------------------------- 
// this function will count the number of words in the file
int wordCount(fstream &myFile, string name)
{
    myFile.open("J:/UC Courses/Spring 2022/Data Structure/HW01/" + name);

    int wordCount = 0;
    char word[NAME];
    while(!myFile.eof()){
        myFile >> word;
        wordCount++;
    }
    myFile.close();
    return wordCount;
}      

// -----------------------------!&!----------------------------- 
// open, read data, and take all the statistic value needed
void info(fstream &dataFile){
    cout << "Please enter the name of file: " << endl;
    cout << "Your file: ";
    cin >> userFile;
    cout << endl << endl;


    if (openFile(dataFile, userFile)) {
        string input;

        getline(dataFile, input); // title
        user.title = input;

        getline(dataFile, input); // author
        user.author = input;

        // getting First Name and Last Name of Author
        vector<string> userFullName = splitFullName(user.author);
        user.firstName = userFullName[0];
        user.lastName = userFullName[1];
    }
    dataFile.close();

    // get the number of lines and words
    user.lineCount = lineCount(dataFile, userFile);
    user.wordCount = wordCount(dataFile, userFile);
}      

// -----------------------------!&!-----------------------------   
// this is where the whole program execute
int main()
{
    // declare variables
    int iinput;
    fstream dataFile;

    info(dataFile);
    
    while (true) {

        instruction();
        cout << "Your choice: ";
        cin >> iinput;
        cout << endl << endl;

        // check if the player enter invalid input, even if they entered input as non-integer
        // references: https://stackoverflow.com/questions/16698670/switch-statement-inside-a-while-loop-which-loop-infinitely      
        if (!cin) {
            iinput = 0;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n' );
        }

        switch(iinput){
            case 1: // count frequency
                frequencyCalc(dataFile, userFile);
                break;
            case 2: // ask the user to enter new file
                info(dataFile);
                break;
            case 3: // create a file which stores all the data
                if (createFile()) {
                    cout << "Successful creating a file!" << endl;
                }
                break;
            case 4: // quit the program
                cout << "Program ends!" << endl;
                return 0;
                break;
            default: // if invalid input end the file and force user to enter a new file
                cout << "Invalid Input." << endl;
                cout << "You need to enter a new file." << endl << endl;
                dataFile.close();
                info(dataFile);
                break;
        }
    }
    return 0;
}

/*Program's Output

Please enter the name of file: 
Your file: MobyDick.txt


Opening file...

----------------------------------------------------
This is the list of program's actions:
1. See letter frequency.
2. Enter the new book/textfile name.
3. Create a new file to store statistic.
4. Quit the program.

Your choice: 1


Frequency of all alphabets in the string:
a: 6.3319%
b: 1.0917%
c: 2.1834%
d: 2.4017%
e: 12.2271%
f: 2.4017%
g: 2.6201%
h: 5.6769%
i: 8.9520%
j: 0.0000%
k: 0.5459%
l: 5.2402%
m: 3.7118%
n: 7.0961%
o: 6.9869%
p: 2.7293%
q: 0.2183%
r: 6.2227%
s: 5.8952%
t: 8.5153%
u: 2.8384%
v: 1.5284%
w: 1.8559%
x: 0.0000%
y: 2.5109%
z: 0.2183%

----------------------------------------------------
This is the list of program's actions:
1. See letter frequency.
2. Enter the new book/textfile name.
3. Create a new file to store statistic.
4. Quit the program.

Your choice: 3


Successful creating a file!
----------------------------------------------------
This is the list of program's actions:
1. See letter frequency.
2. Enter the new book/textfile name.
3. Create a new file to store statistic.
4. Quit the program.

Your choice: 2


Please enter the name of file:
Your file: PeterPan.txt


Opening file...

----------------------------------------------------
This is the list of program's actions:
1. See letter frequency.
2. Enter the new book/textfile name.
3. Create a new file to store statistic.
4. Quit the program.

Your choice: kdj


Invalid Input.
You need to enter a new file.

Please enter the name of file:
Your file: MobyDick.txt


Opening file...

----------------------------------------------------
This is the list of program's actions:
1. See letter frequency.
2. Enter the new book/textfile name.
3. Create a new file to store statistic.
4. Quit the program.

Your choice: 4


Program ends!
*/