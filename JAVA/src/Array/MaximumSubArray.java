package Array;

public class MaximumSubArray {

    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println(solve(nums));
    }

    private static int solve(int[] nums) {
        int max = nums[0];
        int newSum = nums[0];

        for(int i = 1; i < nums.length; i++){

            newSum = Math.max(newSum + nums[i], nums[i]);
            max = Math.max(max, newSum);

        }

        return max;
    }

}
