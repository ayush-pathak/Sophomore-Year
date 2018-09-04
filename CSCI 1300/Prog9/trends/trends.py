import sys
from state import *
from country import Country
from parse import load_sentiments, load_tweets
from colors import get_sentiment_color
import re
from tweet import *
from geo import *

if len(sys.argv) > 1:
    query = ' '.join(sys.argv[1:])
else:
    query = raw_input('Enter query: ')

sentiments = load_sentiments()    # a map from strings to float in (-1.0, +1.0) range
states = load_states()            # list of State instances
tweets = load_tweets(query)       # list of Tweet instances
usa = Country(states, 1200)       # graphical rendering of Country (feel free to change the width)
usa.setTitle(query)

MIN_RELEVANT_WORDS = 4

#------------ your code should follow ------------
r = re.compile(r"[a-zA-Z'-]+")

numTweets={}
numWords=0
sentiTweets={}
for item in states:
    numTweets[item.abbrev()]=0
    sentiTweets[item.abbrev()]=0
totalNational = 0

    
for t in range(len(tweets)):
    distance={}
    location = tweets[t].position()
    for state in states:
        other = state.centroid()
        distance[state.abbrev()]=location.distance(other)
    minDistance = min(distance.itervalues())
    for keys in distance:
        if distance[keys]== minDistance:
            tweetLocationKey = keys

    parts=r.findall(tweets[t].message())    
    listOfWords=[]
    total = 0
    
    for word in parts:
        if word.lower() in sentiments and word.lower()!=query and (sentiments[word.lower()]>=6 or sentiments[word.lower()]<=4):
                listOfWords.append(word.lower())

    numWords += len(listOfWords)
    for item in listOfWords:
        if len(listOfWords)>3:
            total += sentiments[item]
            totalNational += sentiments[item]
        else:
            totalNational += sentiments[item]


    if len(listOfWords)>3:
        numTweets[tweetLocationKey] += 1
        sentiTweets[tweetLocationKey]+= total/len(listOfWords)
    
for state in numTweets:
    if numTweets[state] != 0:
        sentiTweets[state]=sentiTweets[state]/numTweets[state]
    if sentiTweets[state] == 0:
        sentiTweets[state] = None



nationalAverage= totalNational/numWords



for stateCode in sentiTweets:
    color = get_sentiment_color(sentiTweets[stateCode])
    usa.setFillColor(stateCode,color)


maxSenti= max(sentiTweets.itervalues())

minSenti = min(x for x in sentiTweets.itervalues() if x!=None)
        
        
    

for state in sentiTweets:
    if sentiTweets[state]== maxSenti:
        maxState=state
    if sentiTweets[state]== minSenti:
        minState = state
    

print 'National sentiment value {}'.format(('%.2f' %nationalAverage))
print 'Highest sentiment value of {} in {}'.format(('%.2f' %maxSenti),maxState)
print 'Lowest sentiment values of {} in {}'.format(('%.2f' %minSenti),minState)

