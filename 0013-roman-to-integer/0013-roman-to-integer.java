/*
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);

        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            if(i < s.length() - 1 && mp.get(s.charAt(i)) < mp.get(s.charAt(i + 1))){
                ans -=  mp.get(s.charAt(i));
                continue;
            }

            ans += mp.get(s.charAt(i));
        }

        return ans;
    }
}
*/


class Solution {
    public int romanToInt(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int current = getValue(s.charAt(i));
            int next = i + 1 < s.length() ? getValue(s.charAt(i + 1)) : 0;
            if (current < next) {
                ans -= current;
            } else {
                ans += current;
            }
        }
        return ans;
    }

    private int getValue(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
}

/*

MCMXCIV

(M)1000 -> (C) 1000-100 -> (M) 1900 -> (X) 1900-10 -> (C) 1890+100 -> (I) 1990-1 -> 1989+5 => 1994 

 */