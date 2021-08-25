package programmers;

import java.util.PriorityQueue;

public class 야근지수 {

    class Solution {
        public long solution(int n, int[] works) {
            long answer = 0;

            PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
                return Integer.compare(b, a);
            });

            for (int i = 0; i < works.length; i++) {
                pq.offer(works[i]);
            }

            int cnt = n;

            while(cnt > 0) {
                int top = pq.poll();
                if (top == 0) {
                    pq.offer(0);
                    cnt--;
                    continue;
                }
                pq.offer(top - 1);
                cnt--;
            }

            while(!pq.isEmpty()) {
                int top = pq.poll();
                // System.out.println(Math.pow(top, 2));
                long square = (long) Math.pow(top, 2);
                answer += square;
            }

            return answer;
        }
    }

}
