# VE475 Homework6 ex6

## Pollard-Rho Algorithm

There are two code files ```ex6.cpp``` and ```ex6_gmp.cpp``` in the folder. The former one can handle conditions when $n \leq 2^{64}$. The latter one is implemented using the gmp library, in case you want to test quite large numbers for factorization. 

* For execution of the file, if you just need to test small numbers, you can just run ```./ex6``` in the terminal, and it will ask you to input a number to get its factorization. 
* If you want to test large numbers, please run ```./ex6_gmp```, and also input a number to get its factorization. (Important Notes: Please choose numbers for which decimal bits are less than 25, or it will take a very long time to solve. For some specific values like 21 decimal bits 1, it will also take a long time but do not output an answer, maybe due to memory excess.)
* If there is something wrong with the execution file ```ex6```, there is also a ```Makefile``` attached, you can run ```make``` to generate another execution file.
* If ```Makefile``` goes wrong, there is a ```CMakeList```, please run ```cmake ./``` in the folder ```ex6``` to generate another ```Makefile```, and do the above procedures.



## Sample Output

1. Please input a number n to be factorized:1111111111111111111111
   n's factorization is: 1111111111111111111111 = 11 x 11 x 23 x 4093 x 21649 x 8779 x 513239

2. Please input a number n to be factorized:6492198743719874917941414
   n's factorization is: 6492198743719874917941414 = 3 x 2 x 1515230917 x 714104439008957

