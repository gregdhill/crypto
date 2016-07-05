
#include "stdafx.h"
#include "RSA.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>

#include <sstream>
#include <ctime>
#include <cstdlib>
#include "bigint.h"

using std::ostringstream;

void RSA::createKeyPair() {

	// Get p & q
	// -------------------------------------------------------

	srand(time(NULL));
	cout << "Computing P..." << endl;
	BigInteger p = genPrime(32);
	cout << "Computing Q..." << endl;
	BigInteger q = genPrime(32);

	std::cout << "P: " << p.getNumber() << "\n";
	std::cout << "Q: " << q.getNumber() << "\n";

	// -------------------------------------------------------

	BigInteger n = p * q;

	std::cout << "N: " << n.getNumber() << "\n";

	// -------------------------------------------------------

	BigInteger qn = (p - 1) * (q - 1);

	std::cout << "QN: " << qn.getNumber() << "\n";

	// -------------------------------------------------------

	//BigInteger e = 997;
	//if (RSA::gcd(e, qn) == true) {
	//	std::cout << "PHI: " << e.getNumber() << "\n";
	//}

	// -------------------------------------------------------

	//BigInteger d = 0;
	//BigInteger temp = 0;
	//while (d == 0) {
	//	++temp;
	//	if (((temp * e) % qn) == 1) {
	//		d = temp;
	//	}
	//}

	//std::cout << "D: " << d.getNumber() << "\n";

	// -------------------------------------------------------



	//std::cout << "Public Key = (" << e << ", " << n << ")" << "\n";

	//std::cout << "Private Key = (" << d << ", " << n << ")" << "\n";


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

BigInteger RSA::genPrime(int keySize) {
	tries = 0;
	keySize = keySize / 2;
	while (true) {
		BigInteger p;
		static unsigned char hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
		if (keySize)
		{
			ostringstream oss;
			for (int i = 0; i < keySize - 1; ++i)
				oss << hex[rand() % 16];
			oss << hex[1];
			std::string str(oss.str());
			p.toDecimal(str);
		}
		if (RSA::fermat(p.getNumber(), 5) == true) {
			return p.getNumber();
		}
	}
}

bool RSA::fermat(BigInteger n, int k) {

	// a ^ n-1 = 1 (mod n)
	for (int i = 0; i < k; ++i) {
		++tries;
		cout << "Testing Primes: " << tries << "\r";
		int a = rand() % 100 + 1;
		if (modulo(a, n - 1, n) != 1) {
			return false;
		}
	}
	cout << "\n";
	return true;
}

BigInteger RSA::modulo(int base, BigInteger exponent, BigInteger mod) {
	// (base ^ exponent) / mod
	BigInteger x = 1, y = base;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			x = (x * y) % mod;
		}
		y = (y * y) % mod;
		exponent /= 2;
	}
	return x % mod;
}

bool RSA::gcd(BigInteger n1, BigInteger n2) {
	BigInteger n3 = n1;
	BigInteger n4 = n2;
	while (n3 != n4) {
		if (n3 > n4)
			n3 -= n4;
		else
			n4 -= n3;
	}
	if (n3 == 1) {
		return true;
	}
	else {
		return false;
	}
}

