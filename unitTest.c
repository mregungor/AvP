#include <stdio.h>
#include <main.c>

int main()
{
    FILE *fp;
    fp = fopen("not.txt", "w");
    int dogrutestsayisi=0;
    //create a .txt file
    if (fp == NULL) {
        printf("Dosya acilamadi.\n");
        return -1;
    }

    int sayi1 = 10;
    int sayi2 = 2;

    // Toplama işlemi
    int sonuc1 = topla(sayi1, sayi2);
    printf("%d + %d = %d\n", sayi1, sayi2, sonuc1);
    if (sonuc1==sayi1+sayi2)
    {
        dogrutestsayisi++;  
    }
    

    // Çıkarma işlemi
    int sonuc2 = cikar(sayi1, sayi2);
    printf("%d - %d = %d\n", sayi1, sayi2, sonuc2);
    if (sonuc2==sayi1-sayi2)
    {
        dogrutestsayisi++;  
    }

    // Çarpma işlemi
    float sonuc3 = carp(sayi1, sayi2);
    printf("%d * %d = %.2f\n", sayi1, sayi2, sonuc3);
    if (sonuc3==sayi1*sayi2)
    {
        dogrutestsayisi++;  
    }

    // Bölme işlemi
    float sonuc4 = bol(sayi1, sayi2);
    printf("%d / %d = %.2f\n", sayi1, sayi2, sonuc4);
    if (sonuc4==sayi1/sayi2)
    {
        dogrutestsayisi++;  
    }
    fprintf(fp, "Dogru test sayisi: %d", dogrutestsayisi*25);
    fclose(fp);

    return 0;
}