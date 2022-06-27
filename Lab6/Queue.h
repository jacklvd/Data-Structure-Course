#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <vector>
using namespace std;
template <class T>

class Queue {
  private:
    int temp;
	  vector<T> queue;
  public:
    Queue(){
      queue;
    }
    bool isEmpty();
    int vectorSize();
    void enqueue(T);
    T dequeue();
    void clear();
};

template<class T>
bool Queue<T>::isEmpty() {
    if (queue.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}
template<class T>
int Queue<T>::vectorSize(){
    return queue.size();
}
template<class T>
void Queue<T>::enqueue(T action){
    queue.push_back(action);
}

template <class T>
T Queue<T>::dequeue() {
    T temp = queue[0];
    queue.erase(queue.begin());
    return temp;
}

template <class T>
void Queue<T>::clear(){
    for (int i = 0; i < queue.size(); i++){
        queue.pop_back();
    }
}

#endif