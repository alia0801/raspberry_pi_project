#include <fcntl.h> // for open
#include <unistd.h> // for close
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr

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
    printf("Enter string: ");
    //stdin:讀取鍵盤的buffer
    fgets(message,sizeof(message),stdin);

    //發送Message給server端
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        printf("Send failed\n");
        return 1;
    }
    printf("client send:");
    printf("%s\n",message);

    //接收Server的訊息；buf=2000；0=default
    if( recv(sock , server_reply , 2000 , 0) < 0)
        printf("recv failed\n");

    printf("client receive:");
    printf("%s",server_reply);

    close(sock);
    return 0;
  }

