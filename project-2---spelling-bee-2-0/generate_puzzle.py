# Project 2 - Spelling Bee 2.0, generate_puzzle.py (file 1 of 3)
# <Nefthali Arizmendi>
# CS 111, Fall 2022, Reckinger
# Checks for entered letters to see if it's valid for printing and playing.

global letters, valid 

# Inputs the user to type 7 characters.
letters = input("Enter 7 puzzle letters: ")
 
# Forces the letters to become uppercased.
letters = letters.upper()


# Is length of 'letters' greater than 7?
if len(letters) > 7:
  valid = False
  print("Invalid puzzle, must enter exactly 7 letters.")
  
# Is length of 'letters' equal to 7?
elif len(letters) == 7:

#- Are any of the characters in 'letters' the same?
  if letters[0] == letters[1]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[0] == letters[2]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[0] == letters[3]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[0] == letters[4]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[0] == letters[5]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[0] == letters[6]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[1] == letters[2]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[1] == letters[3]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")  
  elif letters[1] == letters[4]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[1] == letters[5]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[1] == letters[6]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[2] == letters[3]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[2] == letters[4]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[2] == letters[5]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[2] == letters[6]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[3] == letters[4]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[3] == letters[5]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[3] == letters[6]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[4] == letters[5]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[4] == letters[6]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
  elif letters[5] == letters[6]:
    valid = False
    print("Invalid puzzle, must enter 7 unique letters.")
	
#= None of the characters in 'letters' are the same.
  else:
#=- Are the characters in 'letters' all part of the alphabet? If so, entered letters are valid.
   if letters.isalpha():
    valid = True
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
	
#=- There are characters in 'letters' that are not part of the alphabet.
   else:
    valid = False
    print("Invalid puzzle, must enter letters only (no numbers, symbols, etc.)")
	
# Length of 'letters' is less than 7 characters long.
else:
 valid = False
 print("Invalid puzzle, must enter exactly 7 letters.")