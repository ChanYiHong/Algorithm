package Dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 개미전사 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];

        st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] D = new int[n];

        D[0] = arr[0];
        D[1] = Math.max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            D[i] = Math.max(D[i-1], D[i-2] + arr[i]);
        }

        System.out.println(D[n-1]);

    }

}
