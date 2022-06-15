#ifndef __arr_h__
#define __arr_h__

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

template <class T>
class MyArr
{
    protected:
    T* _mem; // Pointer to storage
    int _n;  // Number of slots available in the storage 
    int _i;  // Next slot to fill 

    public:
    MyArr();
    virtual ~MyArr();

    void push_back(const T& v);
    const T& operator[](int i) const;
    T& operator[](int i);

    friend ostream& operator<<(ostream& o, const MyArr<T>& a) {
        for (int i=0; i<a.len(); ++i) {
            o << a[i] << endl;
        }
        return o;        
    }

    int len() const { return _i; }   // Provides the number of items in this array
    int size() const { return _n; }  // Provides the size of the underlying container
};

template<class T>
MyArr<T>::MyArr()
: _mem(0), _n(-1), _i(0)
{}

template<class T>
MyArr<T>::~MyArr()
{
    if (_mem) delete [] _mem;
}

// There is a subtle error here.  I will let you find and fix it.
template<class T>
void MyArr<T>::push_back(const T& v)
{
    if (_n < _i) {                                                  // Check if next slot is valid 
        if (_n < 0) {                                               // Case when no memory was ever allocated    
            _mem = new T[10];
            _n = 10;
        }
        else {                                                      // Need to allocate more memory
            T* _tmp = new T[_n+10];
            for (int i=0; i<_n; ++i) { _tmp[i] = _mem[i]; }         // Copy existing data
            delete [] _mem;                                         // Don't forget to delete the current memory
            _mem = _tmp;                                            // Store pointer to the newly allocated memory
            _n += 10;                                               // New number of slots
        }
    }
    _mem[_i] = v;                                                    // Store in next slot
    ++_i;                                                            // Update the slot 
}

template<typename T>
const T& MyArr<T>::operator[](int i) const
{
    return _mem[i];
}

template<typename T>
T& MyArr<T>::operator[](int i)
{
    return _mem[i];
}


#endif