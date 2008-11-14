// internal.h - Junction library			      	-*- c++ -*-
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs::internal

/*-----------------------------------------------------------------.
| Internal: Binary predicates redefined for two differents types.  |
`-----------------------------------------------------------------*/

#ifndef GS_INTERNAL_H
# define GS_INTERNAL_H

# include <functional>

namespace gs
{
  namespace internal
  {
    template <typename _Type1, typename _Type2>
    struct equal_to : public std::binary_function<_Type1, _Type2, bool>
    {
      bool operator ()(const _Type1& _v1, const _Type2& _v2) const
      {
	return _v1 == _v2;
      }
    };


    template <typename _Type1, typename _Type2>
    struct not_equal_to : public std::binary_function<_Type1, _Type2, bool>
    {
      bool operator ()(const _Type1& _v1, const _Type2& _v2) const
      {
	return _v1 != _v2;
      }
    };

    template <typename _Type1, typename _Type2>
    struct less : public std::binary_function<_Type1, _Type2, bool>
    {
      bool operator ()(const _Type1& _v1, const _Type2& _v2) const
      {
	return _v1 < _v2;
      }
    };

    template <typename _Type1, typename _Type2>
    struct less_equal : public std::binary_function<_Type1, _Type2, bool>
    {
      bool operator ()(const _Type1& _v1, const _Type2& _v2) const
      {
	return _v1 <= _v2;
      }
    };

    template <typename _Type1, typename _Type2>
    struct greater : public std::binary_function<_Type1, _Type2, bool>
    {
      bool operator ()(const _Type1& _v1, const _Type2& _v2) const
      {
	return _v1 > _v2;
      }
    };

    template <typename _Type1, typename _Type2>
    struct greater_equal : public std::binary_function<_Type1, _Type2, bool>
    {
      bool operator ()(const _Type1& _v1, const _Type2& _v2) const
      {
	return _v1 >= _v2;
      }
    };

  }
}

#endif
