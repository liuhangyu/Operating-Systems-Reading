####Tips
**进程地址空间与虚拟存储空间**
>http://blog.csdn.net/do2jiang/article/details/4690967
- 早期： 直接到物理空间
- 分段：
	- 当创建一个进程时，操作系统会为该进程分配一个 4GB 大小的虚拟 进程地址空间。之所以是 4GB ，是因为在 32 位的操作系统中，一个指针长度是 4 字节，而 4 字节指针的寻址能力是从 0x00000000~0xFFFFFFFF ，最大值 0xFFFFFFFF 表示的即为 4GB 大小的容量。与虚拟地址空间相对的，还有一个物理地址空间，这个地址空间对应的是真实的物理内存。
	- 进程只能访问虚拟地址中的数据 -- > 进程间地址隔离
	- 分段映射： 地址隔离，程序员只用关心虚拟空间的地址处理，操作系统完成映射
	- 效率低，每次更换整个程序地址空间
- 分页：
	- CPU 访问某一页；if(未分配地址){页错误，分配地址，建立虚拟地址空间到实际内存空间的映射}
