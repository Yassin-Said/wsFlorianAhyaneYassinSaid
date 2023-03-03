#include "hello.h"

MODULE_LICENSE("IDK");
MODULE_DESCRIPTION("My firt kernel module");
MODULE_AUTHOR("You");

static int n = 0;
static char *test = NULL;
module_param(test, charp, S_IRUSR | S_IWUSR);
module_param(n, int, S_IRUSR | S_IWUSR);
static struct file_operations fops = {
    .read = my_dev_read,
    .write = my_dev_write,
    .open = my_dev_open,
    .release = my_dev_close
};
static char *output = NULL;

static int my_dev_open(struct inode *inode, struct file *file) {
  printk("Device is open\n");
  return (0);
}

static int my_dev_close(struct inode *inode, struct file *file) {
  printk("Device is closed\n");
  return (0);
}

static ssize_t my_dev_read(struct file *file, char *buf, size_t len, loff_t *off) {
  return len;
}

static ssize_t my_dev_write(struct file *file, const char *buf, size_t len, loff_t *off) {
  write();
  return len;
}

static int __init my_init()
{
  int i = 0;

  int majnb = register_chrdev(0, "wstest", &fops);
  for (i = 0; i < n; i++) {
    printk("Hello kernel !\n");
  }
  printk("%d\n",majnb);
  return(0);
}

module_init(my_init);

static void __exit my_exit(void)
{
  int i = 0;
  for (i = 0; i < n; i++) {
    printk("Goodbye kernel");
    printk(test);
  }
}

module_exit(my_exit);
