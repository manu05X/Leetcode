class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] bmax = count("");
        for (String b : B) {
            int[] bCount = count(b);
            for (int i = 0; i < 26; ++i) {
                bmax[i] = Math.max(bmax[i], bCount[i]);
            }
        }

        List<String> ans = new ArrayList<>();
        for (String a : A) {
            int[] aCount = count(a);
            boolean isUniversal = true; // Flag to check if 'a' is universal
            for (int i = 0; i < 26; ++i) {
                if (aCount[i] < bmax[i]) {
                    isUniversal = false;
                    break; // Break out of the inner loop
                }
            }
            if (isUniversal) {
                ans.add(a); // Add 'a' to the result if it satisfies all conditions
            }
        }

        return ans;
    }

    public int[] count(String S) {
        int[] ans = new int[26];
        for (char c : S.toCharArray()) {
            ans[c - 'a']++;
        }
        return ans;
    }
}


/*
class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] bmax = count("");
        for (String b: B) {
            int[] bCount = count(b);
            for (int i = 0; i < 26; ++i)
                bmax[i] = Math.max(bmax[i], bCount[i]);
        }

        List<String> ans = new ArrayList();
        search: for (String a: A) {
            int[] aCount = count(a);
            for (int i = 0; i < 26; ++i)
                if (aCount[i] < bmax[i])
                    continue search;
            ans.add(a);
        }

        return ans;
    }

    public int[] count(String S) {
        int[] ans = new int[26];
        for (char c: S.toCharArray())
            ans[c - 'a']++;
        return ans;
    }
}
*/