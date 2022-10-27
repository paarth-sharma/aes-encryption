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

## Contents of this project and their purpose
- **decoding.h** : we have a header file named decoding.h which implements the actual algorithm to obtain the plain text from the encrypted data.

- **encoding.h** : This header implements the algorithm to encrypt the plain text. 

- **key_expand.h** : 128-bit AES requires 10 rounds of encryption and each round requires a distinct key, all these keys are actually generated from the original key and this process of generating keys is called key expansion. This header file includes the function to perform key expansion.  

- **lookup_table_encoding .h** : Each round of AES encryption is performed in various steps and in one of the steps called mix column, we use Galois multiplication lookup tables to ease our task. This header file includes all the lookup tables required for encoding.

- **lookup_table_decoding .h** : this header file includes all the corresponding Gallois lookup up tables required for the decryption.

- **main.cpp** : This c++ file includes the driver code required for the implementation of the algorithm.

- **input.txt** : In this text file we write the plain text which is needed to be encrypted, our code reads plain text from this file and stores the encrypted data in encryption.aes.

- **encryption.aes** : encrypted data is stored in this file during encryption and our code reads the data from this file while performing decryption.

- **outputtext.txt** : After the decryption, our plain text obtained from the encrypted data is stored in this file.

- **key.txt** : symmetric key required for the encryption and decryption is stored in this text file.

## Resources for the Math behind AES (you should do it too.)
- [S-block substitution on which the Rijndael cipher is based; used in AES](https://en.wikipedia.org/wiki/Rijndael_S-box#Example_implementation_in_C_language)
- [Round-constants](https://en.wikipedia.org/wiki/AES_key_schedule#Round_constants)
- [AES (Advanced Encryption Standard)](https://en.wikipedia.org/wiki/Advanced_Encryption_Standard)
- [A 4-part Youtube Playlist by Creel](https://www.youtube.com/watch?v=dRYHSf5A4lw&list=PLKK11LigqitiRH57AbtyJyzsfbNfA8nb-)
> It will give you the basic know how of each step involved, that's how I learnt it, but my approach is a bit more sophisticated, which involves the use of header files that contain fuunctions I call everywhere rather that doing everything in the main file itself

## How to use the project ?
### **Steps to perform encryption ->**

- Store plain text in input.txt file.
- Write your key in file key.txt
- Run the code and choose the option of encryption.
- Encrypted data will be stored in a file named 'encryption.aes' (special kind of file, open it using online hex-editors, normal text editors will show gibberish/garbage text).

### **Steps to perform decryption ->**

- Store encrypted data in file encryption.aes
- Write the key in file key.txt which was used during encryption.
- Run the program and choose the option of decryption.
- Plain text *will be shown as output as well as it will be stored in the text file **outputtext.txt***.

