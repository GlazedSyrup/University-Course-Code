#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T>
class vec
{
    protected:
    T* _data;
    int _size;
    int _next;

    public:
    vec() : _size(100), _next(0) {
        _data = new T[_size];
    }
    virtual ~vec() {
        if (_data) delete [] _data;
        _data = 0;
    }

    inline int max_size() { return _size; }
    inline int len() { return _next; }

    void push_back(const T& val) {
        _data[_next] = val;
        ++_next;
    }

    inline T& operator[](int i) { return _data[i]; }  // L-value
    inline const T& operator[](int i) const { return _data[i]; } // R-value

    void swap(int i, int j) {
        T tmp = this->operator[](i);
        this->operator[](i) = this->operator[](j);
        this->operator[](j) = tmp;
    }
};

// template<typename T>
// void swap(T& a, T& b) 
// {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }

template<typename T, typename U>
void bubblesort(T& v, bool (*cmp)(U&,U&) )
{
    int n = v.len();

    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n-i-1; j++) {
            if (cmp(v[j], v[j+1])) {
                v.swap(j, j+1);
            }
        }
    }
}

class Person {
    public:
    string _firstname;
    string _lastname; 
    int _age;

    Person() {}
    Person(string firstname, string lastname, int age)
        : _firstname(firstname), _lastname(lastname), _age(age)
        {}

    friend ostream& operator<<(ostream& o, const Person& p) {
        o << p._firstname << ", " << p._lastname << ", " << p._age;
        return o;
    }
};

bool compare_age(Person& a, Person& b)
{
    return a._age < b._age;
}

bool compare_age_increasing(Person& a, Person& b)
{
    return a._age > b._age;
}

bool compare_firstname(Person& a, Person& b)
{
    return a._firstname > b._firstname;
}

int main()
{
    vec<Person> v;

    Person superman("Clark", "Kent", 33);
    Person captain_marvel("Carol", "Denver", 24);
    Person galactus("Galan", "", 100000);

    v.push_back(superman);
    v.push_back(captain_marvel);
    v.push_back(galactus);

    cout << "Before sorting." << endl;
    for (auto i=0; i<v.len(); ++i) {
        cout << i << " = " << v[i] << endl;  // R-value operator (const)
    }

    bubblesort<vec<Person>, Person>(v, [](Person& a, Person& b)->bool{ return a._lastname > b._lastname; });

    cout << "After sorting." << endl;
    for (auto i=0; i<v.len(); ++i) {
        cout << i << " = " << v[i] << endl;  // R-value operator (const)
    }

    return 0;
}