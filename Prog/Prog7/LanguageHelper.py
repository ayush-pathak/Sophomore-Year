from string import ascii_letters,punctuation
alpha=list(ascii_letters+punctuation)

class LanguageHelper:
    """A class that finds words from a defined lexicon by the user

    """

    def __init__(self,words):
        """Create a new instance of the LanguageHelper class


        words   An interable sequence of words, one per line
        """
        if isinstance(words,(list,tuple)):
            for j in words:
                if not isinstance(j,str):                                   #this checks if an element is not a string 
                    raise TypeError('words must be a list of strings')
            self._contents=set(words)
        elif isinstance(words,file):
            self._contents=set()
            for line in words:
                if line.count(' ')>0:                                       #this checks if in the line there is a space or not
                    raise ValueError('words must be one per line')
                line=line.strip()
                self._contents.add(line)
        else:
            raise TypeError('words must be a list or file')



    def __contains__(self,query):
        """Determining if a string is a legitimate word
        
        query   the word in question
        """
        if query[0].isupper():
            temp=query.lower()
            if temp in self._contents:
                return True
            elif query in self._contents:
                return True
        elif query[0].islower():
            if query in self._contents:
                return True
            else:
                return False
        else:
            return False

    def getSuggestions(self,query):
        """ Method to get suggestions for a query by a user


        query   the word in question
        """
    
        self._suggestions=set()
        splitsOne=[(query[:i],query[i:]) for i in range(len(query))]  #This splits the word into left and right segments (i.e ('t','est'))
        #########################                                     #and ends with ('tes','t') so it is useful for deletion test and
        ## Suggestion Method 1 ##                                     #insertion test
        #########################
        for L,R in splitsOne:
            delete=L+R[1:]
            if delete in self._contents:
                self._suggestions.add(delete)
            if query[0].isupper():
                if delete.lower() in self._contents:
                    self._suggestions.add(delete)

        #########################
        ## Suggestion Method 2 ##
        #########################
        splitsTwo=[(query[:i],query[i:]) for i in range(len(query)+1)]#splitsTwo adds a extra space which is needed for adding a letter
        for L,R in splitsTwo:                                         #in front,between, and the end of the word (i.e('test',''))
            for a in alpha:
                addition=L+a+R
                if addition in self._contents:
                    self._suggestions.add(addition)
                if query[0].isupper():                                
                    if addition.lower() in self._contents:                
                        self._suggestions.add(addition)


        #########################
        ## Suggestion Method 3 ##
        #########################
        for a in alpha:
            for L,R in splitsOne:
                replace=L+a+R[1:]
                if replace in self._contents:
                    self._suggestions.add(L+a+R[1:])
                if query[0].isupper():
                    if replace.lower() in self._contents:
                        self._suggestions.add(replace)

        #########################
        ## Suggestion Method 4 ##
        #########################
        for L,R in splitsOne:
            if len(R)>1:
                switch=L+R[1]+R[0]+R[2:]
                if switch in self._contents:
                    self._suggestions.add(switch)
                if query[0].isupper():
                    if switch.lower() in self._contents:
                        self._suggestions.add(switch)

        if query[0].isupper():
            self._suggestions=[element.capitalize() for element in self._suggestions]
        return sorted(set(self._suggestions))
