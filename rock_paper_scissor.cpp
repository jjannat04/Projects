#include <bits/stdc++.h>
using namespace std;
// Function to get the computer's choice
string getComputerChoice() {
    // Random device and Mersenne Twister RNG
    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> distrib(0, 2); // 0: Rock, 1: Paper, 2: Scissors

    int choice = distrib(gen);
    switch (choice) {
        case 0: return "rock";
        case 1: return "paper";
        case 2: return "scissors";
        default: return ""; // Should never reach here
    }
}
int main()
{
    int games;
    int user = 0, com = 0;



    cout << "Enter the number of games you want against the bot: ";
    cin >> games;
    string u;
    for (int i = 0; i < games; i++)
    {
        cout << "Enter your choice: (rock/paper/scissors): ";
        cin >> u;
        string c = getComputerChoice();
        cout << "Computer's Choice is: " << c << endl;

        if (u == c) {
            cout << "It's a tie!" << endl;
        } else if ((u == "rock" && c == "scissors") || 
                   (u == "paper" && c == "rock") || 
                   (u == "scissors" && c == "paper")) {
            user++;
            cout << "You win this round!" << endl;
        } else {
            com++;
            cout << "Computer wins this round!" << endl;
        }        

    }
    cout << "User Score: " << user << endl;
    cout << "Computer Score: " << com << endl;

    if (user > com)
    cout << "YOU WON :D";
    else if (com > user)
    cout << "YOU LOST :(";
    else
    cout << "GAME TIED :/";



}