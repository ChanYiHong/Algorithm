package programmers;

import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

public class 보석쇼핑 {

    public int[] solution(String[] gems) {
        int[] answer = new int[2];

        Set<String> arrange = new HashSet<>();
        int start = 0, end = 0;

        Arrays.stream(gems).forEach(g -> {
            arrange.add(g);
        });

        int itemSize = arrange.size();
        Map<String, Integer> itemMap = new HashMap<>();
        int range = 987654321;

        if (itemSize == 1) {
            return new int[]{1, 1};
        }

        boolean endChange = false;

        while (start < gems.length) {

            if (start == end) {
                itemMap.put(gems[start], itemMap.getOrDefault(gems[start], 0) + 1);
                end++;
                endChange = true;
                continue;
            }

            if (end != gems.length && endChange) {
                itemMap.put(gems[end], itemMap.getOrDefault(gems[end], 0) + 1);
                endChange = false;
            }

            if (itemMap.keySet().size() == itemSize) {
                if (range > end - start + 1) {
                    range = end - start + 1;
                    answer[0] = start + 1;
                    answer[1] = end + 1;
                }
                if (itemMap.get(gems[start]) > 1) {
                    int value = itemMap.get(gems[start]);
                    itemMap.put(gems[start], value - 1);
                } else {
                    itemMap.remove(gems[start]);
                }
                start++;
            } else {

                if (end == gems.length) {
                    start++;
                } else {
                    end++;
                    endChange = true;
                }
            }

        }

        return answer;
    }
}
