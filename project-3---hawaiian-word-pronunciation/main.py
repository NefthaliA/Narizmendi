# CS 111, Fall 2022, Reckinger
# Hawaiian Words
# This project teaches the user how to pronouce Hawaiian words
# based on the 12 letters in the Hawaiian language.
# Name: <Nefthali Arizmendi>

# Variables/List
active = True
alphabet = ['a', 'e', 'i', 'o', 'u', 'p', 'k', 'h', 'l', 'm', 'n', 'w',"'", " "]
vowels = ['a', 'e', 'i', 'o', 'u']


while active == True:
 # These Variables reset after each loop of typing a word.
 word = input("Enter a hawaiian word: ")
 word = word.lower()
 length = len(word)
 pronunciation = ""
 count = 0
 valid = True
 constant = False
 combo = False

 #Checks if each letter is in Hawaiian alphabet. If it is NOT, then VALID = FALSE
 while count < length:
  if word[count] not in alphabet:
   valid = False
   print("Invalid word,", word[count], "is not a valid hawaiian character.")
   count = length
  else:
   count = count + 1

 # After each letter check, if it Valid is still true, then print and set count to 0 for the main loop.
 if valid == True:
  count = 0
  print(word.upper(), end=" is pronounced ")

 while count < length and valid == True: 
  # Checks if chracter in word is "a"
  if word[count] == "a":
   # Checks if it is the LAST character in the word entered
   if count + 1 < length:
    # If it is NOT the LAST character in the word, check if next character is a combo vowel.   
    if word[count + 1] == "i" or word[count + 1] == "e":
     pronunciation += "eye"
     combo = True
     
    elif word[count + 1] == "o" or word[count + 1] == "u":
     pronunciation += "ow"
     combo = True
    # Character either has no combo vowel after it or is the last letter in the inputted word.
    else:
     pronunciation += "ah"
   else:
    pronunciation += "ah"

  # Checks if chracter in word is "e"
  elif word[count] == "e":
   # Checks if it is the LAST character in the word entered
   if count + 1 < length:
    # If it is NOT the LAST character in the word, check if next character is a combo vowel.   
    if word[count + 1] == "i":
     pronunciation += "ay"
     combo = True
    
    elif word[count + 1] == "u":
     pronunciation += "eh-oo"
     combo = True
    # Character either has no combo vowel after it or is the last letter in the inputted word.
    else:
     pronunciation += "eh"
   else:
    pronunciation += "eh"
    
  # Checks if chracter in word is "i"
  elif word[count] == "i":
   # Checks if it is the LAST character in the word entered
   if count + 1 < length:
    # If it is NOT the LAST character in the word, check if next character is a combo vowel.
    if word[count + 1] == "u":
     pronunciation += "ew"
     combo = True
    # Character either has no combo vowel after it or is the last letter in the inputted word.
    else:
     pronunciation += "ee"
   else:
    pronunciation += "ee"

  # Checks if chracter in word is "o"
  elif word[count] == "o":
   # Checks if it is the LAST character in the word entered
   if count + 1 < length:
    # If it is NOT the LAST character in the word, check if next character is a combo vowel.
    if word[count + 1] == "i":
     pronunciation += "oy"
     combo = True
   
    elif word[count + 1] == "u":
     pronunciation += "ow"
     combo = True
    # Character either has no combo vowel after it or is the last letter in the inputted word.
    else:
     pronunciation += "oh"
   else:
    pronunciation += "oh"
  # Checks if chracter in word is "u"
  elif word[count] == "u":
   # Checks if it is the LAST character in the word entered
   if count + 1 < length:
    # If it is NOT the LAST character in the word, check if next character is a combo vowel.
    if word[count + 1] == "i":
     pronunciation += "ooey"
     combo = True
    # Character either has no combo vowel after it or is the last letter in the inputted word.
    else:
     pronunciation += "oo"
   else:
    pronunciation += "oo"

  # Checks if chracter in word is "w"
  elif word[count] == "w":
   # Checks if it is the NOT FIRST character in the word entered
   if count > 0:
    # If it is NOT the FIRST character in the word, check if the previous character is a combo vowel.
    if word[count - 1] == "i" or word[count - 1] == "e":
     pronunciation += "v" 
    else:
      pronunciation += "w"
   else:
     pronunciation += "w"
  

  # Constants and apostrophes fall here. 
  else:
    pronunciation += word[count]

  # If character that was found was a vowel and not the last character.
  # If it is NOT followed by an apostrophe or space, print the "-".
  if count + 1 < length and word[count] in vowels:
   if combo == False and word[count + 1] != "'" and word[count + 1] != " ":
    pronunciation += "-"

  if count + 2 < length and word[count] in vowels:
   if combo == True and word[count + 2] != "'" and word[count + 2] != " ":
    pronunciation += "-"
   
  # Reset Combo Bool
  if combo == True:
   count = count + 2
   combo = False
  else:
   count = count + 1

 # If entered word was Valid, print pronunciation of word.
 if valid == True:
  print(pronunciation.capitalize())
 choice = input("Would you like to enter another word? [y/yes, n/no] ")
 if choice[0].lower() == "y":
  active = True
 else:
  active = False
  print("All done.")
