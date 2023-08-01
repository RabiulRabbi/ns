#include<bits/stdc++.h>
using namespace std;
int multiplicativeInverse(int k){
    for(int i = 1; i < 26; i++){
        if((k * i)%26 == 1){
            return i;
        }
    }
        return -1;
}


string encryption(string s, int k){
    int n = s.length();
    for(int i = 0; i < n; i++){
        s[i] = ((s[i] - 'a') * k) % 26 + 'A';
    }
    return s;
}
string decryption(string s, int k_inv){
    int n = s.length();
    for(int i = 0; i < n; i++){
        s[i] = ((s[i] + 'A') * k_inv) % 26 + 'a';
    }
    return s;
}

int main(){
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    string plaintext;
    int key;
    //cout<<"Enter the plaintext: ";
    cin>>plaintext;
    //cout<<"Enter the key: ";
    cin>>key;
    int mulInv = multiplicativeInverse(key);
    if(mulInv == -1){
        cout<<"There is no multiplicative inverse in that key......! \n";
        return 0;
    }
    string ciphertext = encryption(plaintext,key);
    cout<<"Ciphertext is: "<<ciphertext<<"\n";

    plaintext = decryption(ciphertext, mulInv);
    cout<<"Plaintext is: "<<plaintext<<"\n";


}
