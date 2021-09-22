package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 곱하기혹은더하기 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        String str = st.nextToken();

        char[] charArr = str.toCharArray();

        int sum = 0;
        sum += charArr[0] - '0';

        for (int i = 1; i < charArr.length; i++) {
            int cur = charArr[i] - '0';
            if (sum <= 1 || cur <= 1) {
                sum += cur;
            } else {
                sum *= cur;
            }
        }

        System.out.println(sum);

    }

}
