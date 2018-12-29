#include<bits/stdc++.h>
using namespace std;
bool evenodd=false;
void printarr(deque<int> &arr){
	deque<int>::iterator it; 
    for (it=arr.begin();it!=arr.end();++it)cout<<*it<<" ";  
}
bool findsum(deque<int> &arr){
	int sumodd=0;
	int sumeven=0;
	for(int i=0;i<10;i+=2)sumodd+=arr[i];
	for(int i=1;i<10;i+=2)sumeven+=arr[i];
	if(sumodd>sumeven)return true;
	else if(sumodd<sumeven)return false;
	else return true;
}
int main(){
	cout<<"Welcome!\nToday, we are going to be playing a little game, called Two Corners!\n";
	cout<<"Press ENTER to continue...";
	cin.ignore();
	cout<<"\n";
	cout<<"\n";
	cout<<"Two Corners is a two player coin game where each player gets turn one by one.\n";
	cout<<"Press ENTER to continue...";
	cin.ignore();
	cout<<"\n";
	cout<<"\n";
	cout<<"There is a row of even number of coins, and a player on his/her turn can pick a coin from any of the two corners of the row.\n";
	cout<<"Press ENTER to continue...";
	cin.ignore();
	cout<<"\n";
	cout<<"\n";
	cout<<"The player that collects coins with more value wins the game.\n";
	cout<<"Press ENTER to continue...";
	cin.ignore();
	cout<<"\n";
	cout<<"\n";
	cout<<"\nOf course, you will be playing against the computer.";
	cout<<"\nGood luck!\n";
	deque<int> arr(10);
	vector<int> p1;
	vector<int> p2;
	srand(time(NULL));
	for(int i=0;i<10;i++)arr[i]=(rand()%201)-100;
	cout<<"\n";
	cout<<"The list of coins in this game is: ";
	printarr(arr);
	cout<<"\n";
	bool checker=findsum(arr);
	cout<<"Press ENTER to continue...";
	cin.ignore();
	for(int i=1;i<=10;i++){
		if(arr.empty()){
			int p1v=0,p2v=0;
			for(int i=0;i<p1.size();i++)p1v+=p1[i];
			for(int i=0;i<p1.size();i++)p2v+=p2[i];
			if(p2v<p1v){
				cout<<"Computer won. Try again!";
				cin.ignore();
			}
			else{
				cout<<"You won!\n";
				cout<<"Day 4, Clue: ASK KEY what 84 means!";
				cin.ignore();
			}
		}
		system("CLS");
		cout<<"The coins that are now available are: ";
		printarr(arr);
		cout<<"\n";
		if(i%2==1){
			cout<<"Player one's turn!\n";
			cout<<"Press ENTER to continue...\n";
			cin.ignore();
			int c;
			cout<<"Would you like to remove...\n";
			cout<<"1 - "<<arr.at(0);
			cout<<"\n";
			cout<<"2 - "<<arr.at(arr.size()-1);
			cout<<"\n";
			cout<<"Option: ";
			cin>>c;
			while(c!=1&&c!=2){
				system("CLS");
				cout<<"Invalid number!\n";
				cin.ignore();
				cout<<"The coins that are now available are: ";
				printarr(arr);
				cout<<"\n";
				cout<<"Player one's turn!\n";
				cout<<"Press ENTER to continue...\n";
				cin.ignore();
				cout<<"Would you like to remove...\n";
				cout<<"1 - "<<arr.at(0);
				cout<<"\n";
				cout<<"2 - "<<arr.at(arr.size()-1);
				cout<<"\n";
				cout<<"Option: ";
				cin>>c;
			}
			if(c==1){
				p1.push_back(arr.at(0));
				arr.pop_front();
				evenodd=false;
			}
			else {
				p1.push_back(arr.at(arr.size()-1));
				arr.pop_back();
				evenodd=true;
			}
		}
		else{
			cout<<"Computer's turn!\n";
			cout<<"Would you like to remove...\n";
			cout<<"1 - "<<arr.at(0);
			cout<<"\n";
			cout<<"2 - "<<arr.at(arr.size()-1);
			cout<<"\n";
			if(evenodd==checker){
				if(arr.at(0)>arr.at(arr.size()-1)){
					cout<<"Computer chose 1!";
					p2.push_back(arr.at(0));
					arr.pop_front();
					cin.ignore();
					cout<<"\nPress ENTER to continue...\n";
					cin.ignore();
				}
				else{
					cout<<"\nComputer chose 2!";
					p2.push_back(arr.size()-1);
					arr.pop_back();
					cin.ignore();
					cout<<"\nPress ENTER to continue...\n";
					cin.ignore();
				}
			}
			else {
				if(checker==true){
					cout<<"Computer chose 1!";
					p2.push_back(arr.at(0));
					arr.pop_front();
					cin.ignore();
					cout<<"\nPress ENTER to continue...\n";
					cin.ignore();
				}
				else if(checker==false){
					cout<<"Computer chose 2!";
					p2.push_back(arr.size()-1);
					arr.pop_back();
					cin.ignore();
					cout<<"\nPress ENTER to continue...\n";
					cin.ignore();
				}
			}
			if(arr.empty()){
				system("CLS");
				int p1v=0,p2v=0;
				for(int i=0;i<p1.size();i++)p1v+=p1[i];
				for(int i=0;i<p1.size();i++)p2v+=p2[i];
				if(p2v<p1v){
					cout<<"Computer won. Try again!";
					cin.ignore();
				}
				else{
					cout<<"You won!\n";
					cout<<"Day 4, Clue: ASK KEY what 84 means!";
					cin.ignore();
				}
			}
		}
	}
}
