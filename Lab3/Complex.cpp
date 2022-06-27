#include <math.h>
#include <iostream>
#include "Complex.h"
using namespace std;


// constructor
Complex::Complex(){
  double a = b = angle = r = 0;
}

// initialized variables
Complex::Complex(double real, double imaginary){
  a = real;
  b = imaginary;
  calculateR();
  calculateAngle();
}

// initialized variables
Complex::Complex(double x, double y, bool mode){
  if (mode == true){
    r = x;
    angle = y;
    a = r * cos(angle);
    b = r * sin(angle);
  }else{
    a = x;
    b = y;
    calculateR();
    calculateAngle();
  }
}

//////Initialize set and get functions/////
void Complex::setA(double real){
  a = real;
}

void Complex::setB(double imaginary){
  b = imaginary;
}

void Complex::setAngle(double ang){
  angle = ang;
}

void Complex::setR(double distance){
  r = distance;
}

double Complex::getA(){
  return a;
}

double Complex::getB(){
  return b;
}

double Complex::getAngle(){
  return angle;
}

double Complex::getR(){
  return r;
}
//////////////////////////////////////////


// calculate r value
void Complex::calculateR(){
  r = sqrt((a * a) + (b * b));
}

// calculate angle value
void Complex::calculateAngle(){
  angle = tan(b / a);
}

// display the result
void Complex::display(){
  if (b > 0) {
    cout << a << " + " << b << "i\n" << "\t\tr: " << r << ", theta: " << angle << endl << endl;
  } else {
    cout << a << b << "i\n" << "\t\tr: " << r << ", theta: " << angle << endl << endl;
  }
}

// override the addition operation
void Complex::operator+ (Complex lhs){
  a += lhs.getA();
  b += lhs.getB();
  calculateR();
  calculateAngle();
}

// override the subtraction operation
void Complex::operator- (Complex lhs){
  a -= lhs.getA();
  b -= lhs.getB();
  calculateR();
  calculateAngle();
}

// override the multiply operation
void Complex::operator* (double scalar){
  a *= scalar;
  b *= scalar;
  calculateR();
  calculateAngle();
}

// override the divide operation
void Complex::operator/ (double scalar){
  a /= scalar;
  b /= scalar;
  calculateR();
  calculateAngle();
}

// compare two complex number to see whether they are equivalent
bool Complex::operator== (Complex lhs){
  if ((a == lhs.getA() && (b == lhs.getB()))){
    return true;
  }else{
    return false;
  }
}