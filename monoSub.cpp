#include<bits/stdc++.h>
using namespace std;
char encMap[255],decMap[255];

string enc(string s){
    for(int i = 0; i < s.length(); i++){
        s[i] = encMap[s[i]];
    }
    return s;
}
string dec(string s){
    for(int i = 0; i < s.length(); i++){
        s[i] = decMap[s[i]];
    }
    return s;
}

int main(){
    freopen("input.txt","r",stdin);

    for(int i = 0; i < 26; i++){
        char a,b;
        cin>>a>>b;
        encMap[a] = b;
        decMap[b] = a;
    }
    string plaintext;
    cin>>plaintext;

    string ciphertext = enc(plaintext);
    cout<<"Ciphertext is: "<<ciphertext<<"\n";

    plaintext = dec(ciphertext);
    cout<<"Plaintext is: "<<plaintext<<"\n";

    return 0;
}
