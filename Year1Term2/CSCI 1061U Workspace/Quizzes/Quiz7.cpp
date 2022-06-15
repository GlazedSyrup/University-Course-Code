template<class T>
class Pair
{
public:
    Pair( );
    Pair(T firstValue, T secondValue);

    T first;
    T second;
};

template<class T>
Pair<T>::Pair(T firstValue, T secondValue)
{
    first = firstValue;
    second = secondValue;
}

//firstoption
/*
template<class T, class U>
class Pair
{
public:
    Pair( );
    Pair(T firstValue, U secondValue);

    T first;
    U second;
};

template<class T, class U>
Pair<T>::Pair(T firstValue, U secondValue)
{
    first = firstValue;
    second = secondValue;
}
*/


//secondOption
/*
template<class T>
class Pair
{
public:
    Pair( );
    Pair(T firstValue, U secondValue);

    T first;
    T second;
};

template<class T>
Pair<T>::Pair(T firstValue, U secondValue)
{
    first = firstValue;
    second = secondValue;
}
*/