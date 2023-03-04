/**------------------------------------------
    Program 2: Great 13

    Course: CS 141, Spring 2023.
    System: Windows 10
    Author: Nefthali Arizmendi
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <string>

/* Everything below this comment is starter code, and you are not
allowed to modify */

using namespace std;

// Function that displays the instructions to the user

void display_instructions()
{
    cout << "Class: CS 141" << endl
         << "Program 2: Great 13" << endl << endl
         << "Make a series of jumps until there is a single piece left" << endl
         << "anywhere on board. On each move you must jump an adjacent" << endl
         << "piece   into   an  empty  square,  jumping  horizontally," << endl
         << "vertically, or diagonally." << endl << endl
         << "Input of 'R' resets the board back to the beginning, and " << endl
         << "'X' exits the game." << endl;
}

// The internal representation of the board as an array. Do not modify directly.

char board[13]{};

/* These two functions are how you will get and set elements on the board. Only
use these two when changing, or reading the board. */

char get_element(char position)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to get element at position " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    return board[position - 'A'];
}

void set_element(char position, char value)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to set element at postion " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    board[position - 'A'] = value;
}

// print out the board with the legend on the right

void display_board()
{
    cout << endl;
    cout << setw(7) << "Board" << setw(12) << "Position" << endl;
    cout << setw(5) << board[0] << setw(11) << 'A' << endl
         << setw(3) << board[1] << ' ' << board[2] << ' ' << board[3]
         << setw(11) << "B C D" << endl
         << board[4] << ' ' << board[5] << ' ' << board[6] << ' '
         << board[7] << ' ' << board[8] << ' '
         << " E F G H I" << endl
         << setw(3) << board[9] << ' ' << board[10] << ' ' << board[11]
         << setw(11) << "J K L" << endl
         << setw(5) << board[12] << setw(11) << 'M' << endl;
    cout << endl;
}

void make_move();
void initialize_board();
bool game_over();

// Does the move to save repeated lines of code
void apply_move(string move);

int main(){
    // To loop the game. 
    display_instructions();
    initialize_board();
    do {
        display_board();
        make_move();
    } while (!game_over() && !cin.eof());
    return 0;
  }

void make_move(){
  // Asks user to input string of letters to play game.
  string move = "";
  cout << "Enter positions from, jump, and to (e.g. EFG): ";
  cin >> move;
  
  // Use later to mark if letters inputted are between A to M. 
  bool valid = true;

  // When the user wants to restart or exit the game.
  if(move.length() == 1 && ((move.at(0)) == 'R' || (move.at(0)) == 'r')){
    cout << "Restarting game." << endl;
    initialize_board();
  }
  
  else if(move.length() == 1 && ((move.at(0)) == 'X' || (move.at(0)) == 'x')){
    cout << "Exiting." << endl;
    // When the user inputs x, A is temporaily changed to X so when game_over() is called, it knows that the user inputted X wthout having to use a string parameter. 
    set_element('A', 'X');

  }
    

  // Converts all characters in the 3 length string into uppercase.
  else if(move.length() == 3){
    for (int i = 0; i < move.length(); i++){
      move.at(i) = toupper(move.at(i));
    }
    // Checks if the characters are between A to M. 
    int i = 0;
    while (i < 3) {
      if ((move.at(i) < 'A') || (move.at(i) > 'M')) {
        cout << "*** Given move has positions not on the board! Please retry." << endl;
        valid = false;
        i = 3;
        } 
      i++;
    }
    // Checks if there is a peg on the board and an empty space to land.
    if (valid == true){
      if(get_element(move.at(1)) == '#'){
        if(get_element(move.at(0)) == '#'){
          if(get_element(move.at(2)) == '.'){
            
            // Valid move checks for each letter on the board.
            if (move.at(0) == 'A' && ((move.at(1) == 'B' && move.at(2) == 'E') || (move.at(1) == 'C' && move.at(2) == 'G') || (move.at(1) == 'D' && move.at(2) == 'I'))){
              apply_move(move);
            }

            else if (move.at(0) == 'B' && ((move.at(1) == 'C' && move.at(2) == 'D') || (move.at(1) == 'F' && move.at(2) == 'J') || (move.at(1) == 'G' && move.at(2) == 'L'))){
              apply_move(move);
            }
              
            else if (move.at(0) == 'C' && ((move.at(1) == 'G' && move.at(2) == 'K'))){
              apply_move(move);
            }
              
            else if (move.at(0) == 'D' && ((move.at(1) == 'C' && move.at(2) == 'B') || (move.at(1) == 'H' && move.at(2) == 'L') || (move.at(1) == 'G' && move.at(2) == 'J'))){
              apply_move(move);
            }
              
            else if (move.at(0) == 'E' && ((move.at(1) == 'F' && move.at(2) == 'G') || (move.at(1) == 'B' && move.at(2) == 'A') || (move.at(1) == 'J' && move.at(2) == 'M'))){
              apply_move(move);
            }

            else if (move.at(0) == 'F' && ((move.at(1) == 'G' && move.at(2) == 'H'))){
              apply_move(move);
            }

            else if (move.at(0) == 'G' && ((move.at(1) == 'C' && move.at(2) == 'A') || (move.at(1) == 'F' && move.at(2) == 'E') || (move.at(1) == 'H' && move.at(2) == 'I') || (move.at(1) == 'K' && move.at(2) == 'M'))){
              apply_move(move);
            }

            else if (move.at(0) == 'H' && ((move.at(1) == 'G' && move.at(2) == 'F'))){
              apply_move(move);
            }

            else if (move.at(0) == 'I' && ((move.at(1) == 'H' && move.at(2) == 'G') || (move.at(1) == 'D' && move.at(2) == 'A') || (move.at(1) == 'L' && move.at(2) == 'M'))){
              apply_move(move);
            }

            else if (move.at(0) == 'J' && ((move.at(1) == 'K' && move.at(2) == 'L') || (move.at(1) == 'F' && move.at(2) == 'B') || (move.at(1) == 'G' && move.at(2) == 'D'))){
              apply_move(move);
            }

            else if (move.at(0) == 'K' && ((move.at(1) == 'G' && move.at(2) == 'C'))){
              apply_move(move);
            }

            else if (move.at(0) == 'L' && ((move.at(1) == 'K' && move.at(2) == 'J') || (move.at(1) == 'H' && move.at(2) == 'D') || (move.at(1) == 'G' && move.at(2) == 'B'))){
              apply_move(move);
            }

            else if (move.at(0) == 'M' && ((move.at(1) == 'L' && move.at(2) == 'I') || (move.at(1) == 'J' && move.at(2) == 'E') || (move.at(1) == 'K' && move.at(2) == 'G'))){
              apply_move(move);
            }
              
            // These invalid commands are placed in the highest priority whenever the user inputs.  
            else{
              cout << "*** Move is invalid. Please retry." << endl;
            }
          }
          else{
            cout << "*** Destination must be empty. Please retry." << endl;
          }
        }
        else{
          cout << "*** Source needs a piece. Please retry." << endl;
        }
      }
      else{
        cout << "*** Must jump a piece. Please retry." << endl;
      }
    }
  }    
  else{
    cout << "*** Invalid sequence. Please retry." << endl;
  }
}

bool game_over()
{
  // Counts how many pegs are on the board.
  int count = 0;
  if(get_element('A') == '#'){  
    count++;
    }
  if(get_element('B') == '#'){  
    count++;
    }  
  if(get_element('C') == '#'){  
    count++;
    }
  if(get_element('D') == '#'){  
    count++;
    }
  if(get_element('E') == '#'){  
    count++;
    }
  if(get_element('F') == '#'){  
    count++;
    }
  if(get_element('G') == '#'){  
    count++;
    }
  if(get_element('H') == '#'){  
    count++;
    }
  if(get_element('I') == '#'){  
    count++;
    }
  if(get_element('J') == '#'){  
    count++;
    }
  if(get_element('K') == '#'){  
    count++;
    }
  if(get_element('L') == '#'){  
    count++;
    }
  if(get_element('M') == '#'){  
    count++;
    }

  // When the user inputs x, A is temporaily changed to X so when game_over() is called, it knows that the user inputted X wthout having to use a string parameter. 
  if(get_element('A') == 'X'){  
    return true;
  }  
  // If there is one peg left, user wins.
  else if(count == 1){
    cout << "Congrats you win!" << endl;
    return true;
  }
  // Else, game is not over.
  else{
    return false;
  }
}

void initialize_board(){
  // Sets up the board at its beginning state in order to play the game.
  set_element('A', '#');
  set_element('B', '#');
  set_element('C', '#');
  set_element('D', '#');
  set_element('E', '#');
  set_element('F', '#');
  set_element('G', '.');
  set_element('H', '#');
  set_element('I', '#');
  set_element('J', '#');
  set_element('K', '#');
  set_element('L', '#');
  set_element('M', '#');

  
  
}
// Applies the move to the board to prevent many repeated lines.
void apply_move(string move){
  set_element(move.at(0), '.');
  set_element(move.at(1), '.');
  set_element(move.at(2), '#');
}
