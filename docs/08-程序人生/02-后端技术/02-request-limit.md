# 流量控制

行业术语“过载保护”，防止服务器因过载而宕机。

## 常见算法

- 固定窗口
- 滑动窗口
- 漏桶算法
- 令牌桶算法
- 滑动日志算法
- Redis分布式限流

## 漏桶算法

解释：把一次性水杯底部扎一个洞，往里面接水，水杯底部会漏水，当水流过大时，水杯接满后多余的水会直接溢出。

缺点：效率低

代码：
```java
long timeStamp = getNowTime(); 
int capacity = 10000;// 桶的容量
int rate = 1;//水漏出的速度 
int water = 100;//当前水量  
 
public static bool control() {   
    //先执行漏水，因为rate是固定的，所以可以认为“时间间隔*rate”即为漏出的水量
    long  now = getNowTime();
    water = Math.max(0, water - (now - timeStamp) * rate);
    timeStamp = now;
 
    if (water < capacity) { // 水还未满，加水
        water ++; 
        return true; 
    } else { 
        return false;//水满，拒绝加水
   } 
} 
```

## 令牌桶算法

解释：皇帝往令牌桶里放令牌，想进皇宫的人需要从令牌桶里拿一个令牌，当有很多人在短时间内同时拿令牌时，会有人拿不到令牌，拿不到令牌的人就不能进宫。

优点：适合具有突发特性的流量

缺点：

代码：
```java
long timeStamp=getNowTime(); 
int capacity; // 桶的容量 
int rate ;//令牌放入速度
 int tokens;//当前水量  
 
bool control() {
   //先执行添加令牌的操作
   long  now = getNowTime();
   tokens = max(capacity, tokens+ (now - timeStamp)*rate); 
   timeStamp = now;   //令牌已用完，拒绝访问
 
   if(tokens<1){
     return false;
   }else{//还有令牌，领取令牌
     tokens--;
     retun true;
   }
 } 
```

# 控制维度

- QPS，quest per second, 每秒请求数
- 并发数，限制最大进程数和最大线程数
- 连接数，限制TCP最大连接数

# 参考链接

1. https://blog.csdn.net/xushiyu1996818/article/details/106764890
2. https://zhuanlan.zhihu.com/p/158948815
3. https://www.cnblogs.com/liqiangchn/p/14253924.html
