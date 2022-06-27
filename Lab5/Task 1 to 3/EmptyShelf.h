#ifndef EMTYSHELF
#define EMTYSHELF
#include <iostream>  
#include <exception>  
using namespace std;  
class EmptyShelfException : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Shelf is empty!";  
        }  
};

#endif