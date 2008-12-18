// junction_all.h - Junction library                            -*- c++ -*-
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs
// Operator `all'.

#ifndef GS_JUNCTION_ALL_H
# define GS_JUNCTION_ALL_H

# include "junction.h"

namespace gs
{

  namespace
  {
    // Comparaison classes for operators.

    // "All" :  All arguments match the predicate.
    template <typename _Type, typename _TypeCompare,class _Predicate>
    class AllCompare
    {
    public:
      static bool compare(const _TypeCompare& rhs,
                          const typename __Argument<_Type>::type& container)
      {
        for (typename __Argument<_Type>::type::const_iterator it(container.begin());
             it != container.end();
             ++it)
          if (!_Predicate()(rhs, *it))
            return false;
        return true;
      }
    };
  }


  /*------------------.
  | Interface for All |
  `------------------*/

  // Concrete classes for junctions.
  template <typename _Type>
  class All : public __Junction<_Type, AllCompare, All<_Type> >
  {
  public:
    All() {};
    All(const All<_Type>& other) :
      __Junction<_Type, AllCompare, All<_Type> >(other.collection_)
    {}

    All<_Type>& operator = (const All<_Type>& other)
    {
      if (&other != this)
        this->collection_ = other.collection_;
      return *this;
    }
  };

  // Wrapper functions.
  template <typename _Type>
  All<_Type> all(_Type lhs)
  {
    return All<_Type>() << lhs;
  }

#ifdef HAVE_VARIADIC
  // More Wrapper functions with C++0x and variadics templates.
  template <typename _Type, typename ... Rest>
  All<_Type>& _all(All<_Type>& junction, const _Type head, const Rest... tail)
  {
    junction << head;
    _all(junction, tail...);
    return junction;
  }

  template <typename _Type>
  All<_Type>& _all(All<_Type>& junction, const _Type head)
  {
    return junction << head;
  }

  template <typename _Type, typename ... Rest>
  All<_Type> all(_Type first, const Rest... tail)
  {
    All<_Type> junction;
    return _all(junction << first, tail...);
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

  // Enable All as right operator
  template <typename _Lhs, typename _Rhs>
  bool operator == (_Lhs lhs, All<_Rhs> rhs)
  {
    return rhs.equal(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator != (_Lhs lhs, All<_Rhs> rhs)
  {
    return rhs.not_equal(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator < (_Lhs lhs, All<_Rhs> rhs)
  {
    return rhs.greater_equal(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator <= (_Lhs lhs, All<_Rhs> rhs)
  {
    return rhs.greater(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator > (_Lhs lhs, All<_Rhs> rhs)
  {
    return rhs.less_equal(lhs);
  }

  template <typename _Lhs, typename _Rhs>
  bool operator >= (_Lhs lhs, All<_Rhs> rhs)
  {
    return rhs.less(lhs);
  }

  // Use macro for a light interface without variadic template.
# define GS_ALL_2(V1, V2) (gs::all(V1) << V2)
# define GS_ALL_3(V1, V2, V3) (GS_ALL_2(V1, V2) << V3)
# define GS_ALL_4(V1, V2, V3, V4) (GS_ALL_3(V1, V2, V3) << V4)
# define GS_ALL_5(V1, V2, V3, V4, V5) (GS_ALL_4(V1, V2, V3, V4) << V5)
# define GS_ALL_6(V1, V2, V3, V4, V5, V6) (GS_ALL_5(V1, V2, V3, V4, V5) << V6)

}

#endif
