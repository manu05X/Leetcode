class Solution {

    public boolean isSubsequence(String s, String t) 
    {
        int ns = s.length();
        int nt = t.length();
        int ps = 0, pt = 0;

        while (ps < ns && pt < nt) 
        {
            // move both pointers or just the right pointer
            // if (s.charAt(pLeft) == t.charAt(pRight)) 
            // {
            //     pLeft += 1;
            // }
            // pRight += 1;
            if (s.charAt(ps) == t.charAt(pt)) 
            {
                ps++;
                pt++;
            }
            else
            {
                pt++;
            }

        }
        // conditional operator( R== L)
        if(ps == ns) // size of s is equal to s pointer(ps)
        {
            return true;
        }
        else
        {
            return false;
        }
        //return ps == ns; // size(ns) of s is equal to s pointer(ps)
    }
}
// ns = 3, nt = 6
//       ps = 2
// a  b  c
// 0. 1.  2

// a h b g d f
//             t = 6