#include<bits/stdc++.h>
using namespace std;

string encrypt(string plain)
{
	string cipher = "";

	for(int i=0; i<plain.size(); i+=2)
        cipher += plain[i];

    for(int i=1; i<plain.size(); i+=2)
        cipher += plain[i];

    transform(cipher.begin(), cipher.end(), cipher.begin(), ::toupper);

    return cipher;
}

string decrypt(string cipher)
{
	string decipher = "";
    int n = cipher.size();

    for(int i=0, j=(n+1)/2; i<(n+1)/2; i++, j++)
    {
            decipher += cipher[i];
            decipher += cipher[j];
    }

    transform(decipher.begin(), decipher.end(), decipher.begin(), ::tolower);

    return decipher;
}

int main()
{
	string plain;
	cout << "Enter the plainText: ";
	cin >> plain;

	string cipher = encrypt(plain);
	cout << "The cipherText is: " << cipher << endl;

	cout << "The decipherText is: " << decrypt(cipher) << endl;

	return 0;
}


