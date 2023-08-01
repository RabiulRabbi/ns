#include<bits/stdc++.h>
using namespace std;

string encrypt(string plain, vector<int> k)
{
    int nk = k.size(), n = plain.size();
	int row = ceil((double)n/nk);
	int col = nk;

	char mat[row][col];
    for(int i=0, l=0; i<row; i++){
        for(int j=0; j<col; j++){

            if(plain[l] == '\0'){
                mat[i][j] = 'z';
                continue;
            }
            mat[i][j] = plain[l];
            l++;
        }
    }

    string cipher = "";

    for(int j=0; j<col; j++)
        for(int i=0; i<row; i++)
            cipher += mat[i][k[j]-1];

    transform(cipher.begin(), cipher.end(), cipher.begin(), ::toupper);

	return cipher;
}

string decrypt(string cipher, vector<int> k)
{
    vector<int> newk = k;
    for(int i=0; i<k.size(); i++)
        newk[k[i]-1] = i+1;

    int nk = newk.size(), n = cipher.size();
	int row = ceil((double)n/nk);
	int col = nk;

	char mat[row][col];
    for(int j=0, l=0; j<col; j++){
        for(int i=0; i<row; i++){

            mat[i][j] = cipher[l];
            l++;
        }
    }

    string decipher = "";
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            decipher += mat[i][newk[j]-1];

    transform(decipher.begin(), decipher.end(), decipher.begin(), ::tolower);

	return decipher;
}

int main()
{
	string plain;
	cout << "Enter the plainText: ";
	cin >> plain;

	vector<int> k = {3, 1, 4, 5, 2};

	string cipher = encrypt(plain, k);
	cout << "Ciphertext: " << cipher << endl;

	cout << "Plaintext: " << decrypt(cipher, k) << endl;

	return 0;
}

