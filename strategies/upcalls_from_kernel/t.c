//
// Created by 杜建璋 on 2024/2/5.
//
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init touch_init(void)
{
    int ret = -1;
    char path[] = "/usr/bin/touch";
    char *argv[] = {path, "/root/test1.txt", NULL};
    char *envp[3];

    envp[0] = "HOME=/";
    envp[1] = "PATH=/sbin:/bin:/usr/sbin:/usr/bin";
    envp[2] = NULL;

    printk("call_usermodehelper module isstarting..!\n");
    ret = call_usermodehelper(path, argv, envp,UMH_WAIT_PROC);
    printk("ret=%d\n", ret);
    return 0;
}


static void __exit touch_exit(void)
{
    int ret = -1;
    char path[] = "/bin/rm";
    char *argv[] = {path, "-r","/root/test1.txt", NULL};
    char *envp[3];

    envp[0] = "HOME=/";
    envp[1] = "PATH=/sbin:/bin:/usr/sbin:/usr/bin";
    envp[2] = NULL;

    printk("call_usermodehelper module isstarting..!\n");
    ret = call_usermodehelper(path, argv, envp,UMH_WAIT_PROC);
    printk("ret=%d\n", ret);
}


module_init(touch_init);
module_exit(touch_exit);


MODULE_LICENSE("GPL");
