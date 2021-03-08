package Array;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class FindAnagramsMapping {

    public static void main(String[] args) {
        int[] A = {11, 27, 45, 31, 50};
        int[] B = {50, 11, 31, 45, 27};
        int[] result = solve(A, B);

        for (Integer integer : result) {
            System.out.println(integer);
        }

    }

    private static int[] solve(int[] a, int[] b) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] ret = new int[a.length];

        for(int i = 0; i < b.length; i++) {
            map.put(b[i], i);
        }

        for(int i = 0; i < a.length; i++) {
            ret[i] = map.get(a[i]);
        }

        return ret;
    }
}
