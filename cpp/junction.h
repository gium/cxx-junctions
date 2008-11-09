// junction.h - Junction library
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs
// Provided classes : All, Any, None
// Provided functions : all, any, none -- Variadic template enhance their use.

#ifndef GS_JUNCTION_H
#define GS_JUNCTION_H

#include <vector>
#include <algorithm>
#include <functional>

namespace gs
{
  namespace
  {
    // Storing type outside use using class, to make its use easier.
    template <typename _Type>
    struct __Tuple
    {
      typedef std::vector<_Type> type;
    };

    // The __Junction Base class. Parametrized with the Base type, the comparaison function which specialize
    // the behavior for junctions, and the concrete class.
    template <typename _Type, template <typename _Type, class _Predicate> class _Compare, class _Concrete>
    class __Junction
    {
    public:
      _Concrete& operator <<(_Type value)
      {
	container_.push_back(value);
	return *(static_cast<_Concrete*>(this));
      }

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
      typedef typename __Tuple<_Type>::type tuple;
      tuple container_;
    };

    // Comparaison classes.

    // "All"
    template <typename _Type, class _Predicate>
    class AllCompare
    {
    public:
      static bool compare(const _Type compare_value,
			  const typename __Tuple<_Type>::type container)
      {
	for (typename __Tuple<_Type>::type::const_iterator it(container.begin());
	     it != container.end();
	     ++it)
	  if (!_Predicate()(*it, compare_value))
	    return false;
	return true;
      }
    };
  }

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
#  endif
# endif
#endif

}

#endif
