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
//A 
    num[0][0]=1;
    num[0][1]=1;
    num[0][2]=1;
    num[0][3]=0;
    num[0][4]=1;
    num[0][5]=1;
    num[0][6]=1;
//P 
    num[1][0]=1;
    num[1][1]=1;
    num[1][2]=0;
    num[1][3]=0;
    num[1][4]=1;
    num[1][5]=1;
    num[1][6]=1;
//P 
    num[2][0]=1;
    num[2][1]=1;
    num[2][2]=0;
    num[2][3]=0;
    num[2][4]=1;
    num[2][5]=1;
    num[2][6]=1;
//L 
    num[3][0]=0;
    num[3][1]=0;
    num[3][2]=0;
    num[3][3]=1;
    num[3][4]=1;
    num[3][5]=1;
    num[3][6]=0;
//E 
    num[4][0]=1;
    num[4][1]=0;
    num[4][2]=0;
    num[4][3]=1;
    num[4][4]=1;
    num[4][5]=1;
    num[4][6]=1;

}
 

