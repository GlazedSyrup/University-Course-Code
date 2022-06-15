#include <iostream>

//using namespace std;
//all names in


using std::cout; //use the cout name frome std in this program
//using std::endl;


namespace one {

    void alex();

}
namespace two {

    void alex();

}


int main() {
    
    int temp = 5;
    {
        using std::endl; //use the cout name from std in this program
        cout << "temp is " << temp << endl;

    }



    //using the scope resolution operator below applies only to This
    //one endl
    cout << "This is a test." << std::endl;

    one::alex();
    two::alex();

    return 0;

}

namespace one {
    
    void alex(){
        cout << "Hi Alex S glad to see you in class\n"; //\n does 
                                                        // 
    }
}
namespace two {
    
    void alex(){
        cout << "Hi Alex T glad to see you in class\n"; //\n does 
                                                        // 
    }
}