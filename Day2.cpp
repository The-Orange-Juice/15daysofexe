#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=-1,cnt=0,ans;
	srand(time(NULL));
	ans=(rand()%1000000)+1;
	system("CLS");
	cout<<"Welcome! Today, the password is going to be decided by your computer! \nThe password is a number between 1 and 1000000!";
	cout<<"\nPress ENTER to continue";
	cin.ignore();
	cout<<"\nYou have a maximum of 20 tries.";
	cout<<"\nPress ENTER to continue";
	cin.ignore();
	system("CLS");
	while(cnt<19){
		cout<<"Enter password: ";
		cin>>n;
		if(n<1||n>1000000){
			cout<<"Invalid number\n";
			while(n<1||n>1000000){
				cout<<"Enter password: ";
				cin>>n;
			}
			system("CLS");
		}
		if(n==ans){
			cout<<"You found the password!";
			cout<<"You found the password!";
			cout<<"\nPress ENTER to continue";
			cin.ignore();
			system("CLS");
			cout<<"Day 2, Clue: Stop asking me! ASK KEY";
			cin.ignore();
			return 0;
		}
		else if(ans<n){
			cout<<"The password is smaller than your guess!";
			cnt++;
			cout<<"\nGuesses left: "<<19-cnt;
		}
		else if(ans>n){
			cout<<"The password is larger than your guess!";
			cnt++;
			cout<<"\nGuesses left: "<<19-cnt;
		}
		cout<<"\nPress ENTER to continue";
		cin.ignore();
		cin.ignore();
		system("CLS");
	}
	cout<<"Sorry, you did not manage to guess the password in time. \nFeel free to try again!";
	cin.ignore();
}
