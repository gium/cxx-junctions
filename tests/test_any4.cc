// test_any4.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : Any junction operator, with the variadic templated function interface (C++0x).

#include <gs/junction_any.h>
#include <iostream>

int main()
{
  if ((GS_ANY_3(6, 7, 11) < 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (GS_ANY_3(6, 7, 9) > 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (GS_ANY_3(6, 7, 11) == 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((GS_ANY_3(10, 6, 7) << 11) == 10)
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (GS_ANY_3(6, 10, 10) != 10)
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (GS_ANY_3(6, 23, 12) < 10)
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (GS_ANY_3(6, -2, 9) > -1)
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (GS_ANY_2("testrere", "etest") == "test"))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((GS_ANY_2("test", "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (5 < GS_ANY_3(3, 4, 7))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }
}

