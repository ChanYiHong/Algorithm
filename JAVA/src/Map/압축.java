package Map;

import java.util.*;

public class 압축 {

    class Solution {

        private final String[] alpha = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

        private int globalIndex = 1;

        public void init(Map<String, Integer> m) {
            for(String c : alpha) {
                m.put(c, globalIndex++);
            }
        }

        public int findNext(Map<String, Integer> m, String msg, int index, int plus) {

            if(index + plus > msg.length()) return plus - 1;

            String nextStr = msg.substring(index, index + plus);

            if(m.get(nextStr) == null) {
                return plus - 1;
            }
            else {
                return findNext(m, msg, index, plus + 1);
            }

        }

        public int[] solution(String msg) {
            int[] answer = {};

            List<Integer> ans = new ArrayList<>();
            Map<String, Integer> m = new HashMap<>();

            init(m);

            int index = 0;

            while(index < msg.length()) {

                int toNextIndex = findNext(m, msg, index, 2);

                String cur = msg.substring(index, index + toNextIndex);
                ans.add(m.get(cur));

                if(index + toNextIndex + 1 < msg.length()) {
                    String newStr = msg.substring(index, index + toNextIndex + 1);
                    m.put(newStr, globalIndex++);
                }
                index += toNextIndex;

            }

            answer = new int[ans.size()];
            for(int i = 0; i < ans.size(); i++) {
                answer[i] = ans.get(i);
            }

            return answer;
        }
    }
}
