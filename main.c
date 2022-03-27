#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
FILE *ilk,*son;
typedef struct{
int numara;
char ad,soyad;

}uye;

typedef struct{
int kod,dogumYili;
char yazarAdi,yazarSoyadi;
}Yazar;

typedef struct{
Yazar bilgi;
char kategori,kitapAdi;
int isbn,sayfaSayisi,kitapSayisi,basimYili;
}Kitap;


void kayit_ekle();
void kayit_sil();
/*void kayit_guncelle();
void kitaplari_listele();
void odunc_alma();
void kitap_ad_arama();
void yazar_arama();

*/

int main(){
int secim,sec;
do{
printf("**Islem Secimi**\n\n");
printf("1->Kayit Olustur\n");
printf("2->Kayit Sil\n");
printf("3->Kayit Guncelle\n");
printf("4->Kitaplari Listele\n");
printf("5->Kitap odunc Al\n");
printf("6->Kitap Adina Gore Arama Yap\n");
printf("7->Yazar Adina Gore Arama Yap\n");
printf("Yapmak istediginiz islemi secin");
scanf("%d",&secim);

switch(secim){
case 1: kayit_ekle(); break;
case 2: kayit_sil(); break;
/*case 3: kayit_guncelle(); break;
case 4: kitaplari_listele(); break;
case 5: odunc_alma(); break;
case 6: kitap_ad_arama(); break;
case 7: yazar_arama(); break;

break;*/
default:
    printf("lutfen yapacaginiz islemi(1-7) secin\n\n");
    break;
}
printf("Cikis yapmak istiyorsaniz 8 e basin ya da secim islemleri icin baska sayi tuslayin\n\n ");
scanf("%d",&sec);
}while(sec!=8);
return 0;
}

void kayit_ekle(){
uye kisi;
ilk=fopen("kayitolustur.txt","r");
if(ilk==NULL)
{
    printf("dosya acilamiyor");
    exit(1);
}
printf("Ogrenci numaranizi girin: ");
scanf("%d",&kisi.numara);
printf("Adinizi girin");
scanf("%s",kisi.ad);
printf("Soyadinizi girin");
scanf("%s",kisi.soyad);
fprintf(ilk,"%d -- %s -- %s",kisi.numara,kisi.ad,kisi.soyad);
fclose(ilk);
}
void kayit_sil(){


}
