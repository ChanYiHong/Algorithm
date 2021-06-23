package Greedy;

import java.util.*;

public class 최솟값만들기 {

    class Solution
    {
        public int solution(int []A, int []B)
        {
            int answer = 0;

//         Arrays.sort(A);
//         Integer[] tempB = Arrays.stream(B).boxed().toArray(Integer[] :: new);
//         Arrays.sort(tempB, Collections.reverseOrder());

            Queue<Integer> pqA = new PriorityQueue<Integer>();
            Queue<Integer> pqB = new PriorityQueue<Integer>((a, b) ->{
                return Integer.compare(b, a);
            });

            for(int i = 0; i < A.length; i++) {
                pqA.offer(A[i]);
                pqB.offer(B[i]);
            }

            while(!pqA.isEmpty()) {
                int a = pqA.poll();
                int b = pqB.poll();

                answer += a * b;
            }

            return answer;
        }
    }
}
