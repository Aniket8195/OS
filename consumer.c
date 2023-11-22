#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME1 "comm_pipe1"
#define FIFO_NAME2 "comm_pipe2"

int main(){
    char s[300],vowel[20],send[200];
    int num,fd1,fd2,sig,k=0,i,wordcnt=1,charcnt=0,linecnt;
    FILE *fp;

    fp = fopen("fifo.txt","w");

    mknod(FIFO_NAME1, S_IFIFO | 0666, 0);
    mknod(FIFO_NAME2, S_IFIFO | 0666, 0);

    printf("Wating for producer ...\n");
    fd1 = open(FIFO_NAME1, O_RDONLY);
    fd2 = open(FIFO_NAME2, O_WRONLY);
    printf("Got a producer\n");

    if((num = read(fd1, s, 300)) == -1){
        perror("Read");
    }else{
        s[num] = '\0';
        printf("tick ; read %d bytes :\"%s\"\n",num,s);
        k=0;
        vowel[0]='\0';
        wordcnt = 1;

        for (i=0;i<num;i++){
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')){
                vowel[k] = s[i];
                k++;
            }
            if(s[i]== ' ' && s[i+1]!= ' '){
                wordcnt++;
            }
            if(s[i]=='\n'){
                linecnt++;
            }
            charcnt++;
        }
    }

    vowel[k] = '\0';
    printf("Vowel : %s\n",vowel);
    printf("Word Count : %d\n", wordcnt);
    printf("Character Count : %d\n", charcnt);
    printf("Line Count : %d\n", linecnt);

    sprintf(send, "Vowel : %s\n Word Count : %d\n Character Count : %d\n Line Count : %d\n",vowel,wordcnt,charcnt,linecnt);
    write(fd2,send,strlen(send));

    fclose(fp);
    close(fd1);
    close(fd2);

    return 0;
}