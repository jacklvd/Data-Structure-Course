#ifndef STACK_H
#define STACK_H
#include <exception>
#include <iostream>
using namespace std;

class MyException : public exception {
public:
    virtual const char * what() const throw() {
        return "Error";
    }
};

template <class T>
class Stack {
  private:
    T **ptr;
    int size;
    int length;
  public:

    Stack(int usize){
      ptr = new T*[usize];
      size = usize;
      length = -1;
    }


    bool isFull() const {
        bool full;
        if (length == size - 1) {
            full = true;
        }
        else {
            full = false;
        }
        return full;
    }

    bool isEmpty() const {
        bool empty;
        if (length == -1) {
            empty = true;
        }
        else {
            empty = false;
        }
        return empty;
    }

    int getlength(){
      return length + 1;
    }

    void push(T* input){
      try {
            length++;
            ptr[length] = input;
        } catch (MyException &e) {
            cout << e.what() << endl;
        }
    }

    T *pop(){
      T *input = nullptr;
        try {
            input = ptr[length];
            length--;
        } catch (MyException &e) {
            cout << e.what() << endl;
        }
    return input;
    }

    T *top(){
      return ptr[length];
    }

    void makeEmpty(){
      if (length == -1) {
            return;
        }
        while (length != -1) {
            ptr[length] = nullptr;
            delete ptr[length];
            length--;
        }
    }

    // int getCapacity(){
    //   return sizeof(ptr);
    // }

};

#endif