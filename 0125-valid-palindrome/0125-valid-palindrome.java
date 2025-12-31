class Solution {

    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right) {
            Character l = s.charAt(left);
            Character r = s.charAt(right);

            if (!Character.isLetterOrDigit(l)) {
                left++;
                continue;
            }

            if (!Character.isLetterOrDigit(r)) {
                right--;
                continue;
            }

            if (Character.toLowerCase(l) == Character.toLowerCase(r)) {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;
    }

    public boolean isPalindromeRegex(String s) {
        s = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;        
        
    }
}