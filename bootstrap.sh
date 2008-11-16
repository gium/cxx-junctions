#! /bin/sh

# I don't want to execute `autoreconf' since autoheader must not be
# invoked.

mkdir build-aux
aclocal --force -I m4
autoconf --force
automake --add-missing --copy --force-missing



