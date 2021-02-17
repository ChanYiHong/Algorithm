package String;

public class StringPalindrome {

    int start = 0;
    int end = 0;

    public static void main(String[] args) {
        String str = "banana";
        System.out.println(new StringPalindrome().solve(str));
    }

    private String solve(String str) {
        if(str.length() < 1) return str;

        for(int i = 0; i < str.length() - 1; i++) {
            findSubString(str, i, i); // 홀수          예를들어 index 1의 a라고 가정하면  a에서 시작하여 b <- a -> n 으로
            findSubString(str, i, i+1); // 짝수        예를들어 index 1의 a라고 가정하면 an에서 시작 (애초에 달라서 짤림) b <- an -> a
        }

        return str.substring(start, end);
    }

    private void findSubString(String str, int left, int right) {

        System.out.println("left = " + left);
        System.out.println("right = " + right);

        while(left >= 0 && right < str.length() && str.charAt(left) == str.charAt(right)) {
            left--;
            right++;
            System.out.println(left);
            System.out.println(right);
        }

        // while 문에 의해서 -1, +1 로 한칸씩 더 가있는 상태임. 조정.
        // 펠린드롬 길이비교.
        if(end - start < right - left -1) {
            end = right - left;
            start = left + 1;
        }

        System.out.println("start = " + start);
        System.out.println("end = " + end);
        System.out.println("+++++++++++++++++++++++++++++");

    }
}
