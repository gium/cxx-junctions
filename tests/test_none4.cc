// test_none4.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : None junction operator, with the variadic templated function interface (C++0x).

#include <gs/junction_none.h>
#include <iostream>

int main()
{
  if (! (GS_NONE_3(6, 7, 11) < 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((GS_NONE_3(6, 7, 9) > 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((GS_NONE_3(6, 7, 11) == 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! ((GS_NONE_4(10, 6, 7, 11)) == 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (GS_NONE_3(6, 10, 10) != 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (GS_NONE_3(6, 23, 12) < 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (GS_NONE_3(6, -2, 9) > -1))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((GS_NONE_2("testrere", "etest") == "test"))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (GS_NONE_2("test", "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (2 == GS_NONE_3(3, 4, 7))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }
}

