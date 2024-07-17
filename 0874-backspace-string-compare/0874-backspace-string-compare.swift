class Solution {
    func processString(_ str: String) -> String {
        var processed = ""

        for c in str {
            if c == "#"{
                if !processed.isEmpty {
                    processed.removeLast()
                }
            } else {
                processed.append(c)
            }
        }

        return processed
    }

    func backspaceCompare(_ s: String, _ t: String) -> Bool {
        // Compare the processed versions of both strings
        return processString(s) == processString(t)
    }
}