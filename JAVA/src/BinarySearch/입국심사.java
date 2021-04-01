package BinarySearch;

import java.util.Arrays;

public class 입국심사 {

    class Solution {
        public long solution(int n, int[] times) {
            long answer = 0;

            Arrays.sort(times);

            long left = 1;
            long right = (long) n * times[times.length - 1];

            long mid = 0;
            long sum = 0;

            answer = right;

            while(right >= left) {

                sum = 0;
                mid = (left + right) / 2;

                for(int i = 0; i < times.length; i++) {
                    sum += mid / times[i];
                }

                if(sum >= n) {
                    if(answer > mid) {
                        answer = mid;
                    }
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }

            }

            return answer;
        }
    }

}
