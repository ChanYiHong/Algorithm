package String;

import java.util.*;

public class 괄호회전하기 {

    class Solution {

        public String rotation(String s) {

            StringBuilder sb = new StringBuilder();
            sb.append(s.substring(1));
            sb.append(s.charAt(0));
            return sb.toString();

        }

        public int solution(String s) {
            int answer = 0;

            String str = s;
            boolean isCorrect = true;

            for(int i = 0; i < s.length(); i++) {

                Stack<Character> stack = new Stack<>();
                str = rotation(str);

                isCorrect = true;
                int index = 0;

                while(index < str.length()) {

                    char c = str.charAt(index);

                    if(stack.isEmpty()) {
                        stack.push(c);
                    }
                    else {
                        if(c == '{'|| c == '[' || c == '(') {
                            stack.push(c);
                        }
                        else if(c == '}') {
                            if(stack.peek() == '{') {
                                stack.pop();
                            }else {
                                isCorrect = false;
                                break;
                            }
                        }
                        else if(c == ']') {
                            if(stack.peek() == '[') {
                                stack.pop();
                            }else {
                                isCorrect = false;
                                break;
                            }
                        }
                        else if(c == ')') {
                            if(stack.peek() == '(') {
                                stack.pop();
                            }else {
                                isCorrect = false;
                                break;
                            }
                        }
                    }

                    index++;
                }

                if(!stack.isEmpty()) isCorrect = false;

                if(isCorrect) answer++;

            }

            return answer;
        }
    }

}
