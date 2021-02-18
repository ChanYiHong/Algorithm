package Array;

import java.util.HashMap;
import java.util.Map;

public class SubArrayMap {

    public static void main(String[] args) {
        int[] arr = {3, 4, 7, 2, -3, 1, 4, 2};
        int n = 7;
        System.out.println(solve(arr, n));
    }

    private static int solve(int[] arr, int n) {

        Map<Integer, Integer> map = new HashMap<>();
        int sum = 0;
        int cnt = 0;
        map.put(0, 1);

        for(int i = 0; i < arr.length; i++) {
            sum += arr[i];

            if(map.containsKey(sum - n)) cnt++;

            map.put(sum, map.getOrDefault(sum + 1, 1));

        }

        return cnt;

    }

}
