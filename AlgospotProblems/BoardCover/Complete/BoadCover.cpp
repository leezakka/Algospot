#include <iostream>
//-----------------
int Cover(int board[][20]);
bool CheckType(int board[][20], int y, int x, int type, int delta);
//-----------------
int height, width;
const int coverType[4][3][2] = {
	{ {0,0}, {1,0}, {0,1} },
	{ {0,0}, {0,1}, {1,1} },
	{ {0,0}, {1,0}, {1,1} },
	{ {0,0}, {1,0}, {1,-1} }
};
//-----------------
int main() {

  int board[20][20];
	char bw[20];
	int caseCnt;
  int zeroCnt = 0;
	int blockCnt = 0;
	int retNo = 0;

	printf("Input Case : ");
	scanf("%d", &caseCnt);

	if (caseCnt < 0 || caseCnt > 30)
		exit(-1);

	for(int c=0; c<caseCnt; c++) {

		// Initialize
		height = 0; width = 0; zeroCnt = 0; blockCnt = 0;

		// Input Height, Width
		printf("Input H,W : ");
		scanf("%d %d", &height, &width);

		if (height < 1 || height > 20 || width < 1 || width > 20)
			exit(-1);

		// Input Board
		printf("Input Your Board..\n");
	  for(int i=0; i<height; i++) {
      scanf("%s", bw);

			for(int j=0; j<width; j++)  {
        board[i][j] = ( bw[j] == '#') ? 1 : 0;
				if (board[i][j] ==  0)
					zeroCnt++;
				else
				  blockCnt++;	
			}
		}

		if (zeroCnt > 50) 
			exit(-1);

    // Call Cover Function
    if (blockCnt == height * width)
	    retNo = 1;
		else
			retNo = Cover(board);

		printf("Resolution Count : %d\n", retNo);
  }

	return 0;
}

bool CheckType(int board[][20], int y, int x, int type, int delta)
{
	bool retNo = true;

	for (int dirCnt = 0; dirCnt < 3; dirCnt++) {
		int nx = x + coverType[type][dirCnt][1];
		int ny = y + coverType[type][dirCnt][0];

	if ( (board[ny][nx] += delta) > 1)
		retNo = false;
	else if ( nx < 0 || ny < 0 || nx >= width || ny >= height)
		retNo = false;
  }

	return retNo;
}

int Cover(int board[][20]) {

	int x = -1, y = -1;

	for (int h=0; h<height; h++) {
		for(int w=0; w<width; w++)
			if (board[h][w] == 0) {
				x = w;
		    y = h; 
				break;
		  }
  	if (y != -1)
				break;
  }

	if (y == -1)
		return 1;

	int retNo = 0;
	
	for(int typeCnt = 0; typeCnt < 4; typeCnt++) {
		if (CheckType(board, y, x, typeCnt, 1))
			retNo += Cover(board);
		CheckType(board, y, x, typeCnt, -1);
	}

	return retNo;
}










