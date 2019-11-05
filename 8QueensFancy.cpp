#include<iostream>
#include<cmath>
using namespace std;

typedef char box[5][7];

bool ok(int q[], int col);
void backtrack(int &col);
void print(int q[]);

int main(){
	int q[8]={}, c=0;
	
	q[0]=0;
	
	while(c>=0){
		c++;
		if(c==8){
			print(q);
			backtrack(c);
		}
		else {
			q[c]=-1;
		}
		while(c>=0){
			q[c]++;
			if(q[c]==8){
				backtrack(c);
			}	
			else{
				if(ok(q,c)) break;
			}
		}		
	}
	
return 0;
}

bool ok(int q[], int col){
    for(int i=0;i<col;i++){ 
        if((q[i] == q[col]) || (abs(q[col] - q[i]) == abs(col - i))) return false;
    }
    return true;
}
    
void backtrack(int &col){
    col--;
        if(col==-1) exit(0);
}

void print(int q[]) {
	
	static int numSolutions = 0;
   	numSolutions++;
   	cout << "Solution #" <<  numSolutions << ": ";
   	cout << endl;
	
	static char c=char(219);
	
	box wq,bq;
	for(int i=0;i<5;i++){
		for(int j=0;j<7;j++){
			wq[i][j]=char(219);
			bq[i][j]=' ';;
		}
	}
	wq[1][1]=' '; bq[1][1]=char(219);
	wq[1][3]=' '; bq[1][3]=char(219);
	wq[1][5]=' '; bq[1][5]=char(219);
	wq[2][1]=' '; bq[2][1]=char(219);
	wq[2][3]=' '; bq[2][3]=char(219);
	wq[2][5]=' '; bq[2][5]=char(219);
	wq[3][1]=' '; bq[3][1]=char(219);
	wq[3][2]=' '; bq[3][2]=char(219);
	wq[3][3]=' '; bq[3][3]=char(219);
	wq[3][4]=' '; bq[3][4]=char(219);
	wq[3][5]=' '; bq[3][5]=char(219);
	
	
	
	box wb,bb,*board[8][8];
	
	for(int i=0;i<5;i++){						//fill in bb and wb
		for(int j=0;j<8;j++){
			wb[i][j]=' ';
			bb[i][j]=char(219);
		}
	}
	
	for(int i=0;i<8;i++){						//fill in board with pointers to wb and bb alternatively
		for(int j=0;j<8;j++){
			if((i+j)%2==0){
				board[i][j]=&wb;
			}
			else {
				board[i][j]=&bb;
			}
		}
	}
	
	for(int i=0;i<8;i++){						//modify board according to current solution				
		for(int j=0;j<8;j++){
			if(j==q[i] && (i+j)%2==0) board[i][j]=&bq;
			else if(j==q[i] && (i+j)%2!=0) board[i][j]=&wq;			
		}
	}
	
	//print board solution
	//first print upper border
	cout<<" "<<" ";
	for(int i=0;i<7*8;i++){
		cout<<'_';
	}
	cout<<endl;
	
	//print the board
	for(int i=0;i<8;i++){
		for(int k=0;k<5;k++){
			cout<<" "<<char(179); 				//print left border
			for(int j=0;j<8;j++){
				for(int l=0;l<7;l++){
					cout<<(*board[i][j])[k][l];
				}
			}
		cout<<char(179)<<endl;					//at the end of line, print bar and then newline
		}
	}
	
	//before exiting print lower border
	cout<<"  ";
	for(int i=0;i<7*8;i++){
		cout<<char(196);
	} // done printing board;
	cout<<endl;
}







