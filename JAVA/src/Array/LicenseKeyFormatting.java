package Array;

public class LicenseKeyFormatting {

    public static void main(String[] args) {
        String str = "8F3Z-2e-9-w";
        String str2 = "8-5g-3-J";
        int k = 4;
        System.out.println(solve2(str2, k));
    }

    private static String solve(String str, int k) {
        StringBuilder ret = new StringBuilder();
        int cnt = 0;

        for(int i = str.length() - 1; i >= 0; i--) {
            char c = str.charAt(i);
            if(c == '-') continue;

            if(c >= 97 && c <= 122) {
                ret.append((char)(c - 32));
            } else{
                ret.append(c);
            }

            cnt++;
            if(cnt % k == 0 && i != 0) {
                ret.append('-');
            }
        }

        return ret.reverse().toString();
    }

    private static String solve2(String str, int k) {
        String newStr = str.replace("-", "");
        newStr = newStr.toUpperCase();

        StringBuilder sb = new StringBuilder(newStr);

        for(int i = k; i < sb.length(); i += k) {
            sb.insert(sb.length() - i, '-');
        }

        return sb.toString();
    }

}
