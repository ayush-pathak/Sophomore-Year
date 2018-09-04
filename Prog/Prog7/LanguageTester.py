from LanguageHelper import LanguageHelper
import unittest

# We define the custom lexicon that we will use for our controlled tests
lexicon = ('car', 'cat', 'Cate', 'cater', 'care',
           'cot', 'cute', 'dare', 'date', 'dog', 'dodge',
           'coffee', 'pickle', 'grate','marred','married',
           'often','soften','entails','entrails','able-bodied')

class BasicTest(unittest.TestCase):

  def setUp(self):
    self.help = LanguageHelper(lexicon)

  # make sure that all the words in the lexicon are recognized
  def testContainment(self):
    for w in lexicon:
      self.assertTrue(w in self.help)

  def testFailures(self):
    self.assertFalse('cate' in self.help)     # only allowed when capitalized
    self.assertFalse('fox' in self.help)      # word is not there
    self.assertFalse('cofee' in self.help)    # mis-spell word is not there
    self.assertFalse(' ' in self.help)        # no spaces in a list

    
  def testSuggestions(self):
    self.assertEqual(self.help.getSuggestions('cofee'), ['coffee'])
    self.assertEqual(self.help.getSuggestions('Gate'),(['Cate', 'Date', 'Grate']))
    self.assertEqual(self.help.getSuggestions('gate'),(['Cate', 'date', 'grate']))   #capitalization rules are tested here
    self.assertEqual(self.help.getSuggestions('blech'), [])
    self.assertEqual(self.help.getSuggestions('soften'),['often','soften'])
    self.assertEqual(self.help.getSuggestions('entails'),(['entails','entrails']))
    self.assertEqual(self.help.getSuggestions('dodge'),['dodge'])
    self.assertEqual(self.help.getSuggestions('marred'),(['marred','married']))
    self.assertEqual(self.help.getSuggestions('cater'),(['cater']))
    self.assertEqual(self.help.getSuggestions('Cater'),(['Cate','Cater']))
    self.assertEqual(self.help.getSuggestions('car'),(['car','care','cat']))
    self.assertEqual(self.help.getSuggestions('Car'),(['Car','Care','Cat']))
    self.assertEqual(self.help.getSuggestions('ablebodied'),(['able-bodied']))
  

if __name__ == '__main__':
  unittest.main()
