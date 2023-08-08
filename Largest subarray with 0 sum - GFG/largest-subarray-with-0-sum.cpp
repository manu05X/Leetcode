//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int maxLength = 0, curSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            curSum +=A[i]; 
            if(A[i]==0 && maxLength == 0)
            {
                maxLength = 1;
            }
            if(curSum == 0)
            {
                maxLength =i+1;
            }
            
            if(mp.find(curSum) != mp.end())
            {
                maxLength = max(maxLength, i-mp[curSum]);
            }
            else
            {
                mp[curSum] = i;
            }
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends