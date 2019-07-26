class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> check; check.resize(row.size() / 2, 2);
        int ans = 0;
        vector<int> vp; vp.resize(row.size());
        
        for(int i = 0; i < check.size(); i ++){
            int h = max(row[i * 2], row[i * 2 + 1]);
            int l = min(row[i * 2], row[i * 2 + 1]);
            if((h - l == 1) && (h % 2)){
                // OK! no need to move
                check[i] = 0;
            } else {
                vp[l] = i; vp[h] = i;
                ans ++;
            }
        }
        if(ans == 0) return ans;
        for(int i = 0; i < check.size(); i ++){
            if(check[i]){
                queue<int> Q;
                Q.push(i);
                while(!Q.empty()){
                    int x = Q.front(); Q.pop();
                    if(check[x] != 0){
                        Q.push(vp[row[x * 2] ^ 1]);
                        Q.push(vp[row[x * 2 + 1] ^ 1]);
                        check[x] = 0;
                    }
                }
                ans --;
            }
        }
        return ans;
    }
};