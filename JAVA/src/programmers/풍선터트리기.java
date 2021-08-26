package programmers;

public class 풍선터트리기 {

    class Solution {
        public int solution(int[] a) {
            int answer = 2;

            // 젤 왼쪽과 젤 오른쪽은 무조건 선택 가능. 나머지 다 터트리고 하나 남았을 때,
            // 아무리 남은 게 젤 왼쪽이나 젤 오른쪽보다 작아도,
            // 작은 풍선 터트릴 수 있는 기회는 1번 주어짐.
            int left = a[0];
            int right = a[a.length - 1];

            for (int i = 1; i < a.length - 1; i++) {

                // 현재 가장 왼쪽 보다 더 작으면, 다른거 다 터트리고 똑같은 원리로 다른거 다 터트리고,
                // 가장 왼쪽 (맨 처음의 경우) , 현재 보고있는 것, 오른쪽 나머지
                // 오른쪽 나머지가 더 작아도 오른쪽 나머지에 작은거 하나 터트리고
                // 가장 왼쪽이 더 큰거면 현재 보고있는게 살아 남을 수 있음.
                // 그런 원리임.
                if (left > a[i]) {
                    left = a[i];
                    answer++;
                }
                if (right > a[a.length - 1 - i]) {
                    right = a[a.length - 1 - i];
                    answer++;
                }

                if (left == right) {
                    answer--;
                    break;
                }

            }

            return answer;
        }
    }

}
