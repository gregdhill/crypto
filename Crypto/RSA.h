class RSA {
public:

	/**
	* Create RSA public / private key pair,
	* return struct.
	*/
	void createKeyPair();

	//TODO: Standard key sizes
	//TODO: Random big prime.

	int encrypt(int m, int e, int n);

	void decrypt(int c, int d, int n);

private:
	struct keypair {
		int e; // (e, n)
		int d; // (d, n)
		int n;
	};
	
};