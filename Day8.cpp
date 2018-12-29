#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Today's task is easy.\n";
	cout<<"Given a number n, it will be put through a magical function.\n";
	cout<<"If the resulting answer is above 100, you get the hint, or else, you have to try again.";
	cin.ignore();
	system("CLS");
	double n;
	cout<<"\nInput number here: ";
	cin>>n;
	double ans;
	ans=1/atan(n)*atan(10);
	system("CLS");
	if(ans>100){
		cout<<"Look at (50,53)!";
		cin.ignore();
	}
	else{
		cout<<"Wrong answer!";
		cin.ignore();
	}
}
