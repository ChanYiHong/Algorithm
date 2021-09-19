package Kruskal;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 도시분할계획 {

    static class Edge implements Comparable<Edge> {

        int node1;
        int node2;
        int weight;

        public Edge(int node1, int node2, int weight) {
            this.node1 = node1;
            this.node2 = node2;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        PriorityQueue<Edge> pq = new PriorityQueue<>();

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(bf.readLine());

            int node1 = Integer.parseInt(st.nextToken());
            int node2 = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            pq.offer(new Edge(node1, node2, weight));
        }

        int[] parent = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }

        int answer = 0;
        int maxWeight = 0;

        while(!pq.isEmpty()) {

            Edge edge = pq.poll();

            if (!isSameParent(edge.node1, edge.node2, parent)) {
                union(edge.node1, edge.node2, parent);
                answer += edge.weight;
                maxWeight = Math.max(maxWeight, edge.weight);
            }

        }

        // 젤 큰 금액을 빼서 간선을 빼버리고 두 도시로 나눔.
        answer -= maxWeight;

        System.out.println(answer);

    }

    private static int findParent(int x, int[] parent) {

        if (parent[x] != x) {
            return parent[x] = findParent(parent[x], parent);
        }
        return parent[x];

    }

    private static void union(int x, int y, int[] parent) {

        int a = findParent(x, parent);
        int b = findParent(y, parent);

        if (a != b) {
            if (a > b) {
                parent[a] = b;
            } else {
                parent[b] = a;
            }
        }
    }

    private static boolean isSameParent(int x, int y, int[] parent) {

        int a = findParent(x, parent);
        int b = findParent(y, parent);

        if (a == b) return true;
        else return false;

    }

}
