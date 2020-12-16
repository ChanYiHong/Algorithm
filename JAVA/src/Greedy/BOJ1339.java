package Greedy;

import java.util.*;

public class BOJ1339 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int numberToMultiply= 9;
        int n, answer = 0;
        List<String> strs = new ArrayList<>();
        n = sc.nextInt();
        for(int i = 0; i < n; i++){
            String input = "";
            input = sc.next();
            strs.add(input);
        }

        Integer[] alpha = new Integer[26];
        for (int i = 0; i < 26; i++){
            alpha[i] = 0;
        }

        // 각 자리수별로 알파벳 값 치환해서 더해줌.
        for (String str : strs) {
            int dot = 1;
            for(int i = str.length()-1; i >= 0; i--) {
                char num = str.charAt(i);
                alpha[num - 65] += dot;
                dot *= 10;
            }
        }

        // 알파벳 숫자 크기로 소팅
        Arrays.sort(alpha, Collections.reverseOrder());

        for (Integer integer : alpha) {
            answer += (integer * numberToMultiply);
            numberToMultiply--;
        }

        System.out.println(answer);
    }
}

/**

ACDEB

 GCF

 A = 10000
 C = 1000
 D = 100
 E = 10
 B = 1

 G = 100
 c = 10
 f = 1


 **/