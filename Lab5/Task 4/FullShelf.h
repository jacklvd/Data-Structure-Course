#ifndef FULLSHELF_H
#define FULLSHELF_H
#include <iostream>  
#include <exception>  
using namespace std;  
class FullShelfException : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Collection is full!";  
        }  
        //http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/
};

#endif