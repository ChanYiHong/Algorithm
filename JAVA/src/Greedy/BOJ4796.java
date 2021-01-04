package Greedy;

import java.util.Scanner;

public class BOJ4796 {

    static int L, P, V, ans, quotient;
    static int count = 1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(true){
            L = sc.nextInt();
            P = sc.nextInt();
            V = sc.nextInt();
            if(L == 0 && P == 0 && V == 0){
                break;
            }
            ans = 0;
            quotient = V / P;
            ans += (quotient * L);
            if((V % P) < L){
                ans += (V % P);
            }else{
                ans += L;
            }

            System.out.println("Case " + count + ": " + ans);
            count++;
        }
    }
}

