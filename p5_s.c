#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
    char temp[2000];


    //��Kernel�إ�Socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    // AF_INET = IPv4 ��w
    // SOCK_STREAM = TCP�Ҧ�
    // 0 = default(auto)

    if (socket_desc == -1)
        printf("Could not create socket\n");

    printf("Socket created\n");

    //�]�wSocket server�Ӹ`
    server.sin_family = AF_INET;  //IPv4 ��w
    server.sin_addr.s_addr = INADDR_ANY;  //�浹Kernel�M�wServer IP
    server.sin_port = htons( 8888 );  //port

    //�i��Socket server�t�m
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("bind failed. Error");
        return 1;
    }
    printf("bind done\n");

    //Listen:�M�w�h��Client�i�s�J��Socket server
    listen(socket_desc , 3);

    //����Client�n�J
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);

    //�P�N��Client�ݵn�J
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);

    if (client_sock < 0){
        perror("accept failed\n");
        return 1;
    }

    printf("Connection accepted\n");
    
    int n1,n2,ans;
	char op;
    //Ū��Client��Message�Fbuf=2000�F0=default
    if( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 ){
    	
    	n1 = client_message[0] -'0';
    	op = client_message[1];
    	n2 = client_message[2] -'0';
    	if(op=='+'){
    		ans = n1+n2;
		}
		else if(op=='-'){
    		ans = n1-n2;
		}
		else if(op=='*'){
    		ans = n1*n2;
		}
		else if(op=='/'){
    		ans = n1/n2;
		}
    	temp[0] = (char)ans;
    	//�NClient�ǿ骺message�^�ǵ�Client��
        write(client_sock , temp , strlen(temp));
	}
        

    if(read_size == 0)
        printf("Client is disconnected?\n");

    else if(read_size == -1)
        printf("recv failed");

    return 0;
}
