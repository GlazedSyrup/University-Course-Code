#include <iostream>
#include <vector>

using namespace std;


template <class T>
class Stats{
protected:
    T* _mem; // storage pointer
    int _n;  // # of slots of storage free 
    int _i;  // Next slot to fill 

public:
    Stats();
    virtual ~Stats();

    const T average();
    const T min();
    const T max();
    void add(const T& v);

    const T& operator[](int i) const;
    T& operator[](int i);

    friend ostream& operator<<(ostream& o, const Stats<T>& a){
        for (int i=0; i<a.len(); ++i){
            o << a[i] << endl;
        }
        return o;        
    }
};

template<class T>
Stats<T>::Stats()
: _mem(0), _n(-1), _i(0)
{}


template<class T>
Stats<T>::~Stats()
{
    if (_mem) delete [] _mem;
}

template<class T>
void Stats<T>::add(const T& v){
    if (_n < _i){
        if (_n < 0){
            _mem = new T[10];
            _n = 10;
        }
        else {
            T* _tmp = new T[_n+10];
            for (int i=0; i<_n; ++i){
                _tmp[i] = _mem[i];
            }
            delete [] _mem;
            _mem = _tmp;
            _n += 10;
        }
    }
    _mem[_i] = v;
    ++_i;
}

template<class T>
const T Stats<T>::average(){
    T sum = 0;
    for(int i = 0; i < _i; i++){
        sum += _mem[i];
    }
    return   T (sum/_i);
}

template<class T>
const T Stats<T>::min(){
    T s = _mem[0];
    for(int i = 0; i < _i; i++){
        if(s > _mem[i]){
            s = _mem[i];
        }
    }

    return s;
}

template<class T>
const T Stats<T>::max(){
    T s = _mem[0];
    for(int i = 0; i < _i; i++){
        if(s < _mem[i]){
            s = _mem[i];
        }
    }

    return s;
}



template<typename T>
const T& Stats<T>::operator[](int i) const{
    return _mem[i];
}

template<typename T>
T& Stats<T>::operator[](int i){
    return _mem[i];
}


int main(){
    Stats<short> s1 = Stats<short>();
    Stats<int> s2 = Stats<int>();
    Stats<double> s3 = Stats<double>();
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s1.add(4);
    s1.add(5);
    s1.add(6);
    s2.add(1);
    s2.add(2);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    s2.add(6);
    s3.add(1);
    s3.add(2);
    s3.add(3);
    s3.add(4);
    s3.add(5);
    s3.add(6);

    cout << "shorts average: " << s1.average() << endl;
    cout << "shorts min: " << s1.min() << endl;
    cout << "shorts max: " << s1.max() << endl;
    cout << "ints average: " << s2.average() << endl;
    cout << "ints min: " << s2.min() << endl;
    cout << "ints max: " << s2.max() << endl;
    cout << "doubles average: " << s3.average() << endl;
    cout << "doubles min: " << s3.min() << endl;
    cout << "doubles max: " << s3.max() << endl;

    return 0;
}