#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int sock;
	int str_len;
	struct sockaddr_in serv_adr;
	int t=6000;
	int i=0;
	int serv_sock, clnt_sock;
	struct clnt_adr;
	char* a="10.10.141.52";
	pid_t pid;
//	socklen_t adr_sz;
	int state;
	int message=1;
	char BUF[message];
	int total=10;
	int b;
	int T1;
	char msg[10];
	int man=1;
	int woman=1;
	int ms,ws;
	while(1)
	{
		int n=2; // 이거 외의 client 수
			
		man++;
		woman++;
		if(man>10)
			man=1;
		
		if(woman>10)
			woman=2;
		
		ms=((float)man/(float)total)*100;
		ws=((float)woman/(float)total)*100;
		if (ms<40)
		{
			if(ws<40)
				strcpy(msg, "I");
			else if(40<=ws && ws<80)
				strcpy(msg, "J");
			else if(80<=ws)
				strcpy(msg, "L");
		}
		else if (40<=ms && ms<80)
		{
			if(ws<40)
				strcpy(msg, "Q");
			else if(40<=ws && ws<80)
				strcpy(msg, "R");
			else if(80<=ws)
				strcpy(msg, "T");
		}
		else if(80<=ms)
		{
			if(ws<40)
				strcpy(msg, "a");
			else if(40<=ws && ws<80)
				strcpy(msg, "b");
			else if(80<=ws)
				strcpy(msg, "d");
		}
		else
			printf("error");
		
		printf("as\n");
		printf("%d,%d",man,woman);
		sock=socket(PF_INET, SOCK_STREAM, 0);
		//		printf("%d	q\n",sock);
		memset(&serv_adr, 0, sizeof(serv_adr));
		//			printf("%ld	Q\n",sizeof(serv_adr));
		serv_adr.sin_family=AF_INET;
		serv_adr.sin_addr.s_addr=inet_addr(a);
		serv_adr.sin_port=htons(t);
		while(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))<0)
		{
			sleep(5);
			printf("%d\n",t);	
		}
		write(sock,msg,strlen(msg));
		printf("%ld\n",strlen(msg));
		sleep(5);
		read(sock,msg,10);
		T1=atoi(msg);
		printf("aaaa: %s\n",msg);
		msg==0;
		t=T1;
		sleep(3);
		puts("connected..........\n");
		close(sock);
		sleep(10);
	}
}
