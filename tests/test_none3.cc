// test_none3.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : None junction operator, with the variadic templated function interface (C++0x).

#include <gs/junction_none.h>
#include <iostream>

int main()
{
#ifdef __GXX_EXPERIMENTAL_CXX0X__
  if (! (gs::none(6, 7, 11) < 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((gs::none(6, 7, 9) > 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((gs::none(6, 7, 11) == 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! ((gs::none(10, 6, 7, 11)) == 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (gs::none(6, 10, 10) != 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (gs::none(6, 23, 12) < 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (gs::none(6, -2, 9) > -1))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((gs::none("testrere", "etest") == "test"))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! (gs::none("test", "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

#else
  std::cerr << "This interface requires variadic templates." << std::endl
	    << "This compiler doesn't seem to support c++0x feature." << std::endl
	    << "Maybe just a flag is missing (hint: -std=c++0x)." << std::endl;
#endif
}
