#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int barkod;
    char kitapAdi[30];
    char yazarAdi[30];
    char kitapTuru[20];
    char yayinEvi[30];
    int stokSayisi;
}Kitap;
typedef struct {
    char adSoyad[30];
    int TC;
    char cinsiyet;
    int telefonNo;
    char ePosta[30];
    int durum;
    
}Uye;

typedef struct{
int uyeTC,kitapBarkod;
char kitapAdi[30];
}Odunc;


void kayit_olustur(){

 system("cls");
    printf("...Kayit Olusturma Ekrani...\n\n");
    Uye uye;
    printf("TC:               "); scanf(" %d", &uye.TC);
    printf("Ad-Soyad:         "); scanf(" %[^\n]s", uye.adSoyad);
    printf("Cinsiyet:         "); scanf(" %[^\n]s", &uye.cinsiyet);
    printf("E-posta adresiniz:"); scanf(" %[^\n]s", uye.ePosta);
    printf("Telefon No:       "); scanf("%d",&uye.telefonNo);
    uye.durum=0;

    FILE * dosya=fopen("uyeler.txt", "a");
    fwrite( &uye, sizeof(Uye), 1, dosya);
    fclose(dosya);
    printf("Uye kaydi basariyla yapilmistir!\n\n");


}


void kayit_sil(){
  system("cls");
   printf("...Kayit Silme Ekrani...");
   Uye uye;
   int tc;
   int sonuc=0;
   printf("TC:       "); scanf("%d",&tc);
   FILE *dosya=fopen("uyeler.txt","r");
   FILE *ydosya=fopen("yedek.txt","w");
  
   while(fread(&uye, sizeof(Uye), 1, dosya)!= NULL )
   {
       if(tc!=uye.TC)
        fwrite(&uye,sizeof(Uye),1,ydosya);
       else
        sonuc=1;
   }
    fclose(dosya);
    fclose(ydosya);
    if(sonuc==0)
    {
        printf("%d TC numarali kisi kaydi bulunamadi\n",tc);
    }
    else
    {
    remove("uyeler.txt");
    rename("yedek.txt","uyeler.txt");
    printf("%d TC numarali uye kaydi silindi\n",tc);
    }


}
void kayit_listele(){
 system("cls");
    printf("...Uye Listeme Ekrani...\n\n");

    Uye uye;
    int kisiSayisi=0;
    FILE *dosya=fopen("uyeler.txt", "r");
    if(dosya==NULL){
        printf("dosya acilamadi!");
        exit(1);
    }

    printf("%d%-30s%-20s%-20d%-30s% d","TC","AD-SOYAD","CINSIYET","TELEFON","E-POSTA","DURUM");

    while( fscanf(dosya, "%d %s %s %d %s %d",&uye.TC,uye.adSoyad,uye.cinsiyet,&uye.telefonNo, uye.ePosta, &uye.durum)!=EOF)
    {
    printf("%-20d%-30s%-20s%-20d%-30s%-20d\n", uye.TC, uye.adSoyad, uye.cinsiyet, uye.telefonNo, uye.ePosta, uye.durum);

    kisiSayisi++;
    }
    fclose(dosya);
    printf("\nToplam uye sayisi:%d \n", kisiSayisi);

}


void kitap_ekle(){
    system("cls");
    printf("...Kitap Ekleme Ekranı...\n\n");

    Kitap kitap;
    printf("Barkod Numarasi:   "); scanf("%d", &kitap.barkod);
    printf("Kitap Adi:         "); gets(kitap.kitapAdi);
    printf("Yazar Adi:         "); gets(kitap.yazarAdi);
    printf("Kitap Turu:        "); gets(kitap.kitapTuru);
    printf("Yayin Evi:         "); gets(kitap.yayinEvi);
    printf("Stok Sayisi:       "); scanf("%d", &kitap.stokSayisi);

    FILE* dosya=fopen("kitaplar.txt","a");
    fwrite( &kitap, sizeof(Kitap),1,dosya);
    fclose(dosya);
    printf("Kitap Basariyla Eklendi.\n");
}
void kitap_sil(){
	
    system("cls");
    printf("...Kitap silme ekrani...\n\n");

    Kitap kitap;
    int barkod,sonuc=0;
    printf("Barkod     ");scanf("%d",&barkod);
    FILE *dosya=fopen("kitaplar.txt","r");
    if(dosya==NULL);
    {
        printf("Dosya Bulunamadi!");
        exit(1);
    }
    FILE *ydosya=fopen("yedek.txt","w");
    while(fread( &kitap,sizeof(Kitap),1,dosya)!=NULL ){
        if(barkod!=kitap.barkod)
        fwrite(&kitap,sizeof(Kitap),1,ydosya);
        else
        sonuc=1;
    }
    fclose(dosya);
    fclose(ydosya);
    if(sonuc==0)
    {
        printf("%d barkod numarali kitap bulunamadi. \n",barkod);
    }
    else
    {
        remove("kitaplar.txt");
        rename("yedek.txt","kitaplar.txt");
        printf("%d barkod numarali kitap silindi\n",barkod);

    }
}
void kitap_listele(){
    system("cls");
    Kitap kitap;
    printf("<== Kitap Listeleme Ekrani ==>\n\n");
    printf("%-10s %-30s %-20s %-20s %-20s %-20s \n\n", "Kitap Barkodu", "Kitap ismi", "Yazar adi", "Turu","Yayinevi","Stok sayisi");

    FILE*dosya = fopen("kitaplar.txt", "r");
    while(fread(&kitap, sizeof(Uye), 1, dosya) == 1){
        printf("%-10d %-30s %-20s %-20s %-20s %-20d%\n", kitap.barkod, kitap.kitapAdi, kitap.yazarAdi, kitap.kitapTuru,kitap.yayinEvi,kitap.stokSayisi);
    }

    fclose(dosya);


}
void kitap_odunc_al(){
	system("cls");
	int a=0;
    Kitap kitap;
    Odunc odunc;
    printf("<== Odunc Alma Ekrani ==>\n\n");
    printf("Odunc alacaginiz kitabin barkod numarasini girin: ");
    scanf("%d", &odunc.kitapBarkod);
	FILE*dosya = fopen("kitaplar.txt", "r");
    while(fread(&kitap, sizeof(Kitap), 1, dosya) !=NULL){
        if(odunc.kitapBarkod == kitap.barkod ){
            strcpy(odunc.kitapAdi, kitap.kitapAdi);
            a=1;
            break;} }
    if(a==0){
        printf("Kitap bulunamadi\nTekrar deneyin\n");
        return;
    }
    FILE*f= fopen("oduncler.txt","a");
    printf("TC kimlik numaranizi girin   : "); 
	scanf(" %[^\n]s", odunc.uyeTC ); 
	printf("Kitap odunc alma basarilidir.\n");
    fwrite(&odunc, sizeof(Odunc), 1,f);
    fclose(f);
}

void iade_et(){

}
void odunc_kitap_listesi(){
    system("cls");
    Odunc odunc;
    printf("<== Odunc kitap listesi ==>\n\n");
    printf("%-20s %-20s %-30s\n\n", "Barkod numarasi", "Kitap Ismi", "TC");

    FILE*dosya = fopen("oduncler.txt", "r");
         if(dosya==NULL){
             printf("Boyle bir dosya bulunamadi");
             exit(1);
    while(fread(&odunc, sizeof(Odunc), 1, dosya)!=EOF){
        printf("%-20d %-20s %-30d\n",odunc.kitapBarkod,odunc.kitapAdi,odunc.uyeTC);
    }
   fclose(dosya);

}}
int main()
{
int secim;
do{
printf("***Islem Secimi***\n\n");
printf("1-Kayit Olustur\n");
printf("2-Kayit Sil\n");
printf("3-Kayit Listele\n");
printf("4-Kitap Ekle\n");
printf("5-Kitap Sil\n");
printf("6-Kitaplari Listele\n");
printf("7-Odunc Al\n");
printf("8-Iade Et\n");
printf("9-Odunc Verilen Kitap Listesini Goruntule\n\n\n");
printf("Yapmak Istediginiz Islemi Secin\n");
scanf("%d",&secim);

switch(secim){
case 1: kayit_olustur(); break;
case 2: kayit_sil(); break;
case 3: kayit_listele(); break;
case 4: kitap_ekle(); break;
case 5: kitap_sil(); break;
case 6: kitap_listele(); break;
case 7: kitap_odunc_al(); break;
case 8: iade_et(); break;
case 9: odunc_kitap_listesi(); break;

default:
    printf("Lutfen yapacaginiz islemi (1-9 araligindan) secin!\n\n");
printf("Hatali secim, ana menuye yonlendiriliyorsunuz..."); break;

}



}while(secim!=10);



    return 0;
}
