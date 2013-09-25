#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

struct USER{
	string name;
	string role;
};
struct ACTION{
	string role;
	string action;
	string object;
};

class RBAC{
	private:
		fstream f;
		fstream g;
		string username;
		USER x[3];
		ACTION y[9];
		int user_id;
		string command;
		string user_action;
		string user_object;
		bool a;
		
	public:
			RBAC(){}
			void loadFiles(){
				
				f.open("URA.txt", ios::in);
				if(!f){ cout << "URA.txt file not found"; exit(1); }
				
				for(int i = 0; i < 3; ++i){
					f >> x[i].name;
					f >> x[i].role;
				}
				
				g.open("PRA.txt", ios::in);
				if(!g){ cout << "PRA.txt - file not found "; exit(1); }
				
				for(int i = 0; i < 3; ++i){
						g >> y[i].role;
						g >> y[i].action;
						g >> y[i].object;
				}

		}
		bool userLogin(){	
			
			cout << "Login: ";
			getline(cin,username);
			
			if(username == "Alberto"){
				user_id = 1;
				a = true;
			}
			else if(username == "Kevin"){
				user_id = 2;
				a = true;
			}
			else if(username == "Cesar"){
				user_id = 3;
				a = true;
			}
			else{
				cout << "error- username not found";
				a = false;
				cout << a;
			}
			
			for(int i = 0; i < 3; ++i)
			{
				if( username == x[i].name){
					cout << "Welcome " << username << "!\n";
					break;
				}
			}

			return a;
			
		}
		void getUserAction(){
			cout << "cmd> ";
			getline(cin, command);
			
			int sp1 = command.find(' ');
			if (sp1 == -1){
				cout << "Wrong entry - Please input command followed by object";
			}
			else{
				int sp2 = command.find(' ', sp1+1);
				if(sp2==-1){
					user_action = command.substr(0, sp1);
					user_object = command.substr(sp1+1, command.length()-sp1);
				}
			}
		}
		void verifyUserPermissions()
		{
			
				if((user_id == 1 )&&(user_action == "levitate"))
				{
					cout << "Access granted by virtue of roles: ";
					cout << y[0].role << endl;
				}
				else if((user_id == 1 )&&(user_action != "levitate")){
					cout << "Access denied: you are not authorized to perform this action!";
					cout << endl;
				}
				else if((user_id == 2 )&&(user_action == "climb"))
				{
					cout << "Access granted by virtue of roles: ";
					cout << y[1].role << endl;
				}
				else if((user_id == 2 )&&(user_action != "climb")){
					cout << "Access denied: you are not authorized to perform this action!";
					cout << endl;
				}
				else if((user_id == 3 )&&(user_action == "abduct"))
				{
					cout << "Access granted by virtue of roles: ";
					cout << y[1].role << endl;
				}
				else if((user_id == 3 )&&(user_action != "abduct")){
					cout << "Access denied: you are not authorized to perform this action!";
					cout << endl;
				}

				
		}
		void printUserRoles(){
			cout << "Roles: " <<"\n";
			for(int i =0; i < 3; ++i){
				cout << x[i].role << "\n";
			}
		}
		void printUserNames(){
			cout << "Usernames: " <<"\n";
			for(int i = 0; i < 3; ++i){
				cout << x[i].name << "\n";
			}
		}
		void printActions(){
			cout << "Actions: " <<"\n";
			for(int i =0; i < 3; ++i){
				cout << y[i].action << "\n";
			}
		}
		void printObjects(){
			cout << "Objects: " <<"\n";
			for(int i =0; i < 3; ++i){
				cout << y[i].object << "\t";
			}
		}
		~RBAC(){}
};

int main(){
	RBAC A;
	bool access = true;

	A.loadFiles();
	access = A.userLogin();
	if(access == true){
		A.getUserAction();
		A.verifyUserPermissions();
	}

	return(0);
}