
#include <stdio.h>
#include <string.h>
#include "hafta4.c"

//Lab icin hafta4_fonksiyon prototipleri
void hafta4_fonksiyon(int *dizi,int diziElemanSayisi, int *maxPtr, int *minPtr, double *medyanPtr, double *ortalamaPtr);
/*
    dizi: tamsayı dizisi, 
    diziElemanSayisi: gönderilen dizinin kaç elemanlı olduğu

    Fonskiyon İçinde Yapılacak İşlemler:
    1-Dizideki verilerin medyan ve ortalama değerlerini hesaplayarak ilgili işaretçilerin gösterdiği adreslere bu değerleri yazınız.
        Not: Bu değerleri bulmak için sıralama yapmanız gerekirse orjinal dizideki verilerin yerlerini değiştirmeyiniz.
        (Farklı bir dizi tanımlayarak gerçekleştirebilirsiniz.)
    2-Dizideki verilerin orjinal sırasında maximum ve minimum değerlerin yer değiştirilme işlemini gerçekleştiriniz
        Not: Burada orjinal dizideki maksimum ve minumum değerler yer değiştirmelidir.
    3-Dizinin son hali üzerinde maksimum ve minumum değerlerini maxPtr ve minPtr kullanarak maxPtr ve minPtr'nin gösterdiği adreslerdeki alana atayınız.
        Not: Değişim yapmadan önceki halde atama gerçekleştirmeniz durumunda da sistem doğru olarak kabul edecektir.
    
    Önemli Not: ortalamaPtr, medyanPtr, minPtr ve maxPtr ile aldığınız adres değerlerini fonksiyon içerisinde değiştirmeyiniz. Sadece bu adresleri kullanarak değer ataması yapınız.
                Aksi takdirde hatalı adrese değer ataması yapmış olabilirsiniz.
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

    //Degiskenler
    int dizi[]={71,70,73,70,70,68,70,72,71,300,71,69};
    int diziElemanSayisi=12;
    int max=0,min=0;
    double medyan=0.0, ortalama=0.0;

    int *maxPtr, *minPtr; double *medyanPtr, *ortalamaPtr;
    maxPtr=&max; minPtr=&min; medyanPtr=&medyan; ortalamaPtr=&ortalama;

    printf("islem oncesi: max:%d - min:%d - ortalama:%lf - medyan:%lf\n",max, min, ortalama, medyan);
    hafta4_fonksiyon(dizi,diziElemanSayisi, maxPtr, minPtr, medyanPtr, ortalamaPtr);
    printf("islem sonrasi: max:%d - min:%d - ortalama:%lf - medyan:%lf\n",max, min, ortalama, medyan);
    //TEST - 1 
    printf("TEST -1 Min: \n");
    if(min==68)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    printf("\n-------\n");

    printf("TEST -2 Max: \n");
    if(max==300)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    printf("\n-------\n");

    printf("TEST - 3 - MEDYAN\n");
    if( ((int)(medyan*10))==705 ) 
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    printf("\n-------\n");

    printf("TEST - 4 - ORTALAMA\n");
    if( ((int)(ortalama*100))==8958)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}
  
    printf("\n-------\n");

    printf("TEST - 5 - MIN MAX SWAP\n");
    int kontrolDizi[]={71,70,73,70,70,300,70,72,71,68,71,69};
    int kontrolSonuc=1;
    int i;
    for(i=0; i<diziElemanSayisi; i++)
    {
        if(dizi[i]!=kontrolDizi[i])
        {
            kontrolSonuc=0;
            break;
        }
    }
    if(kontrolSonuc==1)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}
    
    printf("\n-------\n");

    //Son Yapilan İslemler
    int puan=dogrutestsayisi*20;
    printf("Puan: %d", puan);
    fprintf(fp, "Puan: %d", puan);
    fclose(fp);

    return 0;
}
