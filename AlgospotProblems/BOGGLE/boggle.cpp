/***********************************
 * Time out -> need to improve Quality
 * ********************************/


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

bool hasWord(int x, int y, string str);
bool isOutOfRange(int x, int y);
void howToRun();

int dy[8] = { 1, 1, 1, 0,-1 ,-1 ,-1, 0};
int dx[8] = {-1, 0 ,1, 1, 1 , 0 ,-1,-1};
char wordField[5][5];
static const int limitRange = 5;

int main() {

	int testCase = 0;
	int retSum = 0;
	string wordStr;

	// get TestCase Cnt
	printf("Input Test Case : ");
	scanf("%d", &testCase);

	if ((testCase < 1) || (testCase > 50))
		return -1;

	for (int gameCnt = 0; gameCnt < testCase ; gameCnt++) {

		// Insert Boggle Map
		printf("Input BOGGLE MAP\n");
		for (int lineCnt = 0; lineCnt < limitRange; lineCnt++) {
			cin >> wordStr;
			// WordField Limit 
			if ((wordStr.length() <= 0) || (wordStr.length() != limitRange))
				exit(0);

			memcpy(wordField[lineCnt], wordStr.data(), wordStr.length());
    }

		// Input WORD to check
	  int wordCnt;
		printf("Input Word Count : ");
		scanf("%d", &wordCnt);
		for(int loopCnt = 0; loopCnt < wordCnt; loopCnt++) {
		  // Initailize	
			retSum = 0;
			string userStr;
			cin >> userStr;

			// UserStr Limit
			if ((userStr.length() < 1) || (userStr.length() > 10))
				exit(0);

			// Main Process
      for(int y=0; y<limitRange; y++) 
        for (int x=0; x<limitRange; x++)
					if (hasWord(y, x, userStr))
						retSum++;

			// Output
      if (retSum > 0)
		  	printf("%s YES\n", userStr.data());
		  else
		  	printf("%s NO\n", userStr.data());
		}
	} 
  return 0;
}

bool hasWord(int y, int x, string userStr) {

  if (userStr[0] != wordField[y][x])
    return false;

  if (userStr.length() == 1)
    return true;
  
  if (!isOutOfRange(y, x))
    return false;

  for(int pos=0; pos<8; pos++) {
    int nextX = x + dx[pos];
    int nextY = y + dy[pos];

    if(hasWord(nextY, nextX, userStr.substr(1)))
      return true;
  }
  return false;
}

bool isOutOfRange(int y, int x) {

  if ( x > limitRange || y > limitRange ) {
    return false;
  }

  return true;
}
