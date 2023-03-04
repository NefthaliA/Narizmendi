/**------------------------------------------
    Program 1: ASCII Flowers
    Prompt for the number of flower layers and display

    Course: CS 141, Spring 2023
    System: Windows 10
    Author: Nefthali Arizmendi
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // display the prompt to the user
    cout << "Program 1: ASCII Flowers\n"
         << "Choose from the following options:\n"
         << "   1. Display the HELLO graphic\n"
         << "   2. Display The Flower\n"
         << "   3. Exit the program\n"
         << "Your choice -> ";

    // read in the user's choice
    int menu_option;
    cin >> menu_option;

    // handle option to quit
    if (menu_option == 3) {
        exit(0);
    }

    // handle the HELLO graphic choice
    if (menu_option == 1) {
        char frame;
        cout << "Enter your frame character: ";
        cin >> frame;
        //top border
        cout << endl;
        for (int i=0; i<2; i++) {
            cout << setfill(frame) << setw(36) << ' ' << endl;
        }
        //message
        cout << setfill(frame) << setw(3) << right << " "
             << "** ** ***** **    **    *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** **    **    *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** **    **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "***** ***** **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "***** ***** **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** **    **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** ***** ***** *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** ***** ***** *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << right;
        //bottom border
        for (int i=0; i<2; i++) {
            cout << setfill(frame) << setw(36) << " " << endl;
        }
    }

  
    if (menu_option == 2) {
        // Two variables to track the number of sections and row number of any given   flower 
        int numberOfSections;
        int rowNumber;
      
        // User inputs number of sections to make flower
        cout << "Enter the number of sections: ";
        cout << endl;
        cin >> numberOfSections;

        // The creation of each flower head (biggest loop)
        for(int sectionNumber = 1; sectionNumber <= numberOfSections; sectionNumber++){ 
          
          // Top rows of flower
            rowNumber = 0; 
          
          // space generator to align the "---" with the center of the biggest flower head
            for(int space = 0; space < numberOfSections; space++){
            cout << " ";
          }
            cout << "---" << endl;
          
            // Increments row number starting from 0
            for(int count = 1; count < sectionNumber; count++){
              rowNumber = rowNumber + 1; 
              
          // space generator to align the rows with the center of the biggest flower head
            for(int space = (numberOfSections - rowNumber); space > 0; space--){
              cout << " ";
          }    
              
          // Top Petal filler
          // Checks how many colons to put in each row number
            cout << "{";
            for(int colonCtr = rowNumber * 2 + 1; colonCtr > 0; colonCtr--){
              cout << ":";
              
            }
            cout << "}" << endl;
         } 
          
          // Center flower core
          // space generator to align the flower
          for(int space = (numberOfSections - sectionNumber); space > 0; space--){
            cout << " ";
          }
          
          cout << "{";
          
          // Checks how many colons to put in each center row          
          for(int ctr = 1; ctr <= sectionNumber; ctr++){
            cout << ":";
          }
          
          cout << "@"; // Inputs @ symbol between sectionNumbers
          
          for(int ctr = 1; ctr <= sectionNumber; ctr++){
            cout << ":";
            
          }
          
          cout << "}";
          cout << endl;

          // Bottom flower
          // Get row number starting from current size of flower head (sectionNumber)
          rowNumber = sectionNumber; 
          for(int count = 1; count < sectionNumber; count++){
            rowNumber = rowNumber - 1; 
            
            // space generator to align the rows with the center of the biggest flower head
            for(int space = (numberOfSections - rowNumber); space > 0; space--){
            cout << " ";
          }        
            cout << "{";
            
            // Checks how many colons to put in each row number
            for(int colonCtr = rowNumber * 2 + 1; colonCtr > 0; colonCtr--){
            cout << ":";
              
            }
            cout << "}" << endl;
          }

          }
            for(int space = 0; space < numberOfSections; space++){
              cout << " ";
          }
            cout << "---" << endl;

        // Stem Creation 
        // Uses a stem counter based on what number of sections the user inputed
        for(int stemCtr = 0; stemCtr < numberOfSections; stemCtr++){ 
          
          // Alternates left and right leaves starting from even based on if number is even
          if((stemCtr % 2) == 0){

          // space generator to align the stem with the flower on top based on number of sections and if the leaf is facing left or right  
          for(int space = 0; space <= numberOfSections; space++){
            cout << " ";
          } 
            cout << "|";
            cout << "/";
            cout << endl;
          }
          else{
          // space generator to align the stem with the flower on top based on number of sections and if the leaf is facing left or right         
          for(int space = 0; space < numberOfSections; space++){
            cout << " ";
          }        
            cout << "\\";       
            cout << "|";
            cout << endl;  

          }
          // Space generator for leafless stem that occurs after every stem with leaf 
          for(int space = 0; space <= numberOfSections; space++){
            cout << " ";
          } 
          cout << "|";
          cout << endl;
        }
      
    }
    return 0;
}