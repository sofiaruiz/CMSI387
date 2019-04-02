# Kernel Modification Tutorial

In order to complete this kernel modification, you should have Oracle Virtual Box installed. You can download the VM at this [link](https://www.virtualbox.org/wiki/Downloads).


---
## Building Kernel From Source
1. In theory, you should be able to run the command below with no issue.
    > apt-get source linux-image-$(uname -r)

    However, when I first ran this command I received the error
    > You must put some 'source' URIs in your sources.list

    If you also encounter this error, edit your sources.list so that each line starting with deb-src is uncommented. To edit this file you can enter the command below.
    > sudo nano /etc/apt/sources.list

    After this, run
    > sudo apt-get update
    > apt-get source linux-image-$(uname -r)

    Then you should be set for the next step.

2. Next, we will build the environment. In order to do this, we will need some packeges. You can get them by using the command. Since there are quite a few packages, it may tell you how much disk space will be used and ask you if you want to continue, at which point you should type "Y" for yes.
    > sudo apt-get build-dep linux-image-$(uname -r)
