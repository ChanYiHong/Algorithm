package Array;

import java.util.HashMap;
import java.util.Map;

// 두개의 구별 가능한 가장 긴 substring.  ccaabbb에서 aabbb를 뜻함.
public class LongestSubstringWithAtMostTwoDistinct {

    public static void main(String[] args) {
        String str = "ccaabbb";
        System.out.println(solve2(str));
    }

    private static int solve(String str) {
        Map<String, Integer> map = new HashMap<>();
        int first = 0;
        int second = 0;

        char cur = str.charAt(0);

        int distinctCnt = 1;
        int index = 0;

        for(char c : str.toCharArray()) {
            if(cur != c) {
                if(distinctCnt == 1) {
                    distinctCnt++;
                    second = index;
                }
                if(distinctCnt == 2) {
                    distinctCnt--;

                    String sub = str.substring(first, index);
                    map.put(sub, sub.length());

                    System.out.println(sub);

                    first = second;
                }
            }
            cur = str.charAt(index);
            index++;
        }

        String sub = str.substring(first, str.length());
        map.put(sub, sub.length());

        System.out.println(sub);

        int ret = 0;

        for(Map.Entry<String, Integer> entry : map.entrySet()) {
            ret = Math.max(ret, entry.getValue());
        }

        return ret;

    }

    // Char 한개 한개 map에 담았다가 지웠다가 한다.
    // aabbbaaabbaa 의 답은 12임.
    public static int solve2(String str) {
        // 1
        int start = 0, end = 0, length = 0, counter = 0;
        Map<Character, Integer> map = new HashMap<>();

        // 2
        while (end < str.length()) {
            char endChar = str.charAt(end);
            map.put(endChar, map.getOrDefault(endChar, 0) + 1);
            if(map.get(endChar) == 1) counter++;
            end++;

            while(counter > 2) {
                char startChar = str.charAt(start);
                map.put(startChar, map.get(startChar) - 1);
                if(map.get(startChar) == 0) counter--;
                start++;
            }

            length = Math.max(length, end-start);
        }

        return length;
    }

}
