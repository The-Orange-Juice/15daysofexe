#include <bits/stdc++.h> 
using namespace std;
#define COMPUTER 1
#define HUMAN 2
struct move{ 
    int pile_index; 
    int stones_removed; 
}; 
void showPiles (int piles[], int n){ 
    int i; 
    printf ("Current Game Status -> "); 
    for (i=0; i<n; i++) printf ("%d ", piles[i]); 
    printf("\n"); 
    return; 
} 
bool gameOver(int piles[], int n){ 
    int i; 
    for (i=0; i<n; i++) if (piles[i]!=0) return (false);
    return (true); 
} 
void declareWinner(int whoseTurn){ 
    if (whoseTurn == COMPUTER){
    	printf ("\nYou won!\n\n"); 
    	cout<<"Day 5, Clue: Go to 51/65/77 in the main world in Demonic to get your hint for today!";
    	cin.ignore();
	}
    else {
    	printf("\nCOMPUTER won\n\n"); 
    	cout<<"Sorry, try again.";
    	cin.ignore();
	}
    return; 
}
int calculateNimSum(int piles[], int n){ 
    int i, nimsum = piles[0]; 
    for (i=1; i<n; i++) nimsum = nimsum ^ piles[i]; 
    return(nimsum); 
}
void makeMove(int piles[], int n, struct move *moves, int turn){ 
		int i, nim_sum = calculateNimSum(piles, n);
	    if (nim_sum != 0){ 
	        for (i=0; i<n; i++){
	            if ((piles[i] ^ nim_sum) < piles[i]){ 
	                (*moves).pile_index = i; 
	                (*moves).stones_removed = piles[i]-(piles[i]^nim_sum); 
	                piles[i] = (piles[i] ^ nim_sum); 
	                break; 
	            } 
	        } 
	    }
    	cout<<"Your turn\n";
		cout<<"Which pile do you want to remove? ";
	    cin>>(*moves).pile_index;
	    (*moves).pile_index--;
	    while((*moves).pile_index>=n||piles[(*moves).pile_index]==0){
	      	system("CLS");
	       	showPiles(piles, n); 
	       	cout<<"Invalid Pile Index. \n";
	       	cin.ignore();
	        	cout<<"Which pile do you want to remove? ";
	        	cin>>(*moves).pile_index;
	        	(*moves).pile_index--;
			}
	        cin.ignore();
	        cout<<"How many stones from the pile do you want removed? ";
	        cin>>(*moves).stones_removed; 
	        /*=1+(rand() % (piles[(*moves).pile_index]))*/
	        while((*moves).stones_removed<1||(*moves).stones_removed>100){
	        	system("CLS");
	        	showPiles(piles, n); 
	        	cout<<"Invalid Number of Stones Removed. \n";
	        	cin.ignore();
	        	cout<<"How many stones from pile "<<(*moves).pile_index<<" would you like to remove? ";
	        	cin>>(*moves).stones_removed; 
			}
	        cin.ignore();
        	piles[(*moves).pile_index] = piles[(*moves).pile_index] - (*moves).stones_removed; 
  			if (piles[(*moves).pile_index] < 0) piles[(*moves).pile_index]=0;
	        return;
	}
    // The player having the current turn is on losing 
    // position, so he/she/it can only wait for the opponent 
    // to make a mistake(which doesn't happen in this program 
    // as both players are playing optimally). He randomly 
    // choose a non-empty pile and randomly removes few stones 
    // from it. If the opponent doesn't make a mistake,then it 
    // doesn't matter which pile this player chooses, as he is 
    // destined to lose this game. 
  
    // If you want to input yourself then remove the rand() 
    // functions and modify the code to take inputs. 
    // But remember, you still won't be able to change your 
    // fate/prediction. 
    else{
        int non_zero_indices[n], count; 
        for (i=0, count=0; i<n; i++) if(piles[i]>0)non_zero_indices[count++]=i;
		(*moves).pile_index = (rand() % (count)); 
        (*moves).stones_removed = 1 + (rand() % (piles[(*moves).pile_index])); 
        piles[(*moves).pile_index] = piles[(*moves).pile_index] - (*moves).stones_removed; 
  		if (piles[(*moves).pile_index] < 0) piles[(*moves).pile_index]=0;
    }
    return; 
}
void playGame(int piles[], int n, int whoseTurn){
    struct move moves; 
    int moveno=0;
    while (gameOver (piles, n)==false){ 
    	moveno++;
    	system("CLS");
    	cout<<"Move number "<<moveno<<"\n";
    	cout<<"Press Enter to continue...";
    	cin.ignore();
        showPiles(piles, n); 
        makeMove(piles, n, &moves, whoseTurn);
        if (whoseTurn == COMPUTER){
            printf("COMPUTER removes %d stone(s) from pile at index %d\n", moves.stones_removed++, moves.pile_index+1); 
            cin.ignore();
            whoseTurn = HUMAN; 
        } 
        else{ 
            printf("You remove %d stone(s) from pile at index %d\n", moves.stones_removed++, moves.pile_index+1); 
            cin.ignore();
            whoseTurn = COMPUTER; 
        } 
    }
    declareWinner(whoseTurn); 
    return; 
}
void knowWinnerBeforePlaying(int piles[], int n, int whoseTurn){ 
    printf("Prediction before playing the game -> ");
    if (calculateNimSum(piles, n) !=0){ 
        if (whoseTurn == COMPUTER) printf("COMPUTER will win\n"); 
        else printf("You will win\n"); 
    } 
    else{ 
        if (whoseTurn == COMPUTER) printf("You will win\n"); 
        else printf("COMPUTER will win\n"); 
    }
    return; 
} 
void instructions(){
	cout<<"Welcome to the game of Nim!\n";
	cout<<"Press Enter to continue...\n";
	cin.ignore();
	cout<<"So... What is Nim?\n";
	cout<<"Press Enter to continue...\n";
	cin.ignore();
	cout<<"Given a number of piles in which each pile contains some stones.\n";
	cout<<"Press Enter to continue...\n";
	cin.ignore();
	cout<<"In each turn, a player can choose only one pile and remove any number of stones (at least one) from that pile.\n";
	cout<<"Press Enter to continue...\n";
	cin.ignore();
	cout<<"The player who cannot move is considered to lose the game (i.e. one who take the last stone is the winner).\n";
	cout<<"Press Enter to continue...\n";
	cin.ignore();
}
int main(){
	srand(time(NULL));
	int n=(rand()%10)+5;
    int piles[n];
    for(int i=0;i<n;i++){
    	piles[i]=(rand()%100)+5;
	}
	int temp=(rand()%2)+1;
	instructions();
    //knowWinnerBeforePlaying(piles, n, temp);
    //cin.ignore();
    playGame(piles, n, temp);
    return(0); 
}
