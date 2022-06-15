// setw example
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw

int main () {
  std::cout << std::setfill (' ') << std::setw (3) << "|" << std::setfill (' ') << std::setw (3) << "|" << std::endl;
  std::cout << std::setfill ('-') << std::setw (3) << "|" << std::setfill ('-') << std::setw (3) << "|" << std::setfill ('-') << std::setw (3) << " " << std::endl;
  std::cout << std::setfill (' ') << std::setw (3) << "|" << std::setfill (' ') << std::setw (3) << "|" << std::endl;
  std::cout << std::setfill ('-') << std::setw (3) << "|" << std::setfill ('-') << std::setw (3) << "|" << std::setfill ('-') << std::setw (3) << " " << std::endl;
  std::cout << std::setfill (' ') << std::setw (3) << "|" << std::setfill (' ') << std::setw (3) << "|" << std::endl;
  return 0;
}