// test_one.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : One junction operator, with the class notation.

#include <gs/junction_one.h>
#include <iostream>

int main()
{
  if (! ((gs::One<int>() << 16 << 27 << 11) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::One<int>() << 1 << 27 << 11) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::One<int>() << 6 << 7 << 9) > 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::One<int>() << 6 << 7 << 11) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::One<int>() << 10 << 6 << 7 << 11) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::One<int>() << 6 << 10 << 10) != 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! (gs::One<int>() << 6 << 7 << 9 < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::One<int>() << 6 << 7 << 9) > -1))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (!((gs::One<std::string>() << "testrere" << "etest") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::One<std::string>() << "test" << "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;
}
