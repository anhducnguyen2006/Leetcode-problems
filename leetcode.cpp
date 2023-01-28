// Leetcode - Longest Substring Without Repeating Characters
// Nguyen Anh Duc, 28/01/2023
// Time complexity: O(n)
// Space: O(n)

// Idea: Loop through the letters and add them
// to the "used" array, up until there is a character
// which already exists in the "used" array. Then
// we check if the current length of the substring 
// (characters in the array "used") is longer then 
// the answer (which will be returned as the longest substring).
// Next, we delete all the letters from right to left up until
// we meet the character that was repeated and that character
// will be inserted in the front: DEABCA -> BCA (we have character
// A that is repeated so we delete the front up until that repeated
// character). Then we continue until we reach the end of the string.
// because the answer can only update when we meet a character
// that is repeated in the "used" array, if it is valid until
// the very end of the string, we have to check whether
// that current length might be longer than the current answer.
// if it is, we update it, otherwise we return the answer. 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //initializing the array "used" and other variables
        
        vector<char> used;
        
        int answer = 0, current = 0, i = 0;
        
        
        // we loop through the whole string
        
        while (i < size(s)) {
            
            // we check whether the current character is 
            // in the "used" array
            
            for(int j = 0; j < size(used); j++) {
                
                // if it is, then as I explained above, 
                // we remove all front characters up until
                // that repeated character and along with it,
                // the length of the removed characters because
                // the new substring will only consist of non 
                // repeated characters, eg. -> DEABCA -> BCA
                // -> the length of the current substring: DEABC -> 5 letters
                // -> after we reach letter "A" -> BCA -> 3 letters
                
                if(used[j] == s[i]) 
                
                {
                    
                    answer = max(answer, current);
                    
                    used.erase(used.begin(), used.begin() + j + 1);
                    
                    current -= (j+1);
                    
                    break;
                    
                }
            }
            
            // regardless of whether the character is repeated or not
            // we will still insert the current s[i] character.
            
            used.push_back(s[i]);
            
            // as so, we also increase the length of the current substring
            
            current++;
            
            i++;
        }
        
        // the case when the substring is valid until the end of the string,
        // so the "repeated character" case was not activated, then
        // we check if it is longer than the previous ones (if there were)
        
        if(current > answer) return current;
        else return answer;
        
    }
};