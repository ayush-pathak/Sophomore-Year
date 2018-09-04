1. Ayush Pathak

2. I spent about 5-6 hours working on this code.

3. I did recieve some help from Professor Goldwasser on some debugging of an error.

4. The overall goal of this piece of code was to classify tweets based on location and determine the sentiments of
   those tweets. The first step that I took was to determine the postion of each tweet by calculating the distance
   of each tweet to the centroid of each state and finding the smallest distance. The tweet location and the overall 
   number of tweets from each state was stored in a dictionary, allowing for easy access. The next step was to determine
   which words from the tweet were intresting. I started by using the re module and compilied all the characters into 
   the words that included an apostrophe. These words where then checked to see if they were in the sentiments dictionary 
   then made sure to have extreme sentiments, namely less than 4.0 and greater than 6.0. If the word met those condtions,
   they are added to a list and stored. The next step is to calculate the average sentiment of that list of words. 
   However, we can only calculate the sentiment if the length of the list is greater than 3. The national average is 
   calculated regardless. The average sentiments are then stored in a dictionary and then divided by the number of tweets
   for that state. The map of the US is then colored based on the sentiment values, if the sentiments are 0, the state is 
   left black. The national average, maximum, and minimum are then reported to the user. I do have to point out that there is
   some discrepency between my code and the examples provided. 