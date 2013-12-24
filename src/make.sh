if test $# -lt 1; then
    echo "Please enter the name of a .cpp file."
    exit 1
fi

CPPFLAGS="-Wall -Wextra -Werror -g -O2 -Wall -pedantic -std=c++11 -pthread"

g++ $CPPFLAGS "$1.cpp" -o "$1.out"
