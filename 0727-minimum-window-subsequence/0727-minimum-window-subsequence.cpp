class Solution {
public:
    string minWindow(string str1, string str2) {
        int strlen1 = str1.size();
        int strlen2 = str2.size();

        int minLen = INT_MAX;

        int idxS1 = 0;
        int idxS2 = 0;

        string minSequance = "";

        //int start = 0, end = 0;
        // iterate over str1 while we haven't reached the end of pointer one.
        while(idxS1 < strlen1)
        {
            if(str1[idxS1] == str2[idxS2])
            {
                // increment to find the next matching element.
                idxS2++;
                // check if a valid substring has been found
                if(idxS2 == strlen2)
                {
                    idxS2--;
                    // here we will stretch the window from start to end by decrementing the size of start;
                    int start = idxS1, end = idxS1+1;
                    // we'll iterate backwards to find all the chars of s2
                    // abced ace
                    while(idxS2 >= 0)
                    {
                        if(str1[start] == str2[idxS2])
                        {
                            idxS2--;
                        }
                        start--;
                    }
                    start+=1;

                    // update minSubLen and minSubsequence if current subsequence is shorter
                    if(minLen > (end - start))
                    {
                        minLen = end - start;
                        minSequance = str1.substr(start, minLen);
                    }
                    idxS1 = start;
                    idxS2 = 0;
                }

            }
            idxS1++;
        }

        return minSequance;
    }
};

/*
The process this algorithm follows is as follows.
1. use 2 pointers to iterate over each string accordingly
2. if we find a match a = a increment both pointers
3. if we've reached the end of str2, str1 obviosuly contains it.
4. at this point we will initialize 2 new pointers. start and end, which will be set to ptr1, the point at which we stopped iterating over str1, end will be set to start + 1
5. We will use the start and end pointers to calculate length and extract the substring.
6. We will iterate backwards and check if the s2[ptr2] == s1[start] if it does then ptr2-- start-- else start--
7. We do this until ptr2 reaches 0, when ptr2 reaches 0 we check if the length of end - start is smaller than the longest_substring, if it is then we have found a smaller substring and we use the susbtr method to extract it.
8. Lastly we set ptr1 to start and ptr2 to 0 to check the rest of the string, in hopes of finding a shorter one.
*/