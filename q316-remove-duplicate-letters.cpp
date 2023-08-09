/*

Copied from: https://ttzztt.gitbooks.io/lc/content/remove-duplicate-letters.html
1. Count the letter frequency with an Array
2. Build a ascending stack: Each time adding a letter to the stack if it has not been added into the stack, mark letter as visited. If current letter is smaller than the that on top of the stack, and top letter has remaining appearance after (as checked by indexing the letter frequency array), pop the letter out and mark it as not visited

*/


class Solution {
public:
    stack<char> answer;
    string removeDuplicateLetters(string s) {
        
        int dic[26] = {0};
        int ans[26] = {0};

        for(int i = 0; i < s.size(); i++) { 
            dic[s[i] - 'a']++;
        }

        answer.push(s[0]);
        ans[s[0] - 'a'] = 1;
        dic[s[0] - 'a'] --;

        for(int i = 1; i < s.size(); i++) {

            int index = s[i] - 'a';
            dic[index] --;

            if(ans[index] > 0) 
                continue;

            while( !answer.empty() && s[i] < answer.top() && dic[answer.top() - 'a'] > 0) {
                ans[answer.top() - 'a'] = 0;
                answer.pop();
            }

            answer.push(s[i]);
            ans[s[i] - 'a'] = 1;
        }

        string result="";
        while (!answer.empty()) {
            result += answer.top();
            answer.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};