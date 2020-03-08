class Solution {
public:
    int findTheLongestSubstring(string m) {
		// Naive: O(N^2)
		// A[i]: 00000b, represents the odd-even status for every char
        // Calculate S[i] = A[0] ^ ... ^ A[i - 1], i = 1, 2, ..., n
        // Choose largest k > 0 s.t., S[i + k] ^ S[i] = 0, i = 0, ... , n - 1
		// Opt: O(N)
		// store the first status seen before:
		// seen[S[i]] = i when S[i] first appears, except for S[0] = 0
        int n = m.length();        
        vector<int> seen(32, n + 1); // corresponds to S[i]
		seen[0] = 0;
		int ans = 0;
        char cur = 0;
        for(int i = 0; i < n; i ++) {
            char t = 0;
            switch(m[i]){
                case 'a': t = 1; break;
                case 'e': t = 1 << 1; break;
                case 'i': t = 1 << 2; break;
                case 'o': t = 1 << 3; break;
                case 'u': t = 1 << 4; break;
                default: break;
            }
            cur = cur ^ t;
            seen[cur] = min(seen[cur], i + 1);	// update seen[]
            ans = max(ans, (i + 1) - seen[cur]);// update ans
        }
        return ans;
    }
};