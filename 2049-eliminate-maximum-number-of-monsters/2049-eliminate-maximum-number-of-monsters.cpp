class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> distCity(n,0);

        for(int i = 0; i < n; i++){
            distCity[i] = (double)dist[i]/speed[i];
        }

        sort(distCity.begin(), distCity.end());
        int count = 0;

        for(int i = 0; i < n; i++){
            if(distCity[i] <= i)
                break;
            
            count++;
        }
        
        return count;
    }
};