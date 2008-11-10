// junction_all.h - Junction library			      	-*- c++ -*-
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs
// Operator `all'.

#ifndef GS_JUNCTION_ALL_H
#define GS_JUNCTION_ALL_H

#include "junction.h"

namespace gs
{

  namespace
  {
    // Comparaison classes for operators.

    // "All" :  All arguments match the predicate.
    template <typename _Type, class _Predicate>
    class AllCompare
    {
    public:
      static bool compare(const _Type compare_value,
			  const typename __Argument<_Type>::type container)
      {
	for (typename __Argument<_Type>::type::const_iterator it(container.begin());
	     it != container.end();
	     ++it)
	  if (!_Predicate()(*it, compare_value))
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
  };

  // Wrapper functions.
  template <typename _Type>
  All<_Type> all(_Type t)
  {
    return All<_Type>() << t;
  }

#ifdef __GXX_EXPERIMENTAL_CXX0X__
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


}

#endif
