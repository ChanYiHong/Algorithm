package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 만들수없는금액 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];

        st = new StringTokenizer(bf.readLine());

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        // target - 1 까지는 무조건 만들 수 있음이 보장됨.
        int target = 1;

        for (int i = 0; i < arr.length; i++) {
            if (target >= arr[i]) {
                target += arr[i];
            } else {
                break;
            }
        }

        System.out.println(target);

    }

}
