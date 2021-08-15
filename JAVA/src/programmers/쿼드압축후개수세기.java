package programmers;

public class 쿼드압축후개수세기 {

    class Solution {

        int zero = 0;
        int one = 0;
        int[][] tree;

        public void quadTree(int x, int y, int len) {

            if (len == 1) {

                if (tree[x][y] == 0) zero++;
                else one++;

                return;
            }

            int element = tree[x][y];
            boolean isAllSame = true;

            for(int i = x; i < x + len; i++) {
                for(int j = y; j < y + len; j++) {
                    if (tree[i][j] != element) {
                        isAllSame = false;
                        break;
                    }
                }
                if (!isAllSame) break;
            }

            if (isAllSame) {
                if (element == 0) zero++;
                else one++;
            }
            else {
                quadTree(x, y, len / 2);
                quadTree(x + len / 2, y, len / 2);
                quadTree(x, y + len / 2, len / 2);
                quadTree(x + len / 2, y + len / 2, len / 2);
            }

        }

        public int[] solution(int[][] arr) {

            tree = arr;

            // 애초에 다 1 or 0일 때
            int element = arr[0][0];
            boolean isAllSame = true;
            for (int i = 0; i < arr.length; i++) {
                for (int j = 0; j < arr.length; j++) {
                    if (arr[i][j] != element) {
                        isAllSame = false;
                        break;
                    }
                    if (!isAllSame) break;
                }
            }

            if (isAllSame) {
                if (element == 0) return new int[]{1, 0};
                else return new int[]{0, 1};
            }

            // 4분할 시 시작점, 길이 넣기
            int len = arr.length / 2;
            quadTree(0, 0, len);
            quadTree(len, 0, len);
            quadTree(0, len, len);
            quadTree(len, len, len);

            return new int[]{zero, one};

        }
    }
}
