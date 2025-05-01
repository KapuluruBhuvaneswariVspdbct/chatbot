# 🪄 LEETCODE GENIE

This is a simple socket-based chatbot implemented in C++ using Winsock for Windows. The chatbot listens on a server and responds with C++ solutions to the first 10 LeetCode problems based on user input.

## 📁 Project Structure
    chatbot/
         ├── server/ 
                │── chat_server.cpp

         ├──client
                ├──client.py

         ├──README.md

               
## 🚀 Features

- Handles TCP client-server connections using Winsock2.
- Responds to messages with lowercase processing.
- Matches numerical inputs (1 to 10) with detailed, commented C++ LeetCode solutions.
- Includes helpful explanations for each problem.
- Demonstrates practical use of STL (Standard Template Library) and hash maps.

## 🧠 Supported LeetCode Problems

The server can return solutions to the following problems:
# Top 50 LeetCode Problems

| No. | Title                                              | Difficulty | Acceptance |
|-----|----------------------------------------------------|------------|-------------|
| 1   | Two Sum                                            | Easy       | 55.5%       |
| 2   | Add Two Numbers                                    | Medium     | 45.9%       |
| 3   | Longest Substring Without Repeating Characters     | Medium     | 36.7%       |
| 4   | Median of Two Sorted Arrays                        | Hard       | 43.4%       |
| 5   | Longest Palindromic Substring                      | Medium     | 35.6%       |
| 6   | Zigzag Conversion                                  | Medium     | 51.2%       |
| 7   | Reverse Integer                                    | Medium     | 30.1%       |
| 8   | String to Integer (atoi)                           | Medium     | 19.0%       |
| 9   | Palindrome Number                                  | Easy       | 59.0%       |
| 10  | Regular Expression Matching                        | Hard       | 29.1%       |
| 11  | Container With Most Water                          | Medium     | 57.5%       |
| 12  | Integer to Roman                                   | Medium     | 68.2%       |
| 13  | Roman to Integer                                   | Easy       | 64.6%       |
| 14  | Longest Common Prefix                              | Easy       | 45.2%       |
| 15  | 3Sum                                               | Medium     | 36.8%       |
| 16  | 3Sum Closest                                       | Medium     | 46.8%       |
| 17  | Letter Combinations of a Phone Number              | Medium     | 63.5%       |
| 18  | 4Sum                                               | Medium     | 37.9%       |
| 19  | Remove Nth Node From End of List                   | Medium     | 48.6%       |
| 20  | Valid Parentheses                                  | Easy       | 42.1%       |
| 21  | Merge Two Sorted Lists                             | Easy       | 66.6%       |
| 22  | Generate Parentheses                               | Medium     | 76.9%       |
| 23  | Merge k Sorted Lists                               | Hard       | 56.3%       |
| 24  | Swap Nodes in Pairs                                | Medium     | 66.9%       |
| 25  | Reverse Nodes in k-Group                           | Hard       | 62.6%       |
| 26  | Remove Duplicates from Sorted Array                | Easy       | 60.0%       |
| 27  | Remove Element                                     | Easy       | 59.8%       |
| 28  | Find the Index of the First Occurrence in a String| Easy       | 44.7%       |
| 29  | Divide Two Integers                                | Medium     | 18.3%       |
| 30  | Substring with Concatenation of All Words          | Hard       | 32.9%       |
| 31  | Next Permutation                                   | Medium     | 42.7%       |
| 32  | Longest Valid Parentheses                          | Hard       | 36.1%       |
| 33  | Search in Rotated Sorted Array                     | Medium     | 42.6%       |
| 34  | Find First and Last Position of Element            | Medium     | 46.5%       |
| 35  | Search Insert Position                             | Easy       | 48.7%       |
| 36  | Valid Sudoku                                       | Medium     | 62.0%       |
| 37  | Sudoku Solver                                      | Hard       | 63.7%       |
| 38  | Count and Say                                      | Medium     | 60.2%       |
| 39  | Combination Sum                                    | Medium     | 74.3%       |
| 40  | Combination Sum II                                 | Medium     | 57.4%       |
| 41  | First Missing Positive                             | Hard       | 40.9%       |
| 42  | Trapping Rain Water                                | Hard       | 64.7%       |
| 43  | Multiply Strings                                   | Medium     | 42.1%       |
| 44  | Wildcard Matching                                  | Hard       | 29.6%       |
| 45  | Jump Game II                                       | Medium     | 41.3%       |
| 46  | Permutations                                       | Medium     | 80.4%       |
| 47  | Permutations II                                    | Medium     | 61.3%       |
| 48  | Rotate Image                                       | Medium     | 77.6%       |
| 49  | Group Anagrams                                     | Medium     | 70.7%       |
| 50  | Pow(x, n)                                          | Medium     | *(TBD)*     |
          

## ⚙️ How It Works

1. Starts a TCP server on port `9090`.
2. Listens for incoming client messages.
3. Converts the message to lowercase.
4. If the message contains a valid problem number (e.g., `1`, `2`, ... `10`), it returns the corresponding LeetCode solution.
5. Otherwise, it sends a default response.

## 🛠️ Dependencies

- Windows
- C++ Compiler (e.g., MSVC)
- Winsock2 (`ws2_32.lib`)

## 🧾 Example Code Snippet

```cpp
unordered_map<int, string> leetcode_solutions = {
    {1, "// Problem 1: Two Sum\n..."},
    {2, "// Problem 2: Add Two Numbers\n..."},
    ...
};
```

-Each value in the map includes:

-Problem Title

-Time and Space Complexity

-Full C++ solution with comments

-Step-by-step explanation
 
 ## 🧪 How to Run
1. Open the project in your C++ development environment (Visual Studio recommended).

2. Make sure Winsock2 is available.

3. Compile and run  chat_server.cpp.
```  
 g++ chat_server.cpp -o chat_server.exe -lws2_32
 
.\chat_server.exe
```

4. Connect to localhost:9090.

5. Run client code using 
```
python client.py 
```

5. Send any number between 1 and 50 to receive the corresponding solution.

## 📚 Example Interaction
```
Connected to the chat.


Type your messages below:

hi 


Please enter a valid problem number (1 - 50 ), say 'bye', or ask for help with DSA.

5


Problem 5 solution:

// Problem 5: Longest Palindromic Substring

// Time: O(n^2), Space: O(1)

#include <string>
string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, maxLength = 1;
    for (int i = 0; i < s.size(); ++i) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);
        if (len > maxLength) {
            maxLength = len;
            start = i - (maxLength - 1) / 2;
        }
    }
    return s.substr(start, maxLength);
}
int expandAroundCenter(string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return right - left - 1;
}


// Explanation:
// - Expand around each character and each pair of adjacent characters.
// - Track the longest palindrome found during the process.



Do you want solution to another problem? (yes/no)

yes

Please enter a problem number (1 - 50).

3

Problem 3 solution:

// Problem 3: Longest Substring Without Repeating Characters
// Time: O(n), Space: O(min(n, m))
#include <unordered_map>
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int start = 0, maxLength = 0;
    for (int end = 0; end < s.size(); ++end) {
        if (map.count(s[end])) start = max(start, map[s[end]] + 1);
        map[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
}


// Explanation:
// - Use a sliding window approach with two pointers: start and end.
// - The map stores the last seen index of each character.
// - If we encounter a repeated character, update the start pointer.



Do you want solution to another problem? (yes/no)

no

Would you like tips to grasp DSA, a roadmap to DSA, or course suggestions? (yes/no)

yes


Would you like tips, a roadmap, or course suggestions? (type: tips / roadmap / courses)

tips


Tips to grasp DSA:
- Start with basics: arrays, strings, and recursion.
- Practice every day.
- Focus on understanding rather than memorization.
- Solve problems on LeetCode, GFG, and InterviewBit.


Do you also want roadmap or course suggestions? (type: roadmap / courses / no)

roadmap


DSA Roadmap:
1. Arrays and Strings
2. Recursion and Backtracking
3. Linked Lists
4. Stacks and Queues
5. Trees and Graphs
6. Greedy and DP
7. Bit Manipulation
8. Tries and Heaps


Do you also want tips or course suggestions? (type: tips / courses / no)

no


Do you want to end the chat? (type 'bye') or continue with a problem (1 - 50 ).

bye


Goodbye! Happy coding!
Server closed the connection.

```

## 💡 Future Improvements
1. Add a client interface (GUI or CLI).

2. Support more LeetCode problems.

3. Add interactive diagrams.

4. Cross-platform socket compatibility (Linux/Mac).

## 🧑‍💻 Author
Made with ❤️ by BHUVANESWARI KAPULURU .
