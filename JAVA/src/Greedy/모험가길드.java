package Greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class 모험가길드 {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int n = Integer.parseInt(st.nextToken());

        int[] fears = new int[n];

        st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < n; i++) {
            fears[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(fears);

        int index = 0;
        int answer = 0;
        int cnt = 0;

        // 내가 보고 있는 공포도가 현재 그룹에 포함된 인원 수 보다 적거나 같다면 그룹 + 1
        while (index < fears.length) {

            int cur = fears[index];
            cnt++;
            if (cur <= cnt) {
                answer++;
                cnt = 0;
            }
            index++;
        }

        System.out.println(answer);

    }

}
