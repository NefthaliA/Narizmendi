/**------------------------------------------
    Program 3: Menu Options

    Course: CS 141, Spring 2023.
    System: Windows 10
    Author: Nefthali Arizmendi
 ---------------------------------------------**/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
#include <iomanip> 
using namespace std;

const int NMISP = 5;
const int RNG_RANGE = 100;

void
display_header(const int ndict, const int nmiss)
{
    /* TODO: Print out the header, you can see an example of it
    in the write-up. Refer to Section "At Program Start".

    Parameters:
        int ndict -> the number of words in the full dictionary
        int nmiss -> the number of word pairs in the misspelled dataset.
    */
  // Added two paramenters to view how many words or word pairs in the   dictionary/misspelled dataset. 
  cout << "*** Typing Tutor" << endl << "There are " << ndict << " words in the dictionary." << endl <<   "There are " << nmiss << " commonly misspelled words." << endl;

  
}

void
display_menu_options()
{
    /* This function prints out all the menu options, it is
    given to you as part of the starter code. If you change
    it,  you run the  risk of failing  an early test of the
    autograder.*/

    cout << endl << "*** Select a menu option:" << endl
         << "1. Spell commonly misspelled words" << endl
         << "2. Type random words from the full dictionary" << endl
         << "3. Display some words from one of the lists" << endl
         << "4. Use binary search to lookup a word in the dictionary" << endl
         << "5. Exit the program." << endl
         << "Your choice: ";
}

vector<int>
randn(const int n, const int max)
{
    /*  TODO: Create and return a vector that has n random numbers drawn
    from  between 0 and the value of the parameter max. This function is
    relevant to many sections, and is needed any time random numbers are
    needed. Check the example file rng.cc for hints.

    Parameters:
        int n -> the number of random numbers to generate
        int max -> the maximum random number, random numbers are drawn from between [0,max]

    Returns:
        a vector that contains n random numbers between [0, max]
    */
  
    // Creates a vector to return random numbers
    vector<int> random;  
    for (int sample = 1; sample <= n; sample++) {
      int rnum = rand() % (max + 1);
      random.push_back(rnum);
    }
    // placeholder statements so code compiles you can delete these
    return random;
}

// Test if file opens or not
ifstream
open(const string& src_file)
{
    ifstream src{src_file};
    if (!src.is_open()) {
        cout << "Could not find file " << src_file << "." << endl;
        exit(1);
    }
    return src;
}

void
extract_dict(vector<string>& dst, const string& src_file)
{
    /* TODO: Read the data from the file, the file name is src_file, and store each line in the vector dst.

    Parameters:
        dst -> an empty vector (of strings), passed by reference, that  you  will  store  every line  of the file in (each line is one element in the file).

        src_file -> a string, passed by reference, that you are not allowed to change  (const),  that is simply the name of the file.
    Hints:
        Use the function (defined in this file) called open.
    */

  // Create a while loop to open the files adds the lines to empty vector 
  string word;
  
  ifstream MyReadFileStream(src_file);

  // Add each word that read into the dst vector 
  while (MyReadFileStream >> word){
    dst.push_back(word);
    }
  MyReadFileStream.close();
}

void
extract_misspelled(vector<string>& misspelled, vector<string>& correct, const string& src_file)
{
    /* TODO: Extract the word pairs (misspelled, correct) from the file
    and store them in their respective vectors.

    Parameters:
        misspelled -> an  empty vector (strings),  passed by reference,
                      that you will store the misspelled words in.

        correct -> an empty vector (strings), passed by reference, that
                   you will store the correct version of the words in.

        src_file -> a string, passed by reference, that you are not
                    allowed to change  (const),  that is simply the
                    name of the file.
    Hints:
        This function is very similar to extract_dict. Instead of simply
        storing the contents of the whole line as an element in dst, you
        have to process  the line into a misspelled word and the correct
        version. Each of those will be stored into separate vectors.  So
        you  should have  misspelled[i]  =  the ith misspelled  word and
        correct[i] = the ith correct word.
    */

  // Uses a loop to read in the misspelled text and uses stringstream to read the words line by line
  string word;
  string line;
  int alternate = 0; 

  ifstream MyReadFileStream(src_file);

  // Since the misspelled have the incorrect and then correct on the same line in the txt file, it needs the alternate interger to seperate the correct and incorrect spellings. 
  while (getline(MyReadFileStream, line)){
    stringstream twoWords(line);
    while (twoWords >> word){
      if(alternate == 0){   
        alternate = 1;
        misspelled.push_back(word);  
        }
      else{
        correct.push_back(word);
        alternate = 0;

        }
      }
    }
  MyReadFileStream.close();
}


void
display_elems(const vector<string>& src, const vector<int>& positions)
{
    /* TODO: With the vector of indices (position), print out the elements
    in the vector src only at those indices,  with a space between each of
    the elements.  Don't print a space after the last element. See Section
    "Menu Option 1: Spelling Misspelled"

    Parameters:
        src -> a vector (strings), passed by reference, that is not
               allowed to be modified (const), which holds the data
               that is to be printed

        positions -> a vector (int), passed by reference, that is not
                     allowed to be modified (const),  which holds the
                     indices for elements in src to print.
    */
  // Displays the elements in Menu Option 1 by checking the size of the position parameter 
  for(int i = 0; i < positions.size(); i++){
    cout << src.at(positions.at(i));
    if(i + 1 != positions.size()){
      cout << " ";
    }
  }
}

void
extract_spelling_answers(vector<string>& dst, const vector<string>& correct, const vector<int> positions)
{
    /* TODO: Copy the elements at the indices, in the positions vector,
    from the correct vector, into the vector dst. See Section "Menu Option 1: Spelling Misspelled".

    Parameters:
        dst -> an empty vector (of strings), passed by reference, that you will copy the specific elements from correct into.

        correct -> a vector (strings), passed by reference, that is not allowed to be modified (const), which holds the data that is to be copied over to dst

        positions -> a vector (int), passed by reference, that is not allowed to be modified (const),  which holds the indices of the elements in correct to copy over

    Hints:
        This is very similar to display_elems, except you are not printing
        out the elements but instead copying them over to dst.
    */
    for(int i = 0; i < positions.size(); i++){
      dst.push_back(correct.at(positions.at(i)));
  }
}

void
extract_spelling_mistakes(vector<string>& dst, const string& to_grade, const vector<string>& correct)
{
    /* TODO: Populate the vector dst with all the spelling errors in the
    user's answer (to_grade).  See Section "Menu Option 1: Spelling Mis-
    spelled"

    Parameters:
        dst -> an empty vector (of strings), passed by reference, that you will fill with strings that represent spelling errors  (mispelling -> correct spelling) (see Hints)

        to_grade -> a string, passed  by reference,  that is not allowed to be modified (const) that holds the user's typed answer.

        correct -> a vector (strings), passed by reference, that is not allowed to be modified (const), which holds the correct answers. (one vector element -> one word)

    Hints:
        First you need to extract the answer, the user gave, for each word. Once you have those, you can compare it with the associated correct answer  (answer ?= correct[i] for the ith word). You then populate the vector dst with a string that described the error. For example, if the word is  "hello" and  the user types  "jello" then the error will be "jello -> hello".
    */

  string word;
  vector <string> to_gradeList;
  
  // While going through what the user inputted, added a temporary vector to make it easier to compare with the vector of correct anwsers 
  stringstream inputs(to_grade);
  while (inputs >> word){
        to_gradeList.push_back(word);  
    }
  
  // Added if the user does not type the 5 words. 
  while (to_gradeList.size() < correct.size()){
    to_gradeList.push_back("NO INPUT");
  }

  // Prints out the mispelled word into the correct spelling
  for(int i = 0; i < correct.size(); i++)
  {
    if(to_gradeList.at(i) != correct.at(i)){
      dst.push_back(to_gradeList.at(i) + " -> " + correct.at(i));
    }
  }
}

void
report_misspell_mistakes(const vector<string>& mistakes, const int num_words)
{
    /*  TODO: Print out the spelling mistakes to the user. Following the format from the write-up. See Section "Menu Option 1: Spell-ing Misspelled".

    Parameters:
        mistakes -> a vector (strings), passed by reference, that is not allowed  to be modified  (const), and holds the messages about  misspellings that we want to report to the user.

        num_words -> an integer, that is not allowed to be modified (const),  which is  the total number  of words being tested
    */
  // Creates a scoring system with number of words correct or inccorect depending on how many mistakes the user inputted 
  int correct = num_words - mistakes.size();
  int points = correct * 3 - mistakes.size() * 6;

  if(mistakes.size() == 0){
    cout << "No misspelled words!" << endl;
  }
  else{
    cout << "Misspelled words: " << endl;
    for(int i = 0; i < mistakes.size(); i++){
      cout << "    " << mistakes.at(i) << endl;
    }    
  }
  
// Prints out score
  cout << correct * 3 << " points: " << correct << " spelled correctly x 3 points for each." << endl << mistakes.size() * 6 << " point penalty: " << mistakes.size() << " spelled incorrectly x -6 points for each. " << endl << "Score: " << points << endl;
  
}

void
evaluate_user_misspells(const vector<string>& src, const vector<int>& positions)
{
  // Starter code given 
  string input;
  getline(cin, input);

  vector<string> mistakes;
  vector<string> answers;

  // With the src vector, and the positions, gets the correct spellings and stores in vector answers 
  extract_spelling_answers(answers, src, positions);

  // with the correct answers and the user input, stores mistyped in vector mistakes
  extract_spelling_mistakes(mistakes, input, answers);

  // With the mistakes and answers, outputs the message with the scoring system
  report_misspell_mistakes(mistakes, answers.size());


    /*TODO: Read the users input for the typing test, and report back their performance. See Section "Menu Option 1: Spelling Misspelled".

    Parameters:
        src -> a vector (strings), passed by reference, that is not allowed to be modified (const), which holds the data that the user is being tested on.

        positions -> a vector (int), passed by reference, that is not allowed to be modified (const),  which holds the indices of the elements in correct to copy over

    Hints:
        Using getline to read in  the entire sequence might be a good idea. This function  should be easier to  write, if you have already completed the functions for calculating and  reporting spelling mistakes. Call those functions
        instead of duplicating the work.
    */
}

void
misspelled(const vector<string>& mspelled, const vector<string>& correct)
{
    /*  TODO: Print out the starting message for option 1, display 5 random words from the dictionary, finally evaluate the user's input. See "Menu Option 1: Spelling Misspelled".

    Parameters:
        mspelled -> a vector (string) where each element is one mispelled word from the data set

        correct -> a vector (string) where each element is a correctly spelled word from the data set

    Hints:
        Do not try to write this function first.  The role of this function is to simply drive the whole procedure for menu option 1, it should be calling helper functions to handle the details of the sub tasks. Use randn, display_elems, and evaluate_user_misspells.
    */

  // Inserts 5 random mispelled words and uses - 1 on mspelled.size() - 1 becuase it is 5 words that gets printed and since the index starts at 0, then it substracts by 1. When it reaches to 5, it will be 4 so 5 words would be printed instead of 6
  vector <int> numbers = randn(5, mspelled.size() - 1);
  
  cout << endl << "*** Using commonly misspelled words." << endl;
  
  display_elems(mspelled, numbers);
  cout << endl << "Type the words above with the correct spelling:" << endl;
  evaluate_user_misspells(correct, numbers);
  


}

void
full_dict(const vector<string>& dict)
{
    /* TODO: Print out starting message for menu option 2, display five random words from the full dictionary, then evaluate the user's input. See Section "Menu Option 2: Typing From Dictionary"

    Parameters:
        dict -> a vector (string), passed by reference, where
                each element is one word from the full
                dictionary.

    Hints:
        Do not start by writing this function. It's role is to simply drive the whole procedure for menu option 2, it should be calling helper functions to  handle the details  of the task.  You should be using randn, display_elems, and evaluate_user_misspells.
    */
  // - 1 is repeated here to have 5 words printed instead of 6 but for dictionary 
  vector <int> rngs = randn(5, dict.size() - 1);
  
  // Calls a function to display elements 
  cout << endl << "*** Using full dictionary." << endl;
  display_elems(dict, rngs);
  cout << endl << "Correctly type the words above:" << endl;
  evaluate_user_misspells(dict, rngs);
  
  
}

void
display_words_prompt()
{
    // This displays the data set choices for menu option 3
    cout << endl << "*** Displaying word list entries." << endl
         << "Which words do you want to display?" << endl
         << "A. Dictionary of all words" << endl
         << "B. Commonly misspelled words (wrongly spelled)" << endl
         << "C. Commonly misspelled words (correctly spelled)" << endl
         << "Your choice: ";
}

void
print_range(const vector<string>& data)
{
    /* TODO:  Display the starting  message for menu option 3,  read the users chosen range, verify that the indices are in range, then print out the  words in the index range.  See Section "Menu Option 3: Word Range"

    Parameters:
        data -> a vector (string),  passed by reference, that cannot be modified (const), which holds the all the data (and the user will print some of it in a range)

        Hints:
            You can determine the range of the data by checking the size of the vector. You need to make sure the  range is valid for the given dataset  (think about what  values the user could give that would be invalid). Check the write-up to make sure you are printing the data in the expected format.
    */

  string userInput;
  int number;
  vector <string> words;
  vector <int> numbers;
  vector <int> positions;

  cout << "*** Enter the start and end indices between 0 and " << data.size() - 1 << ": ";
  // Fixes for the getline function 
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  getline(cin, userInput);

  stringstream twoNum(userInput);
    while (twoNum >> number){
      numbers.push_back(number);
    }
  
  // Checks whether the user inputted two numbers that are in range. Uses .at(0) and .at(1) to check if both of the numbers are within range
  if(numbers.at(0) < -1 || numbers.at(1) > data.size() - 1 || numbers.at(0) > numbers.at(1)){
    cout << "The end index must come after the start, and the indices must be in range." << endl;
  }
    // Prints the word based on what the user inputted for the indicies 
  else{
    for(int i = numbers.at(0); i <= numbers.at(1); i++){
      positions.push_back(i);
    }
    extract_spelling_answers(words, data, positions);
    for(int i = 0; i < words.size(); i++){
      cout << positions.at(i) << ". " << words.at(i) << endl;
    }
  }
}

void
display_in_range(const vector<string>& dict, const vector<string>& mspelled, const vector<string>& correct)
{
    /* TODO: Display the initial messages for menu option 3, read in the user's choice of dataset, and display the data in range. See Section "Menu Option 3: Word Range"

    Parameters:
        dict -> a vector (string),  passed by reference, that cannot be modified (const), which holds the all the data from the full dictionary

        mspelled -> a vector (string), passed by reference, that cannot be modified (const),  which holds the all the miss-pelled words

        correct -> a vector (string), passed by reference, that cannot be modified (const),  which holds the all the words with correct spelling

    Hints:
        First write  the function print_range, which will print data in a range (in general). This function should call print_range, but it will read in the user's  choice of data set and  call print_range with the user's choice.
    */
  // Display the prompt to let the user know the options
  display_words_prompt();

  // Checks what character the user inputted based on the three letter options whether it is upercased or lower
  char userInput;
  cin >> userInput;
  
  if (userInput == 'A' || userInput == 'a'){
    print_range(dict);    
  }
  else if(userInput == 'B' || userInput == 'b'){
    print_range(mspelled);
  }
  else if(userInput == 'C' || userInput == 'c'){
    print_range(correct);
  }
}

void
bsearch(const vector<string>& data)
{
    /* TODO:  Read in the word to search for, from the user, and run the Binary Search Algorithm to search for the word. At every step of the algorithm,  print out the current word, that is being compared with the target.

    Parameters:
        data -> a vector (string), passed by reference, that cannot be modified (const), which holds the all the data from the full dictionary
    Hints:
        See our sample code to learn how the binary search algorithm works. Remember to  output the text in the same format as you  see in the write-up.
    */
  int i = 0;
  int min = 0, mid;
  int max = data.size();
  string target;
  string elem;
  int count = 1;

  // User enters word to find
  cout << "*** Enter word to search: ";
  cin >> target;

  // Binary Search Method 
  while(min < max){
    mid = (min + max) / 2;
    elem = data.at(mid);
    cout << setw(5) << count << ". Comparing to: " << elem << endl;
    count++;

    // Keeps checking until the word the user put was found or not 
    if(target > elem){
      min = mid + 1;
    }
    else if(target < elem){
      max = mid;
    }
    else if(target == elem){
      cout << elem << " was found." << endl;
      min = max;
    }
  }
  if(target != elem){
    cout << target << " was NOT found." << endl;
  }
}

void
extract_all_data(vector<string>& dict, vector<string>& mspelled, vector<string>& correct)
{   // Starter code given 
    extract_dict(dict, "dictionary.txt");
    extract_misspelled(mspelled, correct, "misspelled.txt");
}

int
main()
{  // Starter code given with switch cases 
    srand(1);
    vector<string> dict, mspelled, correct;
    extract_all_data(dict, mspelled, correct);
    display_header(dict.size(), correct.size());
    unsigned int choice;
    do {
        display_menu_options();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            misspelled(mspelled, correct);
            break;
        case 2:
            full_dict(dict);
            break;
        case 3:
            display_in_range(dict, mspelled, correct);
            break;
        case 4:
            bsearch(dict);
            break;
        case 5:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "No menu option " << choice << ". "
                 << "Please try again." << endl;
            cin >> choice;
        }
    } while ((choice != 5) && !cin.eof());
    return 0;
}