#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("<insert your name here>");
MODULE_DESCRIPTION("LKP2E book:ch4/helloworld_lkm: hello, world, our first LKM");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.2");

static int __init helloworld_lkm_init(void)
{
	printk(KERN_INFO "Hello, world\n");
	return 0;		/* success */
}
static void __exit helloworld_lkm_exit(void)
{
	printk(KERN_INFO "Goodbye, world!\n");
}
module_init(helloworld_lkm_init);
module_exit(helloworld_lkm_exit);