package Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 전보{

    static class Edge implements Comparable<Edge>{
        int weight;
        int destination;

        public Edge (int weight, int destination) {
            this.weight = weight;
            this.destination = destination;
        }

        @Override
        public int compareTo(Edge o) {
            if (this.weight != o.weight) {
                return Integer.compare(this.weight, o.weight);
            } else {
                return this.destination - o.destination;
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        List<List<Edge>> graph = new ArrayList<>();

        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(bf.readLine());

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            graph.get(start).add(new Edge(weight, end));
        }

        int[] distance = new int[n + 1];
        Arrays.fill(distance, 987654321);

        boolean[] visited = new boolean[n + 1];

        PriorityQueue<Edge> pq = new PriorityQueue<>();

        distance[c] = 0;
        pq.offer(new Edge(0, c));

        while(!pq.isEmpty()) {

            Edge cur = pq.poll();

            if (visited[cur.destination]) {
                continue;
            }

            visited[cur.destination] = true;
            List<Edge> adjacent = graph.get(cur.destination);

            for (int i = 0; i < adjacent.size(); i++) {

                Edge next = adjacent.get(i);

                if (distance[next.destination] > distance[cur.destination] + next.weight) {
                    distance[next.destination] = distance[cur.destination] + next.weight;
                    pq.offer(new Edge(distance[next.destination], next.destination));
                }

            }

        }

        int cnt = 0;
        int maximum = 0;
        for (int i = 1; i < n + 1; i++) {
            if (i == c) continue;
            if (distance[i] != 987654321) {
                cnt++;
                maximum = Math.max(maximum, distance[i]);
            }
        }

        System.out.println(cnt + " " + maximum);

    }

}
