# Project 1 - summary.py (file 3 of 3)
# Spelling Bee
# <Nefthali Arizmendi>
# CS 111, Fall 2022, Reckinger
# After the player types 5 words from the 7 random characters
# chosen at the beginning, the game finishes (with a GAME OVER)
# and calculates the total score and what words the player used.
# It also calculates how many points each word is.  

# Line 17 to 52 shows the result screen after typing 6 words 
# in the game
global name, words_list, scores_list 

# Using print to show what is going to appear on screen when
# code runs (even creating spaces). Also using =end to connect 
# the name (variable) with the excalmation point. 
print("************************")
print("GAME OVER")
print("************************")
print("Congrats,", name, end="!")
print("")

# Using sum(scores_list)) to add up the points from each word.
print("Final Score:", sum(scores_list))

print("Words played:")

# Using words_list [0] to [5] to show the past words and 
# how many points each word was using scores_list.
print(words_list[0], end="(")
print(scores_list[0], end=")")
print("")

print(words_list[1], end="(")
print(scores_list[1], end=")")
print("")

print(words_list[2], end="(")
print(scores_list[2], end=")")
print("")

print(words_list[3], end="(")
print(scores_list[3], end=")")
print("")

print(words_list[4], end="(")
print(scores_list[4], end=")")
print("")

print(words_list[5], end="(")
print(scores_list[5], end=")")
print("")