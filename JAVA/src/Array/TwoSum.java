package Array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TwoSum {

    public static void main(String[] args) {
        int[] input = {2, 8, 10, 12};
        int target = 10;

        System.out.println(solve(input, target));
    }

    private static List<Integer> solve(int[] input, int target) {

        if(input.length == 0) return null;

        Integer[] arr = Arrays.stream(input).boxed().toArray(Integer[]::new);

        List<Integer> list = Arrays.asList(arr);
        List<Integer> ret = new ArrayList<>();

        for (Integer num : list) {
            if(list.contains(target - num)) {
                if(!ret.contains(list.indexOf(num) + 1)) {
                    ret.add(list.indexOf(num) + 1);
                }
                if(!ret.contains(list.indexOf(target - num) + 1)) {
                    ret.add(list.indexOf(target - num) + 1);
                }
            }
        }

        return ret;

    }


}
