#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N = 250, pn = 0, n, pubK, prK;
int prime[100];
int a[1000];
char b[1000];

void prGen()
{
    int isp[1000];
    for(int i=0; i<N; i++)
        isp[i] = 1;

    for(int i=2; i<N; i++)
        for(int j=2*i; j<N; j+=i)
            isp[j] = 0;
    for(int i=0; i<N; i++)
    {
        if(isp[i] == 1)
            prime[pn++] = i;
    }
}

int randPr()
{
    int k = rand() % pn;
    return prime[k];
}

int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

void keys()
{
    int p1 = randPr(), p2 = randPr();

    n = p1*p2;
    int fi = (p1-1)*(p2-1);

    int e = 2, d = 2;

    while(gcd(e, fi) != 1)
        e++;
    pubK = e;

    while((d*e) % fi != 1)
        d++;
    prK = d;
}

int encrypt(int p)
{
    int enc = 1, e = pubK;
    while(e--)
        enc = (enc*p) % n;

    return enc;
}

void encoder(char p[], int l)
{
    for(int i=0; i<l; i++)
        a[i] = encrypt(p[i]);
}

int decrypt(int a)
{
    int dec = 1, d = prK;
    while(d--)
        dec = (dec*a) % n;

    return dec;
}

void decoder(int a[], int l)
{
    for(int i=0; i<l; i++)
        b[i] = decrypt(a[i]);
}

int main()
{
    prGen();
    keys();
    char p[1000], c[1000], d[1000];
    printf("Enter the plaintext: ");
    scanf("%s", p);

    int l = strlen(p);

    encoder(p, l);
    printf("Ciphertext: ");
    for(int i=0; i<l; i++)
        printf("%d", a[i]);

    decoder(a, l);
    printf("\nPlaintext: %s\n", b);

    return 0;
}
