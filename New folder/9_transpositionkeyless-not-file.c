#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[100], b[100];

void encrypt(char p[])
{
    int n = strlen(p);
    for(int i=0, j=0; j<(n+1)/2; i+=2, j++)
        a[j] = p[i];

    for(int i=1, j=(n+1)/2; j<n; i+=2, j++)
        a[j] = p[i];

    for(int i=0; i<n; i++)
        a[i] = toupper(a[i]);
}

void decrypt(char c[])
{
    int n = strlen(c);

    for(int i=0, j=0; i<(n+1)/2; i++, j+=2)
        b[j] = c[i];
    for(int i=(n+1)/2, j=1; j<n; i++, j+=2)
        b[j] = c[i];

    for(int i=0; i<n; i++)
        b[i] = tolower(b[i]);
}

int main()
{
    char p[100], c[100], d[100];
    printf("Enter the plaintext: ");
    scanf("%s", p);

    encrypt(p);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c);
    strcpy(d, b);
    printf("Plaintext: %s\n", d);

    return 0;

}
