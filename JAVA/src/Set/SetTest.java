package Set;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class SetTest {

    public static void main(String[] args) {
        Set<Integer> set = new HashSet<>();

        set.add(4);
        set.add(3);

        Integer[] integers = set.stream().toArray(Integer[]::new);

        for (Integer integer : integers) {
            System.out.println(integer);
        }

        int[] answer = Arrays.stream(integers).mapToInt(i -> i).toArray();

        for (int i : answer) {
            System.out.println(i);
        }
    }

}
