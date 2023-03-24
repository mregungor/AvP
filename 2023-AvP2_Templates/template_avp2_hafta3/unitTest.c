
#include <stdio.h>
#include <string.h>
#include "hafta3.c"

//Lab icin hafta3_fonksiyon prototipleri
void hafta3_fonksiyon_hesap(double *sonucPtr, char *islemPtr, int sayi1, int sayi2);
/*
    sonucPtr kullanarak [a islem b] hesaplamasinin sonucunu sonucPtr adresinin gosterdigi adrese atayiniz.
    Hesaplama yapilacak islemler: + , -, *, /
    Eger islem tipi icin kullanilan karakter degiskeni olan islem bu islemlerden biri degil ise
    islem degeri isaretci kullanilarak 'N' karakterini almali ve sonuc degeri 0 olmalidir.
*/

void hafta3_fonksiyon_swap(int *aPtr, int *bPtr);
/*
    aPtr ve bPtr'yi kullanarak a ve b degisken degerlerini degistiriniz.
*/


int main()
{
    FILE *fp;
    fp = fopen("not.txt", "w");
    int dogrutestsayisi=0;

    //create a .txt file
    if (fp == NULL) {
        printf("File Pointer Null. Dosya acilamadi.\n");
        return -1;
    }

//Variables
    int a,b; double sonuc; char *islemPtr; char islem;
    int *aPtr, *bPtr; double *sonucPtr;
    aPtr=&a; bPtr=&b; islemPtr=&islem; sonucPtr=&sonuc;

    
    //TEST - 1 - Swap Islemi
    printf("TEST - 1\n");
    a=2;
    b=3;
    printf("a ve b degiskenleri swap islemi oncesi: a:%d - b:%d\n",a,b);
    hafta3_fonksiyon_swap(aPtr,bPtr);
    printf("a ve b degiskenleri swap islemi sonrasi: a:%d - b:%d\n",a,b);
    if(a==3)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}
    if(b==2)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    //TEST - 2 - Toplama islemi
    printf("\n-------\n");
    printf("TEST - 2\n");
    a=2;
    b=3;
    islem='+';
    sonuc=0;

    printf("Test2-oncesi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, a, b);
    printf("Test2-sonrasi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    if(islem=='+' && sonuc==5)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    //TEST - 3 - Cikarma islemi 1
    printf("\n-------\n");
    printf("TEST - 3\n");
    a=2;
    b=3;
    islem='-';
    sonuc=0;

    printf("Test3-oncesi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, a, b);
    printf("Test3-sonrasi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    if(islem=='-' && sonuc==-1)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}
  
    //TEST - 4 - Cikarma islemi 2
    printf("\n-------\n");
    printf("TEST - 4\n");
    a=2;
    b=3;
    islem='-';
    sonuc=0;

    printf("Test4-oncesi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    hafta3_fonksiyon_swap(aPtr,bPtr);
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, a, b);
    printf("Test4-sonrasi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    if(islem=='-' && sonuc==1)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}
    

    //TEST - 5 - Carpma islemi
    printf("\n-------\n");
    printf("TEST - 5\n");
    a=2;
    b=3;
    islem='*';
    sonuc=0;

    printf("Test5-oncesi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, a, b);
    printf("Test5-sonrasi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    if(islem=='*' && sonuc==6)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    //TEST - 6 - Bolme islemi 1
    printf("\n-------\n");
    printf("TEST - 6\n");
    a=21;
    b=3;
    islem='/';
    sonuc=0;

    printf("Test6-oncesi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, a, b);
    printf("Test6-sonrasi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    if(islem=='/' && ((int)(sonuc))==7)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    //TEST - 7 - Bolme islemi 2
    printf("\n-------\n");
    printf("TEST - 7\n");
    a=2;
    b=3;
    islem='/';
    sonuc=0;

    printf("Test7-oncesi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    hafta3_fonksiyon_swap(aPtr,bPtr);
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, a, b);
    printf("Test7-sonrasi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    if(islem=='/' && ((int)(sonuc*10))==15)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    //TEST - 8 - İslem ='#'
    printf("\n-------\n");
    printf("TEST - 8\n");
    a=2;
    b=3;
    islem='#';
    sonuc=5.0;

    printf("Test8-oncesi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, a, b);
    printf("Test8-sonrasi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    if(islem=='N' && sonuc==0)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}


    //TEST - 9 - Once Islem ='+' ve Sonra Islem ='*'
    printf("\n-------\n");
    printf("TEST - 9\n");
    a=2;
    b=3;
    islem='+';
    sonuc=0.0;

    printf("Test9-oncesi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, sonuc, a);
    printf("Test9-ara cikti| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);
    islem='*';
    hafta3_fonksiyon_hesap(sonucPtr, islemPtr, sonuc, b);
    printf("Test9-sonrasi| sonuc:%lf islem:%c  - a:%d - b:%d\n",sonuc, islem, a,b);

    if(sonuc==6)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}
    printf("\n-------\n");


    //Son Yapilan İslemler
    int puan=dogrutestsayisi*10;
    printf("Puan: %d", puan);
    fprintf(fp, "Puan: %d", puan);
    fclose(fp);

    return 0;
}
