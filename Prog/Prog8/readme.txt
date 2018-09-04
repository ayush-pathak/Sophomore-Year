1. Ayush Pathak

2. I spent about 4-5 hours working on this class definition.

3. I did not get any help from outside sources. 

4. The overall goal of this piece of code is to define a new class using the principles of inheritence. There were 
   many options to inherit from, namely the Layer class and Drawable class. For this given implimentation, we decided to 
   inherit the Layer class. The first step was to define the __init__ function, which provides the blueprint for Python to 
   create the Bear class. This function particularly took some time to tinker with because of the specific reference points for 
   each element of the Bear that is added to the layer in regards to the (0,0) reference point of the layer itself.  Once that 
   geometry was layed out, the next method that was defined was a function that returns the boolean value of the roar being open
   or not. This is for the user just in case they lose track of if the roar is open or not. The next method defined is the toggleRoar(). 
   As the name suggests, this method will toggle the roar of the Bear depending on the boolean value of self._roarOpen, which starts out 
   false. The next function defined is walk(). This method makes an animation of the bear walking and resets back to the original state. 
   the next three functions are for changing the fill colors of the body, eye, and ears. This is in order to customize the animal from 
   the defaults. In the init function, there are defaults provided for colors, but if the user changes their mind about the colors, they 
   can very easily change those values. 