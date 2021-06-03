package Dp;

import java.util.*;

public class 정수삼각형 {

    class Solution {

        int[][] D = new int[501][501];
        int[][] TRIANGLE;

        public int DP(int row, int col) {

            // 범위 밖
            if(!isInRange(row, col)){
                return 0;
            }

            // 탈출 조건
            if(row == 0){
                return D[0][0] = TRIANGLE[0][0];
            }

            // 메모이제이션
            if(D[row][col] != -1) {
                return D[row][col];
            }

            // 새로 만들기
            D[row][col] = Math.max(DP(row-1, col-1), DP(row-1, col)) + TRIANGLE[row][col];
            return D[row][col];

        }

        public boolean isInRange(int row, int col) {

            if(col > row) return false;
            if(row < 0 || col < 0) return false;

            return true;

        }

        public int solution(int[][] triangle) {
            int answer = 0;
            TRIANGLE = triangle;

            for(int i = 0; i < triangle.length; i++) {
                Arrays.fill(D[i], -1);
            }

            int lastLineIndex = triangle.length - 1;

            for(int i = 0; i <= lastLineIndex; i++) {
                answer = Math.max(answer, DP(lastLineIndex, i));
            }

            return answer;
        }
    }

// 바텀 업 : 이중포문
// 탑 다운 : 재귀

// [7]
// [3, 8]
// [8, 1, 0]
// [2, 7, 4, 4]

// D[N][M] = P[N][M] + max(D[N-1][M-1], D[N-1][M]);

}
