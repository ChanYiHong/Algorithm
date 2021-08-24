package programmers;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class GPS {

    class Solution {
        public int solution(int n, int m, int[][] edge_list, int k, int[] gps_log) {

            int INF = 987654321;

            List<List<Integer>> graph = new ArrayList<>();
            int[][] dp = new int[k][n + 1]; // dp[i][j] : gps_log index가 i일 때 j node일 경우 최소 수정 횟수.

            for(int i = 0; i <= n; i++) {
                graph.add(new ArrayList<>());
            }

            for(int i = 0; i < m; i++) {
                int x1 = edge_list[i][0];
                int x2 = edge_list[i][1];

                graph.get(x1).add(x2);
                graph.get(x2).add(x1);
            }

            for(int i = 0; i < k; i++) {
                Arrays.fill(dp[i], INF);
            }

            dp[0][gps_log[0]] = 0;   // 승차 위치는 항상 고정.

            for (int i = 1; i < k; i++) { // 모든 gps_log 를 봄. 1부터.
                for (int j = 1; j < n + 1; j++) { // 1 ~ n 번 노드들을 봄.

                    // 먼저 어딘가의 노드에서 온게 아닌, 제자리에서 머문 경우부터 본다.
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j]);

                    // 그 후 현재 노드와 연결되어있는 다른 노드들을 찾고, 그 노드로 부터 현재 노드로 왔을 경우에 최소 수정 횟수를 갱신한다.
                    for (int c = 0; c < graph.get(j).size(); c++) {
                        int previousNode = graph.get(j).get(c);

                        // i - 1, 즉 이전 gps_info의 index일 때 previousNode에 있을 경우 최소 수정 횟수와 비교.
                        dp[i][j] = Math.min(dp[i][j], dp[i-1][previousNode]);
                    }

                    // 실제로 gps_log 현재 인덱스의 노드와 지금 보고있는 j node가 다르면, 경로 수정이 발생하므로 + 1.
                    if (j != gps_log[i]) {
                        dp[i][j]++;
                    }

                }
            }

            if (dp[k-1][gps_log[k-1]] != INF) return dp[k-1][gps_log[k-1]];
            else return -1;

        }
    }

}
