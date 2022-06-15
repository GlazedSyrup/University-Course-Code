//LinkedList class in C++
#include <iostream>
#include <string>

using namespace std;

//A Node structure that is used to build the LinkedList
struct Node {
    string data;
    Node *next;
};

class LinkedList {
    public:
        LinkedList(); //constructor
        ~LinkedList(); //deconstructor
        bool isEmpty() { return (head == NULL);};
        void addFront(string d); //Add data to front of list
        void addBack(string d); //Add data to back of list
        bool remove(string d); //Remove first node with data d
        void displayList(); //Display the contents of the LinkedList
        void operator=(const LinkedList& right_side);
        //Other functions getHead, getNode(string d)
    private:
        Node *head; //the head points to the front of the list
};


LinkedList::LinkedList() {
    //Set the list to be empty
    head = NULL; //this means head is undefined (i.e. points nowhere)
}

LinkedList::~LinkedList() {
    //Delete all nodes in the list
    Node *temp = head->next;
    delete head;
    while (temp->next != NULL) {
        head = temp;
        temp = temp->next;
        delete head;
    }
    delete temp;
}


void LinkedList::addFront(string d) {
    //If the list is empty
    if (isEmpty()) {
        head = new Node;
        head->data = d;
        head->next = NULL;
    } else {
        //If list is not empty
        Node *newhead = new Node;
        newhead->data = d;
        newhead->next = head;
        head = newhead;
    }
}

void LinkedList::addBack(string d) {
    //If the list is empty
    if (isEmpty()) {
        head = new Node;
        head->data = d;
        head->next = NULL;
    } else {
        //If list is not empty
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node;
        current->next->data = d;
        current->next->next = NULL;
    }
}

bool LinkedList::remove(string d){
    if (isEmpty()) {
        return false;
    }
    else{
        Node *current = head;
        if (head->data == d){
            head = head->next;
            delete current;
            return true;
        }
        else{
            while (current->next != NULL){
                if(current->next->data == d){
                    Node *temp = current->next;
                    current->next = current->next->next; // or temp->next
                    delete temp;
                    return true;
                }
                current = current->next;
            }
            return false; //end of LinkedList
        }
    }
}

void LinkedList::displayList(){
    //display contents of list
    cout << "head -> ";
    if(isEmpty()){
        cout << "NULL" << endl;
    }
    else{
        Node *current = head;
        while(current != NULL){
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}

void LinkedList::operator=(const LinkedList& right_side) {
  //Node *current;
  Node *current_right = right_side.head;
  while (current_right != NULL) {
    //copy current_right into the list
    addBack(current_right->data);
    current_right = current_right->next;
  }
}


int main() {
    LinkedList *l = new LinkedList();
    l->displayList();
    l->addFront("apple");
    l->displayList();
    l->addFront("banana");
    l->displayList();
    l->addFront("orange");
    l->displayList();
    l->addFront("banana");
    l->displayList();
    l->addBack("kiwi");
    l->displayList();
    l->remove("orange");
    l->displayList();
    l->remove("kiwi");
    l->displayList();
    l->remove("banana");
    l->displayList();
    LinkedList *l2 = new LinkedList;
    *l2 = *l;
    cout << "List 2:";

    delete l;
    return 0;
}