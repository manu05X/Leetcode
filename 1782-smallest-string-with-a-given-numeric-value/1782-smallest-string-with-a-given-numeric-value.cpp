class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 0);

        for(int pos = n-1; pos >= 0; pos--){
            int add = min(k-pos, 26);

            result[pos] = (char)(add + 'a'-1);
            k -= add;
        }

        return result;
    }
};