package programmers;

import java.util.List;
import java.util.LinkedList;

public class 수식최대화 {

    class Solution {

        String[][] cases = {
                {"+", "-", "*"},
                {"+", "*", "-"},
                {"*", "+", "-"},
                {"*", "-", "+"},
                {"-", "*", "+"},
                {"-", "+", "*"}
        };

        public long calculate(long a, long b, String operator) {
            if(operator.equals("+")) {
                return a + b;
            } else if (operator.equals("*")) {
                return a * b;
            } else {
                return a - b;
            }
        }

        public Long makeResult(List<String> exList, int caseIndex) {

            List<String> list = new LinkedList<>(exList);
            String[] operators = cases[caseIndex];

            for (int i = 0; i < operators.length; i++) {

                String operator = operators[i];

                int index = 0;

                while(index < list.size()) {
                    if (list.get(index).equals(operator)) {
                        long operand1 = Long.parseLong(list.get(index - 1));
                        long operand2 = Long.parseLong(list.get(index + 1));
                        long result = calculate(operand1, operand2, operator);

                        list.remove(index - 1);
                        list.remove(index - 1);
                        list.remove(index - 1);
                        list.add(index - 1, Long.toString(result));
                        index = 0;
                        continue;
                    }
                    index++;
                }

            }

            return Math.abs(Long.parseLong(list.get(0)));
        }

        public long solution(String expression) {
            long answer = 0;

            String numberEx = expression.replace("-", " ");
            numberEx = numberEx.replace("+", " ");
            numberEx = numberEx.replace("*", " ");

            String[] numbers = numberEx.split(" ");

            List<String> exList = new LinkedList<>();

            for (String num : numbers) {
                exList.add(num);
            }

            // 연산자 저장.
            int index = 1;
            for (char c : expression.toCharArray()) {
                if (!Character.isDigit(c)) {
                    exList.add(index, Character.toString(c));
                    index = index + 2;
                }
            }

            for (int i = 0; i < 6; i++) {
                long ret = makeResult(exList, i);
                answer = Math.max(answer, ret);
            }

            return answer;
        }
    }

}
