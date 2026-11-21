class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string word = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (word == "" || word == ".") {
                }
                else if (word == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else {
                    st.push(word);
                }

                word = "";
            }
            else {
                word += path[i];
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};