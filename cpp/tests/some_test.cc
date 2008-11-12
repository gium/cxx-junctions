// test_all.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : All junction, with the class interface.

#include <gs/junction.h>
#include <iostream>

int main()
{
  if (GS_ALL_2(2, 3) < GS_ANY_2(1, 4))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (!(GS_ALL_2(2, 3) < GS_ALL_2(1, 4)))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((GS_ALL_2(2, 3) < GS_ALL_2(5, 4)))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if (!(GS_ALL_3(2, 3, 2) < GS_ANY_2(1, 3)))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((GS_ANY_3("lala", "lili", "lolo") == GS_ANY_2("lulu", "lala")))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  if ((GS_ANY_3("lala", "lili", "lolo") != GS_ANY_2("lulululu", "lala")))
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

}
