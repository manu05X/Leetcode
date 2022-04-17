class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m; // map to store task and its frequency
        for(int i=0; i<tasks.size(); i++)
            m[tasks[i]]++; // storing frequencies in map
        int answer=0;
        for(auto x:m){
            if(x.second==1) // if a task is present only once, return -1
                return -1;
            answer+=(x.second)/3;
            /* if x.second is not divisible by 3, then we would be required to consider the cases when only two tasks are selected 
            - in last round for (x.second%3==2)
            - in last two rounds (x.second%3==1) */
            if(x.second%3==1 || x.second%3==2)
                answer++;
        }
        return answer;
    }
};