#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>

template <class T>

class Deck{

  private:

    struct Node {
      T data;
      struct Node * next;
    };
    Node *head;
    Node *last;
    int length = 0;

  public:

    void insert(T val){
			
  		Node *nn = new Node;
  		nn->data = val;
  		if (length == 0){
  			head = nn;
  			last = nn;
  		}else{
  			last->next = nn;
  			last = nn;
  		}
  		length++;
  	}

    T remove(){	//remove front
			
  		if (length == 0){
  			Node * nn = new Node;
  			head = nn;
  			last = nn;
  			return nn->data;
  		}else {
  			T retval = head->data;
  			Node *oldhead = head;
  			head = head->next;
  			// delete oldhead;
  			length--;
  			return retval;
  		}
	  }

    int size(){
			
      return length;
    }

};


#endif