package DFSBFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class 특정거리의도시찾기 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(bf.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            graph.get(start).add(end);
        }

        List<Integer> answer = new ArrayList<>();
        int[] check = new int[n+1];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(x);

        while (!queue.isEmpty()) {
            Integer cur = queue.poll();

            if (check[cur] == k) {
                answer.add(cur);
                continue;
            }

            List<Integer> adjacent = graph.get(cur);
            for (int i = 0; i < adjacent.size(); i++) {
                int next = adjacent.get(i);

                if (check[next] == 0) {
                    check[next] = check[cur] + 1;
                    queue.offer(next);
                }
            }
        }

        if (answer.size() == 0) {
            System.out.println(-1);
        } else {
            Collections.sort(answer);
            for (Integer ans : answer) {
                System.out.println(ans);
            }
        }
    }

}
