#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Function 1:
void ReadBoardFile(string path){
	string text;
	
	ifstream myfile(path);
	
	while(getline(myfile,text)){
		cout<<text<<" ";
		cout<<endl;
	}
	myfile.close();
}

//Function 2:
void PrintBoard(vector<vector<int>> board){
	int i,j;
	for(i=0;i<board.size();i++){
		for(j=0;j<board.size();j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

//Function 3:
vector<int> ParseLine(string line)
{
  istringstream line_stream(line);
  
  char c;
  int n;
  vector<int> vec;
  while (line_stream >> n >> c && c == ',') {
    vec.push_back(n);
  }
  
  return vec;
}


int main(){
	ReadBoardFile("Board.txt");
}
