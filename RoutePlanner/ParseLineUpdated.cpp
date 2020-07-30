#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

enum class state{
	kEmpty,
	kObstacle
};
string CellString(state a){
	
	if(a==state::kEmpty){
		return "0";
	}
	else
	  return "f";
}

vector<state> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<state> row;
    while (sline >> n >> c && c==',') {
      switch(n){
      	case 0:
      		row.push_back(state::kEmpty);
      		break;
      	case 1:
      		row.push_back(state::kObstacle);
      		break;
	  }
    }
    return row;
}
vector<vector <state>> ReadBoardFile(string path){
	string text;
	vector<vector<state>> board;
	ifstream myfile(path);
	if(myfile){
		while(getline(myfile,text)){
			vector<state> int_line=ParseLine(text);
			board.push_back(int_line);
		}
	}
	return board;
}
void PrintBoard(vector<vector<state>> board){
	int i,j;
	for(i=0;i<board.size();i++){
		for(j=0;j<board[i].size();j++){
			cout<<CellString(board[i][j])<<" ";
		}
		cout<<endl;
	}
}


int main(){
	vector<vector<state>> board=ReadBoardFile("Board1.txt");
	PrintBoard(board);
}
