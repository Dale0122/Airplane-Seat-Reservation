#include <iostream>
using namespace std;
 
void seatPrinter(int chair[13][6]) {
//  Convenient Airplane Seat Printer Function    
//  Ths function reads the array and print the
//  arrangement of seats in the airplane.
 
//  Title Header
    cout << "================= BOEING-737 SEATS =================" << endl;
    cout << "    \t1\t2\t3\t4\t5\t6" << endl;
 
//  Main seat loop printer 
    for (int x = 0; x < 13; x++) {
        cout << "ROW " << x + 1 << "\t";
        for (int y = 0; y < 6; y++) {
            if (chair[x][y] == 0) {
                cout << "* \t"; // Mark 0 or unoccupied seat as "*"
            }
            else {
                cout << "X \t"; // Mark 1 or occupied seat as "X"
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}
 
void AssignSeat(int row,int col,int seat[13][6]){
//  This function assigns the values to seat array.
    seat[row - 1][col - 1] = 1;
    cout << "Your seat is now reserved at Row " << row << " Column " << col << endl << endl;
}
 
void SeatSelector(int rowStart, int rowEnd, int seat[13][6]) {
//  Another convenient fuction
//  This function selects and assign the 
//  desired seat of the passengers.
//  ============================================
//  parameters:
//  rowStart - Defines what is the starting row of the class
//  rowEnd   - Defines what is the last row of the class
 
    int RowChoice, ColChoice;
    cout << endl << "which row do you want to be seated? (ROWS " << rowStart << " - " << rowEnd <<") ";
    cin >> RowChoice;
    cout << endl << "which column do you want to be seated? (COLUMN 1 - 6) ";
    cin >> ColChoice;
 
//  Ensure the user input in rows and columns are valid and/or unoccupied.
    if (((RowChoice > rowStart - 1) && (RowChoice < rowEnd + 1)) && ((ColChoice > 0) && (ColChoice < 7))) { // Checks if seat is valid
        if (seat[RowChoice - 1][ColChoice - 1] == 1){ // This if checks if the seat is occupied
            cout << "\nSorry! That seat is already occupied." << endl;
            }
        AssignSeat(RowChoice,ColChoice,seat);
    }
    else {
        cout << endl << "Invalid row or column. Please Make sure your seat location is correct." << endl;
    }    
}
 
int main() { 
//  Initialize array
    int seat[13][6];
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 6; j++) {
            seat[i][j] = 0; // Set every value of array to 0 (unoccupied).
        }
    }
 
//  Loop for user prompt
    int loop_exit = 1;
    char proceed_buy;
 
    do {
    	system("CLS");
        int Class;
        seatPrinter(seat);
//      Welcome prompt.
        cout << "Welcome passenger!" << endl;
        cout << "What type of ticket would you like to buy?" << endl; 
        cout << "Type the following number of your choice:" << endl;
        cout << "[1]: First Class" << endl;
        cout << "[2]: Business Class" << endl;
        cout << "[3]: Economy Class" << endl << ">>> ";
        cin >> Class;
 
//      Passenger Class logic.
        switch (Class) {
        case 1: // First Class.
            SeatSelector(1,2, seat);
        break;
 
        case 2: // Business Class.
            SeatSelector(3,7, seat);
        break;
        
        case 3: // Economy Class
            SeatSelector(8, 13, seat);
        break;
        
        default: // User input is not in the choices.
            cout << "Invalid class choice." << endl;
            break;
        }
 
        cout << "Do you want to transact again? [Y/N]: ";
        char Continue;
        cin >> Continue;
        if (Continue == 'N' || Continue == 'n') { // User decides to end the transaction.
            loop_exit = 0;
            cout << "Thanks for transacting with us!" << endl << endl << endl;
        }
    } while (loop_exit > 0);
    return 0;
}

