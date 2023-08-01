#include<bits/stdc++.h>
using namespace std;

string encryption_affine(string plainText, int k1, int k2);
string decryption_affine(string cipherText, int k1, int k2);
int multiplicativeInverse(int k1);

int main()
{


    string plainText;
    cout << "Enter the plain text: ";
    cin >> plainText;

    int k1, k2;
    cout << "Enter the keys: ";
    cin >> k1 >> k2;
    int multiplicativeInverse(int k1);
    while(multiplicativeInverse(k1) == -1)
    {
        cout << "There is no multiplicative inverse for " << k1<<  ".\nEnter valid keys: ";
        cin >> k1 >> k2;
    }

    string cipherText = encryption_affine(plainText, k1, k2);
    cout << "The cipherText is: " << cipherText << "\n";

    string decipherText = decryption_affine(cipherText, k1, k2);
    cout << "The decipherText is: " << decipherText << "\n";

    return 0;
}

string encryption_affine(string plainText, int k1, int k2)
{
    string cipherText = "";
    for(int i=0; i<plainText.size(); i++)
    {
        cipherText += (((plainText[i] - 'a') * k1) + k2) % 26 + 'A';
    }

    return cipherText;
}

string decryption_affine(string cipherText, int k1, int k2)
{
    int k1_inverse = multiplicativeInverse(k1);

    string decipherText = "";
    for(int i=0; i<cipherText.size(); i++)
    {
        decipherText += (((cipherText[i] + 'A' - k2) * k1_inverse)) % 26 + 'a';
    }
    return decipherText;
}

int multiplicativeInverse(int k1)
{
    for(int i=1; i<26; i++)
    {
        if((k1 * i) % 26 == 1)
            return i;
    }

    return -1;
}
