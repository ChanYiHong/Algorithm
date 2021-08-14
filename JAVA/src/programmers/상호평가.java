package programmers;

import java.lang.Math;
import java.util.*;


public class 상호평가 {

    class Solution {

        public double getAverage(int[][] scores, int col) {

            int maximum = -1;
            int minimum = 101;
            int sum = 0;
            // List<Integer> list = new ArrayList<>();

            for (int i = 0; i < scores.length; i++) {

                if (col == i) continue;

                maximum = Math.max(maximum, scores[i][col]);
                minimum = Math.min(minimum, scores[i][col]);

                sum += scores[i][col];

                // list.add(scores[i][col]);

            }

            if (scores[col][col] > maximum || scores[col][col] < minimum) {
                return sum / (double) (scores.length - 1);
            }

//         int lamdaMax = maximum;
//         int lamdaMin = minimum;

//         int maxOverlapCnt = (int) list.stream().filter(i -> i == lamdaMax).count();
//         int minOverlapCnt = (int) list.stream().filter(i -> i == lamdaMin).count();

//         if (maxOverlapCnt == 1 && scores[col][col] == maximum) {
//             sum -= maximum;
//             return sum / (double) (scores.length - 1);
//         }

//         if (minOverlapCnt == 1 && scores[col][col] == minimum) {
//             sum -= minimum;
//             return sum / (double) (scores.length - 1);
//         }
            else {
                sum += scores[col][col];
                return sum / (double) scores.length;
            }

        }

        public char getGrade(double avg) {

            System.out.println(avg);

            if (avg >= 90) {
                return 'A';
            }
            else if (avg >= 80 && avg < 90) {
                return 'B';
            }
            else if (avg >= 70 && avg < 80) {
                return 'C';
            }
            else if (avg >= 50 && avg < 70) {
                return 'D';
            }
            else {
                return 'F';
            }

        }

        public String solution(int[][] scores) {

            StringBuilder answer = new StringBuilder();

            for (int i = 0; i < scores.length; i++) {

                double avg = getAverage(scores, i);
                char grade = getGrade(avg);
                answer.append(grade);

            }

            return answer.toString();
        }
    }

}
