#ifndef FULLSHELF
#define FULLSHELF
#include <iostream>  
#include <exception>  
using namespace std;  
class FullShelfException : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Shelf is full!";  
        }  
        //http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/
};

#endif