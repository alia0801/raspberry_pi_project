#include <fcntl.h> // for open
#include <unistd.h> // for close
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include <wiringPi.h>

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];


    //於Kernel建立Socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    // AF_INET = IPv4 協定
    // SOCK_STREAM = TCP
    // 0 = default(kernel將根據SOCK_STREAM對應)

    if (sock == -1)
        printf("Could not create socket\n");

    printf("Socket created\n");

    //設定Socket server細節
    server.sin_family = AF_INET;  //IPv4協定
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //決定連線的IP address
    server.sin_port = htons( 8888 );  //port

    //與Server進行連線
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error\n");
        return 1;
    }

    printf("Connected\n");

    //準備一組Message
    printf("Enter message : ");
    //stdin:讀取鍵盤的buffer
    fgets(message,sizeof(message),stdin);

    //發送Message給server端
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        printf("Send failed\n");
        return 1;
    }
    printf("Send successed\n");

    //接收Server的訊息；buf=2000；0=default
    if( recv(sock , server_reply , 2000 , 0) < 0)
        printf("recv failed\n");

    printf("Server reply :");
    printf("%s",server_reply);
    
    wiringPiSetup() ;
    pinMode (12, OUTPUT) ;//B
    pinMode (13, OUTPUT) ;//A
    pinMode (14, OUTPUT) ;//F
    pinMode (30, OUTPUT) ;//G
    pinMode (21, OUTPUT) ;//C
    pinMode (22, OUTPUT) ;//D
    pinMode (23, OUTPUT) ;//E

  void init(int num[5][7]);
  int num[5][7];
  int i;

  init(num);
  for(i=0;;i++)
  {
    if(i==5){
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
    
    close(sock);
    return 0;
}
  
  
  
  void init(int num[5][7]){
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
 

