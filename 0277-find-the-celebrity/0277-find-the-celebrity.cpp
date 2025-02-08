/* The knows API is defined for you.
      bool knows(int a, int b); */

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;

        // Step 1: Find the potential celebrity
        for(int i = 1; i < n; i++){
            if(knows(candidate, i)){  // If candidate knows i, then candidate cannot be the celebrity
                candidate = i;  // Update candidate
            }
        }

        // Step 2: Verify if the candidate is a real celebrity
        for(int i = 0; i < n; i++){
            if(i != candidate){
                // A celebrity should not know anyone, but everyone should know the celebrity
                if(knows(candidate, i) || !knows(i, candidate)){
                    return -1;
                }
            }
        }

        return candidate;
    }
};



/*

class Solution {
public:
    int findCelebrity(int n) {
        stack<int> s;
        //push all the elements in stack
        for(int i = 0 ; i < n ; i++)
            s.push(i);
        
        //pop top 2 elements and identify which can be potential celebrity
        while(s.size() >= 2){            
            int a = s.top();
            s.pop();            
            int b = s.top();
            s.pop();            
            if(!knows(a,b) && knows(b,a)){
                s.push(a);   
            }
            else{
                
                 s.push(b);
            }           
        }
        
        // if stack empty then no celebrity
        if(s.empty())
            return -1;
       
        //the last element is the potential celebrity. to confirm traverse the loop again
        int last = s.top();
        for(int i = 0 ; i < n ; i++){
            if(i != last){
                if(!knows(i,last) || knows(last,i))
                    return -1;
            }
        }
        return last;
    }
};

*/