package Kruskal;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1922 {

    static class Edge implements Comparable<Edge>{

        int start;
        int next;
        int weight;

        public Edge(int start, int next, int weight) {
            this.start = start;
            this.next = next;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    static int[] parent;

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(bf.readLine());
        int M = Integer.parseInt(st.nextToken());

        PriorityQueue<Edge> pq = new PriorityQueue<>();

        parent = new int[N+1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(bf.readLine());

            int start = Integer.parseInt(st.nextToken());
            int next = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            pq.offer(new Edge(start, next, weight));
        }

        int sum = 0;

        while(!pq.isEmpty()) {

            Edge edge = pq.poll();
            if (!isSameParent(edge.start, edge.next)) {
                union(edge.start, edge.next);
                sum += edge.weight;
            }

        }

        System.out.println(sum);

    }

    public static int findParent(int x) {

        if (parent[x] == x) {
            return x;
        } else {
            return parent[x] = findParent(parent[x]);
        }

    }

    public static void union(int x, int y) {

        int nx = findParent(x);
        int ny = findParent(y);

        if (nx != ny) {
            if (nx > ny) {
                parent[nx] = ny;
            } else {
                parent[ny] = nx;
            }
        }
    }

    public static boolean isSameParent(int x, int y) {

        int nx = findParent(x);
        int ny = findParent(y);

        if (nx == ny) return true;
        else return false;

    }

}
