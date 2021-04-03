#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include <string.h>

//#define SOCKET_NAME "/tmp/9Lq7BNBnBycd6nxy.socket"
#define SOCKET_NAME "./my.socket"

void doprocessing (int sock) {
   int n;
   char buffer[256];
   bzero(buffer,256);
   n = read(sock,buffer,255);
   
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }
   
   printf("Here is the message: %s\n",buffer);
   n = write(sock,"I got your message",18);
   
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
	
}




int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, clilen;
   char buffer[256];
   struct sockaddr_un serv_addr;  // _un for UNIX socket, _in for INET socket
   int n, pid;

   /*
    * In case the program exited inadvertently on the last run,
    * remove the socket.
    */

   unlink(SOCKET_NAME);

   /* First call to socket() function */
   sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   
   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   
   serv_addr.sun_family = AF_UNIX;
   strncpy(serv_addr.sun_path, SOCKET_NAME, sizeof(serv_addr.sun_path) - 1);
   
   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }

   printf("Server Socket ID: %s\n",serv_addr.sun_path);

   /* Now start listening for the clients, here
      * process will go in sleep mode and will wait
      * for the incoming connection
   */
   
   
   if (listen(sockfd,5) == -1) {
       perror("listen");
       exit(1);
   }
   
   while (1) {
      newsockfd = accept(sockfd, NULL, NULL);
		
      if (newsockfd < 0) {
         perror("ERROR on accept");
         exit(1);
      }

      printf("\n\n------------------------------------------\nNew Client\n\n");
      
      /* Create child process */
      pid = fork();
		
      if (pid < 0) {
         perror("ERROR on fork");
         exit(1);
      }
      
      if (pid == 0) {
         /* This is the client process */
         close(sockfd);
         doprocessing(newsockfd);
         exit(0);
      }
      else {
         close(newsockfd);
      }
		
   } /* end of while */
}

