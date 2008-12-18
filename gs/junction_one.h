// junction_one.h - Junction library                            -*- c++ -*-
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs
// Operator `one'.

#ifndef GS_JUNCTION_ONE_H
# define GS_JUNCTION_ONE_H

# include "junction.h"

namespace gs
{

  namespace
  {
    // Comparaison classes for operators.

    // "One" : One (and just one) argument matchs the predicate.
    template <typename _Type, typename _TypeCompare, class _Predicate>
    class OneCompare
    {
    public:
      static bool compare(const _TypeCompare& rhs,
                          const typename __Argument<_Type>::type& container)
      {
        unsigned count = 0;
        for (typename __Argument<_Type>::type::const_iterator it(container.begin());
             it != container.end();
             ++it)
        {
          if (_Predicate()(rhs, *it))
            ++count;
        }

        return count == 1;
      }
    };
  }


  /*------------------.
  | Interface for One |
  `------------------*/

  // Concrete classes for junctions.
  template <typename _Type>
  class One : public __Junction<_Type, OneCompare, One<_Type> >
  {
  public:
    One() {};
    One(const One<_Type>& other) :
      __Junction<_Type, OneCompare, One<_Type> >(other.collection_)
    {}

    One<_Type>& operator = (const One<_Type>& other)
    {
      if (&other != this)
        this->collection_ = other.collection_;
      return *this;
    }
  };

  // Wrapper functions.
  template <typename _Type>
  One<_Type> one(_Type lhs)
  {
    return One<_Type>() << lhs;
  }

#ifdef HAVE_VARIADIC
  // More Wrapper functions with C++0x and variadics templates.
  template <typename _Type, typename ... Rest>
  One<_Type>& _one(One<_Type>& junction, const _Type head, const Rest... tail)
  {
    junction << head;
    _one(junction, tail...);
    return junction;
  }

  template <typename _Type>
  One<_Type>& _one(One<_Type>& junction, const _Type head)
  {
    return junction << head;
  }

  template <typename _Type, typename ... Rest>
  One<_Type> one(_Type first, const Rest... tail)
  {
    One<_Type> junction;
    return _one(junction << first, tail...);
  }
#else
# ifdef __GNUC__
#  if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)) && !defined(JUNCTION_INHIB_0X_WARNING)
  // Since g++ 4.3 variadic template are supported.
#   warning Your g++ version seems to support variadic template.
#   warning Their use will improve the junction interface.
#   warning Add the -std=c++0x flag to your compiler to support this feature.
#   warning You can inhib this warning with -DJUNCTION_INHIB_0X_WARNING.
#   define JUNCTION_INHIB_0X_WARNING 1 // This warn only once.
#  endif
# endif
#endif


  // Enable One as right operator
  template <typename _LHS, typename _RHS>
  bool operator == (_LHS lhs, One<_RHS> rhs)
  {
    return rhs.equal(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator != (_Lhs lhs, One<_Rhs> rhs)
  {
    return rhs.not_equal(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator < (_Lhs lhs, One<_Rhs> rhs)
  {
    return rhs.greater(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator <= (_Lhs lhs, One<_Rhs> rhs)
  {
    return rhs.greater_equal(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator > (_Lhs lhs, One<_Rhs> rhs)
  {
    return rhs.less(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator >= (_Lhs lhs, One<_Rhs> rhs)
  {
    return rhs.less_equal(lhs);
  }

  // Use macro for a light interface without variadic template.
# define GS_ONE_2(V1, V2) (gs::one(V1) << V2)
# define GS_ONE_3(V1, V2, V3) (GS_ONE_2(V1, V2) << V3)
# define GS_ONE_4(V1, V2, V3, V4) (GS_ONE_3(V1, V2, V3) << V4)
# define GS_ONE_5(V1, V2, V3, V4, V5) (GS_ONE_4(V1, V2, V3, V4) << V5)
# define GS_ONE_6(V1, V2, V3, V4, V5, V6) (GS_ONE_5(V1, V2, V3, V4, V5) << V6)

}

#endif
