八股 SAY NO！
数据库设计、索引怎么建立、系统功能模块设计（根据业务流程）

timestamp (4字节) / datatime (8字节)  --  常见时间储存类型(表示形式yyyy-mm-dd hh:mm:ss)
timestamp是当前时间到 Unix元年(1970年1月1日0时0分0秒)的秒数, 以utc的格式储存， 会自动检索当前时区并进行转换, 对于某些时间计算较为方便(直接加减);
对于NULL，timestamp会自动储存当前时间，而datetime会储存NULL, 即datetime存什么就取什么.

go里面的继承关系如何实现  --  采用组合思想 has a, 成员函数传参需要传递 相应对象

http/rpc协议

指针和引用的本质区别

I/O复用的本质，select/poll/epoll的本质区别  --  同时监听多个网络I/O事件

虚拟内存、页面调度算法及优缺点
