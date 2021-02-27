# lib-cubemaths

**Maths library designed to be used with CGPN**

## Build dependencies

- **[GoogleTest](https://github.com/google/googletest):** Run compulsory tests before building.

## Compiler flags

By default, `$(CXX)` will take the `-O3` flag whem building.
To build with debugging symbols and warnings, define the `dev` flag before any rules:

```sh
make test
# g++ -std=c++17 -I. -O3 -o bin/tests tests.cpp -I/usr/include/gtest /usr/lib/libgtest.so

make dev=1 test
# g++ -std=c++17 -I. -g -Wall -Wextra -Wpedantic -Wfloat-equal -o bin/tests tests.cpp -I/usr/include/gtest /usr/lib/libgtest.so
```

**The code MUST pass all tests both with and without optimisation!**
