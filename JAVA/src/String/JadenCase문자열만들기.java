package String;

public class JadenCase문자열만들기 {

    class Solution {
        public String solution(String s) {
            String answer = "";

            StringBuilder sb = new StringBuilder();

            boolean isFirst = true;

            for(int i = 0; i < s.length(); i++) {

                if(s.charAt(i) == ' ') {
                    sb.append(s.charAt(i));
                    isFirst = true;
                    continue;
                }

                if(isFirst) {

                    char firstChar = s.charAt(i);

                    if(firstChar >= 97 && firstChar <= 122) {
                        firstChar = (char) (firstChar - 32);
                    }

                    sb.append(firstChar);
                    isFirst = false;

                }else{

                    char curChar = s.charAt(i);


                    if(curChar >= 65 && curChar <= 90) {
                        curChar = (char) (curChar + 32);
                    }
                    sb.append(curChar);

                }

            }

            return answer = sb.toString();
        }
    }

}
