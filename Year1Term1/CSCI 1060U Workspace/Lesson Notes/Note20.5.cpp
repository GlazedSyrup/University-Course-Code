#include <iostream>
#include <string>

using namespace std;


//A class for person
class Person {
  public:
    Person(); //a default constructor
    Person(string f, string l, int a, bool e);
    ~Person(); //a destructor
    string toString();
    void setFirstName(string f) {firstName = f;};
    string getFirstName() {return firstName;};
    void setLastName(string l) {lastName = l;};
    string getLastName() {return lastName;};
    bool setAge(int a); //mutator function
    int getAge(); //accessor function
    bool ageDefined();
    void setEmployed(bool e) {employed = e;};
    bool isEmployed() {return employed;};
    bool isEqual(Person other);
    friend bool isEqual(Person p1, Person p2);
    friend bool operator==(Person left, Person right);
    friend ostream& operator<<(ostream& os, Person p);
  private:
    string firstName;
    string lastName;
    int age;
    bool employed;
};

Person::Person() {
  firstName = "FNU";
  lastName = "LNU";
  age = -1; //-1 means age undefined
  employed = false;
}

Person::Person(string f, string l, int a, bool e) {
  firstName = f;
  lastName = l;
  age = a;
  employed = e;
}

Person::~Person() {
  //Normally destructor is used to delete any dynamic member variables
  cout << "Destructor called!" << endl;
}

string Person::toString() {
  string pstring = "";

  //add values of member variables to the pstring
  if (ageDefined()) {
  pstring += firstName + " " + lastName
          + " is a " + to_string(age) + " year old who is ";
  } else {
    pstring += firstName + " " + lastName
            + " of an unknown age who is ";
  }
  if (employed) {
    pstring += "employed.\n";
  } else {
    pstring += "unemployed.\n";
  }

  return pstring;
}

bool Person::setAge(int a) {
  if ((a < -1) || (a > 150)) {
    return false;
  } else {
    age = a;
    return true;
  }
}

int Person::getAge() {
  return age;
}

bool Person::ageDefined() {
  /*if (age != -1)
    return true;
  else
    return false;*/
  return (age != -1);
}

bool Person::isEqual(Person other) {
  return ((firstName == other.firstName)
          && (lastName == other.lastName)
          && (age == other.age));
}

bool isEqual(Person p1, Person p2) {
  return ((p1.firstName == p2.firstName)
          && (p1.lastName == p2.lastName)
          && (p1.age == p2.age));
}

bool operator==(Person left, Person right) {
  return ((left.firstName == right.firstName)
          && (left.lastName == right.lastName)
          && (left.age == right.age));
}

ostream& operator<<(ostream& os, Person p) {
  if (p.ageDefined()) {
    os << p.firstName << " " << p.lastName
      << " (" << p.age << ")";
  } else {
    os << p.firstName << " " << p.lastName
      << " (?)";  }
  return os;
}

int main() {
  //Create a dynamic Person variable
  Person *p1 = new Person();
  p1->setFirstName("Cookie");
  p1->setLastName("Monster");
  p1->setEmployed(false);
  cout << *p1 << endl;

  Person *p2 = new Person("Big", "Bird", 81, false);
  cout << p2->toString();

  if (p2->isEqual(*p1)) {
    cout << *p2 << " and " << *p1 << " are the same!"
         << endl;
  } else {
    cout << *p2 << " and " << *p1 << " are not the same!"
         << endl;
  }

  //if (isEqual(*p1, *p1)) {
  if (*p1 == *p1) {
    cout << p1->getFirstName() << " and "
         << p1->getFirstName() << " are the same!"
         << endl;
  } else {
    cout << p1->getFirstName() << " and "
         << p1->getFirstName() << " are not the same!"
         << endl;
  }

  delete p1;
  delete p2;

  return 0;
}