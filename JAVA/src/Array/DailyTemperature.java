package Array;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class DailyTemperature {

    public static void main(String[] args) {
        int[] nums = {73, 74, 75, 71, 69, 72, 76, 73};
        for(int n : solve(nums)){
            System.out.print(n + " ");
        }
    }

    private static int[] solve(int[] nums) {
        if(nums.length == 0) return null;

        int[] ret = new int[nums.length];
        Stack<Integer> stack = new Stack<>();

        for(int i = 0; i < nums.length; i++) {

            while(!stack.isEmpty()) {
                if(nums[i] > nums[stack.peek()]) {
                    ret[stack.peek()] = i - stack.peek();
                    stack.pop();
                }
                else{
                    break;
                }
            }

            stack.push(i);
        }

        while(!stack.isEmpty()) {
            ret[stack.peek()] = 0;
            stack.pop();
        }

        return ret;

    }

}
