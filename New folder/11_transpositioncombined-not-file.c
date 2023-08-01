#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char a[100], b[100];

void encrypt(char p[], int k[], int nk)
{
    int n = strlen(p);
    int row = ceil((double)n/nk), col = nk;

    char mat[row][col];
    for(int i=0, l=0; i<row; i++){
        for(int j=0; j<col; j++){

            if(p[l] == '\0'){
                mat[i][j] = 'z';
                continue;
            }
            mat[i][j] = p[l];
            l++;
        }
    }

    for(int j=0, l=0; j<col; j++)
        for(int i=0; i<row; i++, l++)
            a[l] = mat[i][k[j]-1];

    n = row*col;
    for(int i=0; i<n; i++)
        a[i] = toupper(a[i]);
}

void decrypt(char c[], int k[], int nk)
{
    int n = strlen(c);
    int newk[nk];

    for(int i=0; i<nk; i++)
        newk[k[i]-1] = i+1;

    int row = ceil((double)n/nk), col = nk;

    char mat[row][col];
    for(int j=0, l=0; j<col; j++){
        for(int i=0; i<row; i++){

            mat[i][j] = c[l];
            l++;
        }
    }

    for(int i=0, l=0; i<row; i++)
        for(int j=0; j<col; j++, l++)
            b[l] += mat[i][newk[j]-1];

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


