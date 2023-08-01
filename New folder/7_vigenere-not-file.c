#include<stdio.h>
#include<string.h>

char a[100], b[100];

void encrypt(char p[], char k[])
{
    int n = strlen(p);
    int nk = strlen(k);

    int kstream[n];
    for(int i=0, j=0; i<n; i++, j++)
    {
        if(j == nk)
            j = 0;
        kstream[i] = k[j] - 'a';
    }

    for(int i=0; i<n; i++)
        a[i] = (p[i] - 'a' + kstream[i]) % 26 + 'A';
}

void decrypt(char c[], char k[])
{
    int n = strlen(c);
    int nk = strlen(k);

    int kstream[n];
    for(int i=0, j=0; i<n; i++, j++)
    {
        if(j == nk)
            j = 0;
        kstream[i] = k[j] - 'a';
    }

    for(int i=0; i<n; i++)
        b[i] = (c[i] + 'A' - kstream[i]) % 26 + 'a';
}

int main(){

    char p[100], c[100], d[100], k[100];
    printf("Enter the plaintext: ");
    scanf("%s", p);

    printf("Enter the key-stream (lowercase): ");
    scanf("%s", k);

    encrypt(p, k);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c, k);
    strcpy(d, b);
    printf("Plaintext: %s\n", d);

    return 0;
}

