package String;

public class StringCharAt2 {

    public static void main(String[] args) {
        String s = "(a(b(c)d)";
        System.out.println("result: " + new StringCharAt2().solve(s));
    }

    private String solve(String s) {

        //1
        StringBuilder sb = new StringBuilder();
        StringBuilder result = new StringBuilder();
        int open = 0; // '('

        //2 우선 open의 개수를 알아내자
        for(char c : s.toCharArray()) {
            if(c=='(') {
                open++;
            }else if(c==')'){
                // open이 0개일 때 ')'는 그냥 버린다. ")) ((" 인 케이스
                if(open == 0) continue;
                open--;
            }
            sb.append(c);
        }

        //3 역순으로 뺀다..
        for(int i = sb.length() - 1; i >= 0; i--) {
            if(sb.charAt(i) == '(' && open > 0) {
                open--;
                continue;
            }
            result.append(sb.charAt(i));
        }
        return result.reverse().toString();
    }
}
/**
 *  역순으로 하는 이유
 *
 *  )()( 이렇게 있다 치면
 *
 *  만약 순서대로 한다면
 *  () ( 가 open 개수 셀 때 저장되는데
 *  () (에서 open이 1임
 *  open이 1이므로 (를 무시, open--하므로 open은 0
 *
 *  그 후에 남은 ) ( 를 저장
 *
 *  
 */
