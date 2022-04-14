class Solution {
    public int numUniqueEmails(String[] emails) {
        // hash set to store all the unique emails
        Set<String> uniqueEmails = new HashSet<>(); // []

        for (String email : emails) {
            // split into two parts local and domain
            String[] parts = email.split("@"); //parts: ["test.email+alex","leetcode.com"]

            // split local by '+'
            String[] local = parts[0].split("\\+"); // local: ["test.email","alex"]

            // remove all '.', and concatenate '@' and append domain
            //uniqueEmails.add(local[0].replace(".", "") + "@" + parts[1]);
            String temp1 = local[0].replace(".", ""); // temp1: "testemail"
            String temp2 = temp1 + "@" + parts[1]; // temp2: "testemail@leetcode.com"
            uniqueEmails.add(temp2); // [testemail@leetcode.com]
        }

        return uniqueEmails.size();
    }
}