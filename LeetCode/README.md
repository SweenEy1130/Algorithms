# Chapter 0: Intro
-------------------
According to the opinion from [X Wang](http://www.programcreek.com/2012/11/top-10-algorithms-for-coding-interview/)'s blog, I classified 10 types of important algorithm to help understand and review the LeetCode. The following topics are covered: *String/Array/Matrix*, *Linked List*, *Tree*, *Heap*, *Graph*, *Sorting*, *Recursion vs. Iteration*, *Dynamic Programming*, *Bit Manipulation*, *Probability*, *Combinations and Permutations*, and other problems that need us to find patterns.

1. String/ Array/ Matrix

	Classic problems:

	- [Evaluate Reverse Polish Notation](http://abspirits.sinaapp.com/article/9ubu9)
	- [Longest Palindromic Substring](http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html)
	- Word Break
	- Word Ladder
	- Median of Two Sorted Arrays
	- Regular Expression Matching
	- Merge Intervals
	- Insert Interval
	- Two Sum
	- 3Sum
	- [4Sum](http://abspirits.sinaapp.com/article/axexa)
	- 3Sum Closest
	- String to Integer
	- Merge Sorted Array
	- Valid Parentheses
	- Implement strStr()
	- Set Matrix Zeroes
	- Search Insert Position
	- Longest Consecutive Sequence
	- Valid Palindrome
	- Spiral Matrix
	- Search a 2D Matrix
	- Rotate Image
	- Triangle
	- Distinct Subsequences Total
	- Maximum Subarray
	- Remove Duplicates from Sorted Array
	- Remove Duplicates from Sorted Array II
	- Longest Substring Without Repeating Characters
	- Longest Substring that contains 2 unique characters
	- Palindrome Partitioning
	- Reverse Words in a String
2. Linked List

	- Add Two Numbers
	- Reorder List
	- Linked List Cycle
	- Copy List with Random Pointer
	- Merge Two Sorted Lists
	- Merge k Sorted Lists *
	- Remove Duplicates from Sorted List
	- Partition List
	- LRU Cache

3. Stack and Queue
4. Tree (DFS, BFS, Divide & Conquer) & Heap
	- Binary Tree Preorder Traversal
	- Binary Tree Inorder Traversal
	- Binary Tree Postorder Traversal
	- Word Ladder
	- Validate Binary Search Tree
	- Flatten Binary Tree to Linked List
	- Path Sum
	- Construct Binary Tree from Inorder and Postorder Traversal
	- Convert Sorted Array to Binary Search Tree
	- Convert Sorted List to Binary Search Tree
	- Minimum Depth of Binary Tree
	- Binary Tree Maximum Path Sum *
	- Balanced Binary Tree
5. Graph

	- Clone Graph

6. Binary search & sorting
7. Permutation & combination
	- Permutations
	- Permutations II
	- Permutation Sequence
	- Generate Parentheses

	Some other problems need us to use observations to form rules to solve them:

	- Reverse Integer
	- Palindrome Number
	- Pow(x,n)
	- Subsets
	- Subsets II

8. Two pointers
9. Bit Manipulation, number operation
	- Find Single Number
	- Maximum Binary Gap

10. Dynamic Programming
	- Edit Distance
	- Longest Palindromic Substring
	- Word Break
	- Maximum Subarray

## Technique interview

In a technique interview, it is necessary to know the process and some important attention. In general, the interview has the following steps:

##### Step 1: Ask questions

Understanding the problem before writing the code!

##### Step 2: Design an Algorithm

- Consider the data structure you should use
- Consider the time complexity it could be (From the naive solution to the optimal solution)
- Consider the space complexity (Usually the interviewer will ask you to optimize it)

##### Step 3: Pseduo-code

You should design a blueprint for your solution.

- Is it necessary to use recursion?
- What should the return value should be to make the code more brief?
- What intermediate variables should you use?

##### Step 4: Code

- Use Data Structures Generously
- Take care of the boundary conditions
- Check the validity for the input data.
- Don't crowd your coding

##### Step 5: Test

- Corner case: num.length() is 0 or only root node in the tree
- Extreme cases: 0, negative, null, maximums, etc
- User error:
- Time and memory

--------------------

## Evaluate Reverse Polish Notation

For the reverse polish notation, it is easy to consider using stack to handle the problem.

If the string is number, push it to the stack

If the string is operational symbol, pop two number from the stack and calculate is, push the result to the stack.

Finally, the number remains in the stack is the answer.


## Word break

Define an array `t[]` such that `t[i]==true => 0-(i-1)` can be segmented using dictionary

Initial state `t[0] == true`

	class Solution {
	public:
	    string expandString(string s){
	        int n = s.length();
	        if (n==0) return "";
	        string ret = "";
	        for (int i = 0; i < n; i++)
	            ret += "#" + s.substr(i, 1);
	        ret += "#";

	        return ret;
	    }
	    string longestPalindrome(string s) {
	        string xs = expandString(s);
	        int n = xs.length();
	        int *P = new int[n];
	        int C = 0, R = 0;
	        for (int i = 0; i < n ; i++){
	            int mirror_i = 2 * C - i;
	            P[i] = (R > i) ? min(R-i, P[mirror_i]) : 0;

	            while (xs[i + P[i] + 1] == xs[i - P[i] - 1]){
	                P[i]++;
	            }

	            if (P[i] + i > R){
	                R = P[i] + i;
	                C = i;
	            }
	        }

	        int maxLen = 0;
	        for (int i = 0; i < n; i++){
	            // cout << "(" << i << "," << P[i] << "," << xs[i] <<")\n";
	            if (P[i] > maxLen){
	                maxLen = P[i];
	                C = i;
	            }
	        }
	        return s.substr((C - maxLen)/2, maxLen);
	    }
	};

Time: O(string length * dict size)

One tricky part of this solution is the case:

INPUT: "programcreek", ["programcree","program","creek"].

We should get all possible matches, not stop at "programcree".