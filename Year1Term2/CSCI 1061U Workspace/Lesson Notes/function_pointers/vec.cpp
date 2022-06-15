#include <iostream>

using std::cout;
using std::endl;

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

template<typename T>
void bubblesort(T& v)
{
    int n = v.len();

    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n-i-1; j++) {
            if (v[j] > v[j+1]) {
                v.swap(j, j+1);
            }
        }
    }
}

int main()
{
    srand(0);

    vec<float> v;
    for (int i=0; i<3; ++i) {
        v.push_back( 1.0 - (rand()*2.0)/RAND_MAX );
    }

    cout << "Before sorting." << endl;
    for (int i=0; i<v.len(); ++i) {
        cout << i << " = " << v[i] << endl;  // R-value operator (const)
    }

    bubblesort<vec<float> >(v);

    cout << "After sorting." << endl;
    for (int i=0; i<v.len(); ++i) {
        cout << i << " = " << v[i] << endl;  // R-value operator (const)
    }

    return 0;
}