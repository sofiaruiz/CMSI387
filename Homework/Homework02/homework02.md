# Homework 02

2. This would be a bug because if the state changes between the time getSeatsRemaining() is called and getCashOnHand() is called then seatsRemaining would refer to a different state than cashOnHand, instead of both variables referring to the same state as intended. 

4. Program can be found in BoundedBuffer4.java

6. The virtual address for the first 4-byte word of page 6 is __12288__ and the one for the last 4-byte words of page 6 is __16380__. These virtual addresses translate to the physical addresses: 12288+4096=__16384__ for the first 4-byte word and 16380+4096=__20476__ for the last 4-byte word. 

7. In figure 6.13, the page numbers 1047552 and 1047553 were calculated because the last page is 1023, so if you multply 1023 by 1024 (because pages can point to 1024 page frames) you get those pages. 

8. Write a program that loops many times, each time using an inner loop to access every 4096th element of a large array of bytes. Time how long your program takes per array access. Do this with varying array sizes. Are there any array sizes when the average time suddenly changes? Write a report in which you explain what you did, and the hardware and software system context in which you did it, carefully enough that someone could replicate your results.  
To write this program, I first used classwork 6 in which we had already ceated a timer for an array of bytes. The difference is that in this program I timed how long it took to access every 4096th element in the array. To do that, I made a loop that started of at 0 and then added 4096 everytime it ran (accessing the 4096th element every time). In the loop, I first started the clock and then I accessed the array at the element i, then once the element had been accessed the clock was stopped. I then had an array of times that contained the cpu time used everytime the loop was run. To get the average sum, I added together all of the times stored in the times array and then divided that by the length of the array. My program prints the size allocated (which is passed in on the command line), the times array, and at the end the average time. I am running this program on a mac. 
