/*
iven a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            vector<bool> visited(256, false);
            
            for (int j = i; j < n; j++) {
                if (visited[s[j]]) {
                    break;
                } else {
                    ans = max(ans, j - i + 1);
                    visited[s[j]] = true;
                }
            }
            
            visited[s[i]] = false;
        }
        
        return ans;
    }
};
