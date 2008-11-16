// junction.h - Junction library			      	-*- c++ -*-
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs
// Provided classes : All, Any, None, One
// Provided functions : all, any, none, One

#ifndef GS_JUNCTION_H
# define GS_JUNCTION_H

# include <vector>

# include "internal.h"

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
	      template <typename _Type, typename _TypeCompare, class _Predicate> class _Compare,
	      class _Concrete>
    class __Junction
    {
    public:
      __Junction() {}
      __Junction(const typename __Argument<_Type>::type& collection)
	: collection_(collection)
      {}

      // Push operator.
      _Concrete& operator <<(_Type value)
      {
	collection_.push_back(value);
	return *(static_cast<_Concrete*>(this));
      }

      // Comparaison operators.

      /*------.
      | equal |
      `------*/
      template <typename _TypeCompare>
      bool operator ==(const _TypeCompare& compare_value) const
      {
	return equal(compare_value);
      }

      template <typename _TypeCompare>
      bool equal(const _TypeCompare& compare_value) const
      {
	// compare will be : (compare_value == collection_value)
	// which must be equivalent to  collection_value == compare_value

	typedef _Compare<_Type, _TypeCompare, gs::internal::equal_to<_TypeCompare, _Type> >
	  __compare;
	return __compare::compare(compare_value, collection_);
      }

      /*----------.
      | not equal |
      `----------*/
      template <typename _TypeCompare>
      bool operator !=(const _TypeCompare& compare_value) const
      {
	return not_equal(compare_value);
      }

      template <typename _TypeCompare>
      bool not_equal(const _TypeCompare& compare_value) const
      {
	// compare will be : (compare_value != collection_value)
	// which must be equivalent to  collection_value != compare_value

	typedef _Compare<_Type, _TypeCompare, gs::internal::not_equal_to<_TypeCompare, _Type> >
	  __compare;
	return __compare::compare(compare_value, collection_);
      }

      /*-----.
      | less |
      `-----*/
      template <typename _TypeCompare>
      bool operator <(const _TypeCompare& compare_value) const
      {
	return less(compare_value);
      }

      template <typename _TypeCompare>
      bool less(const _TypeCompare& compare_value) const
      {
	// compare will be : (compare_value > collection_value)
	// which must be equivalent to  collection_value < compare_value

	typedef _Compare<_Type, _TypeCompare, gs::internal::greater<_TypeCompare, _Type> >
	  __compare;
	return __compare::compare(compare_value, collection_);
      }

      /*-----------.
      | less_equal |
      `-----------*/
      template <typename _TypeCompare>
      bool operator <=(const _TypeCompare& compare_value) const
      {
	return less_equal(compare_value);
      }

      template <typename _TypeCompare>
      bool less_equal(const _TypeCompare& compare_value) const
      {
	// compare will be : (compare_value >= collection_value)
	// which must be equivalent to  collection_value <= compare_value

	typedef _Compare<_Type, _TypeCompare, gs::internal::greater_equal<_TypeCompare, _Type> >
	  __compare;
	return __compare::compare(compare_value, collection_);
      }

      /*--------.
      | greater |
      `--------*/
      template <typename _TypeCompare>
      bool operator >(const _TypeCompare& compare_value) const
      {
	return greater(compare_value);
      }

      template <typename _TypeCompare>
      bool greater(const _TypeCompare& compare_value) const
      {
	// compare will be : (compare_value < collection_value)
	// which must be equivalent to  collection_value > compare_value

	typedef _Compare<_Type, _TypeCompare, gs::internal::less<_TypeCompare, _Type> >
	  __compare;
	return __compare::compare(compare_value, collection_);
      }

      /*--------------.
      | greater_equal |
      `--------------*/
      template <typename _TypeCompare>
      bool operator >=(const _TypeCompare& compare_value) const
      {
	return greater_equal(compare_value);
      }

      template <typename _TypeCompare>
      bool greater_equal(const _TypeCompare& compare_value) const
      {
	// compare will be : (compare_value >= collection_value)
	// which must be equivalent to  collection_value <= compare_value

	typedef _Compare<_Type, _TypeCompare, gs::internal::less_equal<_TypeCompare, _Type> >
	  __compare;
	return __compare::compare(compare_value, collection_);
      }

    protected:
      typedef typename __Argument<_Type>::type argument;
      argument collection_;
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
