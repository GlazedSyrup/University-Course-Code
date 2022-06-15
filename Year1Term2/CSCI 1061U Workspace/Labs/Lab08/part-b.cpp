//LinkedList class in C++
#include <iostream>
#include <string>

using namespace std;

//Node structure
template <class T>
struct Node {
    T data;
    Node<T> *next;
};

template <class T>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty() { return (head == NULL);};
        void add(T d); //Add data to the list
        bool remove(T d); //Remove first node 
        void show(); //Display the contents
        void operator=(const LinkedList& right_side);
    private:
        Node<T> *head;
};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T> *temp = head->next;
    delete head;
    while (temp->next != NULL) {
        head = temp;
        temp = temp->next;
        delete head;
    }
    delete temp;
}

template <class T>
void LinkedList<T>::add(T d) {
    //If the list is empty
    if (isEmpty()) {
        head = new Node<T>;
        head->data = d;
        head->next = NULL;
    } else {
        //If list is not empty
        Node<T> *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node<T>;
        current->next->data = d;
        current->next->next = NULL;
    }
}

template <class T>
bool LinkedList<T>::remove(T d){
    if (isEmpty()) {
        return false;
    }
    else{
        Node<T> *current = head;
        if (head->data == d){
            head = head->next;
            delete current;
            return true;
        }
        else{
            while (current->next != NULL){
                if(current->next->data == d){
                    Node<T> *temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    }
}

template <class T>
void LinkedList<T>::show(){
    cout << "{ ";
    if(isEmpty()){
        cout << "NULL" << endl;
    }
    else{
        Node<T> *current = head;
        while(current != NULL){
            cout << current->data << ", ";
            current = current->next;
        }
        cout << "}" << endl;
    }
}

template <class T>
void LinkedList<T>::operator=(const LinkedList& right_side) {
  Node<T> *current_right = right_side.head;
  while (current_right != NULL) {
    add(current_right->data);
    current_right = current_right->next;
  }
}


int main() {
    LinkedList<int> li;
    for (int i = 10; i > 0; --i) {
        li.add(i);
    }
    li.show();

    li.remove(10);
    li.remove(5);
    li.remove(1);
    li.show();

    return 0;
}
