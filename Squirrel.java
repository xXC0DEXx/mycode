import java.util.Scanner;

/**
 * permainan "Jump squirrel, jump!".
 * 
 * @author (Zul Akhyar_2008107010080)
 * @version (29/10/2021)
 * 
 */

public class Squirrel 
{

    /**
     * menampilkan angka 1-100 dari array 10x10
     */
    static void angka()
    {
        //array 10x10
        int[][] num = new int[10][10];
        /* 
        mengisi nilai pada array satu per satu sampai index
        terakhir dengan meng-increment nilai x
        */
        int x=0;
        for (int i = 0; i < num.length; i++) {
            for (int j = 0; j < num.length; j++) {
                //mengisi setiap index array
                num[i][j] = ++x;

                //print ke layar nilai pada setiap index
                System.out.print("[" + num[i][j] + "]" + " ");

                //lanjut print pada baris baru jika index j=9/nilai = 10,20,...,100
                if(j==9){
                    System.out.print("\n");
                }
                //spasi pada index dengan nilai 1-9
                if(i==0 && j<9){
                    System.out.print(" ");                 
                }
            }
        }
    }

    /**
     * langkah2 game
     */
    static void play_game()
    {
        int min,max,limit,letak;
        min=1;
        max=99;
        limit=0;

        //letak squirrel pada angka random
        int random =(int)(min+Math.random()*(max-min));
        System.out.println("Squirrel is at number: " + random);

        //limit lompatan
        if(random<=50){
            limit=20;
        }
        else if(random>50){
            limit=10;
        }

            Scanner jump = new Scanner(System.in);

        do{

            System.out.println("jump limit : " + limit);
            //meminta input lompat 
            System.out.print("jump to : ");
            letak = jump.nextInt();
            System.out.print("\n");

           //input lompat yang diperbolehkan adalah 
            if((letak==random+1)||(letak==random+10)||(letak==random-1)||(letak==random-10)){
                //print pada angka berapa letak squirrel jika belum sampai angka 100 
                if(letak!=100){
                    System.out.println("Squirrel is at : " + letak );
                }
                //nyatakan selamat pada saat squirrel sampai pada angka 100
                else if(letak==100){
                    System.out.println("Congratulation!! Squirrel reaches its finish line at number 100!\n");
                    break;
                }
                //jika limit melompat habis/=0 maka gagal
                if(limit==0){
                    //print anda gagal
                     System.out.println("jump limit is 0 and the squirrel has not reached its finish line at number 100, you failed!\n");
                     break;
                }
                //limit berkurang setiap kali melompat
                limit=limit-1;
                random=letak;//letak awal = letak yg di input
                continue;

            }
            else{
                //ulangi input jika input lompat tidak sesuai
                 System.out.println("you can only jump to adjacentn place. try again");
                 continue;
            }
            
        }while(letak <= 100 || letak > 100);

    }

    /**
     * memulai permainan
     */
    public static void main(String[] args) 
    {
       char answer;
        do{
            angka();
            play_game();

            Scanner scan = new Scanner(System.in);

            //menanyakan ingin main lagi atau tidak
            System.out.println("type y/Y for (yes) or type n/N for (no)");
            System.out.print("Do you still want to play ? : ");
            String str = scan.next();
            answer= str.charAt(0);
            System.out.println("\n");
            //jika input = y/Y
             if (answer=='y'|| answer=='Y') {
                 continue;//main lagi
             }
             //jika input = n/N
             else if(answer=='n'|| answer=='N'){
                 break;//keluar/berhenti
             }

        }while((answer=='y'||answer=='Y'));
    }

}