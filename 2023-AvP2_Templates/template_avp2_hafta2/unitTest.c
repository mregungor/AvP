#include <stdio.h>
#include <string.h>
#include "hafta2.c"

//Lab icin hafta2_fonksiyon prototipi 
void hafta2_fonksiyon(char yazi[], int yaziBoyutu, int kaymaMiktari);
/*
Pozitif kayma miktarı sağa doğru kaydırma, Negatif kayma miktarı sola doğru kaydırma olmalı
*/


void initializeArray(char *Arry, int size, char *InitArry)
{
    int i;
    for(i=0; i<size; i++)
    {
        Arry[i]=InitArry[i];
    }
}

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
    char originalArray[] = "yolculuk";
    char input_arr[]  = "yolculuk"; 
    int arrSize= strlen(originalArray);
    int shift=0;

    printf("Dizi Boyutu: %d\n",arrSize);
    
    //TEST - 1
    shift=1;
    char testStr1[] = "kyolculu";    

    hafta2_fonksiyon(input_arr, arrSize, shift);
    printf("%d - Kaydirma Sonucu: %s\n",shift, input_arr);
    if(strcmp(input_arr,testStr1) == 0)
        dogrutestsayisi++;

    //TEST - 2
    shift=-1;
    char testStr2[] = "olculuky";
    initializeArray(input_arr,arrSize, originalArray);

    hafta2_fonksiyon(input_arr, arrSize, shift);
    printf("%d - Kaydirma Sonucu: %s\n",shift, input_arr);
    if(strcmp(input_arr,testStr2) == 0)
        dogrutestsayisi++;

    initializeArray(input_arr,arrSize, originalArray);

    //TEST - 3
    shift=-2;
    char testStr3[] = "lculukyo";
    initializeArray(input_arr,arrSize, originalArray);

    hafta2_fonksiyon(input_arr, arrSize, shift);
    printf("%d - Kaydirma Sonucu: %s\n",shift, input_arr);
    if(strcmp(input_arr,testStr3) == 0)
        dogrutestsayisi++;

    //TEST - 4
    shift=7;
    char testStr4[] = "olculuky";
    initializeArray(input_arr,arrSize, originalArray);

    hafta2_fonksiyon(input_arr, arrSize, shift);
    printf("%d - Kaydirma Sonucu: %s\n",shift, input_arr);
    if(strcmp(input_arr,testStr4) == 0)
        dogrutestsayisi++;
    

    //Son Yapilan İslemler
    int puan=dogrutestsayisi*25;
    printf("Puan: %d", puan);
    fprintf(fp, "Puan: %d", puan);
    fclose(fp);

    return 0;
}