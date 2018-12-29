#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Len the Hamster is a time traveller!\nBut he doesn't know what the date is.\nMaybe you might know better.\nCan you help him?";
	cin.ignore();
	string str;
	string date;
	string month;
	string year;
	while(str!="01/12/1982"){
		system("CLS");
		cout<<"Simply input a date in the format DD/MM/YYYY: ";
		str.clear();
		getline(cin,str);
		date.clear();
		month.clear();
		year.clear();
		date+=str[0];
		date+=str[1];
		month+=str[3];
		month+=str[4];
		year+=str[6];
		year+=str[7];
		year+=str[8];
		year+=str[9];
		if(str.length()!=10){
			cout<<"\nInvalid Date!";
			cout<<"Press ENTER to continue";
			cin.ignore();
			continue;
		}
		if(date!="01"){
			cout<<"Day isn't prime or composite!";
			cin.ignore();
			continue;
		}
		else if(month!="05"&&month!="12"){
			cout<<"This month and the next month both have 31 days.";
			cin.ignore();
			continue;
		}
		else if(month=="05"){
			cout<<"Not this month! Try again!";
			cin.ignore();
			continue;
		}
		else if(stoi(year)>=2000){
			cout<<"Uh Oh... I think the Y2K Bug broke the time machine.";
			cin.ignore();
			continue;
		}
		else if(stoi(year)<1982){
			cout<<"(Computer) Time didn't quite exist before this...";
			cin.ignore();
			continue;
		}
		else if(str[9]!='2'){
			cout<<"The last digit of the year must be the largest even prime number.";
			cin.ignore();
			continue;
		}
		else if(str[8]!='8'){
			cout<<"Can't really help you any more... Someone ATE the clue.";
			cin.ignore();
			continue;
		}
	}
	cout<<"Day 6, Clue: 13etsp34k is good";
	cin.ignore();
}
