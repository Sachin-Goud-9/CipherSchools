#include<bits/stdc++.h>
using namespace std;


/*
Given n string of brackets determine whether each string is balanced or not.
Each string consits of characters '(','{','[',']','}',')'
A string is balanced if the folloowing conditions are met

Condition 1: It contains no unmatched brackets.
Condition 2: The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched 
             pair of brackets is also a matched pair of brackets.
             
             
             
Example 1:
Input:
2
"({[]})"
"([{]})"
Output:
YES
NO

Example 2:
Input:
2
"[{{{"
"[{}][()]{[]}"
Output:
NO
YES

Example 3:
Input:
1
"[{({[]})}]"
Output:
YES



Appraoch:

This problem can be solved by using the Stack Data Structure.

Stack is a Data Structure which follows First IN First Out(FIFO) order.

Algorithm:

1.If the char is an opening bracket then we push the character into the stack

2.If the char is a closing bracket
    2.1. If the stack is empty this indicates that it fails Condition 1 hence we return "NO".
    2.2. Else 
        2.2.1. If the corresponding closing bracket is encountered then this satisfies conditon 1 hence we pop
               the character.
        2.2.2. else we return "NO" because this fails conditon 2.

3.if stack is empty we return "YES" as brackets are balanced.
4.else we return "NO" as this fails the 2 conditions
*/


//Program

string findBalanced(string bracket)
{
    stack<char> bracket_remaining;   //We use a stack to store the unmatched brackets
    int n=bracket.size();            //Size of string
    
    for(int i=0;i<n;i++)  // We traverse from starting to end of the string 
    {                     //by checking the conditions for each character        
        
        //We check whether the character is an opening bracket if yes then we push it onto the stack
        if(bracket[i]=='(')
        {
            bracket_remaining.push(bracket[i]);
        }
        else if(bracket[i]=='{')
        {
            bracket_remaining.push(bracket[i]);
        }
        else if(bracket[i]=='[')
        {
            bracket_remaining.push(bracket[i]);
        }
        //If we encounter a character which is not opening bracket then we check whether the conditions are satisfing or not.
        else if(bracket[i]==')')
        {
            if(bracket_remaining.empty()==true)
            {
                return "NO";         
            }
            char top_char=bracket_remaining.top();  //We get the top most character in the stack
            if(top_char=='(')        //If we encounter the coresponding closing bracket then the substring is balanced
            {                        //hence we pop the character from the stack
                bracket_remaining.pop();
            }
            else                     //Else the substring is unbalanced so we return "NO"
            {
                return "NO";
            }
        }
        else if(bracket[i]=='}')
        {
            if(bracket_remaining.empty()==true)
            {
                return "NO";         
            }
            char top_char=bracket_remaining.top();  //We get the top most character in the stack
            if(top_char=='{')        //If we encounter the coresponding closing bracket then the substring is balanced
            {                        //hence we pop the character from the stack
                bracket_remaining.pop();
            }
            else                     //Else the substring is unbalanced so we return "NO"
            {
                return "NO";
            }
        }
        else if(bracket[i]==']')
        {
            if(bracket_remaining.empty()==true)
            {
                return "NO";         
            }
            char top_char=bracket_remaining.top();  //We get the top most character in the stack
            if(top_char=='[')        //If we encounter the coresponding closing bracket then the substring is balanced
            {                        //hence the condition 1 is satisfied
                bracket_remaining.pop();            //hence we pop the character from the stack
            }
            else                     //Else the substring is unbalanced so we return "NO"
            {
                return "NO";
            }
        }
    }
    if(bracket_remaining.empty()==true)
        return "YES"; //All the conditions are satisfied hence we return "YES"
    else 
        return "NO";  //This is the case where we encounter only opening brackets.
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string bracket;
        cin>>bracket;
        cout<<findBalanced(bracket)<<"\n";
    }
    return 0;
}


/*
Note: I have written the code by keeping the beginner in mind.
*/