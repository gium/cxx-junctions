// test_none2.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : None junction operator, with the function interface.

#include <gs/junction_none.h>
#include <iostream>

int main()
{
  if (((gs::none(16) << 17 << 11) < 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! ((gs::none(6) << 17 << 9) > 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! ((gs::none(6) << 7 << 11 << 10) == 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (((gs::none(11) << 6 << 7 << 11) == 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! ((gs::none(6) << 10 << 10) != 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! ((gs::none(6) << 7 << 9) < 10))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! ((gs::none(6) << 7 << 9) > -1))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (((gs::none("testrere") << "etest") == "test"))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (! ((gs::none("test") << "tstee") == "test"))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }
}

