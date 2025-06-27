#include <iostream>

int getNumber() {

  std::cout << "Enter your number: ";

  int num{};
  std::cin >> num;

  return num;
}

int main() {

  int num{getNumber()};

  std::cout << "Your number doubled is: " << num * 2 << '\n';

  return 0;
}
