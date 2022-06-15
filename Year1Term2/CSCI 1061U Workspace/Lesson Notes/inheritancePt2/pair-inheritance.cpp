#include <iostream>
#include <string>

// Pulling only these things from the std namespace
using std::cout;
using std::cin;
using std::endl;
using std::string;

// T, U, V, Z, W, X, Y <-- convention
template<typename U, typename V>
class Pair
{
    protected:
    U _first;
    V _second;

    public:
    Pair() {}
    Pair(const U& name, const V& number) : _first(name), _second(number) {}
    Pair(const Pair& o) {
        _first = o._first;
        _second = o._second;
    }

    void set_first(const U& first) { _first = first; }
    void set_second(const V& second) { _second = second; }

    const U& get_first() const { return _first; }
    const V& get_second() const { return _second; }
};

// Inheritance - case 1
template <class U, class V>
class Pair1 : public Pair<U, V>
{
    public:
    void hello_world() { cout << "Hello world." << endl;; }
};

// Inheritance - case 2
template <class U>
class Pair2 : public Pair<int, U>
{
    public:
    void hello_space() { cout << "Hello space." << endl;; }
};

// Inheritance - case 3
class Pair3 : public Pair<int, double>
{
    public:
    void hello_universe() { cout << "Hello universe." << endl;; }
};


typedef Pair<string, int> P1;
typedef Pair<string, Pair<int, string> > P2;

int main()
{
    Pair1<int, int> p1;
    p1.hello_world();

    Pair2<string> p2;
    p2.hello_space();

    Pair3 p3;
    p3.hello_universe();

    P1 adam("Adam", 10032883);
    P1 eve("Eve", 10032843);
    cout << "adam: (" << adam.get_first() << ", " << adam.get_second() << ")" << endl;
    cout << "eve: (" << eve.get_first() << ", " << eve.get_second() << ")" << endl;

    Pair<int, int> coord(2, 3);
    cout << "coord: (" << coord.get_first() << ", " << coord.get_second() << ")" << endl;

    P2 student;
    student.set_first("David Bowie");
    student.set_second(Pair<int, string>(1, "Space Oddity"));

    cout << student.get_first() << endl;
    cout << student.get_second().get_first() << endl;
    cout << student.get_second().get_second() << endl;

    return 0;
}