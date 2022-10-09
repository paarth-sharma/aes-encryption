# Advanced Encrption Standard (AES)

## What is AES ?

1. AES is a block cipher.
2. The key size is 128/192/256 bits
3. Encrypts data in blocks of 128 bits each.

That means it takes 128 bits as input and outputs 128 bits of encrypted cipher text as output. AES relies on substitution-permutation network principle which means it is performed using a series of linked operations which involves replacing and shuffling of the input data.

The number of rounds depends on the key length as follows :

- 128 bit key – 10 rounds
- 192 bit key – 12 rounds
- 256 bit key – 14 rounds

**Creation of Round keys :**

A Key Schedule algorithm is used to calculate all the round keys from the key. So the initial key is used to create many different round keys which will be used in the corresponding round of the encryption.

## Resources for the Math behind AES (you should do it too.)
- [S-block substitution on which the Rijndael cipher is based; used in AES](.https://en.wikipedia.org/wiki/Rijndael_S-box#Example_implementation_in_C_language)
- [Round-constants](.https://en.wikipedia.org/wiki/AES_key_schedule#Round_constants)

