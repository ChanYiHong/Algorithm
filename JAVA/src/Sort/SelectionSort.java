package Sort;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class SelectionSort {

    public int[] sort(int[] arr) {
        int min, index;
        for(int i = 0; i < arr.length; i++) {
            min = arr[i];
            index = i;
            for(int j = i+1; j < arr.length; j++) {
                if(min > arr[j]) {
                    min = arr[j];
                    index = j;
                }
            }
            if(index != i) {
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = new int[] {9,2,7,5,4};
        SelectionSort selectionSort = new SelectionSort();
        int[] result = selectionSort.sort(arr);
        for (int num : result) {
            System.out.println(num);
        }
    }
}
