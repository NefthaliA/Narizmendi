# Project 1 - generate_puzzle.py (file 1 of 3)
# Spelling Bee
# <Nefthali Arizmendi>
# CS 111, Fall 2022, Reckinger
# Outputs the beehive after inputting 7 random characters.

global letters

# Inputs the user to type 7 characters to write. 
letters = input("Enter 7 puzzle letters: ")

# Allows to make the letters uppercased.
letters = letters.upper()

# Outputs the screen to make it look like a beehive. 
# Also includes a list for letters [0] to [6] to place the 7
# characters on the beehive before starting the game.
print("--------SPELLING BEE-------")
print("--------- / ¯¯¯ \ ---------")
print("---------   ", letters[2], "   ---------")
print("----/ ¯¯¯ \ ___ / ¯¯¯ \----")
print("----  ", letters[3], "         ", letters[1], "  ----")
print("----\ ___ / ¯¯¯ \ ___ /----")
print("---------   ", letters[0], "   ---------")
print("----/ ¯¯¯ \ ___ / ¯¯¯ \----")
print("----  ", letters[4], "         ", letters[6], "  ----")
print("----\ ___ / ¯¯¯ \ ___ /----")
print("---------   ", letters[5], "   ---------")
print("--------- \ ___ / ---------")