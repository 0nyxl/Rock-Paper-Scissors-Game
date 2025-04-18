#include <iostream>
#include <string>
#include<cmath>
using namespace std;

struct stTotalRounds
{
    short PlayerWin;
    short ComputerWin;
    short Draw;

};

enum enChoices
{
    Stone = 1,
    Paper = 2,
    Scissor = 3
};

enum enGameInfo
{
    PlayerWin = 1,
    ComputerWin=2,
    Draw=3
};

int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

short HowManyRounds(string Msg) {

    short Rounds = 0;

    cout << Msg;
    cin >> Rounds;

    while (Rounds <= 0 || Rounds > 10) {

        cout << "invalid. Please Enter From [1 - 10]:";
        cin >> Rounds;
    }

    return Rounds;
}

enChoices ReadPlayerChoice() {
    
    short input = 0;

    cout << "\nChoose: [1]-Stone [2]-Paper [3]-Scissor:";
    cin >> input;

    while (input < 1 || input > 3) {
        cout<<"invalid. Enter From [1-3]:";
        cin >> input;
    }

    return static_cast<enChoices>(input);
}

enChoices ComputerChoice() {

    short ComputerChoice = RandomNumber(1, 3);

    return static_cast<enChoices>(ComputerChoice);

}

enGameInfo PlayerVsCompueter(enChoices Player, enChoices Computer) {
    if (Player == Computer)
        return enGameInfo::Draw;

    if ((Player == enChoices::Stone && Computer == enChoices::Scissor) ||
        (Player == enChoices::Paper && Computer == enChoices::Stone) ||
        (Player == enChoices::Scissor && Computer == enChoices::Paper))
        return enGameInfo::PlayerWin;

    return enGameInfo::ComputerWin;
}

string ChoiceToString(enChoices choice) {
    
    switch (choice) {
    case Stone:   return "Stone";
    case Paper:   return "Paper";
    case Scissor: return "Scissor";
    default:      return "Unknown";
    }
}

stTotalRounds FinalResult(stTotalRounds RoundsStats) {

    cout << "\n\n============= Game Over =============\n";
    cout << "Player Wins:   " << RoundsStats.PlayerWin << endl;
    cout << "Computer Wins: " << RoundsStats.ComputerWin << endl;
    cout << "Draws:         " << RoundsStats.Draw << endl;

    if (RoundsStats.PlayerWin > RoundsStats.ComputerWin)
        cout << ">>> Final Winner: [Player] \n";
    else if (RoundsStats.ComputerWin > RoundsStats.PlayerWin)
        cout << ">>> Final Winner: [Computer] \n";
    else
        cout << ">>> Final Result: It's a Draw \n";
    return RoundsStats;
}

void GameStats(short Rounds) {

    stTotalRounds RoundsStats = {};

    for (int i = 0; i < Rounds; i++)
    {
        cout << "\n\n____________Round [" << i + 1 << "] Begins____________\n";
        enChoices Player = ReadPlayerChoice();
        enChoices Computer = ComputerChoice();
        cout << "[Player] Chose: " << ChoiceToString(Player) << endl;
        cout << "[Computer] Chose: " << ChoiceToString(Computer) << endl;
        enGameInfo Result = PlayerVsCompueter(Player, Computer);

        if (Result == enGameInfo::PlayerWin)
        {
            cout << "\033[32mRound Winner: [Player]\033[0m" << endl;
            RoundsStats.PlayerWin++;
        }
        else if (Result == enGameInfo::ComputerWin)
        {
            cout << "\033[31mRound Winner: [Computer]\033[0m" << endl;
            RoundsStats.ComputerWin++;
        }
        else
        {
            cout << "\033[33mRound Winner: [Draw]\033[0m" << endl;
            RoundsStats.Draw++;
        }
    }
    FinalResult(RoundsStats);
}

void StartGame() {

    char PlayAgain = 'Y';
    PlayAgain = towlower(PlayAgain);

    do
    {
        GameStats(HowManyRounds("How Many Rounds [1-10]: "));
        cout << "\nDo you want to play again? [Y/N]: ";
        cin >> PlayAgain;
        
    } while (PlayAgain=='y');

    cout << "\n\nThanks For Playing\n\n";
}


 int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}
