/* 单例模式：类只存在一个实例化对象
 * 构造函数私有或者受保护;
 * 定义静态对象；
 * 定义静态公有函数;
 */
// 饿汉式：一开始就进行实例化
class Singleton {
private:
	Singleton(){}
	static Singleton* Instance;
public:
	static Singleton* GetInstance() {
		return Instance;
	}
};
Singleton* Singleton::Instance = new Singleton;  // 在程序入口前完成单例对象初始化


// 懒汉式，第一次用到类实例时才去实例化 (多线程不安全 --> 可以使用临界区CRITICAL_SECTION或互斥量MUTEX来实现线程锁)
class Singleton {
private:
	Singleton(){}
	static Singleton* Instance;
public:
	static Singleton* GetInstance() {
        // Lock();
		if (Instance == NULL) {
			Instance = new Singleton;
		}
        // UnLock();
		return Instance;
	}
};
Singleton* Singleton::Instance = NULL;

// 当某个线程要访问时，就立即上锁，导致不必要的锁的消耗。
// 所以可以先判断实例是否存在，再进行是否上锁的操作。即双检查锁(DCL)思想。
static Singleton* GetInstance() {
	if (Instance == NULL) {
        Lock();
        if (Instance == NULL) {
            Instance = new Singleton;
        }
		UnLock();
	}

	return Instance;
}
// 分析: m_pInstance = new CSingleton()这句话可以分成三个步骤来执行:
// 1.分配了一个CSingleton类型对象所需要的内存。
// 2.在分配的内存处构造CSingleton类型的对象。
// 3.把分配的内存的地址赋给指针m_pInstance。
// 可能会认为这三个步骤是按顺序执行的,但实际上只能确定步骤 1 是最先执行的,步骤2,3却不一定。
// 问题就出现在这。假如某个线程A在调用执行m_pInstance = new CSingleton()的时候是按照1, 3, 2的顺序的,
// 那么刚刚执行完步骤3给singleton类型分配了内存(此时m_ instance就不是nullptr了 )就切换到了线程B,
// 由于m_pInstance已经不是nullptr了,所以线程B会直接执行return m_ instance得到一个对象,而这个对象并没有真正的被构造! !
// 严重bug就这么发生了。

// 《Effective C++》系列书籍的作者 Meyers提出了C++ 11版本最简洁的跨平台方案
class Singleton {
private:
    Singleton(){}
public:
    static Singleton & GetInstance() {
        static Singleton Instance;  //局部静态变量
        return Instance;
    }
};