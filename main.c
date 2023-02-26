#include <stdio.h>

// Toplama Fonksiyonu
int topla(int sayi1, int sayi2) {
    return sayi1 + sayi2;
}

// Çıkarma Fonksiyonu
int cikar(int sayi1, int sayi2) {
    return sayi1 - sayi2;
}

// Çarpma Fonksiyonu
float carp(float sayi1, float sayi2) {
    return sayi1 * sayi2;
}


// Bölme Fonksiyonu
float bol(float sayi1, float sayi2) {
    if (sayi2 == 0) {
        printf("Hata: sifira bolme hatasi.\n");
        return 0;
    } else {
        return sayi1 / sayi2;
    }
}
