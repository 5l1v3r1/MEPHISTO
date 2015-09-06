#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>

MODULE_LICENSE("GPL");


/**
 * This works just as a loader. It will initialize MEPHISTO, hide it in
 * the memory and gets unloaded right after it. MEPHISTO will stay in
 * Kernel until shutdown, without being registered as a Kernel module
 */

static int __init mephisto_init(void)
{
    //TODO
}

static int __exit mephisto_exit(void)
{
    //TODO
}

module_init(mephisto_init);
module_exit(mephisto_exit);
