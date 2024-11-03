class Solution {
    public String frequencySort(String s) {
        int[] count = new int[128];

        for (char ch: s.toCharArray()) {
            count[ch]++;
        }

        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> Integer.compare(b[1], a[1]));
        for (int i = 0; i < 128; i++) {
            heap.offer(new int[]{i, count[i]});
        }

        StringBuilder sb = new StringBuilder();
        while (!heap.isEmpty()) {
            int[] node = heap.poll();
            if (node[1] == 0) {
                break;
            }

            for (int i = 0; i < node[1]; i++) {
                sb.append((char)node[0]);
            }
        }

        return sb.toString();
    }
}


/*
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
*/