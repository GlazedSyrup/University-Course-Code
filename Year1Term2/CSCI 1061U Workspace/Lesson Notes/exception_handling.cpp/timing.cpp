#include <iostream>
#include <iomanip> // std::setprecision
#include <chrono>
using namespace std;

int arr_sum(int a[], int n)
{
  int sum = 0;
  for (int i=0; i<n; ++i) {
    sum += a[i];
  }
  return sum;
}

int main()
{
  int n = 1000000000;
  int* arr = new int[n];
  for (int i=0; i<n; ++i) {
    arr[i] = i;
  }
  cout << endl;

  auto t_start = std::chrono::high_resolution_clock::now();
  arr_sum(arr, n);
  auto t_end = std::chrono::high_resolution_clock::now();  

  cout << std::fixed
       << std::setprecision(2)
       << "Time (using chrono()) = "
       << std::chrono::duration<double, std::milli>(t_end-t_start).count()
       << " ms"
       << endl;
  
  delete [] arr;
  
  return 0;
}