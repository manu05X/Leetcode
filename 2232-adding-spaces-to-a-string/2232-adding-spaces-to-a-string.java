class Solution {
    public String addSpaces(String s, int[] spaces) {
        int n = s.length();
        int m = spaces.length;

        char[] sChar = s.toCharArray();
        char[] ansChar = new char[m+n];

        int ansP = 0, sP = 0;
        for(int spaceP : spaces){
            while(sP < spaceP){
                ansChar[ansP] = sChar[sP];
                sP++;
                ansP++;
            }
            ansChar[ansP] = ' ';
            ansP++;
        }

        while(sP < n)
        {
            ansChar[ansP]=sChar[sP];
            sP++;
            ansP++;
        }

        return new String(ansChar);
    }
}


/*
class Solution {
    public String addSpaces(String s, int[] spaces) {
        int n = s.length();
        int m = spaces.length;

        StringBuilder str = new StringBuilder();
        int spaceCount = 0;
        int p2 = 0;

        for(int i = 0; i < n && p2 < m; i++){
            int currP = i;//0, 8, 13
            //String tmp = "";

            while(currP <= spaces[p2]-1){
                currP++; // 8,13,15
            }

            str.append(s.substring(i,spaces[p2]));// (0,8), (8,13),(13,15)
            p2++; //0->1->2
            str.append(' ');

            i = currP-1;// i= 7 , 12, 14

        }

         str.append(s.substring(spaces[p2-1], n));

         return str.toString();
    }
}

*/