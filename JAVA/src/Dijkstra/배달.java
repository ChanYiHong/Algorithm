package Dijkstra;

import java.util.*;

public class 배달 {

    class Edge implements Comparable<Edge>{

        int node;
        int weight;

        public Edge(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge e) {
            return Integer.compare(this.weight, e.weight);
        }

    }

    class Solution {
        public int solution(int N, int[][] road, int K) {
            int answer = 0;

            List<Edge>[] graph = new ArrayList[N+1];
            int[] distance = new int[N+1];
            boolean[] visited = new boolean[N+1];

            Arrays.fill(distance, Integer.MAX_VALUE);

            for(int i = 1; i <= N; i++) {
                graph[i] = new ArrayList<>();
            }

            for(int i = 0; i < road.length; i++) {
                graph[road[i][0]].add(new Edge(road[i][1], road[i][2]));
                graph[road[i][1]].add(new Edge(road[i][0], road[i][2]));
            }

            PriorityQueue<Edge> pq = new PriorityQueue<>();

            pq.offer(new Edge(1, 0));
            distance[1] = 0;

            while(!pq.isEmpty()) {

                Edge edge = pq.poll();

                if(edge.weight > distance[edge.node]) {
                    continue;
                }

//             if(visited[edge.node]) {
//                 continue;
//             }

//             visited[edge.node] = true;

                for(Edge next : graph[edge.node]) {

                    if(distance[next.node] > distance[edge.node] + next.weight) {

                        distance[next.node] = distance[edge.node] + next.weight;
                        pq.offer(new Edge(next.node, distance[next.node]));

                    }

                    // if(!visited[next.node]) {
                    //     distance[next.node] = Math.min(distance[next.node], distance[edge.node] + next.weight);
                    //     pq.offer(new Edge(next.node, distance[next.node]));
                    // }

                }

            }

            for(int dis : distance) {
                if(dis <= K){
                    answer++;
                }
            }

            return answer;
        }
    }

}
