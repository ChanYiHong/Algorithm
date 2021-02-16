package String;

public class StringCharAt1 {

    public static void main(String[] args) {
        String num1 = "123";
        String num2 = "888";
        System.out.println(new StringCharAt1().solve(num1, num2));
    }

    private String solve(String num1, String num2) {

        // 알고리즘을 담을 그릇을 정한다. (자료구조)
        int carry = 0;

        // "문자열" + "문자열" 은 새로 인스턴스를 생성하기 때문에 메모리 낭비가 크다
        // 기존의 메모리에 존재하는 String 인스턴스에 추가 시키는 (Thread Safe x) 한 StringBuilder를 사용하자.
        StringBuilder sb = new StringBuilder();

        int num1Length = num1.length()-1;
        int num2Length = num2.length()-1;

        // 둘다 길이(사실 인덱스임)가 0 보다 작아질 때까지 돌림.
        while(num1Length >= 0 || num2Length >= 0) {
            int n1 = 0, n2 = 0;
            // num1이 남았는지 체크.
            if(num1Length >= 0){
                n1 = num1.charAt(num1Length) - '0';
            }
            // num2가 남았는지 체크.
            if(num2Length >= 0){
                n2 = num2.charAt(num2Length) - '0';
            }
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            sb.append(sum % 10);

            num1Length--;
            num2Length--;
        }
        // 자릿수가 하나 더 추가 될 수 있음.
        if(carry!=0){
            sb.append(carry);
        }

        // 현재 거꾸로 들어갔기 때문에, 뒤집어서 보내준다.
        // 이건 굉장한 발견인듯.
        return sb.reverse().toString();
    }
}
