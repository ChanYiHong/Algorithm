package BinarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 떡볶이떡만들기 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] riceCake = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            riceCake[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(riceCake);

        int start = 0;
        int end = riceCake[riceCake.length - 1];
        int answer = 0;

        while (start <= end) {

            System.out.println(start + " , " + end);

            int mid = (start + end) / 2;

            int result = cutRiceCake(riceCake, mid);

            // 떡의 잘린 총합이 손님이 원하는 양보다 많을 경우 더 잘라야 함.
            if (result > M) {
                start = mid + 1;
            }
            // 떡의 잘린 총합이 손님이 원하는 양보다 적으면 덜 잘라야 함.
            else {
                answer = mid; // 최대한 덜 잘렸을 때일 경우..
                end = mid - 1;
            }
        }

        System.out.println(answer);

    }

    private static int cutRiceCake(int[] riceCake, int range) {

        int sum = 0;
        for (int i = 0; i < riceCake.length; i++) {
            if (riceCake[i] <= range) continue;
            sum += riceCake[i] - range;
        }
        return sum;
    }

}
