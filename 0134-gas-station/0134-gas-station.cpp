class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sumRemaning = 0; // track current remaining
        int total = 0; // track total remaining
        int start = 0;

        //if sum remaining of (i-1) >= 0, continue 
        for(int i = 0; i < n; i++){
            int remaning = gas[i] - cost[i];

            if(sumRemaning >= 0){
                sumRemaning += remaning;
            }
            //otherwise, reset start index to be current
            else{
                sumRemaning = remaning;
                start = i;
            }
            total += remaning;
        }

        if(total >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};