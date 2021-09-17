package BinarySearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 부품찾기 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arrange = new int[N];
        for (int i = 0; i < N; i++) {
            arrange[i] = Integer.parseInt(st.nextToken());
        }

        // 정렬 반드시 수행.
        Arrays.sort(arrange);

        st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] orders = new int[M];
        for (int i = 0; i < M; i++) {
            orders[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < M; i++) {
//            boolean result = binaryForStatement(arrange, 0, arrange.length - 1, orders[i]);
            boolean result = countSort(arrange, orders[i]);
            if (result) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

    }

    private static boolean binarySearch(int[] arrange, int start, int end, int findElement) {

        if (start >= end) {
            if (arrange[start] == findElement) return true;
            else return false;
        }

        int mid = (start + end) / 2;

        if (arrange[mid] > findElement) {
            return binarySearch(arrange, start, mid - 1, findElement);
        }
        else if (arrange[mid] < findElement) {
            return binarySearch(arrange, mid + 1, end, findElement);
        }
        // arrange[mid] == findElement
        else {
            return true;
        }

    }

    private static boolean binaryForStatement(int[] arrange, int start, int end, int findElement) {

        while (start < end) {
            int mid = (start + end) / 2;

            if (arrange[mid] > findElement) {
                end = mid - 1;
            } else if (arrange[mid] < findElement) {
                start = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }

    private static boolean countSort(int[] arrange, int findElement) {

        int max = -1;

        for (int i = 0; i < arrange.length; i++) {
            max = Math.max(max, arrange[i]);
        }

        int[] cntArr = new int[max + 1];

        for (int i = 0; i < arrange.length; i++) {
            cntArr[arrange[i]]++;
        }

        return cntArr[findElement] != 0;

    }

}
