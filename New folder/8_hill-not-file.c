#include<stdio.h>
#include<string.h>

char a[100], b[100];

int modInv(int a)
{
    a = a % 26;
    for(int i=1; i<26; i++)
    {
        if((a*i) % 26 == 1)
            return i;
    }
    return -1;
}

int det(int mat[][2])
{
    return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
}

void encrypt(char p[], int mat[][2])
{
    int n = strlen(p);
    if(n % 2 == 1)
    {
        p[n] = 'z';
        n++;
    }

    for(int i=0; i<n; i+=2)
    {
        int m = p[i] - 'a';
        int n = p[i+1] - 'a';
        int x = (m*mat[0][0] + n*mat[1][0]) % 26;
        int y = (m*mat[0][1] + n*mat[1][1]) % 26;
        a[i] = (x + 'A');
        a[i+1] = (y + 'A');
    }
}

void decrypt(char c[], int mat[2][2])
{
    int deter = det(mat);
    int invDet = modInv(deter);

    int invMat[2][2];
    invMat[0][0] = (mat[1][1] * invDet) % 26;
    invMat[0][1] = (((-1) * (mat[0][1] * invDet) % 26) + 26) % 26;
    invMat[1][0] = (((-1) * (mat[1][0] * invDet) % 26) + 26) % 26;
    invMat[1][1] = (mat[0][0] * invDet) % 26;

    int n = strlen(c);
    for(int i=0; i<n; i+=2)
    {
        int m = c[i] - 'A';
        int n = c[i+1] - 'A';
        int x = (m*invMat[0][0] + n*invMat[1][0]) % 26;
        int y = (m*invMat[0][1] + n*invMat[1][1]) % 26;
        b[i] = (x + 'a');
        b[i+1] = (y + 'a');
    }
}

int main()
{
    char p[100], c[100], d[100];
    printf("Enter the plaintext: ");
    scanf("%s", p);

    int mat[2][2];
    printf("Enter the 2x2 matrix:\n");
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            scanf("%d", &mat[i][j]);

    if(det(mat) == 0 || modInv(det(mat)) == -1)
    {
        printf("Matrix is not valid.\n");
        return 0;
    }

    encrypt(p, mat);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c, mat);
    strcpy(d, b);
    printf("Plaintext: %s\n", d);

    return 0;
}
