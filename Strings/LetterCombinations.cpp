/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) {
            return result;
        }
        vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
        letterCombinationsRecursive(result, digits, "", 0, mapping);
        return result;
    }
    
    void letterCombinationsRecursive(vector<string>& result, string digits, string current, int index, vector<string> mapping) {
        if(index == digits.length()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for(int i = 0; i < letters.length(); i++) {
            letterCombinationsRecursive(result, digits, current + letters[i], index + 1, mapping);
        }
    }
};