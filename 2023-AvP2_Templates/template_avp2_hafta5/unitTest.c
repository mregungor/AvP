
#include <stdio.h>
#include <string.h>
#include "hafta5.c"

//Lab icin hafta5_fonksiyon prototipleri
void hafta5_fonksiyon(int dizi[],int diziElemanSayisi, int aykiriDegerler[], double *IQR_Ptr, double *Q1_Ptr, double *Q3_Ptr, int **PtrPtr_AykiriDegerAlt, int **PtrPtr_AykiriDegerUst);
void medyanBul(int *dizi, int diziElemanSayisi, double *medyanPtr);
void diziSiralaKucuktenBuyuge(int *dizi, int diziElemanSayisi);

/*
    dizi: tamsayı dizisi, 
    diziElemanSayisi: gönderilen dizinin kaç elemanlı olduğu
    aykiriDegerler: aykırı değer değilse -1, aykırı değerse 1 değerini alan tamsayı dizisi (eleman sayısı diziElemansayisi ile aynı)
    medyanBul Fonksiyonu: sirali olarak gelen dizi elemanlarini kullanarak medyan değerini hesaplar ve işaretçiyi kullanarak atar.

    Fonskiyon İçinde Yapılacak İşlemler:
    -diziSiralaKucuktenBuyuge fonksiyonunu yazınız.
    -medyanBul fonksiyonunu yazınız. (Geçen hafta yazdığınız algoritmayı fonksiyon haline getirerek çeyrekliklikleri bulurken kullanabilirsiniz.)
    -Diziyi küçükten büyüğe sıralayınız
    -Dizideki aykırı değerleri bulunuz( minor outlier - 1.5xIQR bulmanız yeterli)
    -Aykırı değerleri bulurken hesaplattığınız IQR, Q1 ve Q3 değerlerini işaretçileri kullanarak atayınız.
    -Dizideki verileri kullanarak aykırı olan değerleri barındıran indise göre aykiriDegerler dizisindeki karşılığını -1'den 1'e çeviriniz
    -Çifte işaretçileri kullanarak ana fonksiyonda tanımlı Ptr_AykiriDegerAlt ve Ptr_AykiriDegerUst işaretçilerin adreslerini düzenleyiniz.
    
    //Medyan: https://egitimsozlugu.com/medyan-ortanca-nedir-nasil-bulunur/
    //Uç-Aykırı (outlier) değer hesaplama: https://www.wikihow.com.tr/U%C3%A7-De%C4%9Ferler-Nas%C4%B1l-Hesaplan%C4%B1r 
    //(Test amaçlı kullanabilirsiniz) Aykırı değer hesaplama aracı: https://miniwebtool.com/outlier-calculator/ 
    //Ptr_AykiriDegerAlt: Alt Aykırı değerlerin en büyüğü - daha küçük değerlerin hepsi aykırı değer
    //Ptr_AykiriDegerUst: Ust Aykırı değerlerin en küçüğü - daha büyük değerlerin hepsi aykırı değer
    //PtrPtr_AykiriDegerAlt: Ptr_AykiriDegerAlt işaretçisini gösteren işaretçi (çifte işaretçi)
    //PtrPtr_AykiriDegerUst: Ptr_AykiriDegerUst işaretçisini gösteren işaretçi (çifte işaretçi)
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
    int dizi[]={10,15,72,-50,14,300,16,-1,13,12,11};
    int diziKopya[]={10,15,72,-50,14,300,16,-1,13,12,11};
    int diziSirali[]={-50,-1,10,11,12,13,14,15,16,72,300};
    int aykiriDegerler[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int diziElemanSayisi=11;
    double medyan=0, IQR=0, Q1=0, Q3=0;


    double *medyanPtr, *IQR_Ptr, *Q1_Ptr, *Q3_Ptr;
    int *Ptr_AykiriDegerAlt;
    int *Ptr_AykiriDegerUst;
    int **PtrPtr_AykiriDegerAlt;
    int **PtrPtr_AykiriDegerUst;

    int i;

    //Adres atamalari
    medyanPtr=&medyan;
    IQR_Ptr=&IQR;
    Q1_Ptr=&Q1;
    Q3_Ptr=&Q3;
    Ptr_AykiriDegerAlt=NULL;
    Ptr_AykiriDegerUst=NULL;
    PtrPtr_AykiriDegerAlt=&Ptr_AykiriDegerAlt;
    PtrPtr_AykiriDegerUst=&Ptr_AykiriDegerUst;


    //TEST - 1 - Siralama Islemi
    printf("TEST - 1\n");
    printf("dizi siralama oncesi: \n");
    int kontrolSayac1=0, kontrolSayac2=0;
    for(i=0; i<diziElemanSayisi; i++)
    {
        printf("%d - dizi[%d]:%d",i+1,i, dizi[i]);
        if(dizi[i]==diziKopya[i]) kontrolSayac1++;
    }
    printf("\n");
    diziSiralaKucuktenBuyuge(dizi,diziElemanSayisi);
    printf("dizi siralama sonrasi: \n");
    for(i=0; i<diziElemanSayisi; i++)
    {
        printf("%d - dizi[%d]:%d",i+1,i, dizi[i]);
        if(dizi[i]==diziSirali[i]) kontrolSayac2++;
    } 
    printf("\n");
    if(kontrolSayac1==kontrolSayac2)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}


    //TEST - 2 - Medyan islemi
    printf("\n-------\n");
    printf("TEST - 2\n");
    printf("Test2-oncesi| medyan:%lf\n",medyan);
    medyanBul(dizi, diziElemanSayisi, medyanPtr);
    printf("Test2-oncesi| medyan:%lf\n",medyan);
    if((int)medyan==13)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    //TEST - 3 - aykırı değer bulma
    printf("\n-------\n");
    printf("TEST - 3\n");

    //Aykiri değer hesaplama
    hafta5_fonksiyon(dizi, diziElemanSayisi, aykiriDegerler, IQR_Ptr, Q1_Ptr, Q3_Ptr, PtrPtr_AykiriDegerAlt, PtrPtr_AykiriDegerUst);

    if(Ptr_AykiriDegerAlt == &dizi[1])
    {
        printf("Ptr_AykiriDegerAlt DOGRU\n");
        dogrutestsayisi++;
    }else{printf("Ptr_AykiriDegerAlt YANLIS\n");}
    if(Ptr_AykiriDegerUst == &dizi[9])
    {
        printf("Ptr_AykiriDegerUst DOGRU\n");
        dogrutestsayisi++;
    }else{printf("Ptr_AykiriDegerAlt YANLIS\n");}

    //TEST - 4 - aykırı değer bulma 2
    printf("\n-------\n");
    printf("TEST - 4\n");
    if(Q1 == 10)
    {
        printf("Q1:%lf DOGRU\n",Q1);
        dogrutestsayisi++;
    }else{printf("Q1:%lf YANLIS\n",Q1);}
    if(Q3 == 16)
    {
        printf("Q3:%lf DOGRU\n",Q3);
        dogrutestsayisi++;
    }else{printf("Q3:%lf YANLIS\n",Q3);}
    if(IQR == 6)
    {
        printf("IQR:%lf DOGRU\n",IQR);
        dogrutestsayisi++;
    }else{printf("IQR:%lf YANLIS\n",IQR);}


    //TEST - 5 - aykırı değer bulma 3
    printf("\n-------\n");
    printf("TEST - 5\n");
    int kontrolSayac3=0;
    int kontrolSayac4=0;
    for(i=0; i<diziElemanSayisi; i++)
    {
        if(aykiriDegerler[i]==1) kontrolSayac3++;
        if(aykiriDegerler[i]==-1) kontrolSayac4++;
    }
    if(aykiriDegerler[0]==1 && aykiriDegerler[1]==1 && aykiriDegerler[9]==1 && aykiriDegerler[10]==1)
    {
        printf("aykiriDegerler dizisi DOGRU\n");
        dogrutestsayisi++;
    }else{printf("aykiriDegerler dizisi YANLIS\n");}
    if(kontrolSayac3==4 && kontrolSayac4==7)
    {
        printf("aykiriDegerler dizisi DOGRU\n");
        dogrutestsayisi++;
    }else{printf("aykiriDegerler dizisi YANLIS\n");}

    //TEST - 6 - aykırı değer bulma 3
    printf("\n-------\n");
    printf("TEST - 6\n");
    if(Ptr_AykiriDegerAlt!=NULL && Ptr_AykiriDegerUst!=NULL)
    {
        if(Q1-1.5*IQR>*Ptr_AykiriDegerAlt && Q3+1.5*IQR<*Ptr_AykiriDegerUst)
        {
            printf("aykiriDegerler dogrulama - DOGRU\n");
            dogrutestsayisi++;
        }else{printf("aykiriDegerler dogrulama - YANLIS\n");}
    }else{printf("Ptr_AykiriDegerAlt ve Ptr_AykiriDegerUst NULL - YANLIS\n");}

    //Son Yapilan İslemler
    int puan=dogrutestsayisi*10;
    printf("Puan: %d", puan);
    fprintf(fp, "Puan: %d", puan);
    fclose(fp);

    return 0;
}
