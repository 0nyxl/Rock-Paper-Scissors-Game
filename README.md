Rock, Paper, Scissors Game
A simple console-based Rock, Paper, Scissors game written in C++ where the player competes against the computer. This project showcases basic concepts like random number generation, user input validation, and loop handling in C++.

Features
Player vs Computer: Player selects one of the three options: Stone, Paper, or Scissors. The computer randomly selects one as well.

Multiple Rounds: The player can choose to play between 1 and 10 rounds.

Color-Coded Output: Results are displayed in different colors:

Green: Player wins

Red: Computer wins

Yellow: Draw

Replay Option: After a game is completed, the player is given an option to play again.

Installation

Clone this repository:

git clone https://github.com/0nyxl/Rock-Paper-Scissors-Game.git

Navigate to the project directory:

cd rock-paper-scissors

Compile the code: If you're using g++:

g++ -o rock_paper_scissors main.cpp

Run the game:

./rock_paper_scissors

Gameplay Instructions

1.Player Choice: The player will be prompted to enter their choice: 1 for Stone, 2 for Paper, and 3 for Scissors.
2.Computer Choice: The computer randomly picks one of the three options.
3.Round Evaluation: The game checks the player's and computer's choices, determines the winner, and displays the result.
4.Game Results: After all rounds, the game displays the total wins for both the player and the computer, as well as the number of draws.
5.Play Again: After completing the game, the player is asked if they want to play again by entering Y for yes or N for no.



#How It Works ?

> Random Number Generation: The computer's choice is made randomly using a function that generates a random number between 1 and 3, each corresponding to one of the options (Stone, Paper, Scissors).

> Result Evaluation: The game's result is determined by comparing the player's and computer's choices based on the following rules:

Stone beats Scissors.
Scissors beats Paper.
Paper beats Stone.

> Color-Coded Console Output: The result of each round is color-coded for clarity:

Green (\033[32m) for a #Player win.
Red (\033[31m) for a #Computer win.
Yellow (\033[33m) for a #Draw.

Contributing
Feel free to fork this repository and submit pull requests if you want to improve or extend the game. Some ideas for future improvements include:

Implementing a graphical user interface (GUI) for a more interactive experience.
Adding difficulty levels for the computer (e.g., making the computer smarter).
Implementing a scoring system that persists across multiple games.

License :
This project is open source and available under the MIT License.
