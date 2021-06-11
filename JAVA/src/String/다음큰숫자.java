package String;

public class 다음큰숫자 {

    // class BinaryInfo {
//     String binary;
//     int oneNum;

//     public BinaryInfo(String binary, int oneNum) {
//         this.binary = binary;
//         this.oneNum = oneNum;
//     }
// }

    class Solution {

//     public BinaryInfo transformToBinary(int n) {

//         StringBuilder sb = new StringBuilder();

//         int num = n;
//         int cnt = 0;

//         while(num > 1) {
//             int rest = num % 2;
//             num /= 2;

//             if(rest == 1) cnt++;
//             sb.append(Integer.toString(rest));

//             if(num < 2) {
//                 cnt++;
//                 sb.append(Integer.toString(num));
//             }
//         }

//         return new BinaryInfo(sb.reverse().toString(), cnt);

//     }

        public int solution(int n) {
            int answer = 0;
//         int next = n + 1;
//         BinaryInfo nInfo = transformToBinary(n);
//         BinaryInfo ansInfo;

//         while(true) {
//             BinaryInfo nextInfo = transformToBinary(next);
//             if(nInfo.oneNum == nextInfo.oneNum) break;

//             next++;
//         }
//         return answer = next;

            int oneNum = Integer.bitCount(n);

            for(int i = n+1; ; i++) {
                if(oneNum == Integer.bitCount(i)){
                    answer = i;
                    break;
                }
            }

            return answer;
        }
    }

}
