package TopologicalSort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 커리큘럼 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());

        List<List<Integer>> graph = new ArrayList<>();
        int[] inDegree= new int[n+1];
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        int[] weight = new int[n+1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(bf.readLine());
            int w = Integer.parseInt(st.nextToken());
            weight[i] = w;

            while (true) {
                int parent = Integer.parseInt(st.nextToken());
                if (parent == -1) {
                    break;
                }
                graph.get(parent).add(i);
                inDegree[i]++;
            }
        }

        Queue<Integer> queue = new LinkedList<>();
        int[] answer = Arrays.copyOf(weight, weight.length);

        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        while(!queue.isEmpty()) {

            int node = queue.poll();

            List<Integer> nextList = graph.get(node);

            for (int i = 0; i < nextList.size(); i++) {
                int next = nextList.get(i);
                answer[next] = Math.max(answer[next], answer[node] + weight[next]);
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            System.out.println(answer[i]);
        }

    }

}
