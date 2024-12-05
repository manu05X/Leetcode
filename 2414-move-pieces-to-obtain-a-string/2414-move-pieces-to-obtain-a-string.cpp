class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int m = target.size();

        if(n != m){
            return false;
        }

        int p1 = 0, p2 = 0;

        while( p1 <= n && p2 <= n){

            while(p1 < n && target[p1] == '_'){
                p1++;
            }

            while(p2 < n && start[p2] == '_'){
                p2++;
            }

            if(p1 == n || p2 == n){
                return p1 == n && p2 == n;
            }

            if(target[p1] != start[p2]) return false;

            if(target[p1] == 'L'){
                if(p2 < p1) return false;
            } else {
                if(p1 < p2) return false;
            }

            p1++;
            p2++;

        }

        return true;

    }
};

/*
_L__R__R_

L______RR


*/