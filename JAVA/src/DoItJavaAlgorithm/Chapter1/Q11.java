package DoItJavaAlgorithm.Chapter1;

import java.util.Scanner;

public class Q11 {

    static int cipher(int n){
        int ret = 1;
        while(n >= 10) {
            n /= 10;
            ret++;
        }
        return ret;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n;
        do{
            n = sc.nextInt();
        }while(n < 0);

        System.out.println(cipher(n));

    }

}
