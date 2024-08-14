func firstUniqChar(s string) int {
    n := len(s);
    hm := make([]int, 26);

    for i := 0; i < n; i++ {
        hm[s[i]-'a']++;
    }

    for i := 0; i < n; i++{
        if hm[s[i]-'a'] == 1{
            return i;
        }
    }
    return -1;
}