#### 1.1 – Description of modification/addition to Linux
We want to write a new system call that outputs records about descendant processes of a given process. Each process record will consist of some information about the process which will tell you sub-processes (child process) and the initiating processes (parent process), the process identifier, and the state and runtime statistics of the process.  

#### 1.2 – Rationale as to why this is a good idea, or what the good points of it are

This will keep track of processes running on a user's computer and how they relate to the scheduling. Will also be helpful to us because we will be able to understand the process hierarchy and we will learn to use the kernel data-structures.  

####  Preliminary list of [possible] Linux modules that will be modified/affected

We are not completely sure which modules will be affected, but this might depend on the fork which spawns a new process and will have the ID of the new process, and on weight which suspends the execution of the calling process until one of its children terminates.   

#### 1.4 – Preliminary list of any new modules that you will produce
Our new module will be called pro_rec, since it will be outputting a record of the processes running. 
