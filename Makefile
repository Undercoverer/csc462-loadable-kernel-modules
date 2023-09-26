obj-m += ./ch2/hello.o ./ch2/simple.o ./ch2/second_count.o ./ch2/jiffies.o

PWD := $(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
