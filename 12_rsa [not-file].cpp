#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
int public_key;
int private_key;
int n;
int N = 250;

void primeGen()
{
	vector<bool> seive(N, true);
	seive[0] = false;
	seive[1] = false;

	for (int i = 2; i < N; i++)
		for (int j = i * 2; j < N; j += i)
			seive[j] = false;

	for (int i = 0; i<N; i++) {
		if (seive[i])
			prime.push_back(i);
	}
}

int randPrime()
{
	int k = rand() % prime.size();
	int p = prime[k];
	prime.erase(prime.begin()+k);

	return p;
}
void setkeys()
{
	int p1 = randPrime();
	int p2 = randPrime();
	n = p1 * p2;
	int fi = (p1 - 1) * (p2 - 1);

	int e = 2;
	while (__gcd(e, fi) != 1)
		e++;
	public_key = e;

	int d = 2;
	while ((d * e) % fi != 1)
		d++;
	private_key = d;
}
long long encrypt(long long p)
{
	int e = public_key;
	long long enc = 1;

	while (e--)
		enc = (enc * p) % n;

	return enc;
}
long long decrypt(int c)
{
	int d = private_key;
	long long dec = 1;
	while (d--)
		dec = (dec * c) % n;

	return dec;
}

vector<int> encoder(string plain)
{
    int l = plain.size();
	vector<int> coded(l);

	for (int i=0; i<l; i++)
        coded[i] = encrypt((int)plain[i]);

	return coded;
}
string decoder(vector<int> coded)
{
    int l = coded.size();
	string decoded = "";
	for (int i=0; i<l; i++)
		decoded += decrypt(coded[i]);

	return decoded;
}
int main()
{
	primeGen();
	setkeys();
	string plain;
	cout << "Enter the plainTtext: ";
	cin >> plain;

	vector<int> coded = encoder(plain);
	cout << "The cipher: ";
	for (auto p: coded)
		cout << p;
	cout << "\nThe plainText: " << decoder(coded) << endl;
	return 0;
}
