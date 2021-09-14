package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class 큰수의법칙 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Integer[] integerArr = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Arrays.sort(integerArr, Comparator.reverseOrder());

        if (integerArr[0] == integerArr[1]) {
            System.out.println(integerArr[0] * M);
        }
        else {
            int secondIterCnt = M / (K + 1);
            int firstIterCnt = M - secondIterCnt;
            System.out.println((integerArr[0] * firstIterCnt) + (integerArr[1] * secondIterCnt));
        }

    }

}
