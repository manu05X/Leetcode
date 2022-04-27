class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if(n == 0)
            return 0;
        
        int leftArr[n];
        int rightArr[n];
        
        leftArr[0] = height[0];
        
        cout << leftArr[0]<<" "<<"\n";
        for(int i = 1; i < n; i++)
        {
           leftArr[i] = max(leftArr[i-1], height[i]);
            cout << leftArr[i] <<" ";
        }
        cout << "\n";
        rightArr[n-1] = height[n-1];
         cout << rightArr[n-1]<<" ";
        cout << "\n";
        for(int i = n-2; i>=0; i--)
        {
           rightArr[i] = max(rightArr[i+1], height[i]);
            cout <<rightArr[i] <<" ";
        }
        cout << "\n";
        for(int i = 0; i < n; i++)
        {
            cout << rightArr[i] <<" ";
        }
         cout << "\n";
        
        int water = 0;
        for(int i = 0; i < n; i++)
        {
            water += min(leftArr[i], rightArr[i]) - height[i];
           cout << water <<" ";
        }
        
        return water;
    }
};