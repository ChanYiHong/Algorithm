package String;

import java.util.*;

public class 숫자문자열과영단어 {

    class Solution {

        Map<String, String> englishToNum = new HashMap<>();

        public void init() {

            englishToNum.put("zero", "0");
            englishToNum.put("one", "1");
            englishToNum.put("two", "2");
            englishToNum.put("three", "3");
            englishToNum.put("four", "4");
            englishToNum.put("five", "5");
            englishToNum.put("six", "6");
            englishToNum.put("seven", "7");
            englishToNum.put("eight", "8");
            englishToNum.put("nine", "9");

        }

        public int solution(String s) {

            init();

            StringBuilder sb = new StringBuilder();
            int start = 0;
            boolean english = false;

            for (int i = 0; i < s.length(); i++) {

                char cur = s.charAt(i);

                // 알파벳이면.
                if (cur >= 97 && cur <= 122) {
                    // 알파벳 첫 시작.
                    if (!english) {
                        start = i;
                        english = true;
                    }
                    // 맵에 있는지 확인.
                    else {
                        if (englishToNum.get(s.substring(start, i)) != null) {
                            sb.append(englishToNum.get(s.substring(start, i)));
                            start = i;
                        }
                    }

                }// 숫자면
                else {
                    // 알파벳 끝
                    if (english) {
                        String numberStr = s.substring(start, i);
                        sb.append(englishToNum.get(numberStr));
                        english = false;
                    }
                    sb.append(cur);
                }
            }

            if (english) {
                String numberStr = s.substring(start);
                sb.append(englishToNum.get(numberStr));
            }

            return Integer.parseInt(sb.toString());

        }

        public int solution2(String s) {
            String ret = s;

            String[] num = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
            String[] english = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

            for(int i = 0; i < num.length; i++) {
                ret.replaceAll(english[i], num[i]);
            }

            return Integer.parseInt(ret);
        }
    }

}
