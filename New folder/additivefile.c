#include<stdio.h>
#include<string.h>

char a[20], b[20];     // a[] array-র মধ্যে ciphertext জমা করা হবে, আর b[] এর মধ্যে deciphertext

void encrypt(char p[], int k)              // Ciphertext এর Formula টা ছিলো এমন: C = (P + K)) % 26
{                                               // p[i] হচ্ছে lowercase character, char এর সাথে তো আর key, number-যোগ করা যাবে না
    for(int i=0; i<strlen(p); i++)                              // এইটা থেকে 'a' বাদ দিলে number পাবো, আর number এর সাথেই key গুলা যোগ করা লাগবে, then mod করবো
    {                                                               // আর lastly 'A' যোগ করে দিলে, এইটা আবার number থেকে uppercase character হয়ে যাবে
        a[i] = ((p[i]-'a'+ k) % 26) + 'A';                       // By the way, আমরা কিন্তু ciphertext টা global array a[] তে store করছি, পরে এইটা কে c[] array তে দিয়ে দিবো
    }
}

void decrypt(char c[], int k)              // Deciphertext এর Formula টা ছিলো এমন: P = (C - K) % 26
{
    for(int i=0; i<strlen(c); i++)                           // c[i] হচ্ছে uppercase character, char এর সাথে তো আর key, number বিয়োগ করা যাবে না
    {                                                               // এইখানেও encrypt এর মতোন same কাজ করা লাগবে, কিন্তু আগেরবার  শুরুতেছোটা হাতের 'a' বাদ দিছি, আর এইবার বড় হাতের 'A' যোগ করবো
        b[i] = ((c[i] + 'A' - k) % 26) + 'a';               // আর শেষে 'a' যোগ করলে number থেকে lowercase character হয়ে যাবে, আর এইবার কিন্তু b[] তে রাখছি
    }
}

int main(){

    char p[20], c[20], d[20];       // p[] তে রাখবো, plaintext, c[] তে ciphertext আর d[] তে deciphertext
    int k;

    freopen("additiveInput.txt", "r", stdin); // file-re-open function-এ file এর নাম, "read mode" এর জন্য "r", আর এইখান থেকে input নেওয়ার জন্য stdin লিখতে হবে
    scanf("%s %d", p, &k);     // input নিলাম plaintext, key

    encrypt(p, k); // encrypt() function এ plaintext key টা pass করে দিলাম, এই function টা a[] array-র মধ্যে ciphertext জমা করে দেবে
    strcpy(c, a);   // a[] তে যেই ciphertext জমা করছি, ওইটা c[] array-র মধ্যে copy করে ফেলবো
    printf("Ciphertext: %s\n", c);

    decrypt(c, k); // decrypt() function এ ciphertext key টা pass করে দিলাম, এই function টা b[] array-র মধ্যে deciphertext জমা করে দেবে
    strcpy(d, b);   // b[] তে যেই deciphertext জমা করছি, ওইটা d[] array-র মধ্যে copy করে ফেলবো
    printf("Deciphertext: %s\n", d);

    return 0;
}
