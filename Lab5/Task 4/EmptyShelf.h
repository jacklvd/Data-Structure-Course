#ifndef EMTYSHELF_H
#define EMTYSHELF_H
#include <iostream>  
#include <exception>  
using namespace std;  
class EmptyShelfException : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Collection is empty!";  
        }  
};

#endif