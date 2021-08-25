package programmers;

import java.util.List;
import java.util.ArrayList;

public class 하노이의탑 {

    static List<int[]> move;

    // n개일 때 시작점에서 via를 통해 끝점으로 가는 경로.
    public void hanoi(int n, int start, int end, int via) {

        // 1개일 경우는 그냥 바로 목적지로 옮김.
        if (n == 1) {
            move.add(new int[]{start, end});
            return;
        }

        // 일단 경유지에 n-1개 옮기고.
        hanoi(n - 1, start, via, end);
        // 그 후 젤 큰거 한개 목적지에 옮기고,
        move.add(new int[]{start, end});
        // 나머지 n-1개 목적지로 옮기고.
        hanoi(n - 1, via, end, start);

    }

    public int[][] solution(int n) {
        int[][] answer = {};

        move = new ArrayList<>();
        hanoi(n, 1, 3, 2);

        answer = new int[move.size()][2];
        for(int i = 0; i < move.size(); i++) {
            answer[i][0] = move.get(i)[0];
            answer[i][1] = move.get(i)[1];
        }

        return answer;
    }

}
