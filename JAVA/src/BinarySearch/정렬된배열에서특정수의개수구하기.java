package BinarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 정렬된배열에서특정수의개수구하기 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        int[] input = new int[n];

        st = new StringTokenizer(bf.readLine());

        for (int i = 0; i < n; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        int first = binarySearchFirst(input, 0, input.length - 1, x);

        if (first == -1) {
            System.out.println(-1);
        }
        else {
            int end = binarySearchEnd(input, 0, input.length - 1, x);
            System.out.println(end - first + 1);
        }

    }

    private static int binarySearchFirst(int[] input, int start, int end, int target) {

        if (start > end) return -1;

        int mid = (start + end) / 2;

        if ((mid == 0 || input[mid - 1] < target) && input[mid] == target) {
            return mid;
        }

        if (input[mid] >= target) {
            return binarySearchFirst(input, start, mid - 1, target);
        } else {
            return binarySearchFirst(input, mid + 1, end, target);
        }

    }

    private static int binarySearchEnd(int[] input, int start, int end, int target) {

        if (start > end) return -1;

        int mid = (start + end) / 2;

        if ((mid == input.length - 1 || input[mid + 1] > target) && input[mid] == target) {
            return mid;
        }

        if (input[mid] > target) {
            return binarySearchEnd(input, start, mid - 1, target);
        } else {
            return binarySearchEnd(input, mid + 1, end, target);
        }

    }


}
