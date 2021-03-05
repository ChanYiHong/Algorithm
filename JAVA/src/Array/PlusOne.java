package Array;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class PlusOne {

    public static void main(String[] args) {
        int[] input = {9,9,9};
        List<Integer> result = solve(input);

        for (Integer integer : result) {
            System.out.print(integer + " ");
        }

        int[] result2 = solve2(input);
        for (int num : result2) {
            System.out.print(num + " ");
        }
    }

    private static List<Integer> solve(int[] input) {
        List<Integer> ret = new LinkedList<>();
        Stack<Integer> stack = new Stack<>();
        int index = input.length - 1;

        for(int num : input) {
            stack.push(num);
        }

        boolean check = true;

        while(index >= 0) {
            int top = stack.pop();

            if(check) {
                top++;
            }

            if(top > 9) {
                check = true;
            }else {
                check = false;
            }

            ret.add(0, top % 10);
            index--;
        }

        if(check) {
            ret.add(0, 1);
        }
        return ret;
    }

    // 어짜피 딱 1만 더하는 거라 자릿 수 바껴도 무조건 1띄기임.
    private static int[] solve2(int[] input) {
        int index = input.length - 1;
        int carry = 1;

        while(index >= 0 && carry > 0) {
            input[index] = (input[index] + 1) % 10;

            if(input[index] == 0) {
                carry = 1;
            } else {
                carry = 0;
            }

            index--;
        }

        if(carry == 1) {
            input = new int[input.length + 1];
            input[0] = 1;
        }

        return input;
    }

}

/**
 * Array
 * String
 * Greedy
 * Stack, queue
 * map
 * dfs, bfs
 * 최단거리
 * ...
 *
 *
 * **/
