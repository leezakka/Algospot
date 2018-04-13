/***********************************
 * Time out -> need to improve Quality
 * ********************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool CheckIsBlk(int typeCnt, int y, int x, int board[][20], int weight);
int GetCountOfCover(int board[][20]);
void Initialize(int board[][20]);
int blockShape[4][3][2] = 
{ { {0,0}, {1,0}, {0,1} }, 
  { {0,0}, {1,0}, {1,1} }, 
  { {0,0}, {1,0}, {1,-1} }, 
  { {0,0}, {0,1}, {1,1} }, 
};

static const int maxWhiteBlk = 50;

int boardWidth;
int boardHeight;

int main() {

	int testCase = 0;
	int retSum = 0;
	int blockCnt = 0;
	int zeroCnt = 0;
	string lineStr;

	// get TestCase Cnt
	printf("Input Test Case : ");
	scanf("%d", &testCase);

	// Exception
	if ((testCase < 0) || (testCase > 30))
		return -1;

	for (int gameCnt = 0; gameCnt < testCase ; gameCnt++) {

		int board[20][20];
	  char bw[20];
    
		// initialize
	  blockCnt = 0; zeroCnt = 0; retSum = 0;
		boardHeight = 0; boardWidth = 0;
		memset(bw, 0x00, sizeof(bw));
		Initialize(board); 

		// Insert H W
		printf("Input HEIGHT WIDTH : ");
		scanf("%d %d", &boardHeight, &boardWidth);

	  // Exception
		if (boardHeight < 1 || boardHeight > 20 || boardWidth < 1 || boardWidth > 20)
				exit(0);

		// Input Line MAP
		printf("Input Line MAP ..\n");
		for(int lineCnt = 0; lineCnt < boardHeight; lineCnt++) { 
      
			scanf("%s", bw);
			lineStr.empty();
      lineStr = bw;
	    // Exception
			if (lineStr.length() <= 0 || lineStr.length() > boardWidth)
				exit(0);

			for(int widthCnt = 0; widthCnt < boardWidth; widthCnt++) {
	      // Exception
				if ((bw[widthCnt] != '#') && (bw[widthCnt] != '.'))
          exit(0);

				board[lineCnt][widthCnt] = ( bw[widthCnt] == '#' ) ? 1: 0;

				if (board[lineCnt][widthCnt] == 1) 	
					blockCnt++;
			  else
				  zeroCnt++;
      }
    } 

		if (zeroCnt > maxWhiteBlk)
			exit(0);

		// Main Process
    if (blockCnt == boardWidth * boardHeight)
		  retSum = 1;
    else 
			if (zeroCnt % 3 == 0)
      	retSum = GetCountOfCover(board);
			else
				retSum = 0;

		// Print Result;
    printf("RESULT Cnt: %d\n", retSum);
	} 
  return 0;
}

bool CheckIsBlk(int type, int y, int x, int board[][20], int weight) {

  int retNo = true;

	for( int dirCnt = 0; dirCnt < 3; dirCnt++) {
			int nextY = y + blockShape[type][dirCnt][0];
			int nextX = x + blockShape[type][dirCnt][1];

			// is Already Block
			if ((board[nextY][nextX] += weight) > 1)
      	retNo = false; 
		  else if (nextX < 0 || nextY < 0 || nextX >= boardWidth || nextY >= boardHeight)
				retNo = false;		
  }
  
	return retNo;
}

int GetCountOfCover(int board[][20]) {

	int retNo = 0;
	int curX = -1, curY = -1;

  for (int h=0; h<boardHeight; h++) {
    for(int w=0; w<boardWidth; w++)
      if (board[h][w] == 0) {
        curX = w;
        curY = h;
        break;
      }
    if (curY != -1)
        break;
  }

  if (curY == -1)
    return 1;

	for(int typeCnt = 0; typeCnt < 4; typeCnt++) {
	  if (CheckIsBlk(typeCnt, curY, curX, board, 1))
		  retNo += GetCountOfCover(board);
	  CheckIsBlk(typeCnt, curY, curX, board, -1);
	}

	return retNo;
}

void Initialize(int board[][20]) {
	// just Simple
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			board[i][j] = 1;
}










