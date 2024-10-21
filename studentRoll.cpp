#include <string>
#include "studentRoll.h"
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* Next = new Node; //allocate memory for new Node
  Next->s = new Student(s); //create a deep copy of s
  Next->next = nullptr; //tail means there is no next node

  if(tail == nullptr) { //if list is empty, set head and tail
    head = Next;
    tail = Next;
  }
  else { //append the new Node to the end of the list
    tail->next = Next;
    tail = Next;
  }
}

std::string StudentRoll::toString() const {
  std::ostringstream oss;
  oss << "[";
  Node* current = head;
  while (current != nullptr) {
    oss << current->s->toString(); 
    if(current->next != nullptr) {
      oss << ",";
    }
    current = current->next;
  }
  oss << "]";
  return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = nullptr;
  tail = nullptr;
  Node* current = orig.head;
  while (current != nullptr) {
    insertAtTail(*(current->s));
    current = current->next;
  }
}

StudentRoll::~StudentRoll() {
  Node* current = head;
  while (current != nullptr) {
    Node* nextNode = current->next;
    delete current->s;
    delete current;
    current = nextNode;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) {
    return (*this);
  }
  Node* current = head;
  while (current != nullptr) {
    Node* nextNode = current->next;
    delete current->s;
    delete current;
    current = nextNode;
  }

  head = nullptr;
  tail = nullptr;
  // TODO... Here is where there is code missing that you need to 
  // fill in...
  current = right.head;
  while (current != nullptr) {
    insertAtTail(*(current->s));
    current = current->next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





