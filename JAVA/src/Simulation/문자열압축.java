package Simulation;

public class 문자열압축 {

    class Solution {
        public int solution(String s) {
            int answer = s.length();

            int slice = 1;

            while (slice <= s.length() / 2) {

                StringBuilder compressed = new StringBuilder();

                for (int i = 0; i <= s.length() - slice; i += slice) {

                    String pattern = s.substring(i, slice + i);
                    String remain = s.substring(i + slice);

                    // System.out.println(pattern);
                    // System.out.println(remain);

                    int cnt = 1;
                    int nextStart = i;

                    for (int j = 0; j <= remain.length() - slice; j += slice) {
                        String cur = remain.substring(j, slice + j);

                        // System.out.println("cur : " + cur);

                        if (cur.equals(pattern)) {
                            nextStart += slice;
                            cnt++;
                        } else{
                            break;
                        }
                    }

                    if (cnt > 1) {
                        compressed.append(cnt);
                    }
                    compressed.append(pattern);
                    i = nextStart;

                }

                if (s.length() % slice != 0) {
                    compressed.append(s.substring(s.length() - (s.length() % slice)));
                }

                // System.out.println("Result : " + compressed.toString());

                answer = Math.min(answer, compressed.toString().length());
                slice++;
            }

            return answer;
        }
    }

}
