package FloydWarshall;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ11404 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());

        int[][] distance = new int[n+1][n+1];

        for(int i = 1; i < distance.length; i++) {
            for(int j = 1; j < distance[0].length; j++) {
                if(i != j) distance[i][j] = 987654321;
            }
        }

        st = new StringTokenizer(bf.readLine());
        int m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(bf.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            distance[a][b] = Math.min(distance[a][b], w);
        }

        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(distance[i][j] > distance[i][k] + distance[k][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }

        for(int i = 1; i < distance.length; i++) {
            for (int j = 1; j < distance[0].length; j++) {
                if(distance[i][j] == 987654321) {
                    System.out.print(0 + " ");
                }else{
                    System.out.print(distance[i][j] + " ");
                }
            }
            System.out.println();
        }

    }

}
