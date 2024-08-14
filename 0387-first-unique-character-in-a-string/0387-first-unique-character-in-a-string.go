func firstUniqChar(s string) int {
    var hm [26]int;

    for i:= range s {
        hm[s[i]-'a']++;
    }

    for  i:= range s {
        if hm[s[i]-'a'] == 1{
            return i;
        }
    }
    return -1;
}