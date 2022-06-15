#include <iostream>
#include <fstream>
#include <time.h>

// Changes
// 
// 1. We can now generate a random data point (a double between 0 and 1)
// 2. We want to generate multiple random numbers each time we run the program
//    a. The user should be able to specify how many numbers she wants to create
//       i. Do we use command line arguments? 
//    b. How do we store these multiple values?
//       i. Perhaps we can use arrays to store these values.
//       ii. We don't know how many items user wants to save to the file?
//           I. This means we will have to use dynamic memory.  Use the 
//              `new` keyword.
//           II. Do not forget to delete unused memory. Use the `delete` keyword.
//       iii. We can now print the values as well (just for our own satisfaction)
//    c. We need to write these values to the file 


double gen_a_random_number()
{
    int n = rand();  // Creates an integer between 0 and RAND_MAX
    double v = ((double) n) / RAND_MAX;
    return v;
}

void gen_n_random_numbers(double* a, int n)
{
    for (int i=0; i<n; ++i) {
        a[i] = gen_a_random_number();
    }
}

void prn_vector(double* a, int n)
{
    for (int i=0; i<n; ++i) {
        std::cout << a[i] << " ";    
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    srand(time(NULL)); // Set the seed of the random number

    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " filename num-data" << std::endl;
        return -1;
    }

    std::ofstream fs(argv[1], std::ios::app | std::ios::binary);

    int num_data = atoi(argv[2]);
    double* a = new double[num_data]; // Allocating num_data doubles
    gen_n_random_numbers(a, num_data);

    std::cout << "Written the following values to the file:\n";
    prn_vector(a, num_data);

    fs.write((char*) a, num_data * sizeof(double));

    delete [] a; // Don't ever forget to delete unused memory

    fs.close();
    return 0;
}
