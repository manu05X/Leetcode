class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int ans = 0;
   
      for(auto &it : words){

        int i = 0;          // for iterating in the pref

        while( it[i] == pref[i]){    // if starting elements are matched then keep looping
            count++;
            i++;
            
            if(i==pref.size()){        // if i reaches the size means it got all the elements
                break;                  // so break the while loop
            }
        }

        if(count == pref.size()){    // is it equal to size ?? means all elements are found??
            ans++;                   // no. of string in vector that have this pefix
        }
        count=0;        // for again incrementing for other strinngs in vector

      }

return ans;
    }
};