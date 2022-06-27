#include <cstring>
#include <iomanip>
#include <fstream>
#include "Stack.h"
#include "Queue.h"

// prototype function
void reverse(string str);
bool openFile(fstream &file, string name);

int main() {
  // Stack<char> stack(10);
  fstream file;
  string input;
  if (openFile(file, "Lab_6_Input.txt")) {
      while (file >> input) {
        // try{
        reverse(input);         
         // }catch(exception &e){
           //cout << e.what() << endl;
         // }
        cout << " ";
      }
  }
  file.close();
  return 0;
}

// -----------------------------!&!----------------------------- 
// open file function, if fail print out error
bool openFile(fstream &dataFile, string name)
{
  cout << "Opening file..." << endl << endl;
  dataFile.open(name, ios::in);
  // if data fail to open, throw error
  if (dataFile.fail()) 
  {
     cout << "Error: File Not Found. Please Try Again." << endl;
      return false;
  }
  return true;
}


void reverse(string str) {
  // string temp;
  
  // for (int i = str.length() - 1; i >= 0; i--) {
  //   temp += str[i];
  // }
  // return temp;
  Stack<char> stack(str.length());
  Queue<char> queue;
  for (int i = 0; i < str.length(); i++) {
    stack.push(&str.at(i));
  }
  while (!stack.isEmpty()){
    queue.enqueue(*stack.pop());
  }
  while (!queue.isEmpty()){
    cout << queue.dequeue();
  }
}