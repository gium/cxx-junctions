// test_one3.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : One junction operator, with the variadic templated function interface (C++0x).

#include <gs/junction_one.h>
#include <iostream>

int main()
{
#ifdef __GXX_EXPERIMENTAL_CXX0X__
  if (!((gs::one(6, 7, 11) < 10)))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::one(6, 17, 11) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (!((gs::one(6, 7, 9) > 10)))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (!(gs::one(6, 7, 11) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (((gs::one(10, 6, 7, 11)) == 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::one(6, 10, 10) != 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::one(6, 23, 12) < 10))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (!(gs::one(6, -2, 9) > -1))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (!(gs::one("testrere", "etest") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((gs::one("test", "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;
#else
  std::cerr << "This interface requires variadic templates." << std::endl
	    << "This compiler doesn't seem to support c++0x feature." << std::endl
	    << "Maybe just a flag is missing (hint: -std=c++0x)." << std::endl;
#endif
}
