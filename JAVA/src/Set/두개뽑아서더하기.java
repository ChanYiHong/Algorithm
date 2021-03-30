package Set;


import java.util.Set;
import java.util.TreeSet;
import java.util.Arrays;

public class 두개뽑아서더하기 {

    public int[] solution(int[] numbers) {
        int[] answer = {};
        Set<Integer> set = new TreeSet<>();

        for(int i = 0; i < numbers.length; i++) {
            for(int j = i+1; j < numbers.length; j++) {
                int sum = numbers[i] + numbers[j];
                if(!set.contains(sum)) {
                    set.add(sum);
                }
            }
        }

        Integer[] integers = set.stream().toArray(Integer[] :: new);
        answer = Arrays.stream(integers).mapToInt(i -> i).toArray();
        //Arrays.sort(answer);

        return answer;
    }

}
