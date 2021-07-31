# Cipher1 AES

This cipher is implements as AES, which we learnt in class and in hw3 I have implemented the whole realization. It uses 128-bit key and at each time encrypts a 128-bit text, by splitting into 16 8-bit blocks.

## Instructions

The following arguments are implemented:

```
--generate: generate generate a key;
--encrypt: encrypt a message;
--decrypt: decrypt a message;
--key: use the specified key to encrypt or decrypt; optional  
```

**Please be careful to use each command, or it will throw some kind of wrong operation message.**

## Compile

For compilation, since a ```Makefile``` is included in the folder, you can simply run the ```make``` command to generate an executable file ```g2```, and you can run the program like ```./g2 --encrypt "xxxxxxx" --key keyfile.txt```. 

If the ```Makefile``` is down, please run ```gcc -c aes.c``` and ```g++ -o g2 main.cpp transform.cpp aes.o``` to generate the executable file.

## More detail

In the file ```transform.cpp```, four methods are defined, which are:

* transform plaintext to unsigned char (uint8_t)
* transform unsigned char to plaintext
* transform ciphertext to unsigned char
* transform unsigned char to ciphertext

The former two are implemented like the sbox, with a text reference and an inverse one to transform in both directions.

The latter two are implemented because after encryption, the decimal number represented by some unsigned char are greater than 69, which is the number of all acceptable characters. So it should be splitted into two unsigned chars, one being the result modulo 69, the other is the result dividing 69 and add some integer I defined, to avoid weak ciphertext to some extent.