package Sort;

import java.util.Arrays;

public class InsertionSort {

    public static void main(String[] args) {

        int[] arr = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

        for (int i = 1; i < arr.length; i++) {

            for (int j = i; j > 0; j--) {
                // 한칸 씩 왼쪽으로 이동. (이미 자기 왼쪽은 다 정렬된 상태라고 봄. 왼쪽게 나보다 크면 맞바꿈..)
                if (arr[j - 1] > arr[j]) {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
                // 자기보다 작은 데이터를 만나면 그자리에서 멈춤!
                else {
                    break;
                }
            }

        }

        Arrays.stream(arr).forEach(System.out::println);

    }

}
