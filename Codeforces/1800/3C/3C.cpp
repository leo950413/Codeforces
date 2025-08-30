#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkWin(vector<string>& board, char player){
   for(int i = 0; i < 3; i++){
       if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
           return true;
       }
   }
   for(int j = 0; j < 3; j++){
       if(board[0][j] == player && board[1][j] == player && board[2][j] == player){
           return true;
       }
   }
   if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
       return true;
   }
   if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
       return true;
   }
   return false;
}

int main(){
   vector<string> board(3);
   for(int i = 0; i < 3; i++){
       cin >> board[i];
   }
   int xCount = 0, oCount = 0;
   for(int i = 0; i < 3; i++){
       for(int j = 0; j < 3; j++){
           if(board[i][j] == 'X') xCount++;
           else if(board[i][j] == '0') oCount++;
       }
   }
   bool xWins = checkWin(board, 'X');
   bool oWins = checkWin(board, '0');
   if(xWins && oWins){
       cout << "illegal" << endl;
       return 0;
   }
   if(xCount < oCount || xCount > oCount + 1){
       cout << "illegal" << endl;
       return 0;
   }
   if(xWins && xCount != oCount + 1){
       cout << "illegal" << endl;
       return 0;
   }
   if(oWins && xCount != oCount){
       cout << "illegal" << endl;
       return 0;
   }
   if(xWins){
       cout << "the first player won" << endl;
   }else if(oWins){
       cout << "the second player won" << endl;
   }else if(xCount + oCount == 9){
       cout << "draw" << endl;
   }else{
       if(xCount == oCount){
           cout << "first" << endl;
       }else{
           cout << "second" << endl;
       }
   }
   return 0;
}