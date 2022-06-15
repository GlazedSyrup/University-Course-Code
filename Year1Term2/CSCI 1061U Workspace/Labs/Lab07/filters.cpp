#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Filter{
protected:
  string _name;

public:  
  Filter(const string& name) : _name(name) {}
  virtual ~Filter() {};

  virtual string apply(const string& input) = 0;

  string get_name() { return _name; }
};

class Capitalize: public Filter{
public:
    Capitalize():Filter("Capitalize") {}

    ~Capitalize() {}

    string get_name() { return _name; }

    // Overriding 
    string apply(const string& input) {
        string text = "";
        for(int i = 0; input[i] != '\0'; i++){
            text += (char) toupper(input[i]);
        }
        return text;
    }
};

class CapitalizeFirstLetter: public Filter{
public:
    CapitalizeFirstLetter():Filter("CapitalizeFirstLetter") {}

    ~CapitalizeFirstLetter() {}

    string get_name() { return _name; }

    // Overriding 
    string apply(const string& input) {
        string text = "";
        for(int i = 0; input[i] != '\0'; i++){
            if(i==0){
                text += (char) toupper(input[i]);
            }
            else{
                text += input[i];

            }
        }
        return text;
    }
};

class CapitalizeFirstLetterOfEveryWord: public Filter{
public:
    CapitalizeFirstLetterOfEveryWord():Filter("CapitalizeFirstLetterOfEveryWord") {}

    ~CapitalizeFirstLetterOfEveryWord() {}

    string get_name() { return _name; }

    // Overriding 
    string apply(const string& input) {
        bool newWord = true;
        string text = "";
        for(int i = 0; input[i] != '\0'; i++){
            if(newWord){
                text += (char) toupper(input[i]);
                newWord = false;
            }
            else if(input[i] == ' '){
                text += (char) input[i];
                newWord = true;
            }
            else{
                text += (char) input[i];
            }
        }
        return text;
    }
};

class Obenglobish: public Filter{
public:
    Obenglobish():Filter("Obenglobish") {}

    ~Obenglobish() {}

    string get_name() { return _name; }

    // Overriding 
    string apply(const string& input) {
        bool vowel = false;
        bool newB = false;
        string text = "";
        for(int i = 0; input[i] != '\0'; i++){
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'){
                text += 'o';
                text += 'b';
                text += (char) input[i];
            }
            else{
                text += (char) input[i];
            }
        }
        return text;
    }
};

class ReverseString: public Filter{
public:
    ReverseString():Filter("ReverseString") {}

    ~ReverseString() {}

    string get_name() { return _name; }

    // Overriding 
    string apply(const string& input) {
        string text = "";
        int length = -1;
        for(int i = 0; input[i] != '\0'; i++){
            length++;
        }
        for(int i = 0; input[i] != '\0'; i++){
            text += (char) input[length];
            length--;
        }
        return text;
    }
};

class ToSmall: public Filter{
public:
    ToSmall():Filter("ToSmall") {}

    ~ToSmall() {}

    string get_name() { return _name; }

    // Overriding 
    string apply(const string& input) {
        string text = "";
        for(int i = 0; input[i] != '\0'; i++){
            text += (char) tolower(input[i]);
        }
        return text;
    }
};

class Randomize: public Filter{
public:
    Randomize():Filter("Randomize") {}

    ~Randomize() {}

    string get_name() { return _name; }

    // Overriding 
    string apply(const string& input) {
        string text = "";
        string temp2 = "";
        string temp = input;
        int length = -1;
        int randPos;
        srand(time(0));

        for(int i = 0; input[i] != '\0'; i++){
            length++;
        }

        for(int i = 0; input[i] != '\0'; i++){
            randPos = (rand()%length);
            text += (char) temp[randPos];
        
            for(int i = 0; temp[i] != '\0'; i++){
                if(i != randPos){
                    temp2 += (char) temp[i];
                }
            }

            temp = temp2;
            temp2 = "";
                       
            length--;
            if(length == 0){
                text += (char) temp[0];
                break;
            }
        }
        return text;
    }
};

int main(){

    const int num_filters = 7;
    Filter* filters[num_filters];

    filters[0] = new Capitalize();
    filters[1] = new CapitalizeFirstLetter();
    filters[2] = new CapitalizeFirstLetterOfEveryWord();
    filters[3] = new Obenglobish();
    filters[4] = new ReverseString();
    filters[5] = new ToSmall();
    filters[6] = new Randomize();
    
    string input;
    cout << "Enter string: ";  getline(cin, input);
    
    cout << "Input string: " << input << endl;
    for (int i=0; i<num_filters; ++i) {
    cout << "Filter name:  " << filters[i]->get_name() << endl;
    cout << "Output:       " << filters[i]->apply(input) << endl; 
    }

    for (int i=0; i<num_filters; ++i) delete filters[i];


    return 0;

}