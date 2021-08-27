package programmers;

import java.util.List;
import java.util.ArrayList;

public class 줄서는방법 {

    class Solution {

        public long Factorial(int n) {

            if (n == 1) return 1;
            return n * Factorial(n - 1);

        }

        public int[] solution(int n, long k) {
            int[] answer = new int[n];

            List<Integer> ans = new ArrayList<>();
            List<Integer> numberList = new ArrayList<>();
            for(int i = 1; i <= n; i++) {
                numberList.add(i);
            }

            int i = 0;
            long remain = k - 1;
            long nFactorial = Factorial(n);
            while(i < n) {

                nFactorial = nFactorial / (n - i);
                long index = remain / nFactorial;
                answer[i++] = numberList.get((int) index);
                numberList.remove((int) index);
                remain = remain % nFactorial;

            }

            return answer;
        }
    }

}
