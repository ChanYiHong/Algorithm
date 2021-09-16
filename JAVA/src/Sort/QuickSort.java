package Sort;

import java.util.Arrays;

public class QuickSort {

    public static void main(String[] args) {

        int[] arr = {5, 7, 9, 0, 3, 1, 6, 2, 4, 8};

        quickSort(arr, 0, arr.length - 1);

//        Arrays.stream(arr).forEach(System.out::print);

    }

    private static void quickSort(int[] arr, int start, int end) {

        if (start >= end) {
            return;
        }

        int pivot = start;
        int left = start + 1;
        int right = end;

        while (left <= right) {

            // 왼쪽에서 부터 피봇보다 큰 친구를 찾음.
            while (left <= end) {
                if (arr[left] > arr[pivot]) {
                    break;
                }
                left++;
            }

            // 오른쪽부터 피봇보다 작은 친구를 찾음.
            while (right > start) {
                if (arr[right] < arr[pivot]) {
                    break;
                }
                right--;
            }

            // 엇갈렸을 경우
            if (left > right) {
                int temp = arr[right];
                arr[right] = arr[pivot];
                arr[pivot] = temp;
            }
            // 엇갈리지 않았을 경우
            else {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }

        Arrays.stream(arr).forEach(System.out::print);
        System.out.println();

        quickSort(arr, start, right - 1);
        quickSort(arr, right + 1, end);

    }

}
