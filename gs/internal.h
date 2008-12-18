// internal.h - Junction library                                -*- c++ -*-
// Copyright (c) 2008 Guillaume Sadegh <guillaume@sadegh-beyki.com>
//
// Namespace : gs::internal

/*-----------------------------------------------------------------.
| Internal: Binary predicates redefined for lhs and rhs of         |
| different but compatible type.                                   |
`-----------------------------------------------------------------*/

#ifndef GS_INTERNAL_H
# define GS_INTERNAL_H

# include <functional>

#ifndef HAVE_VARIADIC
# ifdef __GXX_EXPERIMENTAL_CXX0X__
#  define HAVE_VARIADIC 1
# endif
#endif

namespace gs
{
  namespace internal
  {
    template <typename _Lhs, typename _Rhs>
    struct equal_to : public std::binary_function<_Lhs, _Rhs, bool>
    {
      bool operator ()(const _Lhs& lhs, const _Rhs& rhs) const
      {
        return lhs == rhs;
      }
    };


    template <typename _Lhs, typename _Rhs>
    struct not_equal_to : public std::binary_function<_Lhs, _Rhs, bool>
    {
      bool operator ()(const _Lhs& lhs, const _Rhs& rhs) const
      {
        return lhs != rhs;
      }
    };

    template <typename _Lhs, typename _Rhs>
    struct less : public std::binary_function<_Lhs, _Rhs, bool>
    {
      bool operator ()(const _Lhs& lhs, const _Rhs& rhs) const
      {
        return lhs < rhs;
      }
    };

    template <typename _Lhs, typename _Rhs>
    struct less_equal : public std::binary_function<_Lhs, _Rhs, bool>
    {
      bool operator ()(const _Lhs& lhs, const _Rhs& rhs) const
      {
        return lhs <= rhs;
      }
    };

    template <typename _Lhs, typename _Rhs>
    struct greater : public std::binary_function<_Lhs, _Rhs, bool>
    {
      bool operator ()(const _Lhs& lhs, const _Rhs& rhs) const
      {
        return lhs > rhs;
      }
    };

    template <typename _Lhs, typename _Rhs>
    struct greater_equal : public std::binary_function<_Lhs, _Rhs, bool>
    {
      bool operator ()(const _Lhs& lhs, const _Rhs& rhs) const
      {
        return lhs >= rhs;
      }
    };

  } // namespace internal
} // namespace gs

#endif
