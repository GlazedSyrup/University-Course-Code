#include <iostream>

using namespace std;

// TODO: Create a struct containing a string (element_name) and an bool (priority) as well as a node pointer (Node* next)
struct Node {
    string element_name;
    bool priority;
    Node *next;
};

// Queue class
class Queue {
    // --- public members ---
    public:
        // TODO: Constructor (with no parameters) - Creates an empty queue.
        Queue();
        // TODO: Deconstructor - Deletes the queue.
        ~Queue();
        // TODO: isEmpty - Checks if the queue is empty.
        bool isEmpty() {return (front == NULL);};
        // TODO: Enqueue - Adds a new Node to the Queue. The new Node should be added to the back of the queue.
        void enqueue(string d);
        // TODO: Priority Enqueue - Adds a new Node to the front of the Queue.
        // BONUS: [2 Marks] If there are already priority nodes in the Queue the new Node is added at the back of the priority nodes
        void priority_enqueue(string d);
        // TODO: Dequeue - Deletes a Node from the Queue. The Node deleted should be from the front of the queue (and it should return the element_name of the deleted Node)
        bool dequeue();
        // TODO: toString - Returns a string containing the contents of the queue from the back Node to the front Node. For example:
        //           [Yoda] -> [R2D2] -> [Solo]
        void toString();
    // --- private members ---
    private:
        // TODO: Node* front - a pointer to the front of the Queue
        Node *front;
        // TODO: Node* back - a pointer to the back of the Queue
        Node *back;
};

Queue::Queue(){
    front = NULL;
}

Queue::~Queue(){
    Node *temp = front->next;
    delete front;
    while (temp->next != NULL) {
        front = temp;
        temp = temp->next;
        delete front;
    }
    delete temp;
}

void Queue::enqueue(string d){
    if (isEmpty()) {
        front = new Node;
        front->element_name = d;
        front->next = NULL;
    } else {
        Node *newfront = front;
        while (newfront->next != NULL) {
            newfront = newfront->next;
        }
        newfront->next = new Node;
        newfront->next->element_name = d;
        newfront->next->next = NULL;
    }
}

void Queue::priority_enqueue(string d){
    //If the list is empty
    if (isEmpty()) {
        front = new Node;
        front->element_name = d;
        front->next = NULL;
    } else {
        //If list is not empty
        Node *newfront = new Node;
        newfront->element_name = d;
        newfront->next = front;
        front = newfront;
    }
}

bool Queue::dequeue(){
    if (isEmpty()) {
        return false;
    }
    else{
        Node *current = back;
        if (back->element_name == front->element_name){
            front = NULL;
            delete current;
            return true;
        }
        return false;
    }
}

void Queue::toString(){
    //display contents of list
    cout << "front -> ";
    if(isEmpty()){
        cout << "NULL" << endl;
    }
    else{
        Node *current = front;
        while(current != NULL){
            cout << current->element_name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {

    Queue* q = new Queue();

    q->enqueue("Solo");
    q->enqueue("R2D2");
    q->enqueue("Yoda");
    q->priority_enqueue("BB8");

    q->toString();

    q->dequeue();

    q->toString();

    delete q;

    return 0;
}