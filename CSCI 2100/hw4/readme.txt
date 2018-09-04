***************************************
* Partners		              *
* Ayush Pathak, Cemil Can Ali Marandi *
***************************************

*****************
* Group Dynamic *
*****************
JJ and I worked well together. We met up together outside of class and discussed the logic of each function with 
each other and figured out the code togther. There was an issue with the pop function that was giving us a segmentation fault
but I was able to figure out why that was happening. Other than that I feel that we worked eqaul amounts for this homework

********************
* Runtime analysis *
********************
Push:

This function is on the order of O(1).
This is because all that needs to be done is a pointer update for tp.

Pop:

This function is on the order of O(1).
Although this may seem like it would be different because of the number of 
operations performed, it takes only the same number of operations each time 
the function is called. So it will always take however long it takes to do the
pointer updates and the variable assignments.

Copy Constructor:

This function is again on the order of O(1).
Contrary to the deep copy implementation of this class, using shallow copies
takes less time because of the simple variable assignments that need to be done.
Because it is only a matter of assigning a set number of varibles each time the 
function is called, the function is constant time.

operator=:

This function is on the order of O(n).
This is because of the first while statement, which calls the pop function. If we take the example where t is some 
stack of nodes that all have a reference count of 1 per node and of any size say n; and 
let there be some other stack called s that is some stack of any size. When the statment 
t=s; is made, all of t has to be deallocated which means that we have to call the pop function n times. After that, 
then it is just a series of pointer updates which takes the same amount of time after the pop, so the run time for 
this function is O(n).

Destructor:

This function again is on the order of O(n).
This is because the destructor function calls the removeAll function, which calls the pop function until the 
stack is empty. So if we have a stack that is n nodes long, it takes a linear time to run through the entire
stack and delete the nodes that need to be deleted. So the runtime is O(n).


