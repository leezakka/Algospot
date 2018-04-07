#include <iostream>
using namespace std;

bool hasWord(int x, int y, string str);
bool isOutOfRange(int x, int y);
void howToRun();

int dx[8] = {1,0,1,1,1,0,-1,-1};
int dy[8] = {-1,-1,-1,0,1,1,1,0};
char wordField[5][5] =
{{'U','P','L','R','M'}, 
 {'X','P','R','E','T'}, 
 {'G','I','A','E','T'}, 
 {'X','T','N','Z','Y'}, 
 {'X','O','Q','R','S'}};

static const int limitRange = 5;

int main(int argc, char *argv[]) {

  if (argc != 2) {
		howToRun();
    cout<<"Terminated!!"<<endl;
    return 0;
  }

  string userStr = argv[1];

  for(int y=0; y<limitRange; y++) 
    for (int x=0; x<limitRange; x++) 
      if(hasWord(x, y, userStr))
          cout<<"has Word..!!"<<endl;

  return 0;
}

bool hasWord(int x, int y, string userStr) {

  if (userStr[0] != wordField[x][y])
    return false;

  if (userStr.length() == 1)
    return true;
  
  if (!isOutOfRange(x, y))
    return false;


  for(int pos=0; pos<8; pos++) {
    int nextX = x + dx[pos];
    int nextY = y + dy[pos];

    if(hasWord(nextX, nextY, userStr.substr(1)))
      return true;
  }

  return false;
}

bool isOutOfRange(int x, int y) {

  if ( x > limitRange || y > limitRange ) {
    return false;
  }

  return true;
}

void howToRun() {
	cout<<"./Boggle WORD"<<endl;
}
