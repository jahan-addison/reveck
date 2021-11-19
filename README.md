# reverk

An implementation of Scheme and SchemeQL query language.

R5RS Specification: https://schemers.org/Documents/Standards/R5RS/r5rs.pdf

Paper: https://soliloq.uy/~jahan/pdf/SchemeUnit%20and%20SchemeQL.pdf

## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Example:

``` bash
> git submodule update --init --recursive
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
> make
> ./repl
> make test      # Makes and runs the tests.
```
