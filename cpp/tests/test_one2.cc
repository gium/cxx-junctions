// test_one2.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : One junction operator, with the function notation.

#include <gs/junction_one.h>
#include <iostream>

int main()
{
  if (!((gs::one(16) << 17 << 11) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::one(6) << 17 << 11) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::one(6) << 17 << 9) > 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::one(6) << 7 << 11 << 10) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (!((gs::one(11) << 6 << 7 << 11) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::one(6) << 10 << 10) != 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::one(6) << 7 << 9) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::one(6) << 7 << 9) > -1))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (! ((gs::one("testrere") << "etest") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::one("test") << "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;
}
