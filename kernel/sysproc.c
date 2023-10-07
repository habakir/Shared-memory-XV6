#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "stddef.h"

int
sys_fork(void)
{
	return fork();
}

int
sys_exit(void)
{
	exit();
	return 0;  // not reached
}

int
sys_wait(void)
{
	return wait();
}

int
sys_kill(void)
{
	int pid;

	if(argint(0, &pid) < 0)
		return -1;
	return kill(pid);
}

int
sys_getpid(void)
{
	return myproc()->pid;
}

int
sys_sbrk(void)
{
	int addr;
	int n;

	if(argint(0, &n) < 0)
		return -1;
	addr = myproc()->sz;
	if(growproc(n) < 0)
		return -1;
	return addr;
}

int
sys_sleep(void)
{
	int n;
	uint ticks0;

	if(argint(0, &n) < 0)
		return -1;
	acquire(&tickslock);
	ticks0 = ticks;
	while(ticks - ticks0 < n){
		if(myproc()->killed){
			release(&tickslock);
			return -1;
		}
		sleep(&ticks, &tickslock);
	}
	release(&tickslock);
	return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
	uint xticks;

	acquire(&tickslock);
	xticks = ticks;
	release(&tickslock);
	return xticks;
}

int
sys_share(void)
{
    char *name;
    void *addr;
    int size;
	struct proc *curproc = myproc();
    int i;

    if(argstr(0, &name) < 0 || argint(2, &size) < 0 || argptr(1, (void**)&addr, size) < 0 ){
        return -1;
	}

	for(i = 0; i < 10; i++){
		if(strncmp(name, curproc->array[i].name, strlen(name)) == 0){
			return -2;
		}
	}

    for(i = 0; i < 10; i++){
        if(curproc->array[i].size == 0){
			int len = strlen(name);
			if(len > 20){
				len = 20;
			}
            strncpy(curproc->array[i].name, name, len);
            curproc->array[i].addr = addr;
            curproc->array[i].size = size;

            return i;
        }
    }
	return -3;
}

int sys_get(void){

    int i;
    char *name;
    void **addr;
    struct proc *curproc = myproc();

	if(argstr(0, &name) < 0 || argptr(1, (void**)&addr, 4) < 0){
    	return -1;
    }
	int len = strlen(name);
	if(len > 20){
		len = 20;
	}
	
  	for (i = 0; i < 10; i++){
    	if(strncmp(name, curproc->array[i].name, len) == 0){
     		*addr = curproc->array[i].addr;
      		return 0;
    	}
  	}

  	return -2;
}
