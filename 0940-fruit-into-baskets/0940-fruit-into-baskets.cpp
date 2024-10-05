// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int left = 0;
//         // We use a hash map 'basket' to store the number of each type of fruit.
//         unordered_map<int,int> mp;
//         int maxPick = 0;

//         // Add fruit from the right index (right) of the window.
//         for(int right = 0; right < fruits.size(); right++){
//             mp[fruits[right]]++;

//             // If the current window has more than 2 types of fruit,
//             // we remove fruit from the left index (left) of the window,
//             // until the window has only 2 types of fruit.
//             while(mp.size()>2){
//                 mp[fruits[left]]--;

//                 if(mp[fruits[left]] == 0){
//                     mp.erase(fruits[left]);
//                 }
//                 left++;// increase the start ptr
//             }
//             //currPick 
//             int currPick = right-left+1;
//             maxPick = max(currPick,maxPick);// maxPick
//         }
//         return maxPick;
//     }
// };

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

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);

        int fruitType1 = fruits[0]; // First type of fruit (initialized with first fruit)
        int fruitType2 = -1;        // Second type of fruit (initially unset)
        int countFruit1 = 1;        // Count of the first type of fruit
        int countFruit2 = 0;        // Count of the second type of fruit (initially zero)

        int maxFruits = 1;          // Maximum number of fruits collected
        int currentFruits = 1;      // Current number of fruits collected in the window

        for (int i = 1; i < fruits.size(); i++) {
            if (fruits[i] == fruitType1) {
                // If the current fruit is the same as fruitType1, increase count for this type
                countFruit1++;
                currentFruits++;
                countFruit2 = 0; // Reset count for the second type since the last fruit was type 1
            } else {
                if (fruitType2 == -1) {
                    // If fruitType2 is unset, initialize it with the current fruit
                    fruitType2 = fruits[i];
                    countFruit2 = 1;
                    currentFruits++;
                } else {
                    if (fruits[i] == fruitType2) {
                        // If the current fruit is fruitType2, increase count for this type
                        countFruit2++;
                        currentFruits++;
                    } else {
                        // We encountered a new fruit, need to reset window
                        maxFruits = max(maxFruits, currentFruits); // Update maxFruits if current window is bigger
                        
                        if (fruits[i-1] == fruitType1) {
                            // If the previous fruit was fruitType1, adjust to count fruitType2 as the new one
                            fruitType2 = fruits[i];
                            countFruit2 = 1;
                            currentFruits = countFruit1 + countFruit2;
                        } else {
                            // Otherwise, reset fruitType1 to the previous type
                            countFruit1 = countFruit2;
                            fruitType1 = fruitType2;
                            fruitType2 = fruits[i];
                            countFruit2 = 1;
                            currentFruits = countFruit1 + countFruit2;
                        }
                    }
                }
                countFruit1 = 0; // Reset count for the first type when switching
            }
        }
        maxFruits = max(maxFruits, currentFruits); // Final check for the last window
        return maxFruits;
    }
};
