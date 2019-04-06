import threading
import random
import time

#used help from: http://rosettacode.org/wiki/Dining_philosophers#Python !!

class Philosopher(threading.Thread):
    
    running = True
    def __init__(self, name, l_fork, r_fork):
        threading.Thread.__init__(self)
        self.name = name
        self.l_fork = l_fork
        self.r_fork = r_fork

    def run(self):
        while(self.running):
            time.sleep(random.uniform(1, 10))
            self.dine()

    def dine(self):
        fork_1, fork_2 = self.l_fork, self.r_fork
        while self.running:
            fork_1.acquire(True)
            locked = fork_2.acquire(False)
            if locked: 
                break
            fork_1.release()
            fork_1, fork_2 = fork_2, fork_1
        else:
            return
        self.dining()
        fork_1.release()
        fork_2.release()

    def dining(self):			
        print(f'{self.name} :eating')
        time.sleep(random.uniform(1, 10))
        print(f'{self.name} :done eating and put forks down.')

def dining_philosophers():
    forks = [threading.Lock() for n in range(5)]
    philosopherNames = ('Callicles','Solon','Epicurus','Socrates', 'Plato')
 
    philosophers= [Philosopher(philosopherNames[i], forks[i%5], forks[(i+1)%5]) for i in range(5)]
 
    random.seed(507129)
    Philosopher.running = True
    for p in philosophers: p.start()
    time.sleep(100)
    Philosopher.running = False
    print ("Finished.")

dining_philosophers()
