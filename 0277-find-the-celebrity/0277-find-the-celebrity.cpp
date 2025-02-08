/* The knows API is defined for you.
      bool knows(int a, int b); */

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