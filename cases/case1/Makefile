obj-m += t.o
	CURRENT_PATH:=$(shell pwd)
	LINUX_KERNEL_PATH:=/lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules
clean:
	rm -rf  *.mod *.mod.c *ko *.mod.o *.a *.order *.symvers *.o