/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int ret = len;
        int mid = (len - 1) / 2;
        int a = work(target, mountainArr, 0, mid);
        int b = work(target, mountainArr, mid + 1, len - 1);
        if((a != -1) && a < ret) ret = a;
        if((b != -1) && b < ret) ret = b;
        if(ret == len) return -1;
        return ret;
    }
    int work(int t, MountainArray &mountainArr, int l, int r){
        int lv = mountainArr.get(l);
        if(lv == t) return l;
        if(r - l < 3){
            if((l + 1 <= r) && mountainArr.get(l + 1) == t) return l + 1;
            if((l + 2 <= r) && mountainArr.get(l + 2) == t) return l + 2;
            return -1;
        }
        int mid = (l + r) / 2;
        int mv = mountainArr.get(mid);
        int mlv = mountainArr.get(mid - 1);
        int mrv = mountainArr.get(mid + 1);
        if((mlv < mv) && (mv < mrv)){
            if(mv < t){
                return work(t, mountainArr, mid + 1, r);
            }
            else {
                if(lv < t){
                    int ans = work(t, mountainArr, l, mid - 1);
                    if(ans != -1) return ans;
                }
                if(mv == t) return mid;
                int rv = mountainArr.get(r);
                if(rv > mv)
                    return work(t, mountainArr, r, mountainArr.length() - 1);
                else if(rv <= t) 
                    return work(t, mountainArr, mid + 1, r);
                return -1;
            }
        }
        else if ((mlv < mv) && (mv > mrv)){
            if(mv == t) return mid;
            if(lv < t){
                int ans = work(t, mountainArr, l, mid - 1);
                if(ans != -1) return ans;
            }
            int rv = mountainArr.get(r);
            if(rv < t)
                return work(t, mountainArr, mid + 1, r);
            else{
                if(rv == t) return r;
                return work(t, mountainArr, r, mountainArr.length() - 1);
            }
        }
        else if ((mlv > mv) && (mv > mrv)){
            if(mv < t){
                return work(t, mountainArr, l, mid - 1);
            }else{
                if(lv < t){
                    int ans = work(t, mountainArr, l, mid - 1);
                    if(ans != -1) return ans;
                }
                if(mv == t) return mid;
                int rv = mountainArr.get(r);
                if(rv < t)
                    return work(t, mountainArr, mid + 1, r);
                else{
                    if(rv == t) return r;
                    return work(t, mountainArr, r, mountainArr.length() - 1);
                }
            } 
        }
        return -1;
    }
};