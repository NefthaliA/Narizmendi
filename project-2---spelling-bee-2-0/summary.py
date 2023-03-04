# Project 1 - Spelling Bee 2.0, summary.py (file 3 of 3)
# <Nefthali Arizmendi>
# CS 111, Fall 2022, Reckinger
# Inform the user that game has ended and displays information about inputed words and scores. 

global name, words_list, scores_list, bonus 

# Using print to show what is going to appear on screen when
# code runs (even creating spaces). Also using =end to connect
# the name (variable) with the exclamation point.
print("************************")
print("GAME OVER")
print("************************")
if scores_list[0] == 0:
  print("You lost,", name, end="!")

elif scores_list[1] == 0:
  print("You lost,", name, end="!")

elif scores_list[2] == 0:
  print("You lost,", name, end="!")

elif scores_list[3] == 0:
  print("You lost,", name, end="!")

elif scores_list[4] == 0:
  print("You lost,", name, end="!")

elif scores_list[5] == 0:
  print("You lost,", name, end="!")

else: 
  print("You win,", name, end="!")

 
# Using sum(scores_list)) to add up the points from each word.
print("\nFinal Score:", sum(scores_list))
 
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
 
# Check the boolean if it equals True, it prints the string.
if bonus == True: 
  print("Congrats on finding a bonus word!")