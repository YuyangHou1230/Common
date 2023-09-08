# Common

## Utility

### SingleApplication
SingleApplication主要是用于软件只能运行一个实例程序，重复开启时需要进行检测，提示用户或者打开原来的软件窗口，使用方式如下：
```cpp
int main(int argc, char *argv[])
{
    SingleApplication a(argc, argv);
    if(a.isRunning()){
        a.doSomethingIfIsRun();
        return 0;
    }
    MainWindow w;
    a.setMainform(&w);
    w.show();
    return a.exec();
}
```
