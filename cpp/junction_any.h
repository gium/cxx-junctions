// junction_any.h - Junction library			      	-*- c++ -*-
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs
// Operator `any'.

#ifndef GS_JUNCTION_ANY_H
#define GS_JUNCTION_ANY_H

#include "junction.h"

namespace gs
{

  namespace
  {
    // Comparaison classes for operators.

    // "Any" : At least one argument matchs the predicate.
    template <typename _Type, class _Predicate>
    class AnyCompare
    {
    public:
      static bool compare(const _Type compare_value,
			  const typename __Argument<_Type>::type container)
      {
	for (typename __Argument<_Type>::type::const_iterator it(container.begin());
	     it != container.end();
	     ++it)
	  if (_Predicate()(*it, compare_value))
	    return true;
	return false;
      }
    };
  }


  /*------------------.
  | Interface for Any |
  `------------------*/

  // Concrete classes for junctions.
  template <typename _Type>
  class Any : public __Junction<_Type, AnyCompare, Any<_Type> >
  {
  };

  // Wrapper functions.
  template <typename _Type>
  Any<_Type> any(_Type t)
  {
    return Any<_Type>() << t;
  }

#ifdef __GXX_EXPERIMENTAL_CXX0X__
  // More Wrapper functions with C++0x and variadics templates.
  template <typename _Type, typename ... Rest>
  Any<_Type>& _any(Any<_Type>& junction, const _Type head, const Rest... tail)
  {
    junction << head;
    _any(junction, tail...);
    return junction;
  }

  template <typename _Type>
  Any<_Type>& _any(Any<_Type>& junction, const _Type head)
  {
    return junction << head;
  }

  template <typename _Type, typename ... Rest>
  Any<_Type> any(_Type first, const Rest... tail)
  {
    Any<_Type> junction;
    return _any(junction << first, tail...);
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
