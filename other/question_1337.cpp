
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vts;
        for (int row = 0; row < mat.size(); row++) {
            int ones = 0;
            for (auto& val: mat[row]) {
                if (val == 1) 
                    ones++;
            }
            vts.push_back(make_pair(ones, row));
        }

        sort(vts.begin(), vts.end());
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(vts[i].second);
        }
        return ret;
    }
};