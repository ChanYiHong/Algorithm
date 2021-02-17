package Array;

public class SubArraySum {

    public static void main(String[] args) {
        int[] arr = {3,4,7,2,-3,1,4,2};
        int n = 7;
        System.out.println(solve(arr, n));
    }

    //앞에서 부터 쭈욱 보고, 이중 포문으로.. 비효율적인듯..?
    //Map 으로 하는 다음 수업을 기대!!
    private static int solve(int[] arr, int n) {
        int cnt = 0;
        for(int i = 0; i < arr.length; i++) {
            int sum = 0;
            for(int j = i; j < arr.length; j++) {
                sum += arr[j];
                if(sum == n) cnt++;
            }
        }
        return cnt;
    }
}
