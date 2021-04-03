#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include <string.h>

//#define SOCKET_NAME "/tmp/9Lq7BNBnBycd6nxy.socket"
#define SOCKET_NAME "./my.socket"

#define MAXMSG 255

int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, clilen;
   char buffer[256];
   struct sockaddr_un serv_addr;  // _un for UNIX socket, _in for INET socket
   int n, pid;
   char message[MAXMSG];
   /*
    * In case the program exited inadvertently on the last run,
    * remove the socket.
    */

   unlink(SOCKET_NAME);

   /* First call to socket() function */
   sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
   
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

   printf("Client-1 Socket ID: %s\n",serv_addr.sun_path);

   /* Now start listening for the clients, here
      * process will go in sleep mode and will wait
      * for the incoming connection
   */

/* NO "listen" IN DGRAM SEND
  
   if (listen(sockfd,5) == -1) {
       perror("listen");
       exit(1);
   }
*/
 
   while (1) {

/* NO "accept" IN DGRAM SEND

      newsockfd = accept(sockfd, NULL, NULL);
		
      if (newsockfd < 0) {
         perror("ERROR on accept");
         exit(1);
      }
*/

      int size = sizeof (serv_addr);
      int nbytes = recvfrom (sockfd, message, MAXMSG, 0, (struct sockaddr *) &serv_addr, &size);

      if (nbytes < 0){
         perror ("recfrom (server)");
         exit (1);
      }

      printf("\n\n------------------------------------------\nNew Message\n\n");
      
      if (message != NULL) {
         printf("New message: %s\n",message);
         n = sendto (sockfd, "I got your message", 18, 0, (struct sockaddr *) &serv_addr, size);

         if (n < 0)
         {
            perror ("sendto (server)");
            exit (EXIT_FAILURE);
         }
      }
      else {
         close(newsockfd);
      }
		
   } /* end of while */
}

