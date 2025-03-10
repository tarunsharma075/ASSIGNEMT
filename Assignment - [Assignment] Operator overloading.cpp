#include <iostream>
#include<string>
 using namespace std;

class Player{
	private:
		string name;

	public:
		string operator+(Player otherPlayer){
	return name+" "+otherPlayer.name;
}
	Player(string naam){
		name=naam;
	}
};	
	


int main(){
string nameOne;
string nameTwo;
cout<<"Enter The name for Player One"<<endl;
getline(cin,nameOne);
cout<<"Enter The name of Player two"<<endl;
getline(cin,nameTwo);
Player P1(nameOne);
Player P2(nameTwo);
string combinedName =P1+P2;
cout<<combinedName;
return 0;
 
}

 
