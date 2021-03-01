package Array;

import java.util.Arrays;

public class MeetingRoom {

    public static void main(String[] args) {
        int[][] input1 = {{0, 30}, {15, 20}, {5, 10}};
        int[][] input2 = {{1, 2}, {3, 4}, {5, 6}};
        System.out.println(solve(input2));
    }

    private static boolean solve(int[][] input) {

        if(input.length == 0) return false;

        // 정렬.
        Arrays.sort(input, (a, b) -> {
            if(a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            } else{
                return Integer.compare(a[0], b[0]);
            }
        });

        int beforeEnd = input[0][1];
        // 반복문.
        for(int i = 1; i < input.length; i++) {
            int currentStart = input[i][0];
            if(beforeEnd > currentStart) {
                return false;
            }
            beforeEnd = input[i][1];
        }

        return true;

    }

}
