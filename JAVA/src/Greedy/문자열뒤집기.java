package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 문자열뒤집기 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        String str = st.nextToken();

        int zero = 0;
        int one = 0;
        char standard = str.charAt(0);
        if (standard == '0') zero++;
        else one++;

        for (int i = 1; i < str.length(); i++) {
            char cur = str.charAt(i);

            if (cur != standard) {
                if (cur == '0') zero++;
                else one++;
                standard = cur;
            }
        }

        if (zero > one) System.out.println(one);
        else System.out.println(zero);

    }

}
