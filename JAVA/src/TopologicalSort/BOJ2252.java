package TopologicalSort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/** 위상 정렬. (그래프 정렬) **/
public class BOJ2252 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<Integer>[] graph = new ArrayList[N+1];
        /** 나를 가르키고 있는 간선의 수. **/
        int[] inDegree = new int[N+1];

        for(int i = 0; i < N+1; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(bf.readLine());

            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            graph[A].add(B);
            inDegree[B]++;
        }

        Queue<Integer> q = new LinkedList<>();
        Queue<Integer> result = new LinkedList<>();

        // indegree값이 0인 것을 큐에 넣기.
        for(int i = 1; i <= N; i++) {
            if(inDegree[i] == 0) {
                q.offer(i);
            }
        }

        while(!q.isEmpty()) {
            int node = q.poll();

            // 간선의 도착점의 indegree를 낮춤.
            for(int i = 0; i < graph[node].size(); i++) {
                int to = graph[node].get(i);

                inDegree[to]--;

                if(inDegree[to] == 0) {
                    q.offer(to);
                }
            }

            result.offer(node);
        }

        for (Integer r : result) {
            System.out.print(r + " ");
        }

    }

}
