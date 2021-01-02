package Greedy;

import java.util.Scanner;

public class BOJ1138 {

    static int n;
    static int[] input;
    static int[] result;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        input = new int[n];
        result = new int[n];
        for(int i = 0; i < n; i++) {
            input[i] = sc.nextInt();
        }

        for(int i = 0; i < n; i++) {
            // cur : 옆에 몇명 있는상황인지.
            int cur = input[i];
            // 옆에 몇명 지나쳤는지. cur == cnt면 내 자리인것.
            int cnt = 0;
            for(int j = 0; j < n; j++){
                // 앞 부터 쭈욱 찾는데, 이미 지정위치에 사람 있으면 넘어감.
                // (무조건 나보다 작음, 작은 순서대로이기 때문)
                if(result[j] != 0){
                    continue;
                }
                // cur == cnt 면 내자리!
                if(cnt == cur){
                    // i + 1인 이유는 i 가 0부터 시작하고 1번째 사람부터 나타내기 위함.
                    result[j] = i + 1;
                    break;
                }
                // 지정 위치에 사람 없을 경우 카운트 세기.
                cnt++;
            }
        }

        for (int r : result) {
            System.out.print(r + " ");
        }
    }
}