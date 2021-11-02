package OlimPlanet;

import java.util.Comparator;
import java.util.PriorityQueue;

public class WhyHomeViewNeeded {

    static class Edge implements Comparable<Edge> {
        private int node1;
        private int node2;
        private int weight;

        public Edge(int node1, int node2, int weight) {
            this.node1 = node1;
            this.node2 = node2;
            this.weight = weight;
        }

        public int getNode1() {
            return node1;
        }

        public int getNode2() {
            return node2;
        }

        public int getWeight() {
            return weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.getWeight());
        }
    }

    private static boolean isSameParent(int a, int b, int parent[]) {
        return findParent(a, parent) == findParent(b, parent);
    }

    private static void union(int a, int b, int parent[]) {
        int x = findParent(a, parent);
        int y = findParent(b, parent);

        if (x != y) {
            if (x > y) {
                parent[x] = y;
            }
            else {
                parent[y] = x;
            }
        }
    }

    private static int findParent(int x, int parent[]) {
        if (x != parent[x]) {
            return parent[x] = findParent(parent[x], parent);
        }
        return parent[x];
    }

    public static void main(String[] args) {

//        int[][] input = {{0, 611, 648}, {611, 0, 743}, {648, 743, 0}};
        int[][] input = {{0, 326, 503, 290}, {326, 0, 225, 395}, {503, 225, 0, 620}, {290, 395, 620, 0}};

        int len = input.length;
        int[] parent = new int[len];
        int answer = 0;

        for (int i = 0; i < len; i++) {
            parent[i] = i;
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len - i; j++) {
                if (i == j) continue;

                int weight = input[i][j];

                pq.offer(new Edge(i, j, weight));

            }
        }

        while(!pq.isEmpty()) {
            Edge edge = pq.poll();

            int node1 = edge.getNode1();
            int node2 = edge.getNode2();
            int weight = edge.weight;
            if (!isSameParent(node1, node2, parent)) {
                union(node1, node2, parent);
                answer += weight;
            }
        }

        System.out.println(answer);

    }
}
