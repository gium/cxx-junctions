# A macro to check if the compiler supports variadic templates.
# (c) Copyright Guillaume Sadegh
AC_DEFUN([AC_CXX_VARIADIC_TEMPLATES],[
AC_CACHE_CHECK([support for variadic templates (C++0x)],
                [ac_cv_cxx_variadic_templates],
[
  CXXFLAGS_SAVE="$CXXFLAGS"
  ac_cv_cxx_variadic_templates='no'

  AC_LANG_PUSH(C++)
  for extra_flag in ' ' '-std=c++0x'; do
    CXXFLAGS="$CXXFLAGS_SAVE $extra_flag"
    AC_COMPILE_IFELSE(AC_LANG_PROGRAM([[
template <typename ... T>
void foo(const T...){}
void bar(){ foo(1, 2, 3); }
     ]]),
     [ ac_cv_cxx_variadic_templates='yes'
       flag_to_add="$extra_flag"],
     [])
  done
  AC_LANG_POP()
])

  if test x"$ac_cv_cxx_variadic_templates" = x"yes"; then
      CXXFLAGS="$CXXFLAGS_SAVE $extra_flag"
      AC_DEFINE([HAVE_VARIADIC], 1, [Set to 1 if your compiler supports variadic templates.])
  else
      CXXFLAGS="$CXXFLAGS_SAVE"
  fi
])
