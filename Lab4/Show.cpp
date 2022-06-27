#include "Show.h"

Show::Show(){
  title = " ";
  description = " ";
};

Show::Show(string utitle, string udescription){
  title = utitle;
  description = udescription;
};

void Show::setTitle(string utitle){
  title = utitle;
};

void Show::setDescription(string udescription){
  description = udescription;
};

string Show::getTitle(){
  return title;
};

string Show::getDescription(){
  return description;
};

void Show::details(){
  cout << "Title: " << title << endl;
  cout << "Description: " << endl << description << endl << endl;
};