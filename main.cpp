#include <iostream>
#include "array.h"

int main() {
  Array<int> arr {1, 2};
  
  arr.each([](int o) {
    std::clog << o << std::endl;
  });
  
  Array<int> results = arr.map<int>([](const int& o) {
    return o + 10;
  });
  
  results.each([](int o) {
    std::clog << o << std::endl;
  });
      
  int result = results.reduce<int>(0, [](int& m, int o) {
    m += o;
    return m;
  });
  
  std::clog << result << std::endl;
  std::clog << arr[1] << std::endl;
}

