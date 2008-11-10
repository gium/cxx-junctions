// junction.h - Junction library			      	-*- c++ -*-
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs
// Provided classes : All, Any, None, One
// Provided functions : all, any, none, One -- Variadic template enhance their use.

#ifndef GS_JUNCTION_H
#define GS_JUNCTION_H

#include <vector>
#include <algorithm>
#include <functional>

namespace gs
{
  // Base definition for junctions.
  namespace
  {
    // Storing the type for arguments outside the using class, to make its use
    // easier.
    template <typename _Type>
    struct __Argument
    {
      typedef std::vector<_Type> type;
    };

    // The __Junction Base class. Parametrized with the Base type,
    // the comparaison function which specialize operators for
    // junctions, and the concrete class.
    template <typename _Type,
	      template <typename _Type, class _Predicate> class _Compare,
	      class _Concrete>
    class __Junction
    {
    public:
      // Push operator.
      _Concrete& operator <<(_Type value)
      {
	container_.push_back(value);
	return *(static_cast<_Concrete*>(this));
      }

      // Comparaison operators.

      bool operator ==(_Type compare_value)
      {
	return _Compare<_Type, std::equal_to<_Type> >::compare(compare_value, container_);
      }

      bool operator !=(_Type compare_value)
      {
	return _Compare<_Type, std::not_equal_to<_Type> >::compare(compare_value, container_);
      }

      bool operator <(_Type compare_value)
      {
	return _Compare<_Type, std::less<_Type> >::compare(compare_value, container_);
      }

      bool operator <=(_Type compare_value)
      {
	return _Compare<_Type, std::less_equal<_Type> >::compare(compare_value, container_);
      }

      bool operator >(_Type compare_value)
      {
	return _Compare<_Type, std::greater<_Type> >::compare(compare_value, container_);
      }

      bool operator >=(_Type compare_value)
      {
	return _Compare<_Type, std::greater_equal<_Type> >::compare(compare_value, container_);
      }

    private:
      typedef typename __Argument<_Type>::type argument;
      argument container_;
    };

  }
}

  // The four interfaces for all, any, none and one. The four are almost the same,
  // just name classes/functions and inherited classes change.

  #include "junction_all.h"
  #include "junction_any.h"
  #include "junction_none.h"
  #include "junction_one.h"

#endif
