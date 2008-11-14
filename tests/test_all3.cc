// test_all3.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : All junction, with the variadic templated function interface (C++0x).

#include <gs/junction_all.h>
#include <iostream>

int main()
{
#ifdef __GXX_EXPERIMENTAL_CXX0X__
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
#else
  std::cerr << "This interface requires variadic templates." << std::endl
	    << "This compiler doesn't seem to support c++0x feature." << std::endl
	    << "Maybe just a flag is missing (hint: -std=c++0x)." << std::endl;
#endif
}
