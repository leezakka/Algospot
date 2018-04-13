#include <iostream>
#include <string>
using namespace std;

bool RecursiveFindWord( int y, int x, string &word);
char board[5][5] = { {'U','R','L','P','M'} , {'X','P','R','E','T'}, {'G','I','A','E','T'}, {'X','T','N','Z','Y'}, {'X','O','Q','R','S'} };
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

int main()
{
	string str = "KARA";

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			if ( RecursiveFindWord( i, j, str ))
			cout << "Function complete!!" << endl;
		}
	}

	return 0;
}

bool RecursiveFindWord( int y, int x, string &word )
{
	// base case;
	if( board[y][x] != word[0] )
		return false;

	if( word.size() == 1 )
	{
		cout << "true!!" <<endl;
		return true;
	}

	for( int i=0; i<8; ++i )
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		
		string nextStr = word.substr(1);
		
		if( RecursiveFindWord( nextY, nextX, nextStr ) )
			return true;
	}
	return false;
}
