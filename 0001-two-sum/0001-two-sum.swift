class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict = [Int: Int]()
        for (indx, value) in nums.enumerated(){
            let diff = target-value;

            if let found = dict[diff] {
                return [found,indx]
            }
            dict[value]=indx
        }

        return []
    }
}