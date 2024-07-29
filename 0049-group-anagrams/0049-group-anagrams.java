class Solution {
    public List<List<String>> groupAnagrams(String[] nums) 
    {
        Map<String, List> mp = new HashMap<String, List>();
        for(int i = 0; i < nums.length; i++)
        {
            char[] x = nums[i].toCharArray();
            Arrays.sort(x);

            String key = String.valueOf(x);
            if(!mp.containsKey(key)){
                mp.put(key,new ArrayList());
            }

            mp.get(key).add(nums[i]);
        }

        return new ArrayList(mp.values());

    }
}

/*
import java.util.*; 

class HelloWorld {
    public static void main(String[] args) {
        String[] nums = new String[]{"cat","dog","tac","god","act"};
        HashMap<String,String> mp = new HashMap<>();
        
        for(int i = 0; i < 5; i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],""));
	    //mp[nums[i]] = nums[i];
        }
	
	//string arr[] = new string[nums.length];
	List<String> ans = new ArrayList<>();
	//int i = 0
	for(Map.Entry<String,String> entry : mp.entrySet()){
	    String r = entry.getKey(); //key
	    
	    ans.add(r);
	    
	   // if(mp.find(r) != mp.end){
	   //     ans.push_back(mp[r]);
	   // }
	    
	}
	for(int i = 0; i < ans.size(); i++){
	    System.out.print(ans.get(i));
	    System.out.print(",");
	}
	//System.out.println()
	
	//return 0;
    }
}
*/