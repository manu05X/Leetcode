class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        // We use a hash map 'basket' to store the number of each type of fruit.
        unordered_map<int,int> mp;
        int maxPick = 0;

        // Add fruit from the right index (right) of the window.
        for(int right = 0; right < fruits.size(); right++){
            mp[fruits[right]]++;

            // If the current window has more than 2 types of fruit,
            // we remove fruit from the left index (left) of the window,
            // until the window has only 2 types of fruit.
            while(mp.size()>2){
                mp[fruits[left]]--;

                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;// increase the start ptr
            }
            //currPick 
            int currPick = right-left+1;
            maxPick = max(currPick,maxPick);// maxPick
        }
        return maxPick;
    }
};

/*
//  Doesn't respect the requirement of consecutive picking from left to right
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            mp[fruits[i]]++;
        }

        int f = 0, nf = 0, s = -1, ns = 0;
        for(auto i = mp.begin(); i != mp.end(); i++)
        {
            if(i->second > f){
                s = f;
                ns = nf;

                f = i->second;
                nf = i->first;

                
            } else if(i->second > s && i->second < f){
                s = i->second;
                ns = i->first;
            }
        }

        int ans = mp[ns] + mp[nf];

        return ans;
    }
};
*/