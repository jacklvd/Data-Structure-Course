#ifndef SHOW_H
#define SHOW_H

#include <cstring>
#include <iostream>
using namespace std;

// Main/Base class
class Show {
  protected:
  string title, description;

  public:
  Show();
  Show(string, string);
  /////////////////////
  void setTitle(string);
  void setDescription(string);
  string getTitle();
  string getDescription();
  /////////////////////
  virtual void Play(){};
  virtual void showdetails(){};
  void details();
};

#endif

