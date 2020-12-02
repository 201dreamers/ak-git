#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include "linux/slab.h"
#include "linux/ktime.h"


MODULE_AUTHOR("Dmytro Hakman IO-81");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");
static uint amount = 1;
module_param(amount, uint, S_IRUGO);
MODULE_PARM_DESC(amount, "How much hello world messages should appear on the screen");

struct h_list_head{
    struct h_list_head *next;
    ktime_t time;
};

static struct h_list_head *head;

static int __init start(void){
    struct h_list_head *prev_element;
    struct h_list_head *curr_element;
    uint i;

    

    printk(KERN_INFO "amount: %d\n", amount);

    if(amount == 0){
        printk(KERN_WARNING "The parameter is %d\n", amount);
    } else if(amount >= 5 && amount <= 10){
        printk(KERN_WARNING "The parameter is between 5 and 10\n");
    } else if(amount > 10){
        printk(KERN_ERR "The parameter is greater than 10\n");
        return -EINVAL;
    }

    if (amount > 0) {
        head = kmalloc(sizeof(struct h_list_head*), GFP_KERNEL);
        head->next = NULL;
        head->time = ktime_get();
        printk(KERN_INFO "Hello, world!\n");
    }

    curr_element = head;
    for(i = 1; i < amount; i++){
        printk(KERN_INFO "Hello, world!\n");
        
        prev_element = curr_element;
        curr_element = kmalloc(sizeof(struct h_list_head*), GFP_KERNEL);

        curr_element->next = NULL;
        curr_element->time = ktime_get();
        prev_element->next = curr_element;
        
    }
    return 0;
}

static void __exit stop(void){
    struct h_list_head* container1 = head;
    struct h_list_head* container2;

    while(container1 != NULL){
        container2 = container1;
        pr_info("%lld\n", container1->time);
        container1 = container2->next;
        kfree(container2);
    }
}

module_init(start);
module_exit(stop);