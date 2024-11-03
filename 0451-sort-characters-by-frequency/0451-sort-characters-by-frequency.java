class Solution {
    public String frequencySort(String s) {
        PriorityQueue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<>((a,b) -> b.getValue() - a.getValue());

        Map<Character, Integer> freq = new HashMap<>();
        for(Character c : s.toCharArray()){
            freq.put(c, freq.getOrDefault(c,0)+1);
        }

        maxHeap.addAll(freq.entrySet());
        StringBuilder sb = new StringBuilder();

        while(maxHeap.size() > 0){
            Map.Entry<Character, Integer> x = maxHeap.remove();
            for(int i = 0; i < x.getValue(); i++){
                sb.append(x.getKey());
            }
        }
        
        return sb.toString();
    }
}