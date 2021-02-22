package Map;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class MapTest {

    public static void main(String[] args) {
        Map<Integer, String> map = new HashMap<>();
        map.put(1, "A");
        map.put(2, "B");
        map.put(3, "C");

        // 1
        for (Integer key : map.keySet()) {
            System.out.println("Key : " + key + " Value : " + map.get(key));
        }

        // 2
        for (Map.Entry<Integer, String> entry : map.entrySet()) {
            System.out.println("Key : " + entry.getKey() + " Value : " + entry.getValue());
        }

        // 3
        Iterator<Integer> keys = map.keySet().iterator();

        while(keys.hasNext()) {
            Integer key = keys.next();
            System.out.println("Key : " + key + " Value : " + map.get(key));
        }
    }

}
