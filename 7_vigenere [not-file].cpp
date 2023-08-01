#include<bits/stdc++.h>
using namespace std;

string encrypt(string plain, string key)
{
    int n = plain.size(), nk = key.size();

    int kstream[n];
    for(int i=0, j=0; i<n; i++, j++){

        if(j == nk)
            j = 0;
        kstream[i] = key[j] - 'a';
    }

    string cipher = "";
    for(int i=0; i<n; i++)
        cipher += (plain[i] - 'a' + kstream[i]) % 26 + 'A';

    return cipher;
}

string decrypt(string cipher, string key)
{
    int n = cipher.size(), nk = key.size();

    int kstream[n];
    for(int i=0, j=0; i<n; i++, j++){

        if(j == nk)
            j = 0;
        kstream[i] = key[j] - 'a';
    }

    string decipher = "";
    for(int i=0; i<n; i++)
        decipher += (cipher[i] + 'A' - kstream[i]) % 26 + 'a';

    return decipher;
}

int main()
{
    string plain, message1,key,keyword;
    char ch;
    int i,n,m,j=0;
    cout << "Enter the plainText: ";
    cin >> plain;

    cout << "Enter the key-string (lowercase): ";
    cin >> key;

    string cipher = encrypt(plain, key);
    cout << "Ciphertext: " << cipher << endl;

    cout << "Plaintext: " << decrypt(cipher, key) << endl;

    return 0;
}
