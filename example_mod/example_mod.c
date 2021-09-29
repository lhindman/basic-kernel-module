
/*
 * Author: Luke Hindman
 * Date: Wed 29 Sep 2021 09:53:08 AM MDT
 * Description:  Linux Kernel Module template
 */
#include <linux/module.h>
#include <linux/init.h>


static int __init my_init(void)
{
	pr_info("Module Loaded\n");

	return 0;
}

static void __exit my_exit(void)
{
	pr_info("Module Unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Huck Finn");
MODULE_DESCRIPTION("Linux Kernel Module Template");
MODULE_LICENSE("GPL v2");
