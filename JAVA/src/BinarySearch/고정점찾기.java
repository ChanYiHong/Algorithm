package BinarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 고정점찾기 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());

        int[] input = new int[n];

        st = new StringTokenizer(bf.readLine());

        for (int i = 0; i < n; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        int answer = binarySearch(input, 0, input.length - 1);

        System.out.println(answer);

    }

    private static int binarySearch(int[] input, int start, int end) {
        if (start > end) return -1;

        int mid = (start + end) / 2;

        if (input[mid] > mid) {
            return binarySearch(input, start, mid - 1);
        } else if (input[mid] < mid) {
            return binarySearch(input, mid + 1, end);
        } else {
            return mid;
        }

    }
}
