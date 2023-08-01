#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[100], b[100];
int row, col;

void findPos(char mat[][5], char ch)
{
    if(ch == 'J')
        ch = 'I';
    for(row=0; row<5; row++)
    {
        for(col=0; col<5; col++)
        {
            if(mat[row][col] == ch)
                return;
        }
    }
}

void encrypt(char p[], char mat[5][5])
{
    char ch1, ch2;
    int n = strlen(p), l = 0;
    for(int i=0; i<n; i+=2)
    {
        if(i+1 == n){
            p[n] = 'X';
            n++;
        }
        ch1 = toupper(p[i]);
        ch2 = toupper(p[i+1]);

        if(ch1 == ch2)
        {
            ch2 = 'X';
            i--;
        }

        int row1, row2, col1, col2;
        findPos(mat, ch1);
        row1 = row, col1 = col;
        findPos(mat, ch2);
        row2 = row, col2 = col;


        if(row1 == row2)
        {
            col1 = (col1 + 1) % 5;
            col2 = (col2 + 1) % 5;
        }
        else if(col1 == col2)
        {
            row1 = (row1 + 1) % 5;
            row2 = (row2 + 1) % 5;
        }
        else
        {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }
        a[l] = mat[row1][col1];
        a[l+1] = mat[row2][col2];
        l+=2;
    }
}

void decrypt(char c[], char mat[5][5])
{
    char ch1, ch2;
    int n = strlen(c), l = 0;
    for(int i=0; i<n; i+=2)
    {
        ch1 = toupper(c[i]);
        ch2 = toupper(c[i+1]);

        int row1, row2, col1, col2;
        findPos(mat, ch1);
        row1 = row, col1 = col;
        findPos(mat, ch2);
        row2 = row, col2 = col;


        if(row1 == row2)
        {
            col1 = (col1 - 1 + 5 ) % 5;
            col2 = (col2 - 1 + 5) % 5;
        }
        else if(col1 == col2)
        {
            row1 = (row1 - 1) % 5;
            row2 = (row2 - 1) % 5;
        }
        else
        {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }
        b[l] = mat[row1][col1] - 'A' + 'a';
        b[l+1] = mat[row2][col2] - 'A' + 'a';
        l+=2;
    }
}

int main()
{
    freopen("playfair.txt", "r", stdin);
    char p[100], c[100], d[100], mat[5][5];

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf("%c ", &mat[i][j]);

    scanf("%s", p);

    encrypt(p, mat);
    strcpy(c, a);
    printf("Ciphertext: %s\n", c);

    decrypt(c, mat);
    strcpy(d, b);
    printf("Plaintext: %s\n", d);

    return 0;
}
