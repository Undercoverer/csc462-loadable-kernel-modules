/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/jiffies.h>
#include <linux/gcd.h>
#include <linux/param.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       printk(KERN_INFO "Golden Ratio Prime: %llu\n", GOLDEN_RATIO_PRIME);
       printk(KERN_INFO "HZ: %lu\n", HZ);
       printk(KERN_INFO "Jiffies: %lu\n", jiffies);

    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
    printk(KERN_INFO "GCD(3300, 24) = %lu\n", gcd(3300,24));
    printk(KERN_INFO "Jiffies: %lu\n", jiffies);

}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

