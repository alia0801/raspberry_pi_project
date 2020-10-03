#include <wiringPi.h>
int main(void)
{
  wiringPiSetup() ;
  pinMode (12, OUTPUT) ;//B
  pinMode (13, OUTPUT) ;//A
  pinMode (14, OUTPUT) ;//F
  pinMode (30, OUTPUT) ;//G
  pinMode (21, OUTPUT) ;//C
  pinMode (22, OUTPUT) ;//D
  pinMode (23, OUTPUT) ;//E

  void init(int num[10][7]);
  int num[10][7];
  int i;

  init(num);
  for(i=0;;i++)
  {
    if(i==10){
        i=0;
    }
    digitalWrite(13,num[i][0]);
    digitalWrite(12,num[i][1]);
    digitalWrite(21,num[i][2]);
    digitalWrite(22,num[i][3]);
    digitalWrite(23,num[i][4]);
    digitalWrite(14,num[i][5]);
    digitalWrite(30,num[i][6]);
    delay(800);
  }
}
void init(int num[10][7]){
//0
    num[0][0]=0;
    num[0][1]=0;
    num[0][2]=0;
    num[0][3]=0;
    num[0][4]=0;
    num[0][5]=0;
    num[0][6]=1;
//1
    num[1][0]=1;
    num[1][1]=0;
    num[1][2]=0;
    num[1][3]=1;
    num[1][4]=1;
    num[1][5]=1;
    num[1][6]=1;
//2
    num[2][0]=0;
    num[2][1]=0;
    num[2][2]=1;
    num[2][3]=0;
    num[2][4]=0;
    num[2][5]=1;
    num[2][6]=0;
//3
    num[3][0]=0;
    num[3][1]=0;
    num[3][2]=0;
    num[3][3]=0;
    num[3][4]=1;
    num[3][5]=1;
    num[3][6]=0;
//4
    num[4][0]=1;
    num[4][1]=0;
    num[4][2]=0;
    num[4][3]=1;
    num[4][4]=1;
    num[4][5]=0;
    num[4][6]=0;
//5
    num[5][0]=0;
    num[5][1]=1;
    num[5][2]=0;
    num[5][3]=0;
    num[5][4]=1;
    num[5][5]=0;
    num[5][6]=0;
//6
    num[6][0]=1;
    num[6][1]=1;
    num[6][2]=0;
    num[6][3]=0;
    num[6][4]=0;
    num[6][5]=0;
    num[6][6]=0;
//7
    num[7][0]=0;
    num[7][1]=0;
    num[7][2]=0;
    num[7][3]=1;
    num[7][4]=1;
    num[7][5]=0;
    num[7][6]=1;
//8
    num[8][0]=0;
    num[8][1]=0;
    num[8][2]=0;
    num[8][3]=0;
    num[8][4]=0;
    num[8][5]=0;
    num[8][6]=0;
//9
    num[9][0]=0;
    num[9][1]=0;
    num[9][2]=0;
    num[9][3]=0;
    num[9][4]=1;
    num[9][5]=0;
    num[9][6]=0;
}
 
