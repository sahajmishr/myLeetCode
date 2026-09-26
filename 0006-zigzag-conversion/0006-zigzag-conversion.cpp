class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows <= 1 || s.length() <= static_cast<size_t>(numRows)) {
            return s;
        }

        vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};