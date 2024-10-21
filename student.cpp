#include "student.h"
#include <string>
#include <cstring>
#include <sstream>

Student::Student(const char * const name, int perm) {
  this->name = new char[strlen(name) +1]; //allocate memory for this->name
  strcpy(this->name, name); //copy name contents into this->name
  this->perm = perm; //set out perm to the given perm
}

int Student::getPerm() const {
  return this->perm; //return our perm
}

const char * const Student::getName() const {
  return this->name; //return our name
}

void Student::setPerm(const int permNumber) {
  this->perm = permNumber; //set our perm to permNumber
}

void Student::setName(const char * const name) {
  delete [] this->name; //delete our previous name memory
  this->name = new char[strlen(name)+1]; //allocate new memory for name
  strcpy(this->name, name); //copy contents of name into our name
}


Student::Student(const Student &orig) {
  this->name = new char[strlen(orig.name)+1]; //allocate memory for new name
  strcpy(this->name, orig.name); //copy contents of original name into our name
  this->perm = orig.perm; //copy original perm to our perm

}

Student::~Student() {
  delete [] name; //delete name memory
  
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this)  
    return (*this);

  this->name = new char[strlen(right.name)+1]; //allocate memory for our name
  strcpy(this->name, right.name); //copy contents of the right name into ours
  this->perm = right.perm; //copy right perm to ours

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::ostringstream oss; 
  oss << "[" << name << "," << perm << "]";
  return oss.str();
}

