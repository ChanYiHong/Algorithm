package String;

public class 신규아이디추천 {

    public String stepOne(String str) {
        str = str.toLowerCase();
        return str;
    }

    public String stepTwo(String str) {
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);

            if(c == '-' || c == '_' || c == '.') {
                sb.append(c);
            }
            if((c >= 97 && c <= 122) || (c >= 48 && c <= 57)) {
                sb.append(c);
            }
        }

        return sb.toString();
    }

    public String stepThree(String str) {
        StringBuilder sb = new StringBuilder(str);
        boolean isBeforePoint = false;

        for(int i = 0; i < sb.length(); i++) {
            if(sb.charAt(i) == '.' && isBeforePoint == false) {
                isBeforePoint = true;
                continue;
            }
            if(sb.charAt(i) == '.' && isBeforePoint == true) {
                sb.deleteCharAt(i);
                i--;
                continue;
            }
            if(sb.charAt(i) != '.' && isBeforePoint == true) {
                isBeforePoint = false;
            }
        }

        return sb.toString();
    }

    public String stepFour(String str) {

        if(str.length() < 2 && str.charAt(0) == '.'){
            str = "";
            return str;
        }

        if(str.charAt(0) == '.') {
            str = str.substring(1);
        }
        if(str.charAt(str.length() - 1) == '.') {
            str = str.substring(0, str.length() - 1);
        }
        return str;
    }

    public String stepFive(String str) {
        if(str.isEmpty()) {
            str = "a";
        }
        return str;
    }

    public String stepSix(String str) {
        if(str.length() >= 16) {
            str = str.substring(0, 15);
            str = stepFour(str);
        }
        return str;
    }

    public String stepSeven(String str) {
        StringBuilder sb = new StringBuilder(str);
        char last = sb.charAt(sb.length() - 1);
        if(sb.length() <= 2) {
            while(sb.length() < 3) {
                sb.append(last);
            }
        }
        return sb.toString();
    }

    public String solution(String new_id) {
        String answer = new_id;

        answer = stepOne(answer);
        answer = stepTwo(answer);
        answer = stepThree(answer);
        answer = stepFour(answer);
        answer = stepFive(answer);
        answer = stepSix(answer);
        answer = stepSeven(answer);

        System.out.println(answer);

        return answer;
    }

}
