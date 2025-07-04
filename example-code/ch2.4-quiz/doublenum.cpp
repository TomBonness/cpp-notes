#include <iostream>

int userInput() {
  std::cout << "Input your number to double: ";
  int toDouble;
  std::cin >> toDouble;
  return toDouble;
}

int doubleNum(int x) {
  int doubled{x * 2};
  return doubled;
}

int main() { std::cout << doubleNum(userInput()); }
