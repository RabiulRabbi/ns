#include<stdio.h>
#include<string.h>

char a[20], b[20];     // a[] array-র মধ্যে ciphertext জমা করা হবে, আর b[] এর মধ্যে deciphertext

int mulInv(int k1)
{
    for(int i=1; i<26; i++)     // কোন number এর  multiplicative inverse হবে ১ থেকে ২৫ এর মধ্যে ঐ number, যার সাথে গুন করে 26 দিয়ে mod করলে answer 1 আসবে
    {
        if((k1 * i) % 26 == 1)      // যদি এমন number পাই, তাহলে ঐটা রে return করে দেবো
            return i;
    }
    return -1;                  // আর যদি কোন multiplicative inverse না পাই, তাহলে -1 return করে দেবো
}

void encrypt(char p[], int k1, int k2)              // Ciphertext এর Formula টা ছিলো এমন: C = ((P * K1) + K2) % 26
{                                                         // p[i] হচ্ছে lowercase character, char এর সাথে তো আর k1, k2 number গুন-যোগ করা যাবে না
    for(int i=0; i<strlen(p); i++)                              // এইটা থেকে 'a' বাদ দিলে number পাবো, আর number এর সাথেই K1 গুন করা লাগবে আর K2 যোগ করা লাগবে, then mod করবো
    {                                                               // আর lastly 'A' যোগ করে দিলে, এইটা আবার number থেকে uppercase character হয়ে যাবে
        a[i] = (((p[i]-'a')*k1 + k2) % 26) + 'A';                       // By the way, আমরা কিন্তু ciphertext টা global array a[] তে store করছি, পরে এইটা কে c[] array তে দিয়ে দিবো
    }
}

void decrypt(char c[], int k1, int k2)
{
    int k1_inv = mulInv(k1);    // k1 এর multiplicative inverse টা mulInv() function দিয়ে বের করে k1_inv এ store করলাম
                                                        // Deciphertext এর Formula টা ছিলো এমন: P = ((C - K2) + K1_INV) % 26
    for(int i=0; i<strlen(c); i++)                           // c[i] হচ্ছে uppercase character, char এর সাথে তো আর k1, k2 number গুন-যোগ করা যাবে না
    {                                                               // এইখানেও encrypt এর মতোন same কাজ করা লাগবে, কিন্তু আগেরবার  শুরুতেছোটা হাতের 'a' বাদ দিছি, আর এইবার বড় হাতের 'A' যোগ করবো
        b[i] = (((c[i] + 'A' - k2) * k1_inv) % 26) + 'a';               // আর শেষে 'a' যোগ করলে number থেকে lowercase character হয়ে যাবে, আর এইবার কিন্তু b[] তে রাখছি
    }
}

int main(){

    char p[20], c[20], d[20];       // p[] তে রাখবো, plaintext, c[] তে ciphertext আর d[] তে deciphertext
    int k1, k2;

    freopen("affineInput.txt", "r", stdin); // file-re-open function-এ file এর নাম, "read mode" এর জন্য "r", আর এইখান থেকে input নেওয়ার জন্য stdin লিখতে হবে
    scanf("%s", p);     // input নিলাম plaintext

    scanf("%d %d",&k1, &k2);    // input নিলাম key ২টা
    if(mulInv(k1) == -1)         // 1st key এর যদি multiplicative inverse না থাকে (-1 মানে নাই), তাহলে key গুলা text file-এ change করতে হবে, পরে আবার code run করা লাগবে
    {
        printf("k1 does not have multiplicative inverse. Write valid Key values in your text file and run again.\n");
        return 0;
    }

    encrypt(p, k1, k2); // encrypt() function এ plaintext আর key ২টা pass করে দিলাম, এই function টা a[] array-র মধ্যে ciphertext জমা করে দেবে
    strcpy(c, a);   // a[] তে যেই ciphertext জমা করছি, ওইটা c[] array-র মধ্যে copy করে ফেলবো
    printf("Ciphertext: %s\n", c);

    decrypt(c, k1, k2); // decrypt() function এ ciphertext আর key ২টা pass করে দিলাম, এই function টা b[] array-র মধ্যে deciphertext জমা করে দেবে
    strcpy(d, b);   // b[] তে যেই deciphertext জমা করছি, ওইটা d[] array-র মধ্যে copy করে ফেলবো
    printf("Deciphertext: %s\n", d);

    return 0;
}

