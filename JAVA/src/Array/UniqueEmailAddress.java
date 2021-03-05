package Array;

import java.util.HashSet;
import java.util.Set;

public class UniqueEmailAddress {

    public static void main(String[] args) {
        String[] str = {"test.email+james@coding.com", "test.e.mail+toto.jane@coding.com", "testemail+tom@cod.ing.come"};
        System.out.println(solve2(str));
    }

    private static int solve(String[] str) {

        if(str.length == 0) return 0;

        Set<String> set = new HashSet<>();

        for(String s : str) {

            String[] email = s.split("@");

            // 앞 쪽 domain part
            email[0] = email[0].replace(".", "");
            email[0] = email[0].substring(0, email[0].indexOf('+'));

            for (String s1 : email) {
                System.out.println(s1);
            }

            set.add(email[0] + "@" + email[1]);

        }
        return set.size();
    }

    private static int solve2(String[] str) {

        if(str.length == 0) return 0;

        Set<String> set = new HashSet<>();

        for(String s : str) {

            StringBuilder name = new StringBuilder();
            for(int i = 0; i < s.length(); i++) {
                if(s.charAt(i) == '.') continue;
                if(s.charAt(i) == '+') break;
                if(s.charAt(i) == '@') break;

                name.append(s.charAt(i));
            }

            StringBuilder domain = new StringBuilder();
            domain.append(s.substring(s.indexOf('@')));

            set.add(name + "@" + domain);

        }

        return set.size();
    }
}
