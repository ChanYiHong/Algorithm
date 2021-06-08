package BellmanFord;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Edge {

    int start;
    int end;
    int weight;

    public Edge(int start, int end, int weight) {
        this.start = start;
        this.end = end;
        this.weight = weight;
    }

}

public class BOJ11657 {

    private static List<Edge> edges;
    private static Long[] distance;
    private static int N;
    private static int M;
    private static final Long INF = Long.MAX_VALUE;

    public static boolean bellmanFord(int start) {

        distance[start] = 0L;

        /** 최단 경로가 나오는 최대 간선의 개수 N-1개 (모든 점을 거쳐야 최단 거리인 경우가 있을 수 있음)
         *  그리고 모든 간선의 경우를 매번 다 확인해야 함! 이게 핵심. **/
        for(int i = 0; i < N-1; i++) {
            for(int j = 0; j < M; j++) {
                Edge edge = edges.get(j);

                if(distance[edge.start] != INF && distance[edge.end] > distance[edge.start] + edge.weight) {
                    distance[edge.end] = distance[edge.start] + edge.weight;
                }
            }
        }

        /** 한번 더 돌렸는데 또 변화가 있으면 그건 음의 사이클(음의 무한대로 발산.)이 생겼다는 뜻이므로 false를 반환시켜 멈춤. **/
        for(int i = 0; i < N-1; i++) {
            for(int j = 0; j < M; j++) {
                Edge edge = edges.get(j);

                if(distance[edge.start] != INF && distance[edge.end] > distance[edge.start] + edge.weight) {
                    return false;
                }
            }
        }

        return true;

    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // 정점 개수
        M = Integer.parseInt(st.nextToken()); // 간선 개수

        distance = new Long[N + 1];
        edges = new ArrayList<>();

        Arrays.fill(distance, INF);

        for(int i = 0; i < M; i++) {

            st = new StringTokenizer(br.readLine());

            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            edges.add(new Edge(s, e, w));
        }

        if(!bellmanFord(1)) {
            System.out.println(-1);
        }else {
            for(int i = 2; i <= N; i++) {
                if(distance[i] == INF) System.out.println(-1);
                else System.out.println(distance[i]);
            }
        }

    }

}
