#include <unistd.h>
#include <pthread.h>
#include <iostream>

using namespace std;

static int i = 0;

class test {
    public:
        test() : a(0), b(0.0) {}
        void increase(){  // 自增
            a++;
            b++;
        }
        void get() const{
            cout << "a=" << a << " b=" << b << endl;
        }
    private:
        int a;
        double b;
};

void* worker(void* arg) {
    sleep(100);
    test* temp = (test*)arg;
    temp->increase();
}

int main(){
    pthread_t pthd[100];
    test* one = new test;
    for (int i = 0; i < 100; i++) {
        pthread_create(&pthd[i], NULL, worker, one);  // 开启100个线程对变量自增
    }
    for (int i = 0; i < 100; i++) {
        pthread_join(pthd[i], NULL);
    }
    one->get();  //获取结果
    return 0;
}