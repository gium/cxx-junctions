// junction.h - Junction library                                -*- c++ -*-
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


    // Push operator : By value or by references depending the sizeof (_Type).
    // By value.
    template <bool, typename _Type, class _Concrete>
    class __PushCollection
    {
    public:
      __PushCollection() {};
      __PushCollection(const typename __Argument<_Type>::type& collection)
        : collection_(collection)
      {}

      // Push operator.
      _Concrete& operator <<(_Type value)
      {
        this->collection_.push_back(value);
        return *(static_cast<_Concrete*>(this));
      }

    protected:
      typedef typename __Argument<_Type>::type argument_type;
      argument_type collection_;
    };

    // By reference.
    template <typename _Type, class _Concrete>
    class __PushCollection<false, _Type, _Concrete>
    {
    public:
      __PushCollection() {};
      __PushCollection(const typename __Argument<_Type>::type& collection)
        : collection_(collection)
      {}

      // Push operator.
      _Concrete& operator <<(const _Type& value)
      {
        this->collection_.push_back(value);
        return *(static_cast<_Concrete*>(this));
      }

    protected:
      typedef typename __Argument<_Type>::type argument_type;
      argument_type collection_;
    };


    // The __Junction Base class. Parametrized with the Base type,
    // the comparaison function which specialize operators for
    // junctions, and the concrete class.
    template <typename _Type,
              template <typename _Type, typename _TypeCompare, 
                        class _Predicate> class _Compare, 
              class _Concrete>
    class __Junction 
      : public __PushCollection<(sizeof (_Type) <= sizeof (void*)), _Type, 
                                _Concrete>
    {
    public:
      __Junction() {}
      __Junction(const typename __Argument<_Type>::type& collection)
        : __PushCollection<(sizeof (_Type) <= sizeof (void*)),
                           _Type, _Concrete>(collection)
      {}

      // Comparaison operators.

      /*------.
      | equal |
      `------*/
      template <typename _TypeCompare>
      bool operator ==(const _TypeCompare& rhs) const
      {
        return equal(rhs);
      }

      template <typename _TypeCompare>
      bool equal(const _TypeCompare& rhs) const
      {
        // compare will be : (rhs == collection_value)
        // which must be equivalent to  collection_value == rhs

        typedef _Compare<_Type, _TypeCompare, internal::equal_to<_TypeCompare, 
	                 _Type> > compare_type;
        return compare_type::compare(rhs, this->collection_);
      }

      /*----------.
      | not equal |
      `----------*/
      template <typename _TypeCompare>
      bool operator !=(const _TypeCompare& rhs) const
      {
        return not_equal(rhs);
      }

      template <typename _TypeCompare>
      bool not_equal(const _TypeCompare& rhs) const
      {
        // compare will be : (rhs != collection_value)
        // which must be equivalent to  collection_value != rhs

        typedef _Compare<_Type, _TypeCompare, internal::not_equal_to<_TypeCompare, 
                         _Type> > compare_type;
        return compare_type::compare(rhs, this->collection_);
      }

      /*-----.
      | less |
      `-----*/
      template <typename _TypeCompare>
      bool operator <(const _TypeCompare& rhs) const
      {
        return less(rhs);
      }

      template <typename _TypeCompare>
      bool less(const _TypeCompare& rhs) const
      {
        // compare will be : (rhs > collection_value)
        // which must be equivalent to  collection_value < rhs

        typedef _Compare<_Type, _TypeCompare, internal::greater<_TypeCompare, 
                         _Type> > compare_type;
        return compare_type::compare(rhs, this->collection_);
      }

      /*-----------.
      | less_equal |
      `-----------*/
      template <typename _TypeCompare>
      bool operator <=(const _TypeCompare& rhs) const
      {
        return less_equal(rhs);
      }

      template <typename _TypeCompare>
      bool less_equal(const _TypeCompare& rhs) const
      {
        // compare will be : (rhs >= collection_value)
        // which must be equivalent to  collection_value <= rhs

        typedef _Compare<_Type, _TypeCompare, internal::greater_equal<_TypeCompare, 
                         _Type> > compare_type;
        return compare_type::compare(rhs, this->collection_);
      }

      /*--------.
      | greater |
      `--------*/
      template <typename _TypeCompare>
      bool operator >(const _TypeCompare& rhs) const
      {
        return greater(rhs);
      }

      template <typename _TypeCompare>
      bool greater(const _TypeCompare& rhs) const
      {
        // compare will be : (rhs < collection_value)
        // which must be equivalent to  collection_value > rhs

        typedef _Compare<_Type, _TypeCompare, internal::less<_TypeCompare, 
                         _Type> > compare_type;
        return compare_type::compare(rhs, this->collection_);
      }

      /*--------------.
      | greater_equal |
      `--------------*/
      template <typename _TypeCompare>
      bool operator >=(const _TypeCompare& rhs) const
      {
        return greater_equal(rhs);
      }

      template <typename _TypeCompare>
      bool greater_equal(const _TypeCompare& rhs) const
      {
        // compare will be : (rhs >= collection_value)
        // which must be equivalent to  collection_value <= rhs

        typedef _Compare<_Type, _TypeCompare, internal::less_equal<_TypeCompare, 
                         _Type> > compare_type;
        return compare_type::compare(rhs, this->collection_);
      }
    };
  } // anonymous namespace.
} // gs namespace.

  // The four interfaces for all, any, none and one. They are almost the same,
  // just the name of classes/functions and inherited classes change.

 # include "junction_all.h"
 # include "junction_any.h"
 # include "junction_none.h"
 # include "junction_one.h"

#endif
