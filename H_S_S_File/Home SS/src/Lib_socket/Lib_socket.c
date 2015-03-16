/*
 ============================================================================
 Name        : socket_server.c
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 03/02/2015
 Description :
 ============================================================================
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_socket.h"

/*******************************************
*	          F U N C T I O N S            *
********************************************/
/*
 ============================================
 Function     : create_Socket()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int create_Socket(){
	int portno;
	struct sockaddr_in serv_addr;

	// Create Socket Server
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
		error("ERROR opening socket \n ");
	}

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = PORT_NUM;

	serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port =  htons(portno);

	// Bind
    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
		error("ERROR on binding \n ");
	}

	printf("	* Socket Create, port : %d \n" , portno);
	printf("	* Waiting for client Connection ..... \n");
	// Block Function
	listen(sockfd,5);

	return sockfd;
}

/*
 ============================================
 Function     : accept_client_connection()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int accept_client_connection(int sockfd){
	struct sockaddr_in cli_addr;
	socklen_t clilen;
	char *some_addr;

	clilen = sizeof(cli_addr);

    int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0){
		error("ERROR on accept \n ");
	}
    printf("	* Accept connection From a client,  :  " );

	some_addr = inet_ntoa(cli_addr.sin_addr); // return the IP
	printf(" %s\n", some_addr);

	return newsockfd;
}

/*
 ============================================
 Function     : write_socket()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void write_socket(int  newsockfd, char * sMessage, int iSize){

	int  n = write(newsockfd, sMessage, iSize);

	if (n < 0){
		error("ERROR writing to socket \n ");
	}
}

/*
 ============================================
 Function     : read_socket()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
unsigned char read_socket(int newsockfd){
	unsigned char u8Cmd[2] = {0};

	int n = read(newsockfd,u8Cmd,2);
    if (n < 0) {
		error("ERROR reading from socket \n");
	}

    //printf(" Here is the message: %d\n",u8Cmd[0]);

	return u8Cmd[0];
}
/*
 ============================================
 Function     : close_socket()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void close_socket(int sockfd, int newsockfd){
	// Close Socket
	close(newsockfd);
    close(sockfd);
	printf("	* Close Socket \n");
}
/*
 ============================================
 Function     : error()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

/*
 ============================================
 Function     : send_binary()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void send_binary(int newsockfd, char *file_name)
{

    int buff_size = 50240;		//10240;
    char buff[buff_size];
    FILE *pFile;
    size_t result;
    if ( (pFile = fopen(file_name, "rb")) == NULL){
        error("fopen error\n");
    }

    while (( result = fread( buff, 1, buff_size, pFile )) > 0 ) {
        send( newsockfd, buff, result, 0 );
    }


    /*
    if (result > 0){
        if(feof(pFile)){
            send(newsockfd, buff, result, 0);
        }
        else{
            error("read error\n");
        }
    }
    */

    fclose(pFile);

}
