#include <iostream>
using namespace std;

int main() {
  // We put 1 to indicate that there is ship
  bool ships[4][4] = {
    {0, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0}
  };

  // We keep track of how many hits the player has and how many turns they has played in these variables
  int hits = 0;
  int numOfTurns = 0;

  // Allow the player to keep going until they have hit all four ships
  while  (hits < 4) {
    int row, column;

    cout << "Select coordinates \n";

    // Ask player for a row
    cout << "Choose a row number between 0 and 3: ";
    cin >> row;

    // Ask player for a column
    cout << "Choose a column number between 0 and 3: ";
    cin >> column;

    // Check of valid input
    if (row < 0 || row > 3 || column < 0 || column > 3) {
      cout << "Invalid coordinates. Please choose a number between 0 and 3\n\n";
      continue;
    }

    // Check if ship exists in those coordinates
    if (ships [row] [column]){
      // If the player hits a ship, remove it by setting the value to zero
      ships [row] [column] = 0;
      // increase the hit counter
      hits++;

      // Tell player that they  have hit a ship and how many ships are left
      cout << "HIT!! " << ( 4 - hits ) << " left. \n\n";
    }else {
      // Tell the player that they missed
      cout << "Miss\n\n";
  }

    // Count how many turns player has taken
    numOfTurns++;
  }

  cout << "Victory!\n";
  cout << "You won in " << numOfTurns << " turns";

  return 0;
}
