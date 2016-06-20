
#include "stdafx.h"
#include "RSA.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

/*
Primer:

Choose p = 3 and q = 11
Compute n = p * q
Compute q(n) = (p - 1) * (q - 1) = 2 * 10 = 20
Choose e such that 1 < e < q(n) and e and n are coprime. Let e = 7
Compute a value for d such that (d * e) % q(n) = 1. One solution is d = 3 [(3 * 7) % 20 = 1]
Public key is (e, n) => (7, 33)
Private key is (d, n) => (3, 33)
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


	
	
	int p = 3;
	int q = 11;
	int n = p * q;
	//q(n) = (p - 1) * (q - 1) = 2 * 10 = 20
	int qn = (p - 1) * (q - 1);
	//Choose e such that 1 < e < q(n) and e and n are coprime.Let e = 7
	std::vector<int> nf;
	std::vector<int> ef;
	std::vector<int> efs;

	for (int i = 1; i <= n; ++i) {
		if (n%i == 0) {
			nf.push_back(i);
		}
	}

	for (int i = 1; i <= qn; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i%j == 0) {
				ef.push_back(j);
			}
		}
		int co = 0;
		for (auto ef1 : ef) {
			if (std::find(nf.begin(), nf.end(), ef1) != nf.end()) {
				/* v contains x */
				++co;
			}
		}
		if (co == 1) {
			std::cout << "COPRIME: " << i << "\n";
		}
		ef.clear();
	}

	for (auto entry : nf) {
		std::cout << entry << "\n";
	}

	int e = 7;

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

	keypair kp = { e, d, n };

	int c = encrypt(2, e, n);
	decrypt(c, d, n);

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
