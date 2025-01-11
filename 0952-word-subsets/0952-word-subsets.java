class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        // Calculate the maximum frequency for each character in B
        int[] bmax = Arrays.stream(B)
            .map(this::count) // Convert each word in B to its character frequency array
            .reduce(new int[26], (b1, b2) -> { // Combine the frequency arrays
                for (int i = 0; i < 26; i++) {
                    b1[i] = Math.max(b1[i], b2[i]);
                }
                return b1;
            });

        // Filter A for universal words
        return Arrays.stream(A)
            .filter(a -> isUniversal(count(a), bmax))
            .collect(Collectors.toList());
    }

    private int[] count(String S) {
        // Count the frequency of each character in the string
        return S.chars()
            .map(c -> c - 'a') // Convert character to index (0-25)
            .collect(() -> new int[26], (arr, idx) -> arr[idx]++, (arr1, arr2) -> {
                for (int i = 0; i < 26; i++) arr1[i] += arr2[i];
            });
    }

    private boolean isUniversal(int[] aCount, int[] bmax) {
        // Check if aCount satisfies bmax
        return IntStream.range(0, 26).allMatch(i -> aCount[i] >= bmax[i]);
    }
}


/*
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

*/

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