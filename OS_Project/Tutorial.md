# Kernel Modification Tutorial

In order to complete this kernel modification, you should have Oracle Virtual Box installed. You can download the VM at this [link](https://www.virtualbox.org/wiki/Downloads).

1. Download source

> wget https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.19.36.tar.xz

2. extract files

> sudo tar -xvf linux-4.17.4.tar.xz -C/usr/src/

https://medium.com/anubhav-shrimal/adding-a-hello-world-system-call-to-linux-kernel-dad32875872

follow this up until Step 9. Test the System Call

After restarting kernel got error:
 [ end Kernel panic - not syncing: System is deadlocked on memory]

To fix, power down your virtual machine. In the oracle virtualbox menu select your machine and go to settings. Under the System tab, make sure your memory is at at least 2000MB.

Now reboot your kernel, select Ubuntu and it should boot fine.

You can type uname -a and you should see Linux [your machine name] [your kernel version] [date you compiled kernel] and some other info. This means the kernel has successfully compiled.

Now we can go to the testing step from the tutorial above.
