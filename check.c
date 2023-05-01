#include<linux/kernel.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define __NR_sleepingbarber 449

long sleepingbarber_syscall(void)
{
	return syscall(__NR_sleepingbarber);
}

int main(int argc,char *argv[])
{
long activity;
activity=sleepingbarber_syscall();

if(activity <0)
{
	perror("Your sleeping barber system call is not working");
}
else
{
	printf("Congrats!! your sleeping barber system call is working");
}

}
