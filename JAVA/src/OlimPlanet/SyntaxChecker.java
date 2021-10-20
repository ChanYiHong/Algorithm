package OlimPlanet;

import java.util.Stack;

public class SyntaxChecker {

    public static void main(String[] args) {

        String[] inputArr = {"[[(){}]]", "(()))", ")(())[]{}", "({[}])", "[{(([{[]}]))}]"};

        for (String input : inputArr) {
            System.out.println(solve(input));
        }
    }

    private static boolean solve(String input) {

        Stack<Character> openStack = new Stack<>();

        for (int i = 0; i < input.length(); i++) {

            char current = input.charAt(i);

            if (current == '[' || current == '{' || current == '(') {
                openStack.push(current);
            } else {
                if (openStack.isEmpty()) {
                    return false;
                }

                if ((current == ']' && openStack.peek() == '[') || (current == '}' && openStack.peek() == '{')
                        || (current == ')' && openStack.peek() == '(')) {

                    openStack.pop();
                } else {
                    return false;
                }
            }
        }

        return openStack.isEmpty();
    }

}
