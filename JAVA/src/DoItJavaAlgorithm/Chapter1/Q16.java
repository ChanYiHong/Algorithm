package DoItJavaAlgorithm.Chapter1;

import java.util.Scanner;

public class Q16 {

    static void spira(int n) {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n - i + 1; j++){
                System.out.print(' ');
            }
            for(int j = 1; j <= 2*i - 1; j++){
                System.out.print('*');
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        spira(n);
    }

}
