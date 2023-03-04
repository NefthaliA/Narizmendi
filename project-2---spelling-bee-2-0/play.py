# Project 2 - Spelling Bee 2.0, play.py (file 2 of 3)
# <Nefthali Arizmendi>
# CS 111, Fall 2022, Reckinger
# Checks for entered word to see if it's valid for scoring and adds the word and its score
# to their respective lists. 

# Dictionary is already assigned from driver.py
global letters, dictionary, word, score, words_list, scores_list

# The user inputs (types) a word listed from the 7 random
# characters that the user put in before starting the
# Spelling Bee game.
word = input("Word: ")

# All Upper and All Lower variant of entered word

# Dictionary only accepts full lowercase words, so an all lowercase version of the variable
# 'word' is used to see if 'word' is in dictionary.
l_word = word.lower()

# Variable 'letters' is always all uppercase, so an uppercase version of variable 'word' 
# is used to find if center 'letter' is used.
u_word = word.upper()

# Print prefix for entered word. 
print("Score for", word, end=": ")

# Does Dictionary contain 'word'? If so, fetch it's 'score'.
if l_word in dictionary:
 score = dictionary[l_word]

#- Is length of 'word' 4 or above? If so, check if word contains middle 'letter'.
 if len(word) > 3:
 
#-- Does the 'word' contain center 'letter'? If so, Valid Word and print its score.
  if letters[0] in u_word:
    print(score)

#-- 'word' does not contain middle 'letter'. Set 'score' to 0 and print.
  else:
   score = 0
   print(score)
   print(word, "does not contain the middle letter,", letters[0], "so no points given.")

#- Length of 'word' is 3 or less. Set 'score' to 0 and print.
 else:
   score = 0
   print(score)
   print(word, "contains less than 4 letters so no points given.")
   # Also mention if Word doesnt not contain middle Letter.
   if letters[0] not in u_word:
    print(word, "does not contain the middle letter,", letters[0], "so no points given.")

# Dictonary does not contain 'word'. Set 'score' to 0 and print.
else:
 score = 0
 print(score)
 print(word, "is not in the dictionary so no points given.")

# Append entered 'word' to 'word_list'.
words_list.append(word)
# Append score found for 'word' to 'score_list'.
scores_list.append(score) 