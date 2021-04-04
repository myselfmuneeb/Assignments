#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>

using namespace std;
int rounds , player_ch , com_ch , player_score = 0 , com_score = 0 , draw_game;
string user_name;
void display_game();
void players_turn();
bool gameOver();

int main()
{
    system("color 70");
    cout << "\nEnter Your Name : ";
    cin >> user_name;
    system("cls");
    cout << user_name << ":\n how many rounds you want to play : ";
    cin >> rounds;
    for(int round =1; round<=rounds; round++){
        system("cls");
        cout << "\n\n\t\t "<< user_name << " VS Computer" << endl;
        cout << "Round No : " << round << " / " << rounds << endl;
        cout << "\n\t\t  Choose One OF Given Options\n" << endl;
        cout << "\t\t 1) ROCK" << endl;
        cout << "\t\t 2) PAPER" << endl;
        cout << "\t\t 1) SCISSOR\n" << endl;
        cout << "\n\t[PLAYER SCORE : " << player_score << "] [COMPUTER SCORE : " << com_score << "] [Draw : " << draw_game << "]" << endl;
        players_turn();
        gameOver();

    }
    return 0;
}

void players_turn(){
    do{
        cout << "\nYour Turn ";
        cin >> player_ch;
    }while(player_ch!= 1 && player_ch!= 2 && player_ch!= 3);
    srand(time(0));
    com_ch = (rand()%3)+1;

    if(player_ch == 1){
        cout << "\t\tYOU Choose ROCk !\n" << endl;
    }
    else if (player_ch == 2){
        cout << "\t\tYOU Choose PAPER !\n" << endl;
    }
    else{
        cout << "\t\tYou Choose SCISSOR !\n" << endl;
    }
    if(com_ch == 1){
        cout << "\t\tComputer Choose ROCk !\n" << endl;
    }
    else if (com_ch == 2){
        cout << "\t\tComputer Choose PAPER !\n" << endl;
    }
    else{
        cout << "\t\tYou Computer SCISSOR !\n" << endl;
    }
}

bool gameOver(){
    if (player_ch == com_ch){
        cout << "Draw !!!" << endl;
        draw_game++;
    }
    else if (player_ch == 1 && com_ch == 3 || player_ch == 3 && com_ch == 2 || player_ch == 2 && com_ch == 1){
        cout << user_name << " WINS !!!!" << endl;
        player_score++;
    }
    else {
        cout << "COMPUTER WINS !!" << endl;
        com_score++;
    }
    cout << "Press Any Key To Continue" << endl;
    getch();
    if(com_score == player_score){
        system("cls");
        cout << "\n\t[PLAYER SCORE : " << player_score << "] [COMPUTER SCORE : " << com_score << "] [Draw : " << draw_game << "]" << endl;
        cout << "\n\t\t--- GAME IS DRAWN ----" << endl;
    }
    else if(player_score > com_score){
        system("cls");
        cout << "\n\t[PLAYER SCORE : " << player_score << "] [COMPUTER SCORE : " << com_score << "] [Draw : " << draw_game << "]" << endl;
        cout << "\n\t\t--- " << user_name << " WON THE GAME ---" << endl;
    }
    else{
        system("cls");
        cout << "\n\t[PLAYER SCORE : " << player_score << "] [COMPUTER SCORE : " << com_score << "] [Draw : " << draw_game << "]" << endl;
        cout << "\n\t\t--- COMPUTER WON THE GAME ---" << endl;
    }
}
