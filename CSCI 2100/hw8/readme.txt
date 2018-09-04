****************
* Ayush Pathak *
****************

The bulk of this assignment was to implement the remove function for 
a binary search tree, BST for short. To do this, there were 4 cases for removing a node in 
a BST: the node is the root, the node is a leaf, the node has one child, or the node has 2
children. 

The first step in the remove function is to find and mark the node you want to 'remove' with
an iterator. This process is essentially like the find function except it doesn't return a bool.

The next step is to determine which case the node falls under. 

Case 1: The node is the root.

When the node is the root, the first step is move to the right once and then all the way left, as 
much as possible. This is because we want to swap the data with the next node in an inorder traversal
of the tree. 

Once we find the leftmost node, we swap the data and check if the node has a right child or if is a leaf. 
If the node has a right child then we can call the parent class function deleteAndMoveRightChildUp. If the 
node is a leaf then from the parent class we can call the any delete function, which takes care of the 
case when the there is no child to promote.

Case 2: The node is a leaf.

When the node is a just a single leaf, it is just a simple removal of that node. So, we can just call any 
of the delete functions from the parent class.

Case 3: The node has 1 child. 

If the node has either a leaf or right child, all we have to do is call the specific delete function for 
the type of child it has. 

Case 4: The node has 2 children

If the node has 2 children, then we need to find the leftmost node as it would be the next in the inorder 
traversal. After that, we swap the data with the indicated node and then use the approriate delete if the 
leftmost node has a right child or if it is just a single node.

