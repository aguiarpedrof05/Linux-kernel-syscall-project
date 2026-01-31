# include < linux / kernel .h >
# include < linux / syscalls .h >

SYSCALL_DEFINE0 ( helloworld )
{
printk ( KERN_EMERG " hello world !\ n " ) ;
return 0;
}
