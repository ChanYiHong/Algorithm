package PermutationCombination;

import java.util.ArrayList;
import java.util.List;

public class Combination {

    public static void main(String[] args) {
        List<List<Integer>> solve = new Combination().solve(3, 2);

        for (List<Integer> integers : solve) {
            System.out.println("[" + integers.get(0) + " " + integers.get(1) + "]");
        }
    }

    public List<List<Integer>> solve(int n, int k) {

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> tempList = new ArrayList<>();

        backtrack(result, tempList, n, k, 1);

        return result;
    }

    public void backtrack(List<List<Integer>> result, List<Integer> tempList, int n, int k, int start) {
        if(tempList.size() == k) {
            result.add(new ArrayList<>(tempList));
        }
        else {
            for(int i = start; i <= n; i++) {
                tempList.add(i);
                backtrack(result, tempList, n, k, i+1);
                tempList.remove(tempList.size()-1);
            }
        }
    }

}
