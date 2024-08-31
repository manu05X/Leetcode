/*
Analysis

To solve this problem, we need to understand and use the following 2 facts:
1) if the sum of gas >= the sum of cost, then the circle can be completed.
2) if A can not reach C in a the sequence of A-->B-->C, then B can not make it either.

Proof of fact 2:

If gas[A] < cost[A], then A can not even reach B. 
So to reach C from A, gas[A] must >= cost[A]. 
Given that A can not reach C, we have gas[A] + gas[B] < cost[A] + cost[B],
and gas[A] >= cost[A],
Therefore, gas[B] < cost[B], i.e., B can not reach C. 
*/
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
/*
i           = _, 0, 1, 2, 3, 4
remaning    = 0, -2,-2,-2,3, 3
sumRemaning = 0, -2,-2,-2,3, 6
start       = 0, 0, 1, 2, 3, 3
total       = 0, -2,-4,-6,-3,0
*/