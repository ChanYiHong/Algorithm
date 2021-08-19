package programmers;

public class 로또의최고순위와최저순위 {

    class Solution {

        public int ranking(int n) {
            if (n == 6) return 1;
            else if (n == 5) return 2;
            else if (n == 4) return 3;
            else if (n == 3) return 4;
            else if (n == 2) return 5;
            else return 6;
        }

        public int[] solution(int[] lottos, int[] win_nums) {
            int[] answer = new int[2];

            boolean[] check = new boolean[46];

            for (int i = 0; i < win_nums.length; i++) {
                check[win_nums[i]] = true;
            }

            int zeroCnt = 0;
            int sameCnt = 0;

            for (int i = 0; i < lottos.length; i++) {
                if (lottos[i] == 0) {
                    zeroCnt++;
                    continue;
                }
                if (check[lottos[i]]) {
                    sameCnt++;
                }
            }

            int max = sameCnt + zeroCnt;
            int min = sameCnt;

            answer[0] = ranking(max);
            answer[1] = ranking(min);

            return answer;
        }
    }

}
