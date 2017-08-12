#include <iostream>
#include <vector>
using namespace std;
int l1 = 0;
class Solution {
    //Write your code here
    public:
        vector<char> stack;
        vector<char> queue;
    void pushCharacter(char ch)
    {
        //int i = sizeof(stack);
        stack.push_back(ch);
        l1++;
    }
    void enqueueCharacter(char ch)
    {
        //int i = sizeof(stack);
        queue.push_back(ch);
    }
    char popCharacter()
    {
        char ch = stack[l1-1];
        stack.erase(stack.begin()+l1-1);
        l1--;
        return ch;
    }
    char dequeueCharacter()
    {
        char ch = queue[0];
        queue.erase(queue.begin());
        return ch;
    }

};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
    // create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}