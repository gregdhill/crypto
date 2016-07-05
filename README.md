# Toy C++ Crypto

* This repository contains all personal cryptographic implementations. For educational use only, the code is not cryptographically secure, nor has it been optimised efficiently.

* To run, download the repository and open the solution in MSVC.

* Refer to the documentation for relative primers.

## Asymmetric
### RSA

Overview:
* Computes Keypair

TODO: Encryption / Decryption

Dependancies:
* Utilises a modified version of: https://github.com/panks/BigInteger (bundled)
  * bigint.h & bigint.cpp

Notes:
* Heavily underoptimised - key generation is extremely slow.
* For increased speeds, use small key sizes w/ low primailty iterations.

## TODO
* ECC
* AES
