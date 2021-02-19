package Array;

import java.util.HashSet;
import java.util.Set;

public class MatrixZero {

    public static void main(String[] args) {
        int[][] arr = {
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1}
        };
        solve(arr);
    }

    private static void solve(int[][] arr) {
        Set<Integer> rowZero = new HashSet<>();
        Set<Integer> colZero = new HashSet<>();

        // 값이 0인 곳의 고유한 x좌표, y좌표를 set에 저장..! 좋은 기법임. 이거 안쓰면 n3인데 이거 쓰니까 n2임.
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr[i].length; j++) {
                if(arr[i][j] == 0) {
                    rowZero.add(i);
                    colZero.add(j);
                }
            }
        }

        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr[i].length; j++) {
                if(rowZero.contains(i) || colZero.contains(j)) {
                    arr[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

    }
}

// 중복을 허용하지 않는 고유한 좌표값을 저장하기 위해 HashSet을 사용.