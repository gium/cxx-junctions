// test_all.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : All junction, with the class notation.

#include <gs/junction_all.h>
#include <iostream>

int main()
{
  if (! ((gs::All<int>() << 6 << 7 << 11) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::All<int>() << 6 << 7 << 11) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::All<int>() << 6 << 7 << 11) != 10)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::All<int>() << 6 << 7 << 9) < 10)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::All<int>() << 6 << 7 << 9) > -1)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::All<std::string>() << "test" << "test") == "test")
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::All<std::string>() << "test" << "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;
}
