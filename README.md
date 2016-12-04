# simple_benchmark
Dead simple exercise of a benchmark written in C++.

### description
This benchmark tests the CPU/RAM performances with a Mat(10000x10000, R)\*Mat(10000x1, R) multiplication.
`d` and `times` vars specify respectively the _dimesion_ and the _number of times_ to execute the operation, returning the floor average time spent for each iteration. Default values are `d = 10000` and `times = 5`.
In order to calculate the time I'm using `std::chrono::high_resolution_clock` from C++11.

This program has been tested successfully on a Raspberry Pi (g++ version 4.9.2) and on a X86_64 Intel CPU (g++ version 5.4.0) without modifications.

### usage
`make standard` compiles the code *without* OpenMP support.
`make mp` compiles the code *with* OpenMP support.
`./main` launches the benchmark.
