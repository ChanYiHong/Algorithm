package DFSBFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 연구소 {

    static int answer = 0;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] graph = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine());
            for (int j = 0; j < m; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 0) {
                    graph[i][j] = 1;
                    makeWall(graph, 1);
                    graph[i][j] = 0;
                }
            }
        }

        System.out.println(answer);

    }

    private static int sumOfSafeArea(int[][] graph) {
        int ret = 0;
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[i].length; j++) {
                if (graph[i][j] == 0) {
                    ret++;
                }
            }
        }
        return ret;
    }

    private static void makeWall(int[][] graph, int cnt) {
        if (cnt == 3) {
            int[][] temp = new int[graph.length][graph[0].length];
            for (int i = 0; i < graph.length; i++) {
                temp[i] = Arrays.copyOf(graph[i], graph[i].length);
            }
            boolean[][] check = new boolean[graph.length][graph[0].length];
            for (int i = 0; i < graph.length; i++) {
                for (int j = 0; j < graph[i].length; j++) {
                    if (temp[i][j] == 2 && !check[i][j]) {
                        spreadVirus(i, j, temp, check);
                    }
                }
            }
            int ret = sumOfSafeArea(temp);
            answer = Math.max(answer, ret);
            return;
        }

        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[i].length; j++) {
                if (graph[i][j] == 0) {
                    graph[i][j] = 1;
                    makeWall(graph, cnt + 1);
                    graph[i][j] = 0;
                }
            }
        }
    }

    private static void spreadVirus(int x, int y, int[][] graph, boolean[][] check) {
        Queue<int[]> queue = new LinkedList<>();

        queue.offer(new int[]{x, y});
        check[x][y] = true;

        while(!queue.isEmpty()) {

            int[] cur = queue.poll();
            int t = cur[0];
            int s = cur[1];

            for (int i = 0; i < 4; i++) {
                int nx = t + dx[i];
                int ny = s + dy[i];
                if (nx >= 0 && nx < graph.length && ny >= 0 && ny < graph[0].length) {
                    if (!check[nx][ny] && graph[nx][ny] == 0) {
                        graph[nx][ny] = 2;
                        check[nx][ny] = true;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }

        }
    }

}
