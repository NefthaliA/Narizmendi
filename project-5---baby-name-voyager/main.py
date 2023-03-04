# Project 5 - Baby Name Voyager
# CS 111, Reckinger
# Nefthali Arizmendi
# Ask the user for baby name(s) which this code will then plot a graph displaying the ranking of all inputted names over 10 decades. 

import matplotlib.pyplot as plt

# Changes 0's to the desired max value, x.
def clean_data(list, x):
  for i in range(len(list)):
    if int(list[i]) == 0:
      list[i] = x 
    else:
      list[i] = int(list[i])
  return list

# Split data in lines from opened name data file and store them into a dictionary as a string & list.
def create_dictionary(list):
  for i in range(len(list)):
    list[i] = list[i].strip()
    temp_list = list[i].split(" ", 1)
    name = temp_list[0] 
    rank = temp_list[1].split()
    clean_data(rank, 1013)
    babydictionary[name] = rank
  return list, babydictionary

# Split a String into a list of capitalized words.
def split_data(x):
  x = x.strip(",")
  x = x.strip()
  name_list = x.split()
  for i in range(len(name_list)):
    name_list[i] = name_list[i].capitalize()
  return name_list

# Main code below
if __name__ == '__main__':
# Open File to extract data of names.
    file = open('names-data.txt') 
    line_list = file.readlines()
    file.close()

#Set-up an empty dictionary for later use.
    babydictionary = {}
    
# Clean data lines from opened name data file and sort into a dictionary.
    create_dictionary(line_list)

# User input for a list of names, then seperate names into a list.
    names = input("Enter a baby name: ") 
    name_list = split_data(names)
    
# List values for plotting
list_years = [1900, 1920, 1940, 1960, 1980, 2000]
scale = [0,0.5,1,1.5,2,2.5,3,3.5,4,4.5,5]

# Plot Ticks and Values
plt.ylim(1050, -50)
plt.xlim(-0.5, 6)

ticks = range(0, len(list_years))
plt.xticks(ticks, list_years)

# Plot Visuals/Lables
plt.title("Most Popular Baby Names, by decade")
plt.xlabel("Years")
plt.ylabel("Ranking")
file_name = ""

# Plotting points and setting legend based on inputted name.
for i in range(len(name_list)):
  plt.plot(scale, babydictionary[name_list[i]], "o--") 
  plt.legend(name_list, loc="best")
  file_name = file_name + name_list[i]
# Save and Display Finished Plot Graph

plt.savefig(file_name + ".png")
