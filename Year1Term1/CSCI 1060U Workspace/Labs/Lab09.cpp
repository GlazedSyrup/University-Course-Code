#include <iostream>
#include <string>

using namespace std;

class MoneySys{
    public:
        MoneySys(string n, int m);
        ~MoneySys();
        
        //
        void setName(string n) {name = n;};
        string getName() {return name;};
        void setMoney(int m) {money = m;};
        int getMoney() {return money;};
        void toString();

        //Pulls money out of nowhere
        void addMoney(int m) {money += m;};
        void removeMoney(int m) {money -= m;};
        //transfers money from one character/player to another
        void payMoney(MoneySys &p, int amt);
        //overloaded operator function
        friend ostream& operator<<(ostream& os, MoneySys p);
        friend bool operator==(MoneySys left, MoneySys right);
        friend bool operator<(MoneySys left, MoneySys right);
    private:
        string name;
        int money;
};



MoneySys::MoneySys(string n, int m){
    name = n;
    money = m;
}

MoneySys::~MoneySys(){
    cout << "Deconstructor called!" << endl;
}

//p1 transfers money to p2
void MoneySys::payMoney(MoneySys &p, int amt){
    money -= amt;
    p.money += amt;
}

//displays money information
void MoneySys::toString() {
    if (name == "NU"){
        cout << "The account has not been set up." << endl;
    }
    else{
         cout << (name + " bank account:" + to_string(money)) << endl;
    }
}

bool operator==(MoneySys left, MoneySys right){
    return ((left.name == right.name) && (left.money == right.money));
}

bool operator<(MoneySys left, MoneySys right){
    return ((left.money < right.money));
}

ostream& operator<<(ostream& os, MoneySys p){
    os << p.name << " has " << p.money;
    return os;
}



int main(){
    //Create an dynamic) Person variable
    MoneySys *p1 = new MoneySys("Thomas", 1000);
    MoneySys *p2 = new MoneySys("Alex", 1100);


    if(*p1 == *p2){
        cout << p1->getName() << " have been duplicated and are the same!" << endl;
    }
    else{
        cout << p1->getName() << " and " << p2->getName() << " have different accounts" << endl;
    }


    p1-> toString();
    p2-> toString();


    cout << p1->getName() << " gives $500 to " << p2->getName() << endl;
    p1->payMoney(*p2, 500);
    
    p1-> toString();
    p2-> toString();

    cout << p2->getName() << " gives $700 to " << p1->getName() << endl;
    p2->payMoney(*p1, 700);

    p1-> toString();
    p2-> toString();

    cout << p2->getName() << " buys a $20 soda " << endl;
    p2->removeMoney(20);

    p1-> toString();
    p2-> toString();

    cout << p1->getName() << " found a $20 bill " << endl;
    p1->addMoney(20);

    p1-> toString();
    p2-> toString();

    if(*p1 < *p2){
        cout << p1->getName() << " has less money than " << p2->getName() << endl;
    }
    else{
        cout << p1->getName() << " has more money than " << p2->getName() << endl;
    }

    p1-> toString();
    p2-> toString();

    delete p1;
    delete p2;
    
    return 0;
}

