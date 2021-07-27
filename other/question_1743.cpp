class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for (auto& adjacentPair : adjacentPairs) {
            mp[adjacentPair[0]].emplace_back(adjacentPair[1]);
            mp[adjacentPair[1]].emplace_back(adjacentPair[0]);
        }

        int n = adjacentPairs.size() + 1;
        vector<int> ret(n);

        for (auto& m : mp) {
            if (m.second.size() == 1) {
                ret[0] = m.first;
            }
        }
        ret[1] = mp[ret[0]][0];

        for (int i = 2; i < n; i++) {
            ret[i] = (mp[ret[i - 1]][0] == ret[i - 2]) ? mp[ret[i - 1]][1] : mp[ret[i - 1]][0];
        }

        return ret;
    }
};