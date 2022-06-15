#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  ifstream in(argv[1], ios::binary);
  ofstream out(argv[2], ios::binary);

  if ( !in.is_open() ) {
    cerr << "Cannot open " << argv[1] << endl;
    return -1;
  }

  char buf[1000];
  while (true)
  {
    // Read upto 1000 bytes
    in.read(buf, 1000);
    
    // Number of actual bytes read
    
    //fix the line below
    int n_read = in.gcount();
    
    
    cout << "Read " << n_read << " bytes." << endl;

    // If no more bytes to read, break this loop
    if (n_read <= 0) break;

    // Otherwise write out the read bytes to the output file 
    out.write(buf, n_read);
  }
  
  in.close();
  out.close();
}