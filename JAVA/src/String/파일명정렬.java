package String;

import java.util.*;

public class 파일명정렬 {

    class File implements Comparable<File>{
        String head;
        String number;
        String tail;

        public File(String head, String number, String tail) {
            this.head = head;
            this.number = number;
            this.tail = tail;
        }

        @Override
        public int compareTo(File f) {

            String thisHead = this.head.toLowerCase();
            String fileHead = f.head.toLowerCase();

            int thisNumber = Integer.parseInt(this.number);
            int fileNumber = Integer.parseInt(f.number);

            if(!thisHead.equals(fileHead)) {
                return thisHead.compareTo(fileHead);
            } else {
                if(thisNumber != fileNumber) {
                    return Integer.compare(thisNumber, fileNumber);
                }
                else{
                    return 0;
                }
            }

        }

        @Override
        public String toString() {
            return this.head + this.number + this.tail;
        }
    }

    class Solution {
        public String[] solution(String[] files) {
            String[] answer = {};

            List<File> fileList = new ArrayList<>();

            for(String file : files) {

                String head = "";
                String number = "";
                String tail = "";

                boolean isNumber = false;
                int numberStart = 0;

                for(int i = 0; i < file.length(); i++) {
                    if(Character.isDigit(file.charAt(i)) && !isNumber) {
                        head = file.substring(0, i);
                        isNumber = true;
                        numberStart = i;
                        System.out.println(i);
                    }
                    else if(!Character.isDigit(file.charAt(i)) && isNumber) {

                        System.out.println(i);
                        number = file.substring(numberStart, i);
                        tail = file.substring(i);
                        break;
                    }
                }

                // 혹시 tail이 비었을 경우.
                if(number == "") {
                    number = file.substring(numberStart, file.length());
                }

                fileList.add(new File(head, number, tail));

            }

            Collections.sort(fileList);

            answer = new String[fileList.size()];

            for(int i = 0; i < fileList.size(); i++) {
                File file = fileList.get(i);
                if(file.tail == "") answer[i] = file.head + file.number;
                else answer[i] = file.head + file.number + file.tail;
            }

            return answer;
        }
    }
}
