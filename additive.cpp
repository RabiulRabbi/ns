#include<bits/stdc++.h>
using namespace std;

string encryption(string s, int k){
    int n = s.length();
    for(int i = 0; i < n; i++){
        s[i] = (s[i] - 'a' + k)%26 + 'A';
    }
    return s;
}
string decryption(string s, int k){
    int n = s.length();
    for(int i = 0; i < n; i++){
        s[i] = ((s[i] - 'A' - k)+26)%26 + 'a';
    }
    return s;
}


int main(){
    string plaintext;
    int key;
    cout<<"Enter the plaintext: ";
    cin>> plaintext;
    cout<<"Enter the key: ";
    cin>>key;
    string ciphertext = encryption(plaintext,key);
    cout<<"Ciphertext is: "<< ciphertext <<"\n";
    plaintext = decryption(ciphertext, key);
    cout<< "Plaintext is: "<< plaintext <<"\n";
}
