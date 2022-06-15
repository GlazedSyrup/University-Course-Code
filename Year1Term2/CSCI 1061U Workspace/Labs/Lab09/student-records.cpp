#include <iostream>
#include <string>
#include <vector>
#include <ctime> // time()
#include <cstdlib> // srand(), rand()
#include <algorithm> // min_element(), max_element(), sort()




class Student{
protected:
    int number_;
    const int num_courses_;
    std::vector<int> grades_;
    std::string name_;

public:

    Student() : num_courses_(5){ }

    Student(const std::string& name, int number) : name_(name), number_(number), num_courses_(5){
        for (int i=0; i<num_courses_; ++i) {
            grades_.push_back(1 + (rand() % 100));
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& s){
        os << "Name = " << s.name_ << ", Number = " << s.number_;
        return os;
    }

    void print_grades() const{
        std::cout << "Grades: ";
        for (int i=0; i<num_courses_; ++i){
            if(i==num_courses_-1){
                std::cout << grades_[i];
            }else{
                std::cout << grades_[i] << ", ";
            }
        }
        std::cout << std::endl;
    }

    double compute_average(){
        double result;
        for (int i=0; i<num_courses_; ++i){
            result += grades_[i];
        }
        return (result/num_courses_);
    }

    std::string get_name(){
        return name_;
    }

};



std::string gen_name(){
    const char *Name1_alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    const char *Name2_vowels[12] = {"a", "e", "i", "o", "u", "y", "ia", "ie", "io", "oi", "ai", "oa"};
    const char *Name2_constants[64] = {"b", "br", "c", "cr", "ch", "ck", "d", "dr", "f", "fr", "g", "gr", "h", "j", "k", "kr", "l", "lr", "lm", "lt", "m", "mr", "ml", "n", "nr", "nl", "pr", "ph", "ps", "pm", "pl", "q", "r", "rp", "rs", "rd", "rk", "rl", "rc", "rn", "rm", "s", "sr", "st", "sp", "ss", "sd", "sh", "sk", "sl", "sb", "sn", "sm", "t", "ts", "tr", "tc", "th", "tl", "v", "w", "x", "z"};
    std::string name = "";
    bool vowel;
    name += Name1_alphabet[(rand() % 25)];
    if (name == "A" || name == "E" || name == "I" || name == "O" || name == "U" || name == "Y") {
        vowel = true;
    }else{
        vowel = false;
    }
    for(int i = 0; name.length() < 7; i++){
        if(vowel){
            name += Name2_constants[(rand() % 12)];
            vowel = false;
        }else{
            name += Name2_vowels[(rand() % 12)];
            vowel = true;
        }
    }


    return name;
  }

static int gen_number() {
    int result = 201100000+(rand() % 500000);
    return result;
}

std::vector<Student> SortGrade(std::vector<Student> students) {
    std::vector<Student> temp;
    std::vector<Student> newStu;
    int lowAve;
    for(int i = 0; i < 7; i++){
        lowAve = 0;
        for(int ii = 0; ii < students.size()+1; ii++){
            if(students[lowAve].compute_average() > students[ii].compute_average()){
                lowAve = ii;
            }
        }
        newStu.push_back(students[lowAve]);
        for(int ii = 0; ii < students.size(); ii++){
            if(students[ii].compute_average() != students[lowAve].compute_average()){
                temp.push_back(students[ii]);
            }else{
            }
        }
        students.clear();
        students.swap(temp);
    }
    return newStu;
}

std::vector<Student> sortNames(std::vector<Student> students) {
    char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    std::vector<Student> temp;
    std::vector<Student> newStu;
    int smallIndex = 25;
    int nextIndex;
    int index;
    for(int i = 0; i < 7; i++){
        nextIndex = 0;
        smallIndex = 25;
        for(int ii = 0; ii < students.size(); ii++){
            for(int iii = 0; iii < smallIndex; iii++){
                if((students[ii].get_name())[0] == alpha[iii]){
                    if(smallIndex > iii){
                        smallIndex = iii;
                        index = ii;
                    }
                }
            }
        }
        
        newStu.push_back(students[index]);
        for(int ii = 0; ii < students.size(); ii++){
            if(students[ii].get_name() != students[index].get_name()){
                temp.push_back(students[ii]);
            }else{
//                std::cout << students[ii] << std::endl;
            }
        }
        students.clear();
        students.swap(temp);
    }
    return newStu;
}


int main(){
    srand(time(NULL));
    std::vector<Student> students;
    for(int i = 0; i < 7; i++){
        Student student(gen_name(), gen_number());
        students.push_back(student); 
    }

    //call display function
    std::cout << "\nStudent Records:" << std::endl;
    for(int i = 0; i < 7; i++){
        std::cout << students[i] << students[i].compute_average() << std::endl;
    }
    //call sort_name function
    std::cout << "\n\n\nStudent Records: sort = name:" << std::endl;
    students = sortNames(students);
    for(int i = 0; i < 7; i++){
        std::cout << students[i] << ", Grade Average: " << students[i].compute_average() << std::endl;
    }
    
    //call sort_grade function
    students = SortGrade(students);
    std::cout << "\n\n\nStudent Records: sort = grade_average:" << std::endl;
    for(int i = 0; i < 7; i++){
        std::cout << students[i] << ", Grade Average: " << students[i].compute_average() << std::endl;
    }
    //call highest grade average
    int index = 0;
    std::string name = "";
    for(int i = 0; i < 7; i++){
        if(students[index].compute_average() < students[i].compute_average()){
            name = students[i].get_name();
            index = i;
        }
    }
    std::cout << "\n\nHighest Grade Average: " << students[index].compute_average() << "\n" << students[index] << std::endl;
    students[index].print_grades();





    return 0;
}