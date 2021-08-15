package programmers;

import java.util.*;

public class 올바른괄호 {

    class Solution {
        boolean solution(String s) {
            boolean answer = true;

            Stack<Character> open = new Stack<>();

            for (int i = 0; i < s.length(); i++) {
                char cur = s.charAt(i);

                if (cur == ')') {
                    if (open.isEmpty()) {
                        return false;
                    } else {
                        open.pop();
                    }
                }
                else {
                    open.push('(');
                }
            }

            return open.isEmpty() ? true : false;
        }
    }
}
