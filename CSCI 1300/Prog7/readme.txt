1. Ayush Pathak

2. I spent approximately 4-5 hours working on the class definition 

3. I did get some clarification from Professor Goldwasser on the return values for the getSuggestions method

4. The overall goal for this piece of code is to take a lexicon of words that is an interable sequence of strings and return suggestions
   for a given query. The first step taken was to import from the string module the ASCII letters going from lowercase to uppercase, which
   will be important later on. The next step taken was to implement the __init__ function for the class LanguageHelper. 
   In this implementation it is important to understand that we can get different types of iterable sequences. If the sequence is a list or tuple,
   it is easy to iterate over that sequence. If the sequence is a file with one word per line, we need to get rid of the newline character that is added when 
   Python reads the file. Once that is done, the contents of the sequence of words are stored into self._contents. The next method that is 
   defined is the __contains__ method. This method is for the in operator. When looking at the rules of capitalization, the in operator can be 
   confusing. However, the basic rule is that if a word in the lexicon is captialized, it can only be returned in the capitalized form.
   For the query that is called, if it is capitalized, the code will make it lowercase and check as well as check the capitalized form.
   When the query is lowercased, that is just a simple check for the query in self._contents. This works because if the word the user is 
   looking for in self._contents is lowercased, then it is implied that it can be used as an upper and lowercased word. So when the user looks
   for a word that is only uppercased in self._contents with a lowercased form, the in operator will return False as it can only be in an 
   uppercase form. The final method that was implemented in the class definition was the getSuggestions method. This method is used to find 
   suggestions based on the query given by the user. The first method of finding valid suggestions was to delete a letter in the word.
   The way I went about doing this was to first create a list of the ways that the word can be divided up and called that splitsOne.
   Iterating over that list of tuples, removing the first letter in one of the elements in the tuple is effectively deleting one of the letters in the word.
   The code then checks to see if that word, which is stored as a local variable called delete is in the lexicon. If the word is in the lexicon, that variation is 
   add to a set called self._suggestions, which ensures there are no duplicates. The second suggestion method was to insert a letter at every possible position in the word.
   To do this, there needed to be a new list of splits that added a space in the last tuple value in the splits, as splitsOne's last tuple value is ('quer','y'). So we set 
   up a new list of tuples called splitsTwo and last tuple value is ('query',''). In order to get a list of characters to insert into the word, there is module called string 
   and in it, there is a string type called ascii_letters. This string contains all of the letters from a-z in lower and uppercase. So this data is imported from the module and 
   stored as alpha. It is then looped over and assigns the addition label to the new word created from the concatenation of the left hand side plus the letter plus the right hand side.
   The word is then checked to see if it is in the lexicon and needs to be added to the suggestions set. The next method of finding suggestions is to replace a letter in the word. For this 
   method, we go back to the first list of splits, splitsOne, and replace each letter with one from alpha. This word is then stored as replace and checked against self._contents and 
   added to the set if it is in the lexicon. The final method of suggestions is to switch the letters. For this suggestion we use splitsOne for the reason that the last tuple value has one
   character on the right hand side. Howerver, while flipping the characters it is important to make sure that the length of the right hand side is greater than one because of the logic.
   The logic used to flip the letters is based solely on the right hand side. So when the length of the right hand side is less than one, there is no way to flip one character with itself.
   So when the new word is created and stored as switch, it is checked in the lexicon and added if needed. One thing that was skipped in the explanation of the method was the capitalization rules.
   The capitalization is handled is based on the query the user gives. For all the suggestions methods, if the query that the user gives is capitalized, the suggestion word is lowercased and checked.
   This is needed because if the word exists only as a lower cased word, the suggestion wouldn't be added as none of the words in the lexicon matchup. Thus at the end of the method, the suggestions, if capitalized,
   are either capitalized or left unchanged. A note to mention here is that when looping over the ascii_letters, capital letters are added. For this reason, I am saying that capitalization and changing letters is one edit.
   For example, the suggestions for the query 'nissouri' would return 'Missouri', but the query 'nissoure' would return an empty set. Additionally, there is a possiblity that words can have hyphens or other punctuation 
   marks in the word, so in the list of characters called alpha, hyphens and other marks are added so they can be cycled through as well. For example, 'ablebodied' is not in the lexicon, but 'able-bodied' is. 