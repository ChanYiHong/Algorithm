package Kruskal;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge> {

    int a;
    int b;
    int weight;

    public Edge(int a, int b, int weight) {
        this.a = a;
        this.b = b;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge o) {
        if(this.weight < o.weight) {
            return -1;
        }else if(this.weight > o.weight) {
            return 1;
        }else {
            return 0;
        }
    }
}

public class BOJ1197 {

    static int[] parent;

    public static int find(int n) {
        if(parent[n] == n) {
            return n;
        }else {
            return parent[n] = find(parent[n]);
        }
    }

    public static void union(int a, int b) {
        int x = find(a);
        int y = find(b);

        if(x != y) {
            if(x > y) {
                parent[x] = y;
            } else {
                parent[y] = x;
            }
        }
    }

    public static boolean isSameParent(int a, int b) {
        int x = find(a);
        int y = find(b);

        if(x == y) return true;
        else return false;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        parent = new int[V+1];

        List<Edge> graph = new ArrayList<>();


        for(int i = 1; i <= V; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(bf.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            graph.add(new Edge(a, b, w));
        }

        Collections.sort(graph);

        int sum = 0;

        for(Edge edge : graph) {
            if(!isSameParent(edge.a, edge.b)) {
                sum += edge.weight;
                union(edge.a, edge.b);
            }
        }

        System.out.println(sum);

    }

}
