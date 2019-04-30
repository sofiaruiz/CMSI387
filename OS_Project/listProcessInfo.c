#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>

#include "processInfo.h"

asmlinkage long sys_listProcessInfo(void) {

    struct task_struct *task;
 
    for_each_process(task) {
 
	    printk(
	      "Process: %s\n \
	       Process ID: %ld\n \
	       Process State: %ld\n \
	       Priority: %ld\n \
	       Start Time: %llu\n \
	       Time in User Mode: %ld\n \
	       Time in System Mode: %ld\n", \
	       task->comm, \
	       (long)task_pid_nr(task), \
	       (long)task->state, \
	       (long)task->prio, \
		task->start_time,
	       (long)task->utime, \
	       (long)task->stime
	    );
  
  }
  
  return 0;
}
