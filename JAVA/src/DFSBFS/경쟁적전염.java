package DFSBFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 경쟁적전염 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] graph = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine());
            for (int j = 0; j < n; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(bf.readLine());
        int s = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        int[][] check = new int[n][n];
        int virusNum = 1;

        Queue<int[]> queue = new LinkedList<>();

        // 초기에 한번만 순서대로 넣자.
        while (virusNum <= k) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == virusNum) {
                        queue.offer(new int[]{i, j});
                        check[i][j] = 1;
                    }
                }
            }
            virusNum++;
        }

        while (!queue.isEmpty()) {

            int[] cur = queue.poll();
            int a = cur[0];
            int b = cur[1];

//            System.out.println(a + ", " + b);
//            System.out.println(graph[a][b]);

            if (check[a][b] > s) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nx = a + dx[i];
                int ny = b + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (graph[nx][ny] == 0 && check[nx][ny] == 0) {
                        graph[nx][ny] = graph[a][b];
                        check[nx][ny] = check[a][b] + 1;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }

        }

//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                System.out.print(graph[i][j]);
//            }
//            System.out.println();
//        }

        System.out.println(graph[x - 1][y - 1]);

    }

}
