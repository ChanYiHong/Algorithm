import java.util.*;

class Solution {
    
    int[] one = new int[]{1,2,3,4,5};
    int[] two = new int[]{2,1,2,3,2,4,2,5};
    int[] three = new int[]{3,3,1,1,2,2,4,4,5,5};
    
    public int[] solution(int[] answers) {
        int[] answer;
        int len = answers.length;
        
        int[] person1 = new int[len];
        int[] person2 = new int[len];
        int[] person3 = new int[len];
        
        for(int i = 0; i < len; i++){
            person1[i] = one[i % 5];
            person2[i] = two[i % 8];
            person3[i] = three[i % 10];
        }
        
        int person1Score = 0;
        int person2Score = 0;
        int person3Score = 0;
        
        for(int i = 0; i < len; i++){
            if(answers[i] == person1[i]) person1Score++;
            if(answers[i] == person2[i]) person2Score++;
            if(answers[i] == person3[i]) person3Score++;
        }
        
        int max = Math.max(person1Score, Math.max(person2Score, person3Score));
        int[] arr = new int[]{person1Score,person2Score,person3Score};
        
        if(max == arr[0] && max == arr[1] && max == arr[2]) return new int[]{1,2,3};
        else if(max == arr[0] && max == arr[1]) return new int[]{1,2};
        else if(max == arr[0] && max == arr[2]) return new int[]{1,3};
        else if(max == arr[1] && max == arr[2]) return new int[]{2,3};
        else if(max == arr[0]) return new int[]{1};
        else if(max == arr[1]) return new int[]{2};

        return new int[]{3};
    }
}