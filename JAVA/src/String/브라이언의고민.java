package String;

import java.util.*;

public class 브라이언의고민 {

    public static void main(String[] args) {
        브라이언의고민 mainClass = new 브라이언의고민();

        System.out.println(mainClass.solution("aHELLOa"));
    }

    public int cntChar(String sentence, char c) {
        return sentence.length() - sentence.replace(String.valueOf(c), "").length();
    }

    public boolean isLowerCase(char c) {
        return c >= 97 && c <= 122;
    }

    public String solution(String sentence) {
        String answer = sentence;

        HashMap<Character, Integer> map = new HashMap<>();

        boolean doubleRule = false;

        int i = 0;

        while(i < answer.length()) {

            char curChar = answer.charAt(i);

            System.out.println(curChar);

            if(isLowerCase(curChar)) {

                int cnt = cntChar(answer, curChar);

                // 맨 앞 소문자는 딱 2개만 와야해..
                if(cnt != 2) {
                    return "invalid";
                }

                // 바로 다음에 또 소문자면 곤란해.. (범위 위험)
                if(isLowerCase(answer.charAt(i + 1))) {
                    return "invalid";
                }

                // 혹시 2중 규칙인지 확인 (띄어쓰기 할지 말지..)
                if(isLowerCase(answer.charAt(i + 2)) && answer.charAt(i + 2) != curChar) {
                    doubleRule = true;
                }

                int firstIndex = answer.indexOf(curChar);
                int lastIndex = answer.lastIndexOf(curChar);

                answer.replace(String.valueOf(curChar), "");

                if(!doubleRule) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(answer.substring(0, lastIndex - 1));
                    if(lastIndex - 1 < answer.length()) {
                        sb.append(" ");
                        sb.append(answer.substring(lastIndex));

                        answer = sb.toString();
                    }
                }

            }

        }

        return answer;
    }

}
