bool b() {
    int *p = new int;
    return p;
}
// 错误点：
// 1. p 没有值初始化
// 2. p 转换为bool, 永远也无法释放