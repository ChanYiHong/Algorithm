package FloydWarshall;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 플로이드 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(bf.readLine());

        int m = Integer.parseInt(st.nextToken());

        int[][] arr = new int[n][n];
        int INF = 987654321;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) arr[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(bf.readLine());

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            arr[start - 1][end - 1] = Math.min(arr[start - 1][end - 1] ,weight);
        }

        // Floyd Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == INF) {
                    System.out.print(0 + " ");
                }
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

}
