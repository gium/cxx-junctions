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
    bool operator > (int lhs) const {return i_ >= lhs;}
  private:
    int i_;
  };


int main()
{
  if (GS_ALL_2(2, 3) < GS_ANY_2(1, 4))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (!(GS_ALL_2(2, 3) < GS_ALL_2(1, 4)))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((GS_ALL_2(2, 3) < GS_ALL_2(5, 4)))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (!(GS_ALL_3(2, 3, 2) < GS_ANY_2(1, 3)))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((GS_ANY_3("lala", "lili", "lolo") == GS_ANY_2("lulu", "lala")))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((GS_ANY_3("lala", "lili", "lolo") != GS_ANY_2("lulululu", "lala")))
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if ((gs::all(3) << 1 << 5) < IntegerWrapper(6)) // true
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  // Copy
  gs::All<int> j_all(gs::all(3) << 1 << 5);
  gs::All<int> j_all2 = j_all;

  // j_all == j_all2 false since all value from j_all not
  // equal to all value of j_all2
  if (j_all < 6 && j_all2 > 0 && !(j_all == j_all2)) // true
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  // Right value
  if (1 < (gs::all(3) << 6 << 5)) // true
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (!(1 >= (gs::all(3) << 6 << 5))) // true
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (1 == (gs::any(1) << 6 << 5)) // true
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (1 == (GS_ANY_3(1, 3, 4))) // true
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (4 < (GS_ANY_2(GS_ALL_2(1, 2), GS_ALL_2(5, 6)))) // true
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

  if (!(4 < (GS_ANY_2(GS_ALL_2(1, 5), GS_ALL_2(2, 6))))) // true
    std::cout << "PASS" << std::endl;
  else
  {
    std::cout << "FAIL" << std::endl;
    return 1;
  }

}
