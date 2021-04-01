package String;

public class 가장긴펠린드롬 {

    class Solution
    {
        public int odd(String s, int index) {
            int ret = 1;
            int left = index - 1;
            int right = index + 1;

            while(left >= 0 && right < s.length()) {
                if(s.charAt(left) != s.charAt(right)) break;

                ret += 2;
                left--;
                right++;
            }

            return ret;
        }

        public int even(String s, int index) {
            if(index == 0) return 0;

            if(s.charAt(index) != s.charAt(index - 1)) {
                return 0;
            }

            int ret = 2;
            int left = index - 2;
            int right = index + 1;

            while(left >= 0 && right < s.length()) {
                if(s.charAt(left) != s.charAt(right)) break;

                ret += 2;
                left--;
                right++;
            }

            return ret;
        }

        public int solution(String s)
        {
            int answer = 0;

            for(int i = 0; i < s.length(); i++) {
                answer = Math.max(answer, odd(s, i));
                answer = Math.max(answer, even(s, i));
            }

            return answer;
        }
    }

}
