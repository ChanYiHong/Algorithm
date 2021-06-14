package String;

public class 이진변환반복하기 {

    class Solution {
        public int[] solution(String s) {
            int[] answer = new int[2];

            int binaryTransform = 0;
            int deletedZero = 0;

            String str = s;

            while(!str.equals("1")) {

                int beforeLen = str.length();
                str = str.replace("0", "");
                int afterLen = str.length();

                deletedZero += (beforeLen - afterLen);

                str = Integer.toBinaryString(afterLen);

                binaryTransform++;

            }

            answer[0] = binaryTransform;
            answer[1] = deletedZero;

            return answer;
        }
    }

}
