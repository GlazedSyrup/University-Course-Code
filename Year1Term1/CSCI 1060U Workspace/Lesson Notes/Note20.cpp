#include <iostream>
#include <string>

using namespace std;

//A composite structure for a person
struct Person {
    string firstname;
    string lastname;
    int age;
    bool employed;
};

Person* createPerson(string f, string l, int a, bool e);
    

int main(){
    //Create an automatic (ordinary) Person variable
    Person p;

    p.firstname = "Cookie";
    p.lastname = "Monster";
    p.age = 42;
    p.employed = true;

    cout << p.firstname << " " << p.lastname << " is a " << p.age << " year old." << endl;

    //create a dynamic Person variable
    Person *p2 = new Person;

    (*p2).firstname = "Big"; //there is a better was to do this
    p2->lastname = "Bird";
    p2->age = 89;
    p2->employed = true;

    cout << p2 -> firstname << " " << p2->lastname << " is a " << p2->age << " year old." << endl;

    delete p2;

    p2 = createPerson("Ernie", "LNU", 36, true);
    cout << p2 -> firstname << " " << p2->lastname << " is a " << p2->age << " year old." << endl;

    delete p2;

    return 0;
}

Person* createPerson(string f, string l, int a, bool e){
    Person *temp = new Person;
    temp->firstname = f;
    temp->lastname = l;
    temp->age = a;
    temp->employed = e;
    return temp;
}
