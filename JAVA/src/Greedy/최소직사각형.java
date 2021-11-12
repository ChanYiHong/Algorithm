package Greedy;

public class 최소직사각형 {

    class Solution {
        public int solution(int[][] sizes) {
            int answer = 0;

            int width = 0;
            int height = 0;

            for (int i = 0; i < sizes.length; i++) {
                int a = sizes[i][0];
                int b = sizes[i][1];

                if (a > b) {
                    width = Math.max(width, a);
                    height = Math.max(height, b);
                } else {
                    width = Math.max(width, b);
                    height = Math.max(height, a);
                }

            }

            return answer = width * height;
        }
    }

}
