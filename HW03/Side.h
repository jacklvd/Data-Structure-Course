#ifndef SIDE_H
#define SIDE_H

#include <exception>
#include <iostream>
using namespace std;

class MyException : public exception {
public:
    virtual const char * what() const throw() {
        return "Error";
    }
};

static int SizeOfSide = 5;

template <class T>
class Side {

  private:

    T ptr[5];
    int size;
    int length;

  public:

    Side(){
      size = SizeOfSide;
      T blank;
      for (int i = 0; i < 5; i++){
        ptr[i] = blank;
      }
      length = 0;
    }

		// check if side is full
    bool isFull() const {
      return length >= size;
    }

		// check side empty
    bool isEmpty() const {
      return length <= 0;
    }

    int getlength(){
      return length;
    }

		// insert to side
    void push(T input){
      try {
        ptr[length] = input;
        length++;
      } catch (MyException &e) {
          cout << e.what() << endl;
      }
    }

    T pop(){
      T input;
        try {
          length--;
          input = ptr[length];
        } catch (MyException &e) {
            cout << e.what() << endl;
        }
      return input;
    }


    void makeEmpty(){
      length = 0;
    }

};


#endif