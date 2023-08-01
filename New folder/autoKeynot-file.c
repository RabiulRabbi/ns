#include<stdio.h>
#include<string.h>

char a[20], b[20];     // a[] array-র মধ্যে ciphertext জমা করা হবে, আর b[] এর মধ্যে deciphertext

void encrypt(char p[], int k1)              // Ciphertext এর Formula টা ছিলো এমন: C[i] = (P[i] + K[i])) % 26
{
    int k[30];          // key stream টা generate করবো
    k[0] = k1;              // key stream এর 1st key হবে যেইটা input দিছে
    for(int i=1; i<strlen(p); i++)      // পরের key গুলা হবে plaintext এর value গুলা, 2nd key হবে 1st plaintext value, 3rd টা 2nd এর, 4th টা 3rd এর, এইভাবে
         k[i] = p[i-1] - 'a';                                // p[i] হচ্ছে lowercase character, char এর সাথে তো আর key, number-যোগ করা যাবে না
    for(int i=0; i<strlen(p); i++)                              // এইটা থেকে 'a' বাদ দিলে number পাবো, আর number এর সাথেই key গুলা যোগ করা লাগবে, then mod করবো
    {                                                               // আর lastly 'A' যোগ করে দিলে, এইটা আবার number থেকে uppercase character হয়ে যাবে
        a[i] = ((p[i]-'a'+ k[i]) % 26) + 'A';                       // By the way, আমরা কিন্তু ciphertext টা global array a[] তে store করছি, পরে এইটা কে c[] array তে দিয়ে দিবো
    }
}

void decrypt(char c[], int k1)              // Deciphertext এর Formula টা ছিলো এমন: P[i] = (C[i] - K[i]) % 26
{
    int k[30];           // key stream টা generate করবো, উপরের টার মতনই, copy করে just paste করে দেবো
    k[0] = k1;               // difference শুধু, এইখানে ciphertext থেকে key-stream বের করবো,  আগের "p" এর বদলে "c" বসবে
    for(int i=1; i<strlen(c); i++)
         k[i] = (c[i-1] + 'A' - k[i-1] ) % 26;  // আর formula টা অনেকটা 27 no. line এর decryption এর  formula-র মতোই, শুধু index "i" এর বদলে এইখানে "i+1" হবে, আর last এর "+a" টা নাই

    for(int i=0; i<strlen(c); i++)                           // c[i] হচ্ছে uppercase character, char এর সাথে তো আর key, number বিয়োগ করা যাবে না
    {                                                               // এইখানেও encrypt এর মতোন same কাজ করা লাগবে, কিন্তু আগেরবার  শুরুতেছোটা হাতের 'a' বাদ দিছি, আর এইবার বড় হাতের 'A' যোগ করবো
        b[i] = ((c[i] + 'A' - k[i]) % 26) + 'a';               // আর শেষে 'a' যোগ করলে number থেকে lowercase character হয়ে যাবে, আর এইবার কিন্তু b[] তে রাখছি
    }
}

int main(){

    char p[20], c[20], d[20];       // p[] তে রাখবো, plaintext, c[] তে ciphertext আর d[] তে deciphertext
    int k1;
    scanf("%s %d", p, &k1);     // input নিলাম plaintext, key

    encrypt(p, k1); // encrypt() function এ plaintext আর 1st key টা pass করে দিলাম, এই function টা a[] array-র মধ্যে ciphertext জমা করে দেবে
    strcpy(c, a);   // a[] তে যেই ciphertext জমা করছি, ওইটা c[] array-র মধ্যে copy করে ফেলবো
    printf("Ciphertext: %s\n", c);

    decrypt(c, k1); // decrypt() function এ ciphertext আর 1st key টা pass করে দিলাম, এই function টা b[] array-র মধ্যে deciphertext জমা করে দেবে
    strcpy(d, b);   // b[] তে যেই deciphertext জমা করছি, ওইটা d[] array-র মধ্যে copy করে ফেলবো
    printf("Deciphertext: %s\n", d);

    return 0;
}

