class Solution {

public:
    int maxLength(vector<string>& arr) {
        vector<pair<int, int>> vi;
        for (string &a : arr) {
            int temp = 0;
            bool flag = true;
            for (char &c : a) {
                int x = 1 << (c - 'a');
                if ((x & temp) == 0) {
                    temp += x;
                } 
                else {
                    flag = false;
                    break;
                } 
            }
            if (flag)
                vi.push_back(make_pair(temp, a.size()));
        }

        int ret = 0;
        vector<pair<int, int>> vs1;
        vector<pair<int, int>> vs2;
        vs1.push_back(make_pair(0, 0));
        for (auto& v : vi) {
            for (auto& s1 : vs1) {
                if ((v.first & s1.first) == 0) {
                    vs2.push_back(make_pair(v.first + s1.first, v.second + s1.second));
                }
            }

            while (!vs2.empty()) {
                ret = max(ret, vs2.back().second);
                vs1.push_back(vs2.back());
                vs2.pop_back();
            }
        }

        return ret;
    }
};
