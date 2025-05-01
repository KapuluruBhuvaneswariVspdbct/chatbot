#include <iostream>
#include <string>
#include <winsock2.h>
#include <algorithm>
#include<unordered_map>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

#define PORT 9090

string to_lowercase(const string& input) {
    string lower = input;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

unordered_map<int, string> leetcode_solutions =  {
        {1, "// Problem 1: Two Sum\n// Time: O(n), Space: O(n)\n#include <unordered_map>\nvector<int> twoSum(vector<int>& nums, int target) {\n    unordered_map<int, int> mp;\n    for (int i = 0; i < nums.size(); ++i) {\n        int complement = target - nums[i];\n        if (mp.count(complement)) return {mp[complement], i};\n        mp[nums[i]] = i;\n    }\n    return {};\n}\n// Explanation:\n// - We use a hashmap to store each number and its index.\n// - For each number, check if target - current number exists in map.\n// - If yes, return the indices."},
    
        {2, "// Problem 2: Add Two Numbers\n// Time: O(max(m, n)), Space: O(max(m, n))\nstruct ListNode {\n    int val;\n    ListNode* next;\n    ListNode(int x) : val(x), next(nullptr) {}\n};\nListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {\n    ListNode* dummy = new ListNode(0);\n    ListNode* curr = dummy;\n    int carry = 0;\n    while (l1 || l2 || carry) {\n        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;\n        carry = sum / 10;\n        curr->next = new ListNode(sum % 10);\n        curr = curr->next;\n        if (l1) l1 = l1->next;\n        if (l2) l2 = l2->next;\n    }\n    return dummy->next;\n}\n// Explanation:\n// - Traverse both lists simultaneously.\n// - Keep track of carry while adding digits.\n// - Create new nodes for the resulting list."},
    
        {3, "// Problem 3: Longest Substring Without Repeating Characters\n// Time: O(n), Space: O(min(n, m))\n#include <unordered_map>\nint lengthOfLongestSubstring(string s) {\n    unordered_map<char, int> map;\n    int start = 0, maxLength = 0;\n    for (int end = 0; end < s.size(); ++end) {\n        if (map.count(s[end])) start = max(start, map[s[end]] + 1);\n        map[s[end]] = end;\n        maxLength = max(maxLength, end - start + 1);\n    }\n    return maxLength;\n}\n// Explanation:\n// - Use a sliding window approach with two pointers: start and end.\n// - The map stores the last seen index of each character.\n// - If we encounter a repeated character, update the start pointer."},
    
        {4, "// Problem 4: Median of Two Sorted Arrays\n// Time: O(log(min(m, n))), Space: O(1)\n#include <algorithm>\ndouble findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {\n    if (nums1.size() > nums2.size()) swap(nums1, nums2);\n    int m = nums1.size(), n = nums2.size();\n    int left = 0, right = m, mid = (m + n + 1) / 2;\n    while (left < right) {\n        int partition1 = (left + right) / 2;\n        int partition2 = mid - partition1;\n        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];\n        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];\n        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];\n        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];\n        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {\n            if ((m + n) % 2 == 0) {\n                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;\n            } else {\n                return max(maxLeft1, maxLeft2);\n            }\n        } else if (maxLeft1 > minRight2) {\n            right = partition1 - 1;\n        } else {\n            left = partition1 + 1;\n        }\n    }\n    return 0.0;\n}\n// Explanation:\n// - Use binary search on the smaller array to partition both arrays.\n// - Ensure the left side elements are smaller than the right side elements."},
    
        {5, "// Problem 5: Longest Palindromic Substring\n// Time: O(n^2), Space: O(1)\n#include <string>\nstring longestPalindrome(string s) {\n    if (s.empty()) return \"\";\n    int start = 0, maxLength = 1;\n    for (int i = 0; i < s.size(); ++i) {\n        int len1 = expandAroundCenter(s, i, i);\n        int len2 = expandAroundCenter(s, i, i + 1);\n        int len = max(len1, len2);\n        if (len > maxLength) {\n            maxLength = len;\n            start = i - (maxLength - 1) / 2;\n        }\n    }\n    return s.substr(start, maxLength);\n}\nint expandAroundCenter(string& s, int left, int right) {\n    while (left >= 0 && right < s.size() && s[left] == s[right]) {\n        --left;\n        ++right;\n    }\n    return right - left - 1;\n}\n// Explanation:\n// - Expand around each character and each pair of adjacent characters.\n// - Track the longest palindrome found during the process."},
    
        {6, "// Problem 6: Zigzag Conversion\n// Time: O(n), Space: O(n)\n#include <string>\nstring convert(string s, int numRows) {\n    if (numRows == 1) return s;\n    vector<string> rows(min(numRows, int(s.size())));\n    int curRow = 0, step = 1;\n    for (char c : s) {\n        rows[curRow] += c;\n        if (curRow == 0 || curRow == numRows - 1) step = -step;\n        curRow += step;\n    }\n    string result;\n    for (string& row : rows) result += row;\n    return result;\n}\n// Explanation:\n// - Traverse the string in a zigzag pattern and store characters in different rows.\n// - Then concatenate the rows to get the final result."},
    
        {7, "// Problem 7: Reverse Integer\n// Time: O(log(x)), Space: O(1)\nint reverse(int x) {\n    int result = 0;\n    while (x != 0) {\n        int pop = x % 10;\n        x /= 10;\n        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return 0;\n        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) return 0;\n        result = result * 10 + pop;\n    }\n    return result;\n}\n// Explanation:\n// - Extract the last digit from the number and build the result by reversing the digits.\n// - Handle overflow cases using INT_MAX and INT_MIN."},
    
        {8, "// Problem 8: String to Integer (atoi)\n// Time: O(n), Space: O(1)\n#include <string>\nint myAtoi(string s) {\n    int i = 0, sign = 1, result = 0;\n    while (i < s.size() && s[i] == ' ') ++i; // Skip leading spaces\n    if (i < s.size() && (s[i] == '+' || s[i] == '-')) {\n        sign = (s[i] == '-') ? -1 : 1;\n        ++i;\n    }\n    while (i < s.size() && isdigit(s[i])) {\n        result = result * 10 + (s[i] - '0');\n        ++i;\n    }\n    return sign * result;\n}\n// Explanation:\n// - Skip leading spaces and handle the sign.\n// - Convert the string to an integer while handling overflows."},
    
        {9, "// Problem 9: Palindrome Number\n// Time: O(log(x)), Space: O(1)\nbool isPalindrome(int x) {\n    if (x < 0) return false;\n    int original = x, reversed = 0;\n    while (x != 0) {\n        int pop = x % 10;\n        x /= 10;\n        reversed = reversed * 10 + pop;\n    }\n    return original == reversed;\n}\n// Explanation:\n// - Reverse the number and check if it equals the original."},
    
        {10, "// Problem 10: Regular Expression Matching\n// Time: O(m * n), Space: O(m * n)\nbool isMatch(string s, string p) {\n    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));\n    dp[0][0] = true;\n    for (int i = 1; i <= p.size(); ++i) {\n        if (p[i - 1] == '*') dp[0][i] = dp[0][i - 2];\n    }\n    for (int i = 1; i <= s.size(); ++i) {\n        for (int j = 1; j <= p.size(); ++j) {\n            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];\n            else if (p[j - 1] == '*') {\n                dp[i][j] = dp[i - 1][j] || dp[i][j - 2];\n            }\n        }\n    }\n    return dp[s.size()][p.size()];\n}\n// Explanation:\n// - Use dynamic programming to match the string with the pattern."},

        {11, "// Problem 11: Container With Most Water\n"
                 "// Time: O(n), Space: O(1)\n"
                 "int maxArea(vector<int>& height) {\n"
                 "    int i = 0, j = height.size() - 1, ans = 0;\n"
                 "    while (i < j) {\n"
                 "        ans = max(ans, min(height[i], height[j]) * (j - i));\n"
                 "        if (height[i] < height[j]) ++i;\n"
                 "        else --j;\n"
                 "    }\n"
                 "    return ans;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Two-pointer shrinking from both ends.\n"
                 "// - Always move the shorter line inward."},
        
            {12, "// Problem 12: Integer to Roman\n"
                 "// Time: O(1), Space: O(1)\n"
                 "string intToRoman(int num) {\n"
                 "    vector<pair<int,string>> M = {{1000,\"M\"},{900,\"CM\"},{500,\"D\"},{400,\"CD\"},\n"
                 "                                 {100,\"C\"},{90,\"XC\"},{50,\"L\"},{40,\"XL\"},\n"
                 "                                 {10,\"X\"},{9,\"IX\"},{5,\"V\"},{4,\"IV\"},{1,\"I\"}};\n"
                 "    string ans;\n"
                 "    for (auto &p : M) {\n"
                 "        while (num >= p.first) {\n"
                 "            ans += p.second;\n"
                 "            num -= p.first;\n"
                 "        }\n"
                 "    }\n"
                 "    return ans;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Greedy subtraction using all Roman numeral symbols in descending order."},
        
            {13, "// Problem 13: Roman to Integer\n"
                 "// Time: O(n), Space: O(1)\n"
                 "int romanToInt(string s) {\n"
                 "    unordered_map<char,int> M{{'I',1},{'V',5},{'X',10},{'L',50},\n"
                 "                             {'C',100},{'D',500},{'M',1000}};\n"
                 "    int ans = 0;\n"
                 "    for (int i = 0; i < s.size(); ++i) {\n"
                 "        if (i+1 < s.size() && M[s[i]] < M[s[i+1]]) ans -= M[s[i]];\n"
                 "        else ans += M[s[i]];\n"
                 "    }\n"
                 "    return ans;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Add or subtract based on next symbol’s value."},
        
            {14, "// Problem 14: Longest Common Prefix\n"
                 "// Time: O(n * m), Space: O(1)\n"
                 "string longestCommonPrefix(vector<string>& strs) {\n"
                 "    if (strs.empty()) return \"\";\n"
                 "    for (int i = 0; i < strs[0].size(); ++i) {\n"
                 "        char c = strs[0][i];\n"
                 "        for (int j = 1; j < strs.size(); ++j)\n"
                 "            if (i == strs[j].size() || strs[j][i] != c)\n"
                 "                return strs[0].substr(0, i);\n"
                 "    }\n"
                 "    return strs[0];\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Character by character check across all strings."},
        
            {15, "// Problem 15: 3Sum\n"
                 "// Time: O(n^2), Space: O(1)\n"
                 "vector<vector<int>> threeSum(vector<int>& nums) {\n"
                 "    sort(nums.begin(), nums.end());\n"
                 "    vector<vector<int>> res;\n"
                 "    for (int i = 0; i < nums.size(); ++i) {\n"
                 "        if (i && nums[i] == nums[i-1]) continue;\n"
                 "        int lo = i+1, hi = nums.size()-1;\n"
                 "        while (lo < hi) {\n"
                 "            int sum = nums[i] + nums[lo] + nums[hi];\n"
                 "            if (sum < 0) ++lo;\n"
                 "            else if (sum > 0) --hi;\n"
                 "            else {\n"
                 "                res.push_back({nums[i], nums[lo], nums[hi]});\n"
                 "                while (lo < hi && nums[lo] == nums[lo+1]) ++lo;\n"
                 "                while (lo < hi && nums[hi] == nums[hi-1]) --hi;\n"
                 "                ++lo; --hi;\n"
                 "            }\n"
                 "        }\n"
                 "    }\n"
                 "    return res;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Sort + two-pointer to find zero-sum triplets."},
        
            {16, "// Problem 16: 3Sum Closest\n"
                 "// Time: O(n^2), Space: O(1)\n"
                 "int threeSumClosest(vector<int>& nums, int target) {\n"
                 "    sort(nums.begin(), nums.end());\n"
                 "    int best = nums[0] + nums[1] + nums[2];\n"
                 "    for (int i = 0; i < nums.size(); ++i) {\n"
                 "        int lo = i+1, hi = nums.size()-1;\n"
                 "        while (lo < hi) {\n"
                 "            int sum = nums[i] + nums[lo] + nums[hi];\n"
                 "            if (abs(sum - target) < abs(best - target)) best = sum;\n"
                 "            if (sum < target) ++lo;\n"
                 "            else --hi;\n"
                 "        }\n"
                 "    }\n"
                 "    return best;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Similar to 3Sum, but track closest sum."},
        
            {17, "// Problem 17: Letter Combinations of a Phone Number\n"
                 "// Time: O(4^n * n), Space: O(4^n * n)\n"
                 "vector<string> letterCombinations(string digits) {\n"
                 "    if (digits.empty()) return {};\n"
                 "    vector<string> m = {\"\",\"\",\"abc\",\"def\",\"ghi\",\"jkl\",\"mno\",\"pqrs\",\"tuv\",\"wxyz\"};\n"
                 "    vector<string> res = {\"\"};\n"
                 "    for (char d : digits) {\n"
                 "        vector<string> tmp;\n"
                 "        for (string& prev : res)\n"
                 "            for (char c : m[d - '0'])\n"
                 "                tmp.push_back(prev + c);\n"
                 "        res.swap(tmp);\n"
                 "    }\n"
                 "    return res;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Iteratively build combinations for each digit."},
        
            {18, "// Problem 18: 4Sum\n"
                 "// Time: O(n^3), Space: O(1)\n"
                 "vector<vector<int>> fourSum(vector<int>& nums, int target) {\n"
                 "    sort(nums.begin(), nums.end());\n"
                 "    vector<vector<int>> res;\n"
                 "    for (int i = 0; i < nums.size(); ++i) {\n"
                 "        if (i && nums[i] == nums[i-1]) continue;\n"
                 "        for (int j = i+1; j < nums.size(); ++j) {\n"
                 "            if (j != i+1 && nums[j] == nums[j-1]) continue;\n"
                 "            int lo = j+1, hi = nums.size()-1;\n"
                 "            while (lo < hi) {\n"
                 "                long sum = (long)nums[i] + nums[j] + nums[lo] + nums[hi];\n"
                 "                if (sum < target) ++lo;\n"
                 "                else if (sum > target) --hi;\n"
                 "                else {\n"
                 "                    res.push_back({nums[i], nums[j], nums[lo], nums[hi]});\n"
                 "                    while (lo < hi && nums[lo] == nums[lo+1]) ++lo;\n"
                 "                    while (lo < hi && nums[hi] == nums[hi-1]) --hi;\n"
                 "                    ++lo; --hi;\n"
                 "                }\n"
                 "            }\n"
                 "        }\n"
                 "    }\n"
                 "    return res;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Extend 3Sum with one more loop (i, j) then two-pointer."},
        
            {19, "// Problem 19: Remove Nth Node From End of List\n"
                 "// Time: O(n), Space: O(1)\n"
                 "ListNode* removeNthFromEnd(ListNode* head, int n) {\n"
                 "    ListNode dummy(0); dummy.next = head;\n"
                 "    ListNode *first = &dummy, *second = &dummy;\n"
                 "    for (int i = 0; i <= n; ++i) first = first->next;\n"
                 "    while (first) { first = first->next; second = second->next; }\n"
                 "    second->next = second->next->next;\n"
                 "    return dummy.next;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Two-pointer spaced by n nodes to remove the target."},
        
            {20, "// Problem 20: Valid Parentheses\n"
                 "// Time: O(n), Space: O(n)\n"
                 "bool isValid(string s) {\n"
                 "    unordered_map<char,char> M{{')','('},{']','['},{'}','{'}};\n"
                 "    stack<char> st;\n"
                 "    for (char c : s) {\n"
                 "        if (M.count(c)) {\n"
                 "            if (st.empty() || st.top() != M[c]) return false;\n"
                 "            st.pop();\n"
                 "        } else st.push(c);\n"
                 "    }\n"
                 "    return st.empty();\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Use stack to match opening/closing pairs."},
        
            {21, "// Problem 21: Merge Two Sorted Lists\n"
                 "// Time: O(n), Space: O(1)\n"
                 "ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {\n"
                 "    ListNode dummy(0), *p = &dummy;\n"
                 "    while (l1 && l2) {\n"
                 "        if (l1->val < l2->val) { p->next = l1; l1 = l1->next; }\n"
                 "        else { p->next = l2; l2 = l2->next; }\n"
                 "        p = p->next;\n"
                 "    }\n"
                 "    p->next = l1 ? l1 : l2;\n"
                 "    return dummy.next;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Merge like in merge sort."},
        
            {22, "// Problem 22: Generate Parentheses\n"
                 "// Time: Catalan(n) ≈ O(4^n / sqrt(n)), Space: same\n"
                 "void dfs(string cur, int open, int close, vector<string>& ans, int n) {\n"
                 "    if (cur.size() == 2*n) { ans.push_back(cur); return; }\n"
                 "    if (open < n) dfs(cur+'(', open+1, close, ans, n);\n"
                 "    if (close < open) dfs(cur+')', open, close+1, ans, n);\n"
                 "}\n"
                 "vector<string> generateParenthesis(int n) {\n"
                 "    vector<string> ans;\n"
                 "    dfs(\"\", 0, 0, ans, n);\n"
                 "    return ans;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Backtracking with open/close count constraints."},
        
            {23, "// Problem 23: Merge k Sorted Lists\n"
                 "// Time: O(n log k), Space: O(k)\n"
                 "ListNode* mergeKLists(vector<ListNode*>& lists) {\n"
                 "    auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};\n"
                 "    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);\n"
                 "    for (auto l : lists) if (l) pq.push(l);\n"
                 "    ListNode dummy(0), *p = &dummy;\n"
                 "    while (!pq.empty()) {\n"
                 "        auto t = pq.top(); pq.pop();\n"
                 "        p->next = t; p = p->next;\n"
                 "        if (t->next) pq.push(t->next);\n"
                 "    }\n"
                 "    return dummy.next;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Min-heap of current heads; extract min, advance."},
        
            {24, "// Problem 24: Swap Nodes in Pairs\n"
                 "// Time: O(n), Space: O(1)\n"
                 "ListNode* swapPairs(ListNode* head) {\n"
                 "    ListNode dummy(0); dummy.next = head;\n"
                 "    ListNode* p = &dummy;\n"
                 "    while (p->next && p->next->next) {\n"
                 "        ListNode* a = p->next;\n"
                 "        ListNode* b = a->next;\n"
                 "        a->next = b->next;\n"
                 "        b->next = a;\n"
                 "        p->next = b;\n"
                 "        p = a;\n"
                 "    }\n"
                 "    return dummy.next;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Swap pointers in pairs using a dummy head."},
        
            {25, "// Problem 25: Reverse Nodes in k-Group\n"
                 "// Time: O(n), Space: O(1)\n"
                 "ListNode* reverseKGroup(ListNode* head, int k) {\n"
                 "    ListNode dummy(0); dummy.next = head;\n"
                 "    ListNode *pre = &dummy, *end = &dummy;\n"
                 "    while (true) {\n"
                 "        for (int i = 0; i < k && end; ++i) end = end->next;\n"
                 "        if (!end) break;\n"
                 "        ListNode* start = pre->next;\n"
                 "        ListNode* next = end->next;\n"
                 "        end->next = nullptr;\n"
                 "        pre->next = reverseList(start);\n"
                 "        start->next = next;\n"
                 "        pre = start;\n"
                 "        end = pre;\n"
                 "    }\n"
                 "    return dummy.next;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Reverse each k-sized block in place."},
        
            {26, "// Problem 26: Remove Duplicates from Sorted Array\n"
                 "// Time: O(n), Space: O(1)\n"
                 "int removeDuplicates(vector<int>& nums) {\n"
                 "    int i = 0;\n"
                 "    for (int j = 1; j < nums.size(); ++j)\n"
                 "        if (nums[j] != nums[i]) nums[++i] = nums[j];\n"
                 "    return i + 1;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Two pointers: slow i tracks unique end, fast j scans."},
        
            {27, "// Problem 27: Remove Element\n"
                 "// Time: O(n), Space: O(1)\n"
                 "int removeElement(vector<int>& nums, int val) {\n"
                 "    int i = 0;\n"
                 "    for (int x : nums)\n"
                 "        if (x != val) nums[i++] = x;\n"
                 "    return i;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Overwrite matching elements by skipping val."},
        
            {28, "// Problem 28: Find the Index of the First Occurrence in a String\n"
                 "// Time: O(n*m), Space: O(1)\n"
                 "int strStr(string haystack, string needle) {\n"
                 "    int n = haystack.size(), m = needle.size();\n"
                 "    if (m == 0) return 0;\n"
                 "    for (int i = 0; i + m <= n; ++i) {\n"
                 "        if (haystack.substr(i,m) == needle) return i;\n"
                 "    }\n"
                 "    return -1;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Brute-force substring check."},
        
            {29, "// Problem 29: Divide Two Integers\n"
                 "// Time: O(log^2 n), Space: O(1)\n"
                 "int divide(int dividend, int divisor) {\n"
                 "    if (dividend == INT_MIN && divisor == -1) return INT_MAX;\n"
                 "    long a = labs(dividend), b = labs(divisor), ans = 0;\n"
                 "    while (a >= b) {\n"
                 "        long t = b, m = 1;\n"
                 "        while (a >= (t << 1)) { t <<= 1; m <<= 1; }\n"
                 "        a -= t;\n"
                 "        ans += m;\n"
                 "    }\n"
                 "    return (dividend > 0) == (divisor > 0) ? ans : -ans;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Bit-shifting subtraction to speed up division."},
        
            {30, "// Problem 30: Substring with Concatenation of All Words\n"
                 "// Time: O(n * m * w), Space: O(m)\n"
                 "vector<int> findSubstring(string s, vector<string>& words) {\n"
                 "    if (words.empty()) return {};\n"
                 "    int n = s.size(), m = words.size(), k = words[0].size();\n"
                 "    unordered_map<string,int> cnt;\n"
                 "    for (auto &w : words) ++cnt[w];\n"
                 "    vector<int> ans;\n"
                 "    for (int i = 0; i + m*k <= n; ++i) {\n"
                 "        unordered_map<string,int> seen;\n"
                 "        int j = 0;\n"
                 "        for (; j < m; ++j) {\n"
                 "            string t = s.substr(i + j*k, k);\n"
                 "            if (!cnt.count(t) || ++seen[t] > cnt[t]) break;\n"
                 "        }\n"
                 "        if (j == m) ans.push_back(i);\n"
                 "    }\n"
                 "    return ans;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Sliding window of size m*k, check word counts."},
        
            {31, "// Problem 31: Next Permutation\n"
                 "// Time: O(n), Space: O(1)\n"
                 "void nextPermutation(vector<int>& nums) {\n"
                 "    int i = nums.size()-2;\n"     
                 "    while (i >= 0 && nums[i] >= nums[i+1]) --i;\n"
                 "    if (i >= 0) {\n"
                 "        int j = nums.size()-1;\n"
                 "        while (nums[j] <= nums[i]) --j;\n"
                 "        swap(nums[i], nums[j]);\n"
                 "    }\n"
                 "    reverse(nums.begin()+i+1, nums.end());\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Find first decreasing pair, swap with next larger, then reverse suffix."},
        
            {32, "// Problem 32: Longest Valid Parentheses\n"
                 "// Time: O(n), Space: O(n)\n"
                 "int longestValidParentheses(string s) {\n"
                 "    stack<int> st; st.push(-1);\n"
                 "    int ans = 0;\n"
                 "    for (int i = 0; i < s.size(); ++i) {\n"
                 "        if (s[i] == '(') st.push(i);\n"
                 "        else {\n"
                 "            st.pop();\n"
                 "            if (st.empty()) st.push(i);\n"
                 "            else ans = max(ans, i - st.top());\n"
                 "        }\n"
                 "    }\n"
                 "    return ans;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Stack holds last unmatched index to compute lengths."},
        
            {33, "// Problem 33: Search in Rotated Sorted Array\n"
                 "// Time: O(log n), Space: O(1)\n"
                 "int search(vector<int>& nums, int target) {\n"
                 "    int l = 0, r = nums.size()-1;\n"
                 "    while (l <= r) {\n"
                 "        int mid = (l+r)/2;\n"
                 "        if (nums[mid] == target) return mid;\n"
                 "        if (nums[l] <= nums[mid]) {\n"
                 "            if (nums[l] <= target && target < nums[mid]) r = mid-1;\n"
                 "            else l = mid+1;\n"
                 "        } else {\n"
                 "            if (nums[mid] < target && target <= nums[r]) l = mid+1;\n"
                 "            else r = mid-1;\n"
                 "        }\n"
                 "    }\n"
                 "    return -1;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Modified binary search checking sorted half."},
        
            {34, "// Problem 34: Find First and Last Position of Element in Sorted Array\n"
                 "// Time: O(log n), Space: O(1)\n"
                 "int findBound(vector<int>& A, int target, bool isFirst) {\n"
                 "    int l=0, r=A.size()-1, ans=-1;\n"
                 "    while (l<=r) {\n"
                 "        int mid = (l+r)/2;\n"
                 "        if (A[mid]==target) { ans = mid; if(isFirst) r=mid-1; else l=mid+1; }\n"
                 "        else if (A[mid]<target) l=mid+1;\n"
                 "        else r=mid-1;\n"
                 "    }\n"
                 "    return ans;\n"
                 "}\n"
                 "vector<int> searchRange(vector<int>& nums, int target) {\n"
                 "    return {findBound(nums,target,true), findBound(nums,target,false)};\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Two binary searches for left and right bounds."},
        
            {35, "// Problem 35: Search Insert Position\n"
                 "// Time: O(log n), Space: O(1)\n"
                 "int searchInsert(vector<int>& nums, int target) {\n"
                 "    int l=0, r=nums.size();\n"
                 "    while (l<r) {\n"
                 "        int mid=(l+r)/2;\n"
                 "        if (nums[mid]<target) l=mid+1;\n"
                 "        else r=mid;\n"
                 "    }\n"
                 "    return l;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Standard lower_bound binary search."},
        
            {36, "// Problem 36: Valid Sudoku\n"
                 "// Time: O(1) (~81 checks), Space: O(1)\n"
                 "bool isValidSudoku(vector<vector<char>>& board) {\n"
                 "    bool row[9][9]={}, col[9][9]={}, box[9][9]={};\n"
                 "    for (int i=0;i<9;++i) for (int j=0;j<9;++j) if (board[i][j]!='.') {\n"
                 "        int num=board[i][j]-'1';\n"
                 "        int k=(i/3)*3 + j/3;\n"
                 "        if (row[i][num]||col[j][num]||box[k][num]) return false;\n"
                 "        row[i][num]=col[j][num]=box[k][num]=true;\n"
                 "    }\n"
                 "    return true;\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Use boolean arrays to track seen digits per row/col/box."},
        
            {37, "// Problem 37: Sudoku Solver\n"
                 "// Time: Exponential worst-case, Space: O(1)\n"
                 "bool solve(vector<vector<char>>& b) {\n"
                 "    for (int i=0;i<9;++i) for (int j=0;j<9;++j) if (b[i][j]=='.') {\n"
                 "        for (char c='1';c<='9';++c) {\n"
                 "            b[i][j]=c;\n"
                 "            if (isValidSudoku(b) && solve(b)) return true;\n"
                 "        }\n"
                 "        b[i][j]='.';\n"
                 "        return false;\n"
                 "    }\n"
                 "    return true;\n"
                 "}\n"
                 "void solveSudoku(vector<vector<char>>& board) { solve(board); }\n"
                 "// Explanation:\n"
                 "// - Backtracking with validity checks."},
        
            {38, "// Problem 38: Count and Say\n"
                 "// Time: O(n^2), Space: O(n)\n"
                 "string countAndSay(int n) {\n"
                 "    string s=\"1\";\n"
                 "    for (int i=1;i<n;++i) {\n"
                 "        string t;\n"
                 "        for (int j=0;j<s.size();++j) {\n"
                 "            int cnt=1;\n"
                 "            while (j+1<s.size() && s[j]==s[j+1]) { cnt++; ++j; }\n"
                 "            t += to_string(cnt) + s[j];\n"
                 "        }\n"
                 "        s.swap(t);\n"
                 "    }\n"
                 "    return s;\n"
                 "// Explanation:\n"
                 "// - Iterative generation of the 'say' sequence."},
        
            {39, "// Problem 39: Combination Sum\n"
                 "// Time: Exponential, Space: O(target/min)\n"
                 "void dfsCS(vector<int>& cand, int t, vector<int>& cur, vector<vector<int>>& ans, int idx) {\n"
                 "    if (t==0) { ans.push_back(cur); return; }\n"
                 "    for (int i=idx;i<cand.size() && t>=cand[i];++i) {\n"
                 "        cur.push_back(cand[i]);\n"
                 "        dfsCS(cand, t-cand[i], cur, ans, i);\n"
                 "        cur.pop_back();\n"
                 "    }\n"
                 "}\n"
                 "vector<vector<int>> combinationSum(vector<int>& candidates, int target) {\n"
                 "    sort(candidates.begin(), candidates.end());\n"
                 "    vector<vector<int>> ans;\n"
                 "    vector<int> cur;\n"
                 "    dfsCS(candidates, target, cur, ans, 0);\n"
                 "    return ans;\n"
                 "// Explanation:\n"
                 "// - Backtracking allowing reuse of same candidate."},
        
            {40, "// Problem 40: Combination Sum II\n"
                 "// Time: Exponential, Space: O(n)\n"
                 "void dfsCS2(vector<int>& cand, int t, vector<int>& cur, vector<vector<int>>& ans, int idx) {\n"
                 "    if (t==0) { ans.push_back(cur); return; }\n"
                 "    for (int i=idx;i<cand.size()&&t>=cand[i];++i) {\n"
                 "        if (i>idx && cand[i]==cand[i-1]) continue;\n"
                 "        cur.push_back(cand[i]);\n"
                 "        dfsCS2(cand, t-cand[i], cur, ans, i+1);\n"
                 "        cur.pop_back();\n"
                 "    }\n"
                 "}\n"
                 "vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {\n"
                 "    sort(candidates.begin(), candidates.end());\n"
                 "    vector<vector<int>> ans;\n"
                 "    vector<int> cur;\n"
                 "    dfsCS2(candidates, target, cur, ans, 0);\n"
                 "    return ans;\n"
                 "// Explanation:\n"
                 "// - Backtracking with skipping duplicates, no reuse."},
        
            {41, "// Problem 41: First Missing Positive\n"
                 "// Time: O(n), Space: O(1)\n"
                 "int firstMissingPositive(vector<int>& nums) {\n"
                 "    int n = nums.size();\n"
                 "    for (int i=0;i<n;++i)\n"
                 "        while (nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])\n"
                 "            swap(nums[i], nums[nums[i]-1]);\n"
                 "    for (int i=0;i<n;++i)\n"
                 "        if (nums[i]!=i+1) return i+1;\n"
                 "    return n+1;\n"
                 "// Explanation:\n"
                 "// - Place each number in its correct index slot via swaps."},
        
            {42, "// Problem 42: Trapping Rain Water\n"
                 "// Time: O(n), Space: O(1)\n"
                 "int trap(vector<int>& height) {\n"
                 "    int l=0, r=height.size()-1;\n"
                 "    int lmax=0, rmax=0, ans=0;\n"
                 "    while (l<r) {\n"
                 "        if (height[l]<height[r]) {\n"
                 "            lmax = max(lmax, height[l]);\n"
                 "            ans += lmax - height[l++];\n"
                 "        } else {\n"
                 "            rmax = max(rmax, height[r]);\n"
                 "            ans += rmax - height[r--];\n"
                 "        }\n"
                 "    }\n"
                 "    return ans;\n"
                 "// Explanation:\n"
                 "// - Two-pointer, track left/right max heights."},
        
            {43, "// Problem 43: Multiply Strings\n"
                 "// Time: O(m*n), Space: O(m+n)\n"
                 "string multiply(string num1, string num2) {\n"
                 "    int n1=num1.size(), n2=num2.size();\n"
                 "    vector<int> a(n1+n2);\n"
                 "    for (int i=n1-1;i>=0;--i)\n"
                 "        for (int j=n2-1;j>=0;--j) {\n"
                 "            int p=(num1[i]-'0')*(num2[j]-'0');\n"
                 "            int sum = p + a[i+j+1];\n"
                 "            a[i+j+1] = sum % 10;\n"
                 "            a[i+j] += sum / 10;\n"
                 "        }\n"
                 "    string s;\n"
                 "    for (int x : a) if (!(s.empty() && x==0)) s.push_back('0'+x);\n"
                 "    return s.empty()?\"0\":s;\n"
                 "// Explanation:\n"
                 "// - Simulate grade-school long multiplication into digit array."},
        
            {44, "// Problem 44: Wildcard Matching\n"
                 "// Time: O(n*m), Space: O(n*m)\n"
                 "bool isMatch(string s, string p) {\n"
                 "    int n=s.size(), m=p.size();\n"
                 "    vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));\n"
                 "    dp[0][0]=true;\n"
                 "    for (int j=1;j<=m;++j)\n"
                 "        dp[0][j]= (p[j-1]=='*') && dp[0][j-1];\n"
                 "    for (int i=1;i<=n;++i)\n"
                 "        for (int j=1;j<=m;++j) {\n"
                 "            if (p[j-1]=='?' || p[j-1]==s[i-1]) dp[i][j] = dp[i-1][j-1];\n"
                 "            else if (p[j-1]=='*') dp[i][j] = dp[i][j-1] || dp[i-1][j];\n"
                 "        }\n"
                 "    return dp[n][m];\n"
                 "// Explanation:\n"
                 "// - Dynamic programming with '?' and '*' rules."},
        
            {45, "// Problem 45: Jump Game II\n"
                 "// Time: O(n), Space: O(1)\n"
                 "int jump(vector<int>& nums) {\n"
                 "    int n=nums.size(), jumps=0, curEnd=0, furthest=0;\n"
                 "    for (int i=0;i<n-1;++i) {\n"
                 "        furthest = max(furthest, i+nums[i]);\n"
                 "        if (i == curEnd) {\n"
                 "            ++jumps;\n"
                 "            curEnd = furthest;\n"
                 "        }\n"
                 "    }\n"
                 "    return jumps;\n"
                 "// Explanation:\n"
                 "// - Greedy layer-by-layer maximum reach counting jumps."},
        
            {46, "// Problem 46: Permutations\n"
                 "// Time: O(n! * n), Space: O(n)\n"
                 "void dfsPerm(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& ans) {\n"
                 "    if (cur.size() == nums.size()) { ans.push_back(cur); return; }\n"
                 "    for (int i=0;i<nums.size();++i) {\n"
                 "        if (used[i]) continue;\n"
                 "        used[i] = true;\n"
                 "        cur.push_back(nums[i]);\n"
                 "        dfsPerm(nums, used, cur, ans);\n"
                 "        cur.pop_back(); used[i] = false;\n"
                 "    }\n"
                 "}\n"
                 "vector<vector<int>> permute(vector<int>& nums) {\n"
                 "    vector<vector<int>> ans;\n"
                 "    vector<int> cur;\n"
                 "    vector<bool> used(nums.size());\n"
                 "    dfsPerm(nums, used, cur, ans);\n"
                 "    return ans;\n"
                 "// Explanation:\n"
                 "// - Standard backtracking generating all orderings."},
        
            {47, "// Problem 47: Permutations II\n"
                 "// Time: O(n! * n), Space: O(n)\n"
                 "void dfsPerm2(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& ans) {\n"
                 "    if (cur.size() == nums.size()) { ans.push_back(cur); return; }\n"
                 "    for (int i=0;i<nums.size();++i) {\n"
                 "        if (used[i]) continue;\n"
                 "        if (i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;\n"
                 "        used[i] = true;\n"
                 "        cur.push_back(nums[i]);\n"
                 "        dfsPerm2(nums, used, cur, ans);\n"
                 "        cur.pop_back(); used[i] = false;\n"
                 "    }\n"
                 "}\n"
                 "vector<vector<int>> permuteUnique(vector<int>& nums) {\n"
                 "    sort(nums.begin(), nums.end());\n"
                 "    vector<vector<int>> ans;\n"
                 "    vector<int> cur;\n"
                 "    vector<bool> used(nums.size());\n"
                 "    dfsPerm2(nums, used, cur, ans);\n"
                 "    return ans;\n"
                 "// Explanation:\n"
                 "// - Backtracking skipping duplicates for unique permutations."},
        
            {48, "// Problem 48: Rotate Image\n"
                 "// Time: O(n^2), Space: O(1)\n"
                 "void rotate(vector<vector<int>>& matrix) {\n"
                 "    int n = matrix.size();\n"
                 "    for (int i = 0; i < n; ++i)\n"
                 "        for (int j = i; j < n; ++j)\n"
                 "            swap(matrix[i][j], matrix[j][i]);\n"
                 "    for (int i = 0; i < n; ++i)\n"
                 "        reverse(matrix[i].begin(), matrix[i].end());\n"
                 "}\n"
                 "// Explanation:\n"
                 "// - Transpose then reverse each row."},
        
            {49, "// Problem 49: Group Anagrams\n"
                 "// Time: O(n * k log k), Space: O(n * k)\n"
                 "vector<vector<string>> groupAnagrams(vector<string>& strs) {\n"
                 "    unordered_map<string,vector<string>> M;\n"
                 "    for (auto &s : strs) {\n"
                 "        string t = s;\n"
                 "        sort(t.begin(), t.end());\n"
                 "        M[t].push_back(s);\n"
                 "    }\n"
                 "    vector<vector<string>> ans;\n"
                 "    for (auto &p : M) ans.push_back(move(p.second));\n"
                 "    return ans;\n"
                 "// Explanation:\n"
                 "// - Sort each string as key and group originals."},
        
            {50, "// Problem 50: Pow(x, n)\n"
                 "// Time: O(log n), Space: O(1)\n"
                 "double myPow(double x, int n) {\n"
                 "    long long N = n;\n         if (N < 0) { x = 1/x; N = -N; }\n"
                 "    double ans = 1;\n"
                 "    while (N) {\n"
                 "        if (N & 1) ans *= x;\n"
                 "        x *= x;\n"
                 "        N >>= 1;\n"
                 "    }\n"
                 "    return ans;\n"
                 "// Explanation:\n"
                 "// - Fast exponentiation by squaring with sign handling."}
        
            
    };
    

    

    void handle_client(SOCKET client_socket) {
        char buffer[1024];
        int last_problem = -1;
        bool awaiting_extra_help = false;
        string last_help_type = "";
    
        while (true) {
            int received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (received == SOCKET_ERROR || received == 0) {
                cout << "Client disconnected or error occurred." << endl;
                break;
            }
    
            buffer[received] = '\0';
            string client_msg(buffer);
            cout << "Received: " << client_msg << endl;
    
            for (auto& c : client_msg) c = tolower(c);
    
            string response;
    
            if (awaiting_extra_help) {
                if (client_msg == "yes") {
                    response = "Would you like tips, a roadmap, or course suggestions? (type: tips / roadmap / courses)";
                } else if (client_msg == "no") {
                    response = "Do you want to end the chat? (type 'bye') or continue with a problem (1 - 50 ).";
                    awaiting_extra_help = false;
                } else if (client_msg == "tips") {
                    response = "Tips to grasp DSA:\n- Start with basics: arrays, strings, and recursion.\n- Practice every day.\n- Focus on understanding rather than memorization.\n- Solve problems on LeetCode, GFG, and InterviewBit.\n\nDo you also want roadmap or course suggestions? (type: roadmap / courses / no)";
                    last_help_type = "tips";
                } else if (client_msg == "roadmap") {
                    response = "DSA Roadmap:\n1. Arrays and Strings\n2. Recursion and Backtracking\n3. Linked Lists\n4. Stacks and Queues\n5. Trees and Graphs\n6. Greedy and DP\n7. Bit Manipulation\n8. Tries and Heaps\n\nDo you also want tips or course suggestions? (type: tips / courses / no)";
                    last_help_type = "roadmap";
                } else if (client_msg == "courses") {
                    response = "Recommended courses:\n- 'DSA Self Paced' by GeeksforGeeks\n- 'Mastering DSA' by Love Babbar\n- Coursera Algorithms Specialization by Stanford\n- Udemy DSA Bootcamp\n\nDo you also want tips or a roadmap? (type: tips / roadmap / no)";
                    last_help_type = "courses";
                } else {
                    response = "Please type: tips / roadmap / courses, or 'no' to skip.";
                }
            } else if (client_msg == "hi" || client_msg == "hello") {
                response = "Hi! I am your DSA LeetCode bot. Tell me a LeetCode problem number (1 - 50 ) you have a doubt in.";
            } else if (isdigit(client_msg[0])) {
                int qnum = stoi(client_msg);
                if (leetcode_solutions.find(qnum) != leetcode_solutions.end()) {
                    last_problem = qnum;
                    response = "Problem " + to_string(qnum) + " solution:\n" + leetcode_solutions[qnum] + "\n\nDo you want solution to another problem? (yes/no)";
                } else {
                    response = "Sorry, I don't have the solution for that problem yet.";
                }
            } else if (client_msg == "yes") {
                response = "Please enter a problem number (1 - 50).";
            } else if (client_msg == "no") {
                response = "Would you like tips to grasp DSA, a roadmap to DSA, or course suggestions? (yes/no)";
                awaiting_extra_help = true;
            } else if (client_msg == "bye") {
                response = "Goodbye! Happy coding!";
                send(client_socket, response.c_str(), response.length(), 0);
                break;
            } else {
                response = "Please enter a valid problem number (1 - 50 ), say 'bye', or ask for help with DSA.";
            }
    
            cout << "Sending response: " << response << endl;
            send(client_socket, response.c_str(), response.length(), 0);
        }
    
        closesocket(client_socket);
    }
    
int main() {
    WSADATA wsaData;
    SOCKET server_socket, client_socket;
    sockaddr_in server_addr, client_addr;
    int client_size = sizeof(client_addr);

    // Initialize Winsock
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
    cout << "Failed. Error Code: " << WSAGetLastError();
    return 1;
}


    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        cout << "Socket creation failed!" << endl;
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        cout << "Bind failed!" << endl;
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 1) == SOCKET_ERROR) {
        cout << "Listen failed!" << endl;
        return 1;
    }

    cout << "Server listening on port " << PORT << "..." << endl;

    // Accept a client connection
    client_socket = accept(server_socket, (sockaddr*)&client_addr, &client_size);
    if (client_socket == INVALID_SOCKET) {
        cout << "Client connection failed!" << endl;
        return 1;
    }

    cout << "Client connected!" << endl;

    // Handle client communication
    handle_client(client_socket);

    // Cleanup
    closesocket(server_socket);
    WSACleanup();
    return 0;
}
