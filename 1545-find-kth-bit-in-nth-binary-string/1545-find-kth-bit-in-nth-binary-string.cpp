class Solution {
    string ri(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) swap(s[l++] ^= 1, s[r--] ^= 1);
        s[l] ^= 1;
        return s;
    }
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while (s.size() < k) s += "1" + ri(s);
        return s[k-1];
    }
};