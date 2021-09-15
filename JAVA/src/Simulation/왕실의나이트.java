package Simulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 왕실의나이트 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String input = st.nextToken();

        int[] dx = new int[]{1, 2, -1, -2, 1, 2, -1, -2};
        int[] dy = new int[]{2, 1, 2, 1, -2, -1, -2, -1};

        int row = Integer.parseInt(Character.toString(input.charAt(1))) - 1;
        int col = input.charAt(0) - 'a';

        int ans = 0;

        for (int i = 0; i < 8; i++) {
            int movedRow = row + dx[i];
            int movedCol = col + dy[i];
            if (movedRow >= 0 && movedRow < 8 && movedCol >= 0 && movedCol < 8) {
                ans++;
            }
        }

        System.out.println(ans);

    }
}
