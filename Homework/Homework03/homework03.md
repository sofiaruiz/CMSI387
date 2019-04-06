# Homework 03

1. Write an implementation of the Dining Philosophers program, demonstrating deadlock avoidance.

Code can be found in "dining_philosophers.py"

2. Write a short paragraph explaining why your program is immune to deadlock?

The problem with the original dining philosophers problem is that if a philosopher sees one fork on the table they will pick it up, even if there is no other fork next to them, which can result in deadlock because there will never be enough forks for all of the philosophers to have two. In our implementation, the philosophers will only pick up a fork if there is another one for them to pick up, if they pick one up and they can't pick another one up they will immediately set it down for another philosopher to grab. This prevents deadlock. 

3. Modify the file-processes.cpp program from Figure 8.2 on page 338 to simulate this shell command:
```
tr a-z A-Z < /etc/passwd
```
Code can be found in "problem_three.c"

4. Write a program that opens a file in read-only mode and maps the entire file into the virtual-memory address space using mmap. The program should search through the bytes in the mapped region, testing whether any of them is equal to the character X. As soon as an X is found, the program should print a success message and exit. If the entire file is searched without finding an X, the program should report failure. Time your program on files of varying size, some of which have an X at the beginning, while others have an X only at the end or not at all.

Code can be found in "problem_four.cpp"

5. Read enough of Chapter 10 to understand the following description: In the TopicServer implementation shown in Figures 10.9 and 10.10 on pages 456 and 457, the receive method invokes each subscriber's receive method. This means the TopicServer's receive method will not return to its caller until after all of the subscribers have received the message. Consider an alternative version of the TopicServer, in which the receive method simply places the message into a temporary holding area and hence can quickly return to its caller. Meanwhile, a separate thread running in the TopicServer repeatedly loops, retrieving messages from the holding area and sending each in turn to the subscribers. What Java class from Chapter 4 would be appropriate to use for the holding area? Describe the pattern of synchronization provided by that class in terms that are specific to this particular application.

The Java class from Chapter 4 that would be appropriate to use for the holding area would be the Bounded Buffers class. In this sense, each time the receive method would place the messages into an intermediate storage area, the buffer. Then, a thread running in the TopicServer would loop and retrieve the messages from the buffer, thus sending them to the subscribers. In this regard, each thread will operate at its own pace. However, if the TopicServer thread finds an empty buffer it will need to wait for the receive method to catch up. By making the buffer a bounded buffer we would need to make the receive method wait if it gets too far ahead of the TopicServer thread and fills the buffer. These synchronization restrictions help to guarantee that the rate of the two threads will match up in the long run, but not necessarily in the short term.
