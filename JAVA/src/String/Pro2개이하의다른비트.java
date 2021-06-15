package String;

public class Pro2개이하의다른비트 {

    class Solution {

        public long[] solution(long[] numbers) {
            long[] answer = new long[numbers.length];

            int index = 0;

            for(int i = 0; i < numbers.length; i++) {

                long num = numbers[i];
                String binary = Long.toBinaryString(num);

                if(num % 2 == 0) {
                    answer[index++] = num + 1;
                }
                else {
                    // 마지막 "0" index
                    int lastIndex = binary.lastIndexOf("0");
                    // 마지막 "0" index 다음에 최초의 "1"
                    int firstIndex = binary.indexOf("1", lastIndex);

                    // "0"이 없는 경우 앞에 "10"붙이고 나머지 다 "111...";
                    if(lastIndex == -1) {
                        binary = Long.toBinaryString(num + 1);
                        binary = binary.substring(0, 2) + binary.substring(2).replace("0", "1");
                    } else {
                        binary = binary.substring(0, lastIndex) + "1" + binary.substring(lastIndex + 1, firstIndex) + "0" + binary.substring(firstIndex+1);
                    }
                    // 현재 2진수 형태이므로, parseLong(binary, 2) 로!
                    answer[index++] = Long.parseLong(binary, 2);
                }

            }

            return answer;
        }
    }

}
