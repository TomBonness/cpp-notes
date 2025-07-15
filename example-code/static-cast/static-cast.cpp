#include <iostream>

int main() {

  std::cout << "Enter a single character: \n";
  std::int8_t userInt{};
  std::cin >> userInt;

  std::cout << "You entered " << userInt << " which has ASCII code "
            << static_cast<int>(userInt) << "\n";
}
