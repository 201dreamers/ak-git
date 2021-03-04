#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("Dmytro Hakman IO-81");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint amount = 1;
module_param(amount, uint, 0);
MODULE_PARM_DESC(amount, "How much hello world messages should appear on the screen");

static int __init initter(void)
{
  uint i = 0;

  printk(KERN_INFO "amount: %d\n", amount);

  if(amount == 0) {
    printk(KERN_WARNING "The parameter is %d\n", amount);
  } else if(amount >= 5 && amount <= 10) {
    printk(KERN_WARNING "The parameter is between 5 and 10\n");
  } else if(amount > 10) {
    printk(KERN_ERR "The parameter is greater than 10\n");
    return -EINVAL;
  }

  for(i = 0; i < amount; i++){
    printk(KERN_INFO "Hello, world!\n");
  }
  return 0;
}

static void __exit exitter(void)
{
  /* Do nothing here right now */
}

module_init(initter);
module_exit(exitter);