package Greedy;

import java.util.*;

public class BOJ1744 {

    static int n;
    static int[] input;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        input = new int[n];
        for(int i = 0; i < n; i++) {
            input[i] = sc.nextInt();
        }
        Arrays.sort(input);
        List<Integer> plus = new ArrayList<>();
        List<Integer> minus = new ArrayList<>();
        for(int number : input) {
            if(number <= 0) minus.add(number);
            else plus.add(number);
        }

        int ans = 0;
        boolean two = true;
        for(int i = 0; i < minus.size(); i++) {
            if(two) {
                two = false;
            } else{
                ans += (minus.get(i) * minus.get(i-1));
                two = true;
            }
        }
        if(!two) ans += minus.get(minus.size()-1);

        two = true;

        for(int i = plus.size()-1 ; i >= 0 ; i--){
            if(two) {
                two = false;
            } else {
                if(plus.get(i) == 1 || plus.get(i+1) == 1){
                    ans += plus.get(i) + plus.get(i+1);
                } else {
                    ans += (plus.get(i) * plus.get(i + 1));
                }
                two = true;
            }
        }

        if(!two) ans += plus.get(0);

        System.out.println(ans);

    }

}
