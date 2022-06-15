// str.cpp
#include "str.h"
#include <vector>
#include <cstring>
str::str() : _n(0), _buf(0){}

str::str(int n) : _n(n){
  _buf = new char[_n];
}

str::str(char ch) : _n(1){
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str){
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i=0; i<_n; ++i) _buf[i]=c_str[i];
}

str::~str(){
  if (_buf) delete [] _buf;
}

ostream& operator<<(ostream& os, const str& s){
  if (!s.is_empty()) {
    for (int i=0; i<s.length(); ++i) {
      cout << s[i];
    }
  }
  else cout << "[null str]";
  
  return os;
}

istream& operator>>(istream& is, str& s){
  char ch;
  do {
    ch = is.get();
    if (ch == ' ' || ch == '\n') break;
    s = s + ch;
  } while(true);

  return is;
}

// 1. TODO - assignment operator
const str& str::operator=(const str& s){
  return *this;
}


// 2. TODO - concatenation operator
str operator+(const str& a, const str& b){
  char str3[100];
  int i = 0;
  int j = 0;

  while (a[i] != '\0'){
    str3[j] = a[i];
    i++;
    j++;
  }
  i = 0;

  while (b[i] != '\0') {
    str3[j] = b[i];
    i++;
    j++;
  }
  str3[j] = '\0';

  return str3;  
}
