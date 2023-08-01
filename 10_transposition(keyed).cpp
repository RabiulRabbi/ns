#include<bits/stdc++.h>
using namespace std;

int bognum = -1;

string encrypt(string plain, vector<int> k)
{
    int nk = k.size(), n = plain.size();
    char bogchar = 'z';

    if(bognum == -1){

        bognum = (nk - (n % nk)) % nk;
        for(int i=0; i<bognum; i++)
            plain += bogchar;
    }

    string cipher = "";
    for(int i=0; i<n; i += nk)
        for(int j=0; j<nk; j++)
            cipher += plain[i + k[j] - 1];

    transform(cipher.begin(), cipher.end(), cipher.begin(), ::toupper);

    return cipher;
}
string decrypt(string cipher, vector<int> k)
{
    vector<int> newk = k;
    for(int i=0; i<k.size(); i++)
        newk[k[i]-1] = i+1;

    string decipher = encrypt(cipher, newk);
    transform(decipher.begin(), decipher.end(), decipher.begin(), ::tolower);

    return decipher;
}
int main()
{
    string plain;
    cout<<"Enter the plainText: ";
    cin >> plain;

    vector<int> k = {3,1,4,5,2};

    string cipher = encrypt(plain, k);
    cout<<"Ciphertext: " << cipher << endl;

    cout<<"Plaintext: " << decrypt(cipher, k)<<endl;

    return 0;
}
