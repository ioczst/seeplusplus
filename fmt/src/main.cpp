#include <iostream>
#include <fmt/core.h>
#include <cstring>

int main()
{
  // fmt::print("The answer is {}.", 42);
  char *myString1 = "Hello";
  std::string myString2 = "Hello, world!";

  fmt::print("The answer is {}.\n", myString1);
  fmt::print("The answer is {}.\n", myString2);


  return 0;
}