// test_any2.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : Any junction operator, with the function notation.

#include <gs/junction_any.h>
#include <iostream>

int main()
{
  if (((gs::any(6) << 7 << 11) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::any(6) << 7 << 9) > 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::any(6) << 7 << 11) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::any(10) << 6 << 7 << 11) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::any(6) << 10 << 10) != 10)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::any(6) << 7 << 9) < 10)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::any(6) << 7 << 9) > -1)
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::any("testrere") << "etest") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::any("test") << "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;
}
