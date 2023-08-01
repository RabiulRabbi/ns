#include<bits/stdc++.h>
using namespace std;

string encryption(string s, int k){
    for(int i = 0; i < s.length(); i++){
        int temp = s[i]-'a';
        s[i] = (s[i] - 'a' + k)%26 + 'A';
        k = temp;
    }
    return s;
}
string decryption(string s, int k){
    for(int i = 0; i < s.length(); i++){
        int temp = s[i] - 'A' - k;
        s[i] = (s[i] - 'A' - k + 26)%26 + 'a';
        k = temp;
    }
    return s;
}

int main(){
    string plaintext;
    int key;
    cout<<"Enter the plaintext: ";
    cin>>plaintext;
    cout<<"Enter the key: ";
    cin>>key;

    string ciphertext = encryption(plaintext, key);
    cout<<"Ciphertext is: "<<ciphertext<<"\n";

    plaintext = decryption(ciphertext, key);
    cout<<"Plaintext is: "<< plaintext<<"\n";

}
