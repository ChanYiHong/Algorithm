package Dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 숫자일로만들기 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());

        int[] D = new int[30001];

        Arrays.fill(D, 987654321);

        D[1] = 0;

        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0) {
                D[i] = Math.min(D[i], D[i/5] + 1);
            }
            if (i % 3 == 0) {
                D[i] = Math.min(D[i], D[i/3] + 1);
            }
            if (i % 2 == 0) {
                D[i] = Math.min(D[i], D[i/2] + 1);
            }
            D[i] = Math.min(D[i], D[i-1] + 1);
        }

        System.out.println(D[n]);

    }
}
