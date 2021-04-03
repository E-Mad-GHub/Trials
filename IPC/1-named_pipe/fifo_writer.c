#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


#define MaxLoops 12000 /* outer loop */
#define ChunkSize 16 /* how many written at a time */
#define IntsPerChunk 4 /* four 4-byte ints per chunk */
#define MaxZs 250 /* max microseconds to sleep */


int main() {
	const char* pipeName = "./fifoChannel";

	printf("Here 1\n");	

	mkfifo(pipeName, 0666); /* read/write for user/group/others */

	printf("Here 2\n");	

	int fd = open(pipeName, O_CREAT | O_WRONLY); /* open as write-only */

	printf("Here 3\n");	

	if (fd < 0) return -1; /* can't go on */
	
	printf("Here 4\n");	

	int i;
	for (i = 0; i < MaxLoops; i++) { /* write MaxWrites times */
		
		int j;
		for (j = 0; j < ChunkSize; j++) { /* each time, write ChunkSize bytes */
			
			int k;
			int chunk[IntsPerChunk];
			for (k = 0; k < IntsPerChunk; k++)
				chunk[k] = rand();

			printf("Here 5\n");	

			write(fd, chunk, sizeof(chunk));

			printf("Here 6\n");	

		}

		usleep((rand() % MaxZs) + 1); /* pause a bit for realism */
	}

	printf("Here 7\n");	

	close(fd); /* close pipe: generates an end-of-stream marker */

	printf("Here 8\n");	

	unlink(pipeName); /* unlink from the implementing file */

	printf("Here 9\n");	

	printf("%i ints sent to the pipe.\n", MaxLoops * ChunkSize * IntsPerChunk);
	return 0;
}
