#include <iostream>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,colm;
char turn = 'x';
bool draw = false;
void disp_board();
void player_turn();
bool gameOver();


int main()
{
    system("color 70");
    while(!gameOver()){
    disp_board();
    player_turn();
    }
    if (turn == '0' && draw == false){
        cout<< "\n\t\tPlayer 1 [x] Wins!!!"<< endl;
    }
    else if (turn == 'x' && draw == false){
         cout<< "\n\t\tPlayer 2 [O] Wins!!!"<< endl;
    }
    else{
        cout<< "\n\t\tGame Draw !!!" << endl;
    }

    return 0;
}
void disp_board(){
    system("cls");
    cout<< "\n\n\t  Tick    Cross     Game\n\n";
    cout<< "\tPlayer 1 [x]\n\tPlayer 2 [0]\n\n";
    cout<< "\t     |     |     " << endl;
    cout<< "\t  "<< board[0][0] <<"  |  "<< board[0][1] <<"  |  "<< board[0][2] <<"  " << endl;
    cout<< "\t_____|_____|_____" << endl;
    cout<< "\t     |     |     " << endl;
    cout<< "\t  "<< board[1][0] <<"  |  "<< board[1][1] <<"  |  "<< board[1][2] <<"  " << endl;
    cout<< "\t_____|_____|_____" << endl;
    cout<< "\t     |     |     " << endl;
    cout<< "\t  "<< board[2][0] <<"  |  "<< board[2][1] <<"  |  "<< board[2][2] <<"  " << endl;
    cout<< "\t     |     |     " << endl;
}
void player_turn(){
    if(turn == 'x'){
        cout<< "\n\t\tPlayer [1]"<<endl;
    }
    if (turn == '0'){
        cout<< "\n\t\tPlayer[2]"<<endl;
    }
    int choice;
    cin>> choice;
    switch(choice){
        case 1: row =0; colm =0; break;
        case 2: row =0; colm =1; break;
        case 3: row =0; colm =2; break;
        case 4: row =1; colm =0; break;
        case 5: row =1; colm =1; break;
        case 6: row =1; colm =2; break;
        case 7: row =2; colm =0; break;
        case 8: row =2; colm =1; break;
        case 9: row =2; colm =2; break;
        default : cout << "Invalid Number" << endl;
    }
    if(turn == 'x' && board[row][colm]!= 'X' && board[row][colm]!= 'O'){
            board[row][colm] = 'X';
            turn = '0';
        }
    else if (turn == '0' && board[row][colm]!= 'X' && board[row][colm]!= 'O'){
        board[row][colm] = 'O';
        turn = 'x';
    }
    else {
        cout << "Box Already Selected" << endl;
        player_turn();
    }
    disp_board();
}
bool gameOver(){
    for(int i=0; i<=2; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return true;
        }
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]){
            return true;
        }
    }
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            if (board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }

        }

    }
    draw = true;

    return true;
}
