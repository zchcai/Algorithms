class Solution {
public:
    /* d[i] means the min cost after put the i books, d[0] = 0
     * d[i] = min(d[i - 1] + books[i - 1][1], 
                min( d[j] + max(books[j][1], ..., books[i - 1][1]))), for j < i but books[j][0] + books[j + 1][0] + ... + books[i - 1][0] <= width
     * */
    int minHeightShelves(vector<vector<int>>& books, int width) {
        vector<int> d; d.resize(books.size() + 1);
        d[0] = 0; d[1] = books[0][1];
        for(int i = 2; i <= books.size(); i ++){
            d[i] = d[i - 1] + books[i - 1][1];
            int j = i - 1;
            int w = 0;
            int h = 0;
            while(j >= 0){
                w += books[j][0];
                h = max(h, books[j][1]);
                if(w > width) break;
                d[i] = min(d[i], d[j] + h);
                j --;
            }
        }
        return d[books.size()];
    }
};
