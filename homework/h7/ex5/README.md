# VE475 Homework7 ex5

## Square and multiply algorithm

The implementation of the common algorithm and the faster algorithm is realized in the file ```main.cpp```. 

By using the gmp library, I choose $n$ to be a random number of 40000 bits, and $\alpha, \beta, a, b$ be four random numbers of 20000 bits. After running, it will show you the time consumption of running the two algorithms, and a comparation between the two exponentiation results.

By running a lot of times, the common algorithm would run for about 8-9 seconds, while the faster one only needs about 5 seconds to complete the computation.

* For execution of the file, if you just need to test small numbers, you can just run ```./ex5``` in the terminal.
* If there is something wrong with the execution file ```ex5```, there is also a ```Makefile``` attached, you can run ```make``` to generate another execution file.
* If ```Makefile``` goes wrong, there is a ```CMakeList```, please run ```cmake ./``` in the folder ```ex5``` to generate another ```Makefile```, and do the above procedures.



## Sample output

* The running time of the common algorithm which calculates a, b separately is: **8.27876**
  The running time of the faster algorithm is: **5.09407**
  **Same exponentiation calculated!**
* The running time of the common algorithm which calculates a, b separately is: **9.19392**
  The running time of the faster algorithm is: **5.61659**
  **Same exponentiation calculated!**