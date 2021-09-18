package Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 미래도시 {

    static class Edge {
        int start;
        int end;

        public Edge (int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<List<Integer>> graph = new ArrayList<>();

        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(bf.readLine());

            int node1 = Integer.parseInt(st.nextToken());
            int node2 = Integer.parseInt(st.nextToken());

            graph.get(node1).add(node2);
            graph.get(node2).add(node1);
        }

        st = new StringTokenizer(bf.readLine());

        int x = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] distance = floydWarshall(graph, n);

        if (distance[1][k] == 987654321 || distance[k][x] == 987654321) {
            System.out.println(-1);
        } else{
            System.out.println(distance[1][k] + distance[k][x]);
        }

//        int answer = 0;
//
//        int[] distance = new int[n + 1];
//        boolean[] visited = new boolean[n + 1];
//        Arrays.fill(distance, 987654321);
//
//        Queue<Integer> queue = new LinkedList<>();
//
//        distance[1] = 0;
//        queue.offer(1);
//
//
//        // 1 -> K
//        while (!queue.isEmpty()) {
//
//            int cur = queue.poll();
//
//            if (visited[cur]) {
//                continue;
//            }
//
//            List<Integer> adjacent = graph.get(cur);
//            for (int i = 0; i < adjacent.size(); i++) {
//                int next = adjacent.get(i);
//                if (distance[next] > distance[cur] + 1) {
//                    distance[next] = distance[cur] + 1;
//                    visited[cur] = true;
//                    queue.offer(next);
//                }
//            }
//        }
//
//        answer += distance[k];
//
//        distance = new int[n + 1];
//        visited = new boolean[n + 1];
//        Arrays.fill(distance, 987654321);
//
//        queue = new LinkedList<>();
//
//        distance[k] = 0;
//        queue.offer(k);
//
//
//        // k -> X
//        while (!queue.isEmpty()) {
//
//            int cur = queue.poll();
//
//            if (visited[cur]) {
//                continue;
//            }
//
//            List<Integer> adjacent = graph.get(cur);
//            for (int i = 0; i < adjacent.size(); i++) {
//                int next = adjacent.get(i);
//                if (distance[next] > distance[cur] + 1) {
//                    distance[next] = distance[cur] + 1;
//                    visited[cur] = true;
//                    queue.offer(next);
//                }
//            }
//        }
//
//        answer += distance[x];
//
//        System.out.println(answer);
    }

    private static int[][] floydWarshall(List<List<Integer>> graph, int n) {

        int[][] distance = new int[n + 1][n + 1];
        int INF = 987654321;

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == j) distance[i][j] = 0;
                else distance[i][j] = INF;
            }
        }

        for (int i = 0; i < graph.size(); i++) {
            List<Integer> adjacent = graph.get(i);
            int start = i;
            for (int j = 0; j < adjacent.size(); j++) {
                int end = adjacent.get(j);
                distance[start][end] = 1;
            }
        }

        // 플로이드 와샬 사용...
        for (int k = 0; k < n + 1; k++) {
            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < n + 1; j++) {
                    distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        return distance;

    }

}
