#include<stdio.h>
#include<string.h>

char a[20], b[20];     // a[] array-র মধ্যে ciphertext জমা করা হবে, আর b[] এর মধ্যে deciphertext
char encMap[256], decMap[256];  // encMap[] দিয়ে ছোট হাতের letter এর সাথে বড় হাতের letter map করবো, আর decMap[] এ বড় হাতের সাথে ছোট হাতের letter

void encrypt(char p[])
{
    for(int i=0; i<strlen(p); i++)
    {
        a[i] = encMap[p[i]];          // lowercase plaintext টার mapping encMap[]-এ আছে, ঐটা a[] store করতাছে
    }
}

void decrypt(char c[])
{
    for(int i=0; i<strlen(c); i++)
    {
        b[i] = decMap[c[i]];              // uppercase ciphertext টার mapping decMap[]-এ আছে, ঐটা b[] store করতাছে
    }
}

int main(){

    char p[20], c[20], d[20];       // p[] তে রাখবো, plaintext, c[] তে ciphertext আর d[] তে deciphertext

    freopen("monosubInput.txt", "r", stdin); // file-re-open function-এ file এর নাম, "read mode" এর জন্য "r", আর এইখান থেকে input নেওয়ার জন্য stdin লিখতে হবে


    for(int i=0; i<26; i++)             // ২৬টা letter map করার জন্য loop ঘুরবে ২৬ বার
    {
        char x, y;                  // file এ character গুলা পাশাপাশি লিখে map করা আছে, তাই at a time ২টা করে character input নিবো
        scanf(" %c %c", &x, &y);            // 1st space টা কিন্তু দিতে হবে, নাহলে ভুল scan করবে

        encMap[x] = y;      // lowercase এর সাথে uppercase map করছি, encryption এর জন্য
        decMap[y] = x;          // uppercase এর সাথে lowercase map করছি, decryption এর জন্য
    }
    scanf("%s", p);     // একেবারে file এর শেষ থেকে input নিলাম plaintext

    encrypt(p); // encrypt() function এ plaintext টা pass করে দিলাম, এই function টা a[] array-র মধ্যে ciphertext জমা করে দেবে
    strcpy(c, a);   // a[] তে যেই ciphertext জমা করছি, ওইটা c[] array-র মধ্যে copy করে ফেলবো
    printf("Ciphertext: %s\n", c);

    decrypt(c); // decrypt() function এ ciphertext টা pass করে দিলাম, এই function টা b[] array-র মধ্যে deciphertext জমা করে দেবে
    strcpy(d, b);   // b[] তে যেই deciphertext জমা করছি, ওইটা d[] array-র মধ্যে copy করে ফেলবো
    printf("Deciphertext: %s\n", d);

    return 0;
}
