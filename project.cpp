#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

enum ChoiceGame{stone=1, paper=2, scissor=3};
enum ChoiceWin{WinUsers=1,Wincomputer=2,draw=3};


struct stGameResults{

    int GameRounds,
        PlayerWon=0,
        ComputerWon=0,
        DrawTimes=0;
    string FinallWinner;

};

int Read( string message ){

    int Number=0 ;

    do{

        cout << message << endl ;
        cin >> Number ;

    } while ( Number < 0 );

    return Number;
}

int RandomNumber(int From, int To){
    int randum= rand() % (To - From + 1) + From ;
    return randum;
}

int InputOfComputer(){

        int computer=RandomNumber(1,3);
        return computer;

    }

int InputOfUser(){

    int user=Read("\nYour Choice : [1]:stone,  [2]:Paper,  [3]:Scissor  ? ");
    return user;

}

ChoiceWin GetWinnerOfGame(int pleyerComputer, int pleyerUser){

    if(pleyerUser==ChoiceGame::stone){
        if(pleyerComputer==ChoiceGame::paper){
            return ChoiceWin::Wincomputer;
        }
        else if(pleyerComputer==ChoiceGame::scissor){
            return ChoiceWin::WinUsers;
        }
        else {
            return ChoiceWin::draw ;
        }
    }

    else if(pleyerUser==ChoiceGame::paper){
        if(pleyerComputer==1){
            return ChoiceWin::WinUsers;
        }
        else if(pleyerComputer==ChoiceGame::scissor){
            return ChoiceWin::Wincomputer;
        }
        else {
            return draw;
        }
    }

    else {
        if(pleyerComputer==ChoiceGame::stone){
            return ChoiceWin::Wincomputer;
        }
        else if(pleyerComputer==ChoiceGame::paper){
            return ChoiceWin::WinUsers;
        }
        else{
            return draw;
        }
    }
}

string GetNameGame(int Value){

    if(Value==ChoiceGame::stone){
        return "Stone";
    }
    else if (Value==ChoiceGame::paper){
        return "Paper";
    }
    else
        return "Scissor";

}

void PrintHeader(int pleyerComputer, int pleyerUser,stGameResults &won){

    cout << "Player1 choice : " << GetNameGame(pleyerUser) << endl ;
    cout << "computer Choice : " << GetNameGame(pleyerComputer) << endl;
    ChoiceWin GetWinner=GetWinnerOfGame(pleyerComputer,pleyerUser);
    if(GetWinner==ChoiceWin::Wincomputer){
            system("color 4f");
            (won.ComputerWon)++;
            cout << "\aRound Winner : [Computer]" << endl;
     }

     else if(GetWinner==ChoiceWin::WinUsers){
            system("color 2f");
            (won.PlayerWon)++;
            cout << "\aRound Winner : [Users]" << endl;
     }

     else {
        system("color 6f");
        (won.DrawTimes)++;
        cout << "\aRound Winner : [draw]" << endl;
     }
}

string CheckFinallWinner(stGameResults won){

    if( won.ComputerWon > won.PlayerWon ){
        return "Computer" ;
    }
    else if(won.ComputerWon < won.PlayerWon){
        return "User";
    }
    else
        return "Draw";
}

void ManyRounds(stGameResults &won){


    won.GameRounds=Read("How many Rounds 1 to 10 ? ");
    for(int i = 1 ; i <= won.GameRounds ; i++){
        cout << "________________Round[" << i << "]________________" << endl ;
        int Computer=InputOfComputer();
        int User=InputOfUser();

        PrintHeader(Computer,User,won);
    }
}

void Results(stGameResults won){

    cout << "\n\n\n" ;
    cout << "\t\t\t\t_____________________________________________________________________" << endl ;
    cout << "\t\t\t\t                          +++ Game Over +++                         " << endl;
    cout << "\t\t\t\t_____________________________________________________________________" << endl ;
    cout << "\t\t\t\t____________________________[Game Results]___________________________" << endl ;
    cout << "\t\t\t\tGame Rounds : " << won.GameRounds << endl ;
    cout << "\t\t\t\tPlayer1 won times : " << won.PlayerWon << endl;
    cout << "\t\t\t\tComputer won times : " << won.ComputerWon << endl ;
    cout << "\t\t\t\tDraw times : " << won.DrawTimes << endl ;
    cout << "\t\t\t\tFinal Winner : " << CheckFinallWinner(won) << endl ;
    cout << "\t\t\t\t_____________________________________________________________________" << endl ;

}

void ResetProgram(){

    system("cls");
    system("color 0f");

}

void start(){

    char Question='y';

    do {

        ResetProgram();
        stGameResults won;
        ManyRounds(won);
        Results(won);

        cout << "\n\nDo you want to play again? y/n ? " ;
        cin >> Question;


    } while(Question=='y' || Question=='Y');

    system("color 0f");
}


int main()
{

    srand((signed)time(NULL));

    start();

    return 0;
}
