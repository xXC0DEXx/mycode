#include <stdio.h>
void menu(){
  printf("1. Daftar menu\n");
  printf("2. Belanja\n");
  printf("3. Keluar\n\n");
}//fungsi printf menu
void tabel(){
  printf("\n");
  printf("+-------+-----------------------------------------------+\n");
  printf("|\t|\t\t\t\t\t\t|\n");
  printf("|  No\t|\tNama\t\t\tHarga\t\t|\n");
  printf("|\t|\t\t\t\t\t\t|\n");
  printf("+-------+-----------------------------------------------+\n");
  printf("|\t|\t\t\t\t\t\t|\n");
  printf("|  1\t|\tCaffe Americano\t\t32K\t\t|\n");
  printf("|  2\t|\tCaffe Latte\t\t42K\t\t|\n");
  printf("|  3\t|\tGreen Tea\t\t22K\t\t|\n");
  printf("|  4\t|\tBlack Tea\t\t22K\t\t|\n");
  printf("|  5\t|\tCaramel Macchiato\t54K\t\t|\n");
  printf("|\t|\t\t\t\t\t\t|\n");
  printf("+-------+-----------------------------------------------+\n\n");
}//fungsi printf table
int main(){
int p,m,b,size=0,totalharga=0,i=0,uang,uangtmbh;
int total[50];
int harga[5]={32000,42000,22000,22000,54000};//daftar harga menu
char yn;
do {
printf("\n\t=====Selamat datang di Queen Cafe=====\n\n");
menu ();
  do{
    printf("Pilihan Anda : "); scanf(" %d", &p);//memastikan user menginut pilihan yang tersedia
    if(p<1||p>3){printf("\n");printf("Maaf, Input Anda Tidak Sesuai !\n");}
  }while (!(p==1||p==2||p==3));
      if (p==1){
        tabel(); //menampilkan tabel menu jika user memilih pilihan daftar menu
        printf("Tekan Enter untuk melanjutkan..."); getchar();//fungsi press enter untuk melanjutkan
      }else if(p==2){
        printf("\n");
          do{
            do{
              do{     //fungsi memilih menu
                printf("Inputkan Nomor Menu : ");scanf(" %d", &m);
                if(m<1||m>5){printf("\n");printf("Maaf, Input Anda Tidak Sesuai !\n");}
              }while(!(m==1||m==2||m==3||m==4||m==5)); //memastikan input menu tersedia
                  if(m>=1||m<=5){printf("Input Banyak Menu Yang Diinginkan : "); scanf(" %d", &b);printf("\n");}
                    total[i]=harga[m-1]*b; i++; //fungsi untuk menentukan harga untuk setelah itu di Masukkan dalam array total[]
                    size=size+1;//fungsi ini untuk menentukan ukuran array total[] agar bisa di jumlah
            }while(!(m==1||m==2||m==3||m==4||m==5));
              do{//fungsi untuk memilih menu lagi jika user ingin menu yg lain
              printf("Apakah Anda Ingin Menu Lainnya (y/n)? "); scanf(" %c", &yn);printf("\n");
              if(!(yn=='y'||yn=='n')){printf("\n");printf("Maaf, Input Anda Tidak Sesuai !\n");}
            }while(!(yn=='y'||yn=='n'));//memastikan user menginput y atau n
         }while(yn=='y');
            if(yn=='n'){
                for(i=0; i < size; i++){
                  totalharga = totalharga + total[i];//fungsi ini menentukan total harga belanjaan
                }
                printf("Total Belanjaan        :Rp. %d\n", totalharga);
                printf("Masukkan Uang Anda     :Rp. ");scanf(" %d", &uang);
                printf("\n");
                if(totalharga<=uang){
                  printf("----------------------------------\n");
                  printf("Kembalian Anda         :Rp. %d\n\n", uang-totalharga);
                }else if(totalharga>uang){
                    printf("Uang Tidak Cukup       :Rp. %d\n", totalharga-uang);
                    printf("Masukkan Uang Tambahan :Rp. ");scanf(" %d", &uangtmbh);
                    printf("----------------------------------\n");
                    uang=uang+uangtmbh;
                    printf("Kembalian Anda         :Rp. %d\n\n",uang-totalharga);
                }
                printf("\t=====Terimakasih Telah Berkunjung=====\n");
                break;
             }
      }else if(p==3){
        printf("\n\t=====Terimakasih Telah Berkunjung=====\n");
          break;
          //menghentikan program jika user memilih pilihan keluar
      }
}while(getchar() == '\n');/*loop untuk mengulang seluruh program jika user
                          telah meihat menu dan ingin membeli(enter untuk lanjut)*/
return 0;
}