#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char **argv)
{
 int max=3000, s,i,ret;
 struct sockaddr_in serv;

 s=socket(AF_INET, SOCK_STREAM, 0);
 if(s < 0)
 {
  printf("Socket failed \n");
  return -1;
 }
 
 serv.sin_addr.s_addr = inet_addr(argv[1]);
 serv.sin_family = AF_INET;

 for(i = 0; i < max; i++)
 {
  serv.sin_port = htons(i);
  ret = connect(s, (struct sockaddr *)&serv,sizeof(serv));
  if(ret == 0)
  {
   printf("Service on %d\n", i);
  }

 }
 close(s);
 return 0;
}

