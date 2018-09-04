****************
* Ayush Pathak *
****************

Remove function:

The remove function in an AVL tree has to do 2 main things:
1. Remove the node 
2. Reset the heights of the nodes that are above the removed node

Removing the node:
To remove the node, it is a simple as to call the remove function from the BinarySearchTree class. 
This remove function takes care of finding the node, swapping the data, and delete the required node. 

Resetting the heights of the nodes:
This part requires finding the parent of the node that is removed. This means creating iterators and
resetting the height of that node. Then we have to move up the path towards the root and reset the heights
if need be. This is taken care of repurposing the while loop in the insert function. This loop is different from 
the insert loop because it doesn't break because it is possible that the whole path would need to pivot, so this
loop keeps going until the parent iterator is null.  

Test File

The test file for the remove function tests the conditions where a pivot may or may not occur due the height
balance property. Some removes, like that of a leaf node, may or may not trigger a pivot because the parent may 
have 2 children and the property may still be satisfied. On the other hand, we may remove a leaf and cause the whole
leaf to root path to pivot at every node. 
