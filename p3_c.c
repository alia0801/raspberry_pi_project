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


    //��Kernel�إ�Socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    // AF_INET = IPv4 ��w
    // SOCK_STREAM = TCP
    // 0 = default(kernel�N�ھ�SOCK_STREAM����)

    if (sock == -1)
        printf("Could not create socket\n");

    printf("Socket created\n");

    //�]�wSocket server�Ӹ`
    server.sin_family = AF_INET;  //IPv4��w
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //�M�w�s�u��IP address
    server.sin_port = htons( 8888 );  //port

    //�PServer�i��s�u
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error\n");
        return 1;
    }

    printf("Connected\n");

    //�ǳƤ@��Message
    printf("Enter string: ");
    //stdin:Ū����L��buffer
    fgets(message,sizeof(message),stdin);

    //�o�eMessage��server��
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        printf("Send failed\n");
        return 1;
    }
    printf("client send:");
    printf("%s\n",message);

    //����Server���T���Fbuf=2000�F0=default
    if( recv(sock , server_reply , 2000 , 0) < 0)
        printf("recv failed\n");

    printf("client receive:");
    printf("%s",server_reply);

    close(sock);
    return 0;
  }

