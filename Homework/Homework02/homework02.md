# Homework 02

2. This would be a bug because if the state changes between the time getSeatsRemaining() is called and getCashOnHand() is called then seatsRemaining would refer to a different state than cashOnHand, instead of both variables referring to the same state as intended. 

6. The virtual address for the first 4-byte word of page 6 is __12288__ and the one for the last 4-byte words of page 6 is __16380__. These virtual addresses translate to the physical addresses: 12288+4096=__16384__ for the first 4-byte word and 16380+4096=__20476__ for the last 4-byte word. 

7. In figure 6.13, the page numbers 1047552 and 1047553 were calculated because the last page is 1023, so if you multply 1023 by 1024 (because pages can point to 1024 page frames) you get those pages. 
