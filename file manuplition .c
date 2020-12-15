#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
main(int ag,char*arg[])
{
char buf[100];
struct stat s;
int fd1,fd2,n;
fd1=open(arg[1],0);
fd2=creat(arg[2],0777);
stat(arg[2],&s);
if(fd2==-1)
printf("ERROR IN CREATION");
while((n=read(fd1,buf,sizeof(buf)))>0)
{
if(write(fd2,buf,n)!=n)
{
close(fd1);
close(fd2); } }
printf("\t\n UID FOR FILE.......>%d \n FILE ACCESSTIME.....>%s \n FILE MODIFIED TIME........>%s \n FILE I-NODENUMBER......>%d \n PERMISSION FOR FILE.....>%o\n\n",s.st_uid,ctime(&s.st_atime),ctime(&s.st_mtime),s.st_mode);
close(fd1);
close(fd2);
}
