# Project 1 - play.py (file 2 of 3)
# Spelling Bee
# <Nefthali Arizmendi>
# CS 111, Fall 2022, Reckinger
#Makes the user type out each word and the code uses the 
#dictionary to output the scoring system each word the user inputs.

# Dictionary is already asssigned from driver.py
global dictionary, word, score, words_list, scores_list 

# The user inputs (types) a word listed from the 7 random 
# characters that the user put in before starting the 
# Spelling Bee game.
word = input("Word: ")

# Once a word is typed, it checks the dictionary to 
# calculate  score.
score = dictionary[word]

# Prints out the string and uses the word (variable) to input the 
# word the user put before.
print("Score for", word, end=": ")
print(score)

# Adds word to words_list and score to scores_list using append.
words_list.append(word)
scores_list.append(score)