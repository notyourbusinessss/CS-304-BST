# CS-304-BST
This is Assignment 4 of Data Structure. Which requires us to create a BST or a Binary Search Tree. 
Like so : 

![alt text](images/image.png)

The tree works by putting new nodes either on the right or left of the root ( if there isnt a root make it the root ), so if it is bigger make the node connect on the right if it is smaller on the left.

# The Goal
The goal is to make a Binary search tree that will sort a given array.

## What to implement 
1. The big 5 ( destructor, copy constructor/assignment and move constructor/assignment )
2. Insert function
3. PreOrder Traversal
4. InOrder Traversal ( for in order vector return )
5. have a remove function
6. Compare the performance of both normal sorting and TreeSort

Note : I also made it so it prints the tree


###     Bonus
- Bonus 1 : Use stack for array's that have repeating numbers.
- Bonus 2 : Use a self Balancing tree .

# Time Complexity 

Here is a quick pixaleted tables of the time complexit difference

![Boo !!!](images/Time.png)

## Comparison of the two Times 

###     TreeSort 
TreeSort is normally __**O**(n(log(n)))__ as previously showned.\
Here are some example results of timing given by the program :
| run # | Time (μs) |
| ----- | --------- |
|   1   | 000       |
|   2   | 000       |
|   3   | 000       |

###     c++'s std::sort
Std::Sort should be __**O**(n(log(n)))__ much like TreeSort thus we would expect them to have similar outcomes in time.\
Here are some results to show this : 
| run # | Time (μs) |
| ----- | --------- |
|   1   | 000       |
|   2   | 000       |
|   3   | 000       |


# Grading

and the grading

![ AAHHH !](images/Grading.png)

# The actual file 
Here is the file about the Assignment : [Click here for link !](Documents/CS304_A4_treesort.pdf)

Note: there is a problem with it as it says that you can sort with a preorder but you cannot, other then that there is some problem but it's not that bad.
