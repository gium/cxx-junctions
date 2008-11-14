// test_all.cc - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Tests : All junction, with the class interface.

#include <gs/junction.h>
#include <iostream>

  class IntegerWrapper
  {
  public:
    IntegerWrapper(int i) : i_(i) {}
    bool operator >= (int lhs) const {return i_ >= lhs;}
  private:
    int i_;
  };


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

  if ((gs::all(3) << 1 << 5) < IntegerWrapper(6)) // true
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

  // Copy
  gs::All<int> j_all(gs::all(3) << 1 << 5);
  gs::All<int> j_all2 = j_all;

  if (j_all < 6 && j_all2 > 0 && j_all == j_all2) // true
    std::cout << "PASS" << std::endl;
  else
    std::cout << "FAIL" << std::endl;

}
