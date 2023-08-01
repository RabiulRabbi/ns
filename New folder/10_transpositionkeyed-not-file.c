#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[100], b[100];
int bog = -1;

void encrypt(char p[], int k[], int nk)
{
    int n = strlen(p);
    if(bog == -1)
    {
        bog = nk - (n % nk);
        for(int i=0; i<bog; i++)
        {
            p[n] = 'z';
            n++;
        }
    }

    for(int i=0; i<n; i+=nk)
        for(int j=0; j<nk; j++)
            a[i+j] = p[i+k[j]-1];

    for(int i=0; i<n; i++)
        a[i] = toupper(a[i]);
}

void decrypt(char c[], int k[], int nk)
{
    int n = strlen(c);
    int newk[nk];

    for(int i=0; i<nk; i++)
        newk[k[i]-1] = i+1;

    encrypt(c, newk, nk);
    strcpy(b, a);

    for(int i=0; i<n; i++)
        b[i] = tolower(b[i]);
}

int main()
{
    char p[100], c[100], d[100];
    printf("Enter the plaintext: ");
    scanf("%s", p);

    int k[] = {3, 1, 4, 5, 2};
    int nk = 5;

    encrypt(p, k, nk);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c, k, nk);
    strcpy(d, b);
    printf("Plaintext: %s\n", d);

    return 0;

}

