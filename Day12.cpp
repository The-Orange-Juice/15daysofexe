#include <bits/stdc++.h>
using namespace std;
vector< pair<int, int> > get_directions(int board[][8], int x, int y, int color) {
    vector< pair<int, int> > directions;
    if(board[x][y]) {
        return directions;
    }
    if((y < 6) && (board[x][y+1] == -color)) {
        for(int i=y+2; i < 8; i++) {
            if(!board[x][i]) {
                break;
            } else if(board[x][i] == color) {
                directions.push_back(make_pair<int, int>(0, x*8+i));
                break;
            }
        }
    }
    if((y < 6) && (x < 6) && (board[x+1][y+1] == -color)) {
        for(int i=0; (x+i+2 < 8) && (y+i+2 < 8); i++) {
            if(!board[x+i+2][y+i+2]) {
                break;
            } else if(board[x+i+2][y+i+2] == color) {
                directions.push_back(make_pair<int, int>(1, (x+i+2)*8+(y+i+2)));
                break;
            }
        }
    }
    if((x < 6) && (board[x+1][y] == -color)) {
        for(int i=x+2; i < 8; i++) {
            if(!board[i][y]) {
                break;
            } else if(board[i][y] == color) {
                directions.push_back(make_pair<int, int>(2, i*8+y));
                break;
            }
        }
    }
    if((y > 1) && (x < 6) && (board[x+1][y-1] == -color)) {
        for(int i=0; (x+i+2 < 8) && (y-i-2 >= 0); i++) {
            if(!board[x+i+2][y-i-2]) {
                break;
            } else if(board[x+i+2][y-i-2] == color) {
                directions.push_back(make_pair<int, int>(3, (x+i+2)*8+(y-i-2)));
                break;
            }
        }
    }
    if((y > 1) && (board[x][y-1] == -color)) {
        for(int i=y-2; i >= 0; i--) {
            if(!board[x][i]) {
                break;
            } else if(board[x][i] == color) {
                directions.push_back(make_pair<int, int>(4, x*8+i));
                break;
            }
        }
    }
    if((y > 1) && (x > 1) && (board[x-1][y-1] == -color)) {
        for(int i=0; (x-i-2 >= 0) && (y-i-2 >= 0); i++) {
            if(!board[x-i-2][y-i-2]) {
                break;
            } else if(board[x-i-2][y-i-2] == color) {
                directions.push_back(make_pair<int, int>(5, (x-i-2)*8+(y-i-2)));
                break;
            }
        }
    }
    if((x > 1) && (board[x-1][y] == -color)) {
        for(int i=x-2; i >= 0; i--) {
            if(!board[i][y]) {
                break;
            } else if(board[i][y] == color) {
                directions.push_back(make_pair<int, int>(6, i*8+y));
                break;
            }
        }
    }
    if((y < 6) && (x > 1) && (board[x-1][y+1] == -color)) {
        for(int i=0; (x-i-2 >= 0) && (y+i+2 < 8); i++) {
            if(!board[x-i-2][y+i+2]) {
                break;
            } else if(board[x-i-2][y+i+2] == color) {
                directions.push_back(make_pair<int, int>(7, (x-i-2)*8+(y+i+2)));
                break;
            }
        }
    }
    return directions;
}
vector< pair<int, vector< pair<int, int> > > > get_moves(int board[][8], int color) {
    vector< pair<int, vector< pair<int, int> > > > moves;
    for(int i=0; i < 8; i++) {
        for(int j=0; j < 8; j++) {
            moves.push_back(make_pair<int, vector< pair<int, int> > >(i*8+j, get_directions(board, i, j, color)));
            if(!moves.back().second.size()) {
                moves.pop_back();
            }
        }
    }
    return moves;
}
void make_move(int board[][8], int x, int y, int color, vector< pair<int, int> > directions) {
    for(auto it=directions.begin(); it != directions.end(); it++) {
        int i = x;
        int j = y;
        while((i != ((*it).second/8)) || (j != ((*it).second&7))) {
            board[i][j] = color;
            if(i < ((*it).second/8)) {
                i++;
            } else if((i > (*it).second/8)) {
                i--;
            }
            if(j < ((*it).second&7)) {
                j++;
            } else if(j > ((*it).second&7)) {
                j--;
            }
        }
    }
}
void undo_move(int board[][8], int x, int y, int color, vector< pair<int, int> > directions) {
    for(auto it=directions.begin(); it != directions.end(); it++) {
        int i = x;
        int j = y;
        while((i != ((*it).second/8)) || (j != ((*it).second&7))) {
            board[i][j] = -color;
            if(i < ((*it).second/8)) {
                i++;
            } else if((i > (*it).second/8)) {
                i--;
            }
            if(j < ((*it).second&7)) {
                j++;
            } else if(j > ((*it).second&7)) {
                j--;
            }
        }
        board[i][j] = color;
    }
    board[x][y] = 0;
}
void print(int board[][8]) {
    for(int i=7; i >= 0; i--) {
        printf("%d ", i);
        for(int j=0; j < 8; j++) {
            if(!board[j][i]) {
                printf("-");
            } else if(board[j][i] == 1) {
                printf("O");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
    printf("  ");
    for(int i=0; i < 8; i++) {
        printf("%d", i);
    }
    printf("\n\n");
}
int score(int board[][8], int color) {
    int sum = 0;
    for(int i=0; i < 8; i++) {
        for(int j=0; j < 8; j++) {
            sum += board[i][j];
        }
    }
    return sum * color;
}
int negamax_aux(int board[][8], int color, int depth, int alpha, int beta) {
    if(depth == 0) {
        return score(board, color);
    }
    vector< pair<int, vector< pair<int, int> > > > moves = get_moves(board, color);
    if(moves.size() == 0) {
        if(get_moves(board, -color).size() == 0) {
            return score(board, color);
        }
        int val = -negamax_aux(board, -color, depth-1, -beta, -alpha);
        if(val >= beta) {
            return val;
        }
        if(val > alpha) {
            alpha = val;
        }
    } else {
        for(auto it=moves.begin(); it != moves.end(); it++) {
            make_move(board, (*it).first/8, (*it).first&7, color, (*it).second);
            int val = -negamax_aux(board, -color, depth-1, -beta, -alpha);
            undo_move(board, (*it).first/8, (*it).first&7, color, (*it).second);
            if(val >= beta) {
                return val;
            }
            if(val > alpha) {
                alpha = val;
            }
        }
    }
    return alpha;
}
int negamax(int board[][8], int color, int depth) {
    int alpha = -65;
    int beta = 65;
    vector< pair<int, vector< pair<int, int> > > > moves = get_moves(board, color);
    int move = moves[0].first;
    for(auto it=moves.begin(); it != moves.end(); it++) {
        make_move(board, (*it).first/8, (*it).first&7, color, (*it).second);
        int val = -negamax_aux(board, -color, depth-1, -beta, -alpha);
        undo_move(board, (*it).first/8, (*it).first&7, color, (*it).second);
        if(val >= beta) {
            return (*it).first;
        }
        if(val > alpha) {
            alpha = val;
            move = (*it).first;
        }
    }
    return move;
}
int main(int argc, char **argv) {
	cout<<"Welcome to a game of Othello!\n";
	cin.ignore();
	cout<<"The game begins with four disks placed in a square in the middle of the grid, two facing white side up, two pieces with the dark side up, with same-colored disks on a diagonal with each other.\n";
	cin.ignore();
	cout<<"Assuming the game starts with dark.\nAfter placing the piece, dark turns over (flips, captures) all light pieces lying on a straight line between the new piece and any anchoring dark pieces.\n";
	cin.ignore();
	cout<<"All reversed pieces now show the dark side, and dark can use them in later moves - unless light has reversed them back in the meantime.\n";
	cin.ignore();
	cout<<"In other words, a valid move is one where at least one piece is reversed.\n";
	cin.ignore();
	cout<<"Now light plays, and the game operates under the same rules.\n";
	cin.ignore();
	cout<<"Players take alternate turns.\nIf one player can not make a valid move, play passes back to the other player.\n";
	cin.ignore();
	cout<<"When neither player can move, the game ends.\n";
	cin.ignore();
	cout<<"This occurs when the grid has filled up or when neither player can legally place a piece in any of the remaining squares.\n";
	cin.ignore();
	cout<<"This means the game may end before the grid is completely filled.\n";
	cin.ignore();
	cout<<"This possibility may occur because one player has no pieces remaining on the board in that player's color.\n";
	cin.ignore();
	cout<<"The player with the most pieces on the board at the end of the game wins.\n";
	cin.ignore();
	cout<<"\n\n";
	cout<<"Good luck!";
	cin.ignore();
    int depth = 3;
    if(argc > 1) {
        depth = atol(argv[1]);
    }
    depth *= 2;
    int board[8][8];
    memset(board, 0, sizeof(board));
    board[3][3] = board[4][4] = -1;
    board[3][4] = board[4][3] = 1;
    int turn = -1;
    while(true) {
    	system("CLS");
        print(board);
        vector< pair<int, vector< pair<int, int> > > > moves= get_moves(board, turn);
        printf("Available moves: ");
        for(auto it=moves.begin(); it != moves.end(); it++) {
            printf("(%d, %d)  ", (*it).first/8, (*it).first%8);
        }
        printf("\n");
        if(moves.size() == 0) {
            turn = -turn;
            moves = get_moves(board, turn);
            if(moves.size() == 0) {
                if(score(board,-1)<0)cout<<"You lose! Try again.";
                else{
                	cout<<"You win! Hint for today: _ _ _ (Number)\n_ _ _ _ (Word in l3etsp34k)\n_ _ _ _ _ (Another word in l3etsp34k)";
				}
				cin.ignore();
                return 0;
            }
        } 
		else {
            int x, y;
            if(turn == -1) {
            	cout<<"x: ";
                scanf("%d",&x);
            	cout<<"y: ";
            	scanf("%d",&y);
                for(auto it=moves.begin(); it != moves.end(); it++){
                    if(x*8+y == ((*it).first)) {
                        printf("\nYou chose: %d %d\n", x, y);
                        make_move(board, x, y, turn, (*it).second);
                        turn = -turn;
                        cin.ignore();
                        cin.ignore();
                        break;
                    }
                }
            } 
			else {
                x = negamax(board, turn, depth);
                for(auto it=moves.begin(); it != moves.end(); it++) {
                    if(x == ((*it).first)) {
                        printf("COMPUTER chose: %d %d\n", x/8, x%8);
                        make_move(board, x/8, x%8, turn, (*it).second);
                        turn = -turn;
                        cin.ignore();
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
