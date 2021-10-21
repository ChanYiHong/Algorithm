package Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 화성탐사 {

    static class Edge implements Comparable<Edge>{

        private int x;
        private int y;
        private int weight;

        public Edge(int x, int y, int weight) {
            this.x = x;
            this.y = y;
            this.weight = weight;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public int getWeight() {
            return weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(x, o.getX());
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int t = Integer.parseInt(st.nextToken());

        for (int k = 0; k < t; k++) {
            st = new StringTokenizer(bf.readLine());
            int n = Integer.parseInt(st.nextToken());

            int[][] graph = new int[n][n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(bf.readLine());
                for (int j = 0; j < n; j++) {
                    graph[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int[][] dis = new int[n][n];
            int INF = 987654321;
            for (int i = 0; i < n; i++) {
                Arrays.fill(dis[i], INF);
            }

            int[] dx = {1, -1, 0, 0};
            int[] dy = {0, 0, 1, -1};

            dis[0][0] = graph[0][0];
            PriorityQueue<Edge> pq = new PriorityQueue<>();
            pq.offer(new Edge(0, 0, graph[0][0]));

            while (!pq.isEmpty()) {

                Edge edge = pq.poll();
                int x = edge.getX();
                int y = edge.getY();
                int weight = edge.getWeight();

                if (dis[x][y] < weight) {
                    continue;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {

                        if (dis[nx][ny] > dis[x][y] + graph[nx][ny]) {
                            dis[nx][ny] = dis[x][y] + graph[nx][ny];
                            pq.offer(new Edge(nx, ny, graph[nx][ny]));
                        }

                    }
                }

            }

            System.out.println(dis[n-1][n-1]);
        }
    }
}
