// A. Sheaff SysTimer RPi 2/6/13
// Add module attributes 
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

// Define module attribute strings. May be used else where so use defines
#define SYSTIMER_MOD_AUTH "Sheaff"
#define SYSTIMER_MOD_DESCR "SysTimer Raspberry Pi"
#define SYSTIMER_MOD_SDEV "SysTimerRPi"

// Module init
static int __init rpisystimer_minit(void)
{
    printk(KERN_INFO "%s\n", SYSTIMER_MOD_DESCR);
    printl(KERN_INFO "By: %s\n", SYSTIMER_MOD_AUTH); 
    return 0; 
}

// Module removal
static void __exit rpisystimer_mcleanup(void)
{
    printk(KERN_INFO "Good bye\n");
    return;
}

module_init(rpisystimer_minit);
module_exit(rpisystimer_mcleanup);

// Macros to set module attributes when using modinfo
MODULE_LINCENSE("GPL");
MODULE_AUTHOR(SYSTIMER_MOD_AUTH); 
MODULE_DESCRIPTION(SYSTIMER_MOD_DESCR);
MODULE_SUPPORTED_DEVICE(SYSTIMER_MOD_SDEV); 
