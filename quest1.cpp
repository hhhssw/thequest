#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(void){

int num = 0;
int i = 0;
int j = 0;
int test;

string Command[100] = {};
string Output[100] = {};
string Char[100] = {};
int time[100] = {};

cin >> num; 
for(i=0;i<num;i++){
	cin >> Command[i] >> Char[i] >> time[i];
	if(Command[i] == "type"){
		
		Output[time[i]-1] = Char[i];
		
	}else if(Command[i] == "undo"){
		int Count = atoi(Char[i].c_str());
		int b = time[i] - 1;
		while(Count--){
			int j = 0;
			for(j=0;j<num;j++){
				if(Command[j] == "type" and time[j] == b){
					Output[j] = "";
				}else if(Command[j] == "undo" and time[j] == b){
					int Count2 = atoi(Char[j].c_str());
					int bb = time[j] - 1;
					while(Count2--){
						int k = 0;
						for(k=0;k<num;k++){
							if(Command[k] == "type" and time[k] == bb){
								Output[k] = Char[bb-1];

							}
						}
						bb = bb -1;
					}
				}
			}
			b = b - 1;
		}
	}
} 

for(j=0;j<time[num-1];j++){
	cout << Output[j];	
}

return 0;
}
