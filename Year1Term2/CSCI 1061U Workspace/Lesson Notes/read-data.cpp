#include <iostream>
#include <fstream>

int main(int argc, char** argv){
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " filename" << std::endl;
        return -1;
    }

    std::ifstream fs(argv[1], std::ios::binary);

    double v;
    std::cout << "Read a (scalar):\n";
    fs.read((char*) &v, sizeof(double));
    std::cout << v << std::endl;

    fs.close();
    return 0;
}