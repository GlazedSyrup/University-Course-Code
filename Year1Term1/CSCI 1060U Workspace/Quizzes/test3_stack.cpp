#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class Stack {
  public:
    Stack();
    ~Stack();
    void push(int d);
    int pop();
    bool isEmpty() {return (top == NULL);};
    friend ostream& operator<<(ostream& os, Stack &s);
  private:
    Node *top;
};

Stack::Stack() {
  top = NULL;
}

Stack::~Stack() {
  //PART 2
    Node *temp = top->next;
    delete top;
    while (temp->next != NULL) {
        top = temp;
        temp = temp->next;
        delete top;
    }
    delete temp;
}

void Stack::push(int d) {
  Node *newtop = new Node;
  newtop->data = d;
  newtop->next = top;
  top = newtop;
}

int Stack::pop() {
    //PART 1
  if (!isEmpty()) {
    Node *temp = top;
    if (top->next == NULL){
      delete temp;
      return top->data;
    }
    else{
      top = top->next;
      delete temp;
      return top->data;
    }
  }
  else {
      cout << "ERROR: Stack is empty!\n";
      exit(1);
  }
}


ostream& operator<<(ostream& os, Stack &s) {
  //PART 3
    cout << "top -> ";
    Node *temp;
    if(temp->data == 0){
      cout << "NULL";
      return os;
    }
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    
  return os;
}


int main() {
  Stack *s = new Stack();
  cout<< *s << endl;
  s->push(5);
  cout<< *s << endl;
  s->push(3);
  cout<< *s << endl;
  while (!s->isEmpty()) {
    cout << "Stack content popped: " << s->pop() << endl;
  }
  cout<< *s << endl;
  delete s;
  return 0;
}