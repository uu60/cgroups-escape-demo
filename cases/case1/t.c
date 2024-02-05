//
// Created by 杜建璋 on 2024/2/5.
//
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init exception_init(void) {
    int ret = -1;
    char path[] = "/root/a.out";
    char *argv[] = {path, NULL};
    char *envp[3];

    envp[0] = "HOME=/";
    envp[1] = "PATH=/sbin:/bin:/usr/sbin:/usr/bin";
    envp[2] = NULL;

    while (true) {
        printk("call_usermodehelper module isstarting..!\n");
        ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);
        printk("ret=%d\n", ret);
    }
    return 0;
}


static void __exit exception_exit(void) {
    // TODO
}


module_init(exception_init);
module_exit(exception_exit);


MODULE_LICENSE("GPL");