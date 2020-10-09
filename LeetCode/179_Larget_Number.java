import java.util.ArrayList;
import java.util.Comparator;

class Solution {

    public String largestNumber(int[] nums) {
        ArrayList<String> list = new ArrayList<>();
        StringBuilder answerBuilder = new StringBuilder();
        String answer = null;

        for (int num : nums) {
            list.add(String.valueOf(num));
        }

        list.sort(createComparator());

        for (String str : list) {
            answerBuilder.append(str);
        }

        answer = answerBuilder.toString();

        if (isZero(answer)) {
            answer = "0";
        }

        return answer;
    }

    private boolean isZero(String str) {
        boolean isZero = true;

        for (char c : str.toCharArray()) {
            if (c != '0') {
                isZero = false;

                break;
            }
        }

        return isZero;
    }

    private Comparator<String> createComparator() {
        return (String o1, String o2) -> {
            if ((o1.charAt(0) - '0') < (o2.charAt(0) - '0')) {
                return 1;
            } else if ((o1.charAt(0) - '0') == (o2.charAt(0) - '0')) {
                return chooseOne(o1, o2);
            }

            return -1;
        };
    }

    private int chooseOne(String o1, String o2) {
        String choiceOne = o1 + o2;
        String choiceTwo = o2 + o1;
        long choiceOneInt = Long.valueOf(choiceOne);
        long choiceTwoInt = Long.valueOf(choiceTwo);

        if (choiceOneInt > choiceTwoInt) {
            return -1;
        } else if (choiceOneInt == choiceTwoInt) {
            return 0;
        }

        return 1;
    }
}

public class Main {

    public static void main(String[] args) {
        System.out.println(new Solution().largestNumber(new int[]{20, 2}));
        System.out.println(new Solution().largestNumber(new int[]{3, 30, 34, 5, 9}));
        System.out.println(new Solution().largestNumber(new int[]{0, 0}));
    }
}