// junction.h - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : All junction, with the variadic templated function notation (C++0x).

#include <junction.h>
#include <iostream>

int main()
{
  if (! (gs::all(6, 7, 11) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! (gs::all(6, 7, 11) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (gs::all(6, 7, 11) != 10)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (gs::all(6, 7, 9) < 10)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (gs::all(6, 7, 9) > -1)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (gs::all("test","test") == "test")
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! (gs::all("test",  "tst") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;
}