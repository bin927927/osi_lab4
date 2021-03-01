/*
 * Simple device driver which uses an initialise and exit funcions.
 * With hardware, these calls are used to initialise the driver when
 * it is inserted and to deinitialise it when it is removed from the
 * kernel
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

/*
 * this function is called on insert of driver to kernel
 */
static int hello_init(void) {
  printk("<1> Hello world!\n");
  return 0;
}

/*
 * this function is called on exit of driver from kernel
 */
static void hello_exit(void) {
  printk("<1> Oh No, I am gone...\n");
}


/* 
 * provide the OS given hooks (mudule_init and module_exit) with out functions
 */
module_init(hello_init);

module_exit(hello_exit);
