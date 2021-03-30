package String;

public class 삼진법뒤집기 {

    public int solution(int n) {
        int answer = 0;

        int num = n;
        StringBuilder sb = new StringBuilder();

        while(num > 0) {
            int cur = num % 3;
            sb.append(String.valueOf(cur));

            num /= 3;
        }

        int index = sb.length() - 1;
        int quotient = 0;

        while(index >= 0) {

            if(sb.charAt(index) != '0'){
                answer += ((sb.charAt(index) - '0') * (int) Math.pow(3, quotient));

            }

            quotient++;
            index--;
        }

        return answer;
    }

}
