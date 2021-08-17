package Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ4485 {

    static class Edge implements Comparable<Edge>{

        int X;
        int Y;
        int weight;

        public Edge (int X, int Y, int weight) {
            this.X = X;
            this.Y = Y;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int index = 1;
        ArrayList<Edge>[][] graph;

        while (true) {
            st = new StringTokenizer(bf.readLine());
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) break;

            int[][] weights = new int[n][n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(bf.readLine());
                for (int j = 0; j < n; j++) {
                    weights[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            System.out.println("Problem " + index + ": " + new BOJ4485().dijkstra(weights));
            index++;
        }
    }

    public int dijkstra(int[][] weight) {

        int len = weight.length;

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[][] check = new boolean[len][len];
        int[][] distance = new int[len][len];

        for (int i = 0; i < len; i++) {
            Arrays.fill(distance[i], 987654321);
        }

        pq.offer(new Edge(0, 0, weight[0][0]));
        distance[0][0] = weight[0][0];

        while(!pq.isEmpty()) {

            Edge edge = pq.poll();

            if (check[edge.X][edge.Y]) {
                continue;
            }

            check[edge.X][edge.Y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = edge.X + dx[i];
                int ny = edge.Y + dy[i];

                if (nx >= 0 && nx < len && ny >= 0 && ny < len) {
                    distance[nx][ny] = Math.min(distance[nx][ny], distance[edge.X][edge.Y] + weight[nx][ny]);
                    pq.offer(new Edge(nx, ny, distance[nx][ny]));
                }
            }

        }

        return distance[len-1][len-1];

    }

}
