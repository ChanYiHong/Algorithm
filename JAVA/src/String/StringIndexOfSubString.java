package String;

public class StringIndexOfSubString {

    public static void main(String[] args) {
        String[] str = {"test", "teacher"};
        System.out.println(new StringIndexOfSubString().solve(str));
    }

    private String solve(String[] str) {

        if(str.length == 0) return "";

        String firstStr = str[0];

        for(int i = 1; i < str.length; i++) {

            while(str[i].indexOf(firstStr) != 0) {
                firstStr = firstStr.substring(0, firstStr.length()-1);
            }

        }
        return firstStr;
    }
}
