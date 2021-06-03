package Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Edge implements Comparable<Edge> {

    int node;
    int weight;

    public Edge(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge o) {
        return Integer.compare(this.weight, o.weight);
    }

}

public class BOJ1753 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken()); // 정점 개수
        int E = Integer.parseInt(st.nextToken()); // 간선 개수

        st = new StringTokenizer(br.readLine());  // 한줄 한줄 입력마다 StringTokenizer 갱신.

        int K = Integer.parseInt(st.nextToken()); // 시작점

        int[] distance = new int[V+1];
        boolean[] visited = new boolean[V+1];
        Arrays.fill(distance, 987654321);

        ArrayList<Edge>[] graph = (ArrayList<Edge>[]) new ArrayList[V+1]; // Graph 를 만들기 위해 ArrayList 배열 만들기.

        for (int i = 1; i <= V; i++) {
            graph[i] = new ArrayList<Edge>();
        }

        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            graph[start].add(new Edge(end, w));
        }

        distance[K] = 0; // 시작점은 자기 자신으로 가는 거리를 0으로.

        PriorityQueue<Edge> pq = new PriorityQueue<>(); // 우선순위 큐 생성. Min Heap으로.. (weight 기준.)

        pq.offer(new Edge(K, 0)); // 최초 자기 자신으로 가는 edge를 넣고 시작.
        
        while(!pq.isEmpty()) {
            Edge edge = pq.poll();

            if(visited[edge.node]) {  // 방문한 적이 있으면 패스.
                continue;
            }

            visited[edge.node] = true; // 방문 했다고 표시.

            for(Edge next : graph[edge.node]) {  // 해당 점에서 갈 수 있는 edge를 그래프에서 찾음.
                if(!visited[next.node]) {
                    // 해당 점까지의 현재 최단거리랑, 현재 점까지의 최단거리 + 현재 점에서 해당 점까지의 weight 를 더한 것중 작은 것으로 갱신.
                    distance[next.node] = Math.min(distance[next.node], distance[edge.node] + next.weight);
                    // 해당 점, 해당 점까지의 최단 거리로 edge를 넣기.
                    pq.offer(new Edge(next.node, distance[next.node]));
                }
            }

        }

        // 단순 출력.
        for(int i = 1; i < distance.length; i++) {
            if(distance[i] == 987654321) {
                System.out.println("INF");
            } else {
                System.out.println(distance[i]);
            }
        }

    }

}
