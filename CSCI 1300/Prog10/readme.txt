1. Ayush Pathak

2. I spent about an hour on this piece of code.

3. I did not get any help from outside sources.

4. The goal of this piece of code is to define a function that called diskUsage(path) that calculates the total disk usage of a directory 
   and files using a recursive implementation of the function. The first step was to figure out the base case of the function, which in this
   function would be the size of a file. When ever the function is called on a directory that has files and sub-directories, the function 
   checks to see if an item in the directory is a sub-directory. If it is a sub directory, the total disk usage is found by calling the 
   function again for all the items within a sub-directory. The total for each item is then reported to the user. For sub-directories, the total
   disk usage is not reported until all the items within it have been calculated for. The function continues until all the items in the directory
   have been calculated and the total disk usage of the path specified is reported back. 