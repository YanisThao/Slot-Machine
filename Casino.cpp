#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <string>

using namespace std;

// Function to randomly get a slot symbol
// Returns one emoji symbol from the symbolsArray
string getRandomSymbol() {
    string symbolsArray[] = {"🍒", "🔔", "🍋", "⭐", "💎"};  // Array of emoji symbols
    int randomIndex = rand() % 5;  // Pick random index 0-4
    return symbolsArray[randomIndex];
}

// Function to calculate payout based on matching symbols
// Takes the array of spun symbols and bet amount, returns the payout
int calculatePayout(string resultArray[], int betAmount) {
    // If all 3 symbols match ➡️ big win!
    if (resultArray[0] == resultArray[1] && resultArray[1] == resultArray[2]) {
        cout << "💥 JACKPOT! You won 10x your bet! 💥\n";
        return betAmount * 10;
    }
    // If any two symbols match ➡️ small win
    else if (resultArray[0] == resultArray[1] || resultArray[1] == resultArray[2] || resultArray[0] == resultArray[2]) {
        cout << "🎉 Nice! You won 2x your bet! 🎉\n";
        return betAmount * 2;
    }
    // No match ➡️ loss
    else {
        cout << "😢 No win this time. Better luck next spin! 😢\n";
        return 0;
    }
}

int main() {
    srand(time(0));  // Seed random generator

    int playerBalance = 100;  // 💵 Player starts with $100 to play
    string userChoice;        // Stores user's yes/no choice to play again

    cout << "🎰 Welcome to the Emoji Casino Slot Machine! 🎰\n";

    // Main game loop: runs while player has money
    while (playerBalance > 0) {
        cout << "\nYour current balance is: $" << playerBalance << endl;
        cout << "Would you like to spin the slot machine? (yes/no): ";
        cin >> userChoice;  // Get player decision

        if (userChoice == "no") {
            break;  // Exit game if player says no
        }

        int betAmount;  // Amount player bets each round
        cout << "Enter your bet amount: ";
        cin >> betAmount;

        // Input validation: must bet between $1 and player's current balance
        while (betAmount > playerBalance || betAmount < 1) {
            cout << "Invalid bet. Enter an amount between $1 and your balance: ";
            cin >> betAmount;
        }

        // Spin reels: fill resultArray with 3 random symbols
        string resultArray[3];  // Array to hold spin results
        for (int i = 0; i < 3; i++) {
            resultArray[i] = getRandomSymbol();
        }

        // Show spin results
        cout << "\nYou spun: " << resultArray[0] << " " << resultArray[1] << " " << resultArray[2] << "\n";

        // Calculate winnings based on spin results
        int payout = calculatePayout(resultArray, betAmount);

        // Update player balance
        playerBalance = playerBalance - betAmount + payout;

        // Show outcome of the spin
        if (payout > 0) {
            cout << "You won $" << payout << "!\n";
        } else {
            cout << "You lost your bet.\n";
        }

        // Show updated balance
        cout << "New balance: $" << playerBalance << "\n";

        // Check for game over condition
        if (playerBalance <= 0) {
            cout << "\n💀 You're out of money! Game over. 💀\n";
        }
    }

    // End of game message
    cout << "\nThanks for playing! You leave with $" << playerBalance << ". 💰\n";

    return 0;
}
