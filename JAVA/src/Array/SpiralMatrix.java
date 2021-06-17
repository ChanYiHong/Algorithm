package Array;

public class SpiralMatrix {

    public static void main(String[] args) {
        int[][] input = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };

        int[] result = solve(input);
        for (int i : result) {
            System.out.println(i);
        }
    }

    private static int[] solve(int[][] input) {

        int rowLength = input.length;
        int colLength = input[0].length;
        int cnt = rowLength * colLength;
        int row = 0;
        int col = 0;
        int[] ret = new int[cnt];
        boolean[][] check = new boolean[rowLength][colLength];
        int direction = 0;
        int index = 0;

        while(cnt > 0) {

            System.out.println(row);
            System.out.println(col);
            System.out.println("---------");
            // 오른쪽.
            if(direction % 4 == 0) {
                if(row >= 0 && row < rowLength && col >= 0 && col < colLength && !check[row][col]) {
                    ret[index] = input[row][col];
                    check[row][col] = true;
                    col++;
                    index++;
                    cnt++;
                }
                else {

                    direction++;
                    row++;
                    col--;
                }
            }

            // 밑쪽.
            else if(direction % 4 == 1) {
                if(row >= 0 && row < rowLength && col >= 0 && col < colLength && !check[row][col]) {
                    ret[index] = input[row][col];
                    check[row][col] = true;
                    row++;
                    index++;
                    cnt++;
                }
                else {

                    direction++;
                    row--;
                    col--;
                }
            }

            // 왼쪽.
            else if(direction % 4 == 2) {
                if(row >= 0 && row < rowLength && col >= 0 && col < colLength && !check[row][col]) {
                    ret[index] = input[row][col];
                    check[row][col] = true;
                    col--;
                    index++;
                    cnt++;
                }
                else {

                    direction++;
                    row--;
                    col++;
                }
            }

            // 위쪽.
            else if(direction % 4 == 3) {
                if(row >= 0 && row < rowLength && col >= 0 && col < colLength && !check[row][col]) {
                    ret[index] = input[row][col];
                    check[row][col] = true;
                    row--;
                    index++;
                    cnt++;
                }
                else {

                    direction++;
                    row++;
                    col++;
                }
            }
        }

        return ret;
    }
}
