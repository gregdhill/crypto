
#include "stdafx.h"
#include "RSA.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>

/*
Primer:

Compute 2 primes
Compute n = p * q
Compute q(n) = (p - 1) * (q - 1)
Choose e such that 1 < e < q(n) and e and n are coprime.
Compute a value for d such that (d * e) % q(n) = 1
Public key is (e, n)
Private key is (d, n)
The encryption of m = 2 is c = 27 % 33 = 29
The decryption of c = 29 is m = 293 % 33 = 2

Euler's Totient Function and Euler's Theorem

*/

void RSA::createKeyPair() {
	
	//preselected random number of the desired length

	//Fermat test

	//apply a certain number of Miller - Rabin tests(depending on the length and the allowed error rate like 2-100
	//to get a number which is very probably a prime number.

	//Primality test
	//Greatest common divisor
	//Chinese remainder theorem
	//Euler's totient function

	//Mersenne Twister

	//Fermat primality test

	//http://crypto.stackexchange.com/questions/71/how-can-i-generate-large-prime-numbers-for-rsa
	//http://www.di-mgt.com.au/rsa_alg.html

	long prime = 0;
	srand(time(0));
	prime = rand() % 100 + 100;
	std::cout << "PRIME: " << prime << "\n";



	int p = genPrime();
	int q = genPrime();

	std::cout << "P: " << p << "\n";
	std::cout << "Q: " << q << "\n";


	int n = p * q;

	std::cout << "N: " << n << "\n";


	int qn = (p - 1) * (q - 1);

	std::cout << "QN: " << qn << "\n";




	//Choose e such that 1 < e < q(n) and e and n are coprime.Let e = 7
	int e = 997;
	if (RSA::gcd(e, qn) == true) {
		std::cout << "PHI: " << e << "\n";
	}


	int d = 0;
	int temp = 0;
	while (d == 0) {
		++temp;
		if (((temp * e) % qn) == 1) {
			d = temp;
		}
	}

	std::cout << "D: " << d << "\n";



	std::cout << "Public Key = (" << e << ", " << n << ")" << "\n";

	std::cout << "Private Key = (" << d << ", " << n << ")" << "\n";


	//keypair kp = { e, d, n };
	//int c = encrypt(2, e, n);
	//decrypt(c, d, n);

}

int RSA::encrypt(int m, int e, int n) {
	std::cout << "M: " << m << "\n";
	int c1 = pow(m, e);
	int c = c1 % n;
	std::cout << "C: " << c << "\n";
	return c;
}

void RSA::decrypt(int c, int d, int n) {
	int m1 = pow(c, d);
	int m2 = m1 % n;
	std::cout << "M: " << m2 << "\n";
}

int RSA::genPrime() {
	while (true) {
		unsigned int p = rand() % 300000000000000000 + 10;
		if (RSA::fermat(p, 100) == true) {
			return p;
		}
	}
}

bool RSA::fermat(int n, int k) {

	// a ^ n-1 = 1 (mod n)
	for (int i = 0; i < k; ++i) {
		int a = rand() % n + 1;
		if (modulo(a, n - 1, n) != 1) {
			return false;
		}
	}

	return true;
}

int RSA::modulo(int base, int exponent, int mod) {
	// (base ^ exponent) / mod
	long long x = 1, y = base;
		while (exponent > 0) {
			if (exponent % 2 == 1) {
				x = (x * y) % mod;
			}
			y = (y * y) % mod;
			exponent /= 2;
		}
	return x % mod;
}

bool RSA::gcd(int n1, int n2) {
	int n3 = n1;
	int n4 = n2;
	while (n3 != n4) {
		if (n3 > n4)
			n3 -= n4;
		else
			n4 -= n3;
	}
	if (n3 == 1) {
		return true;
	} else {
		return false;
	}
}

