#include <iostream>

int valueFromUser() {
  std::cout << "Enter an integer: ";
  int input{};
  std::cin >> input;

  return input;
}

void printDouble(int value) {
  std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main() {
  int num{valueFromUser()};

  printDouble(num);

  return 0;
}
