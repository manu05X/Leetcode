class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> prefixCommon(n), freq(n+1, 0);
        int commonCount = 0;

        for(int i = 0; i < n; i++){
            int aCurrElm = A[i];
            int bCurrElm = B[i];

            freq[aCurrElm]++;
            if(freq[aCurrElm] == 2){
                commonCount++;
            }

            freq[bCurrElm]++;
            if(freq[bCurrElm] == 2){
                commonCount++;
            }

            prefixCommon[i]=commonCount;
        }

        return prefixCommon;
    }
};