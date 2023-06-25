
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& v) {
        int cnt = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i][0] == v[j][1] && v[i][1] == v[j][0]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};