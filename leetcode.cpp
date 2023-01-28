// Leetcode - Zigzag Conversion
// Nguyen Anh Duc, 28/01/2023
// Time complexity: O(n)
// Space: O(1)
// Runtime: 7 ms (Beats 92,37%)
// Memory 8.2 MB (Beats 82,53%)

// Idea: Loop through every row from top to bottom and fill in the answer according 
// to it. 

class Solution {
public:
    string convert(string s, int numRows) {
        
        //initializing variables -> answer, size of the string s
        
        string answer = "";
        
        int l = s.size();
        
        // check if the number of Rows required is one, 
        // then it is eg. (numRows = 1, string s = ANDY) -> A N D Y -> no changes,
        // or if the number of rows is longer or equal to the number 
        // of letters in a string: (numRows = 4, string s = ANDY)
        // ANDY -> A -> answer = ANDY -> no changes
        //         N
        //         D
        //         Y
        
        if(numRows == 1 || numRows >= l) {
            return s;
        }
        
        // loop through every row, this is the main idea
        
        for(int i = 0; i < numRows; i++) {
            
            // now for every row, we add accordingly the letters that appear in that row 
            // in correct order i.e., we can observe a pattern: let's say we have to 
            // solve (string s = PAYPALISHIRING, numRow = 3) ->
            // P   A   H   N
            // A P L S I I G
            // Y   I   R
            // -> all the letters of each row is distanced equally:
            //
            // P A Y P A L I S H I R  I  N  G
            // 0 1 2 3 4 5 6 7 8 9 10 11 12 13  -> 0, 4, 8, 12
            // ^       ^       ^         ^
            //
            // P A Y P A L I S H I R  I  N  G
            // 0 1 2 3 4 5 6 7 8 9 10 11 12 13  -> 1, 5, 9, 13
            //   ^       ^       ^          ^
            //
            // P A Y P A L I S H I R  I  N  G
            // 0 1 2 3 4 5 6 7 8 9 10 11 12 13  -> 2, 6, 10 (only 3 since there is no 14th letter)
            //     ^       ^       ^         
            //
            // that distance is calculated by: numRows * 2 - 2 for all cases because:
            // 
            // Solve: (numRows = 3, strings s = PAYPA)
            //
            // P   A   -> first we have to travel from P to Y -> it is: numRows - 1 
            // A P     -> next we have to travel from Y to A -> it is: numRows - 1
            // Y       -> That is why the whole distance is: numRows - 1 + numRows - 1 
            
            for(int j = i; j < l; j += numRows*2-2) {
                
                // P  -> all of them are the begins of every row (i.e. the first numRow characters are
                // A  -> the beginings of the rows, eg. numRows = 3 -> PAYPALISHIRING -> P, A, Y are
                // Y  -> the first letters of every row)
                
                answer.push_back(s[j]);
                
                // here we insert the rest of the letter accordingly, i.e. 
                // we can see a pattern: 
                // Solve (numRows = 4, string s  = PAYPALISHIRING)
                // 
                // P     I     N -> we can see that for every now from top to bottom
                // A   L S   I G -> the position of the letters between any two columns
                // Y A   H R     -> are distanced numRows - i from the corresponding 
                // P     I       -> letter of a column, i.e. we have letter A, first 
                // -> letter from the second row -> numRow = 1, and letter L which is 
                // -> positioned numRows - i distance away from A. (eg. S and I from row 2
                // -> or Y and A or H and R from row 3 (numRow = 2))
                // -> to calculate that distance, the same idea is used -> the distance
                // -> from A to P = (numRow - i) - 1 and then from P to L = (numRow - i) - 1,
                // -> so the sum is (numRows - i)*2 - 2. First we have to check whether
                // -> it is even valid, i.e. it's not out of range of the string.
                // -> We also have to be careful, because if i is equal to 0 (the first row),
                // -> or if i is equal to numRows (last row), we don't have letter in between
                // -> two columns.
                
                if(j+(numRows-i)*2-2<l && (numRows-i)*2-2>0 && i!=0) 
                {
                    //append the characters accordingly to the answer string.
                    answer.push_back(s[j+((numRows-i)*2-2)]);
                }
            }
        }
        
        // return the answer
        return answer;
    }
};