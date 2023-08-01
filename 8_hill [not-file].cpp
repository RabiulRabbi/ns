#include<bits/stdc++.h>
using namespace std;

int modInv(int a) {
    a = a % 26;
    for (int x = 1; x < 26; x++) {
        if ((a*x) % 26 == 1)
            return x;
    }
    return -1;
}
int det(int mat[2][2])
{
    return  mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
}
string decryption(string cipher,int mat[2][2]){
    string plain = "";
    int deter = det(mat);
    int invDet = modInv(deter);

    int invMat[2][2];
    invMat[0][0] = (mat[1][1] * invDet) % 26;
    invMat[0][1] = ((((-1) * (mat[0][1] * invDet) % 26) + 26)) % 26;
    invMat[1][0] = ((((-1) * (mat[1][0] * invDet) % 26) + 26)) % 26;
    invMat[1][1] = (mat[0][0] * invDet) % 26;

    for(int i = 0; i < cipher.size(); i += 2){
        int a = cipher[i]- 'A';
        int b = cipher[i+1] - 'A';
        int x = (a*invMat[0][0] + b*invMat[1][0]) % 26;
        int y = (a*invMat[0][1] + b*invMat[1][1]) % 26;
        plain += (x+'a');
        plain += (y+'a');
    }
    return plain;
}
string encryption(string plain, int mat[2][2]){
    string cipher = "";
    if(plain.size() % 2 == 1){
        plain += 'z';
    }
    for(int i = 0; i < plain.size(); i += 2){
        int a = plain[i]- 'a';
        int b = plain[i+1] - 'a';
        int x = (a*mat[0][0] + b*mat[1][0]) % 26;
        int y = (a*mat[0][1] + b*mat[1][1]) % 26;
        cipher += (x+'A');
        cipher += (y+'A');

    }
    return cipher;
}
int main()
{
    string plain;
    int mat[2][2], row = 2, col = 2;

    cout << "Enter the plaintext: ";
    cin >> plain;

    cout << "Enter the 2x2 Matrix:\n";
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> mat[i][j];

    if(det(mat) == 0 || modInv(det(mat)) == -1){
        cout << "Matrix is not valid\n";
        return 0;
    }
    string cipher = encryption(plain,mat);
    cout << "Ciphertext: " << cipher << endl;

    cout << "Plaintext: " << decryption(cipher,mat) << endl;

    return 0;
}
