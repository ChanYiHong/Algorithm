package JavaPractice;

import java.util.Arrays;
import java.util.List;
import java.util.function.BiConsumer;
import java.util.function.Consumer;
import java.util.function.IntBinaryOperator;
import java.util.function.Supplier;

public class LamdaTest {

    private static int[] arr = {1,2,3,4,5};

    public static void main(String[] args) {
        MyFunctionalInterface fi = () -> {
            String str = "flex";
            System.out.println(str);
        };

        fi.method1();

        Consumer<String> consumer = a -> System.out.println(a);
        consumer.accept("kkk");

        BiConsumer<String, Integer> biConsumer = (a, b) -> System.out.println(a + b);
        biConsumer.accept("kkk", 1);

        Supplier<String> supplier = () -> "반환";
        System.out.println(supplier.get());

        maxOrMin((a,b) -> {
            if(a >= b) return a;
            else return b;
        });

        maxOrMin((a,b) -> {
            if(a <= b) return a;
            else return b;
        });

    }

    private static void maxOrMin(IntBinaryOperator operator) {

        int result = arr[0];
        for (int i : arr) {
            result = operator.applyAsInt(result, i);
        }
        System.out.println(result);
    }
}
