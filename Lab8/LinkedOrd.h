#ifndef LINKEDORD
#define LINKEDORD
#include <iostream>
using namespace std;

// //////////////////////////////
template<class T>
class LinkedList {
private:
    struct Node {
        T value;
        struct Node * next;
        struct Node * prev;
    };
    Node* head;
    Node* P = nullptr;

public:
    LinkedList() {
        head = nullptr;
    };

    void AddItem(T);
    T GetItem(T);
    bool IsInlist(T);
    bool IsEmpty();
    int Size();
    T SeeNext();
    T SeePrev();
    T SeeAt(int);
    void Reset();
    void display();

    ~LinkedList(){
        Node * NodePtr;
        Node * NextNode = nullptr;

        NodePtr = head;

        while(NodePtr != nullptr){
            NextNode = NodePtr;
            delete NodePtr;
            NodePtr = NextNode;
        }
    };
    class MyException : public exception {
      public:
        virtual const char * what() const throw() {
          return "Error";
        }
    };

    bool operator == (const LinkedList & obj){
        Node * NodePtr1;
        Node * NodePtr2;
        NodePtr1 = head;
        NodePtr2 = obj.head;

        if(head == nullptr && obj.head == nullptr){
            return true;
        }

        if(head == nullptr && obj.head != nullptr){
            return false;
        }

        if(head != nullptr && obj.head == nullptr){
            return false;
        }

        while(NodePtr1 != nullptr && NodePtr2 != nullptr){
            if(NodePtr1->value != NodePtr2->value){
                return false;
            }
        NodePtr1 = NodePtr1->next;
        NodePtr2 = NodePtr2->next;
        }
        return true;
        }

    bool operator != (const LinkedList & obj){
        Node * NodePtr1;
        Node * NodePtr2;
        NodePtr1 = head;
        NodePtr2 = obj.head;

        if(head == nullptr && obj.head == nullptr){
            return false;
        }

        if(head == nullptr && obj.head != nullptr){
            return false;
        }

        if(head != nullptr && obj.head == nullptr){
            return false;
        }

        while(NodePtr1 != nullptr && NodePtr2 != nullptr){
            if(NodePtr1->value != NodePtr2->value){
                return true;
            }
        NodePtr1 = NodePtr1->next;
        NodePtr2 = NodePtr2->next;
        }
        return true;
        }

    bool operator > (const LinkedList & obj){
        Node * NodePtr1;
        Node * NodePtr2;
        NodePtr1 = head;
        NodePtr2 = obj.head;

        if(head == nullptr || obj.head == nullptr){
            return false;
        }

        while(NodePtr1 != nullptr && NodePtr2 != nullptr){
            if(NodePtr1->value == NodePtr2->value || NodePtr1->value < NodePtr2->value){
                return false;
            }
            NodePtr1 = NodePtr1->next;
            NodePtr2 = NodePtr2->next;
        }
        return true;
    }

    bool operator < (const LinkedList & obj){
        Node * NodePtr1;
        Node * NodePtr2;
        NodePtr1 = head;
        NodePtr2 = obj.head;

        if(head == nullptr || obj.head == nullptr){
            return false;
        }

        while(NodePtr1 != nullptr && NodePtr2 != nullptr){
            if(NodePtr1->value == NodePtr2->value || NodePtr1->value > NodePtr2->value){
                return false;
            }
            NodePtr1 = NodePtr1->next;
            NodePtr2 = NodePtr2->next;
        }
        return true;
    }

};

// template <class T>
// void LinkedList<T>::AddItem(T item) {
//     Node * NodePtr;
//     Node * NewNode;

//     NewNode = new Node;
//     NewNode->value = item;
//     NewNode->next = nullptr;

//     if(!head)
//         head = NewNode;
//     else{
//         NodePtr = head;
//         while(NodePtr->next){
//             NodePtr = NodePtr->next;
//         }
//         NodePtr->next = NewNode;
//     }
// }

template <class T>
void LinkedList<T>::AddItem(T item) {

    Node* curr;
    Node* newNode = new Node;
    newNode->value = item;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // if list is empty
    if (!head) {
        head = newNode;
    }
    // if the node is to be insered at the beginning
    // of the doubly linked list
    else if (head->value > newNode->value || head->value == newNode->value) {
        newNode->next = head;
        newNode->next->prev = newNode;
        head = newNode;
    }
    else {
        curr = head;

        // locate the node after which the new node
        // is to be inserted
        while (curr->next != nullptr && curr->next->value < newNode->value) {
            curr = curr->next;
        }
        // make the approriate links
        newNode->next = curr->next;

        // if the new node is not inserted
        // at the end of the list
        if (curr->next != nullptr) {
            newNode->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

}

template <class T>
T LinkedList<T>::GetItem(T item) {
    if (head == nullptr) {
        cout << "The list is empty\n";
        return NULL;
    }
    T retVal;
    Node* temp = new Node;
    if (head->value == item) {
        temp = head;
        head = head->next;
        retVal = temp -> value;
        delete temp;
        return retVal;
    }

    temp = head;
    while (temp->next != nullptr && temp->next->value != item) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node* del = temp->next;;
        retVal = temp->next->value;
        temp->next = temp->next->next;
        delete del;
        return retVal;
    }
    else
    {
        cout << "The number you want to remove is not in the list\n";
        return NULL;
    }
}

template <class T>
bool LinkedList<T>::IsInlist(T item) {
    struct Node * temp = head;
    bool ans;
    if (temp == NULL) {
        ans = false;
    }
    else {
        while (temp != NULL) {
            if (temp->value == item) {
                ans = true;
                break;
            }
            else {
                ans = false;
            }
            temp = temp->next;
        }
    }
    return ans;
}

template <class T>
bool LinkedList<T>::IsEmpty() {
    if(!head)
        return true;
    else
    return false;
}

template <class T>
int LinkedList<T>::Size() {
    Node * NodePtr;
    int size = 1;
    if(!head)
        return 0;
    else{
        NodePtr = head;
        while(NodePtr->next){
            NodePtr = NodePtr->next;
            size = size + 1;
        }
    }
    return size;
}

template <class T>
T LinkedList<T>::SeeNext(){
    MyException e;
    if(!head)
        throw e;

    if(P == head){
        P = P->next;
        return head->value;
    }
    else if(P == nullptr){
        Reset();
        return P->value;
    }
    else {
        Node * NodePtr;

        NodePtr = P;
        P = P->next;
        return NodePtr->value;
    }
}

template <class T>
T LinkedList<T>::SeePrev(){
    MyException e;
    if(!head)
        throw e;

    if(P == head){
        P = P->prev;
        return head->value;
    }
    else if(P == nullptr){
        Reset();
        return P->value;
    }
    else {
        Node * NodePtr;

        NodePtr = P;
        P = P->prev;
        return NodePtr->value;
    }
}

template <class T>
T LinkedList<T>::SeeAt(int i) {
    MyException e;
    Node * NodePtr = P;
    int count = 0;

    if(!head)
        throw e;

    else if(i > Size() - 1 || i < 0)
        throw e;

    else if(i == 0){
        Reset();
        return head->value;
    }
    else{
    NodePtr = head;
        for (int z = 0; z < Size(); z++){
            if (count == i){
                P = NodePtr;
                return NodePtr->value;
                break;
            }
            count++;
            NodePtr = NodePtr->next;
        }
    }
    throw e;
}

template <class T>
void LinkedList<T>::Reset(){
    P = head;
}

template <class T>
void LinkedList<T>::display(){
  Reset();
  T viewer = SeeNext();
  do{
    viewer.Ascii();
    viewer = SeeNext();
  }while(viewer != head->value);
}


// task 2
class Item{
private:
    double SKU;
    string Description;
    double Price;
    string UOM;
    double QuantityOnHand;
    int LeadTime;
    struct Date {
        int day, month, year;
    };
    Date today = {03, 12, 2022};

public:
    Item(){
        SKU = 0;
        Description = "";
        Price = 0;
        UOM = "";
        QuantityOnHand = 0;
        LeadTime = 0;
    }

    Item(double a, string b, double c, string d, double e = 0){
        SKU = a;
        Description = b;
        Price = c;
        UOM = d;
        QuantityOnHand = e;
    }

    Item(double a){
        SKU = a;
    }

    string GetPartInfo(){
        string s = to_string(int(SKU));
        string info = s + ": " + Description;
        return info;
    }

    double GetPrice(){
        return Price;
    }

    bool InStock(){
        if(QuantityOnHand > 0)
            return true;
        else
            return false;
    }

    bool Available(Date day2){
        if (QuantityOnHand > 0)
            return true;
        else{
            if(day2.day < today.day + LeadTime)
                return true;
            else
                return false;
        }
    }

    void Ascii(){
      string output = "";
      int lengthofbox = 0;
      lengthofbox += Description.length() + (to_string(SKU)).length() + (to_string(Price)).length();
      
      for (int i = 0; i < (lengthofbox + 16); i++){
        output += "-";
      }
      output += "\n|" + Description + "|" + "SKU: " + to_string(SKU) + "|" + "PRICE: " + to_string(Price) + "|\n";
      for (int i = 0; i < (lengthofbox + 16); i++){
        output += "-";
      }
      cout << output << endl;
    }

    bool operator == (const Item & obj){
        if(SKU == obj.SKU)
            return true;
        else
            return false;
    };

    bool operator != (const Item & obj){
        if(SKU != obj.SKU)
            return true;
        else
            return false;
    };

    bool operator > (const Item & obj){
        if(SKU > obj.SKU)
            return true;
        else
            return false;
    };

    bool operator < (const Item & obj){
        if(SKU < obj.SKU)
            return true;
        else
            return false;
    };
};

// //////////////////////////////
#endif