# Redis 安装

## CentOS7 安装Redis5

```shell
cd /usr/local && wget http://download.redis.io/releases/redis-5.0.0.tar.gz
tar -zxvf redis-5.0.0.tar.gz
cd redis-5.0.0/
make && make install # PREFIX=/usr/local/redis
mkdir -p /etc/redis && cp redis.conf /etc/redis/redis.conf
touch /etc/systemd/system/redis.service

====== redis.conf ======
[Unit]
 Description=redis-server
After=network.target
        
[Service]
Type=forking
ExecStart=/usr/local/redis/bin/redis-server /etc/redis/redis.conf
PrivateTmp=true
        
[Install]
WantedBy=multi-user.target
====== redis.conf ======

systemctl daemon-reload
systemctl enable redis.service
systemctl start redis.service

vim /etc/redis/redis.conf
    bind 0.0.0.0
    daemonize yes
    protected-mode no
    
====== raw cmd ======
hostnamectl set-hostname redis01

vim /etc/selinux/config
systemctl set-default multi-user.target
systemctl stop firewalld
systemctl disable firewalld
timedatectl set-timezone Asia/Shanghai

date

sed -e 's|^mirrorlist=|#mirrorlist=|g'  -e 's|^#baseurl=http://mirror.centos.org/centos|baseurl=https://mirrors.tuna.tsinghua.edu.cn/centos|g' -i.bak /etc/yum.repos.d/CentOS-*.repo
yum clean all
yum makecache

reboot

yum install gcc-c++ -y
wget https://download.redis.io/releases/redis-5.0.0.tar.gz
tar -zxvf redis-5.0.0.tar.gz
cd redis-5.0.0/
make && make install PREFIX=/usr/local/redis

mkdir -p /etc/redis && cp redis.conf /etc/redis/
ll /etc/redis/redis.conf
vim /etc/redis/redis.conf
touch /etc/systemd/system/redis.service
vim /etc/systemd/system/redis.service

[Unit]
Description=redis-server
After=network.target
   
[Service]
Type=forking
ExecStart=/usr/local/redis/bin/redis-server /usr/local/redis/bin/redis.conf
PrivateTmp=true
   
[Install]
WantedBy=multi-user.target

systemctl daemon-reload
systemctl enable redis.service
reboot or systemctl start redis.service
systemctl status redis
ps -ef |grep redis
====== raw cmd ======
```

## CentOS7 安装Redis6

### Linux版本

`CentOS Linux release 7.9.2009 (Core)`

### Redis版本

`Redis v6.2.9`

### 前置依赖

`gcc v5.3+`

`tcl v8.5+`

### 升级gcc版本

```shell
yum -y install centos-release-scl
yum -y install devtoolset-9-gcc devtoolset-9-gcc-c++ devtoolset-9-binutils
scl enable devtoolset-9 bash # scl命令启用只是临时的，退出xshell或者重启就会恢复到原来的gcc版本。
gcc -v
    gcc version 9.3.1 20200408 (Red Hat 9.3.1-2) (GCC)
#如果要长期生效的话，执行如下：
echo -e "\nsource /opt/rh/devtoolset-9/enable" >> /etc/profile
```

### 升级tcl版本

```shell
yum install -y tcl-devel
```

### 开始安装

```shell
cd /usr/local/ && wget http://download.redis.io/releases/redis-6.2.9.tar.gz
tar -zxvf redis-6.2.9.tar.gz
cd redis-6.2.9
make && make test
make install # 如果使用systemd管理Redis服务，则需要加上参数 USE_SYSTEMD=yes

# 可选make 选项：
# 编译安装到指定目录下
make PREFIX=/usr/local/redis install

# 编译出错时，清出编译生成的文件
make distclean

# 卸载
make uninstall
```

### 配置文件

```shell
mkdir /etc/redis && cp redis.conf /etc/redis/6379.conf
```

修改：

```bash
#bind 127.0.0.1 # 将这行代码注释，监听所有的ip地址，外网可以访问
protected-mode no # 把yes改成no，允许外网访问
daemonize yes # 把no改成yes，后台运行
appendonly yes # 开启aof备份
```

### 开机自启

```shell
cp utils/redis_init_script /etc/init.d/redis_6379
chmod 777 /etc/init.d/redis_6379

# 1. 将redis服务添加到开机自启
chkconfig --add redis_6379

# 2. 设置redis开机自启
chkconfig redis_6379 on

# 3. 查看redis 有没有设置为开机启动
chkconfig --list | grep redis
```

### 服务注册

依赖安装：

```shell
yum -y install systemd-devel # 使用systemd管理redis需要安装
```

常用命令：

```shell
systemctl start redis_6379.service #启动redis服务
systemctl enable redis_6379.service #设置开机自启动
systemctl disable redis_6379.service #停止开机自启动
systemctl status redis_6379.service #查看服务当前状态
systemctl restart redis_6379.service　 #重新启动服务
systemctl list-units --type=service | grep redis #查看所有已启动的Redis服务
```

service文件sample：

```shell
[Unit]
Description=Redis data structure server
Documentation=https://redis.io/documentation
#Before=your_application.service another_example_application.service
#AssertPathExists=/var/lib/redis
Wants=network-online.target
After=network-online.target

[Service]
#ExecStart=/usr/local/bin/redis-server --supervised systemd --daemonize no
## Alternatively, have redis-server load a configuration file:
ExecStart=/usr/local/bin/redis-server /etc/redis/redis.conf
LimitNOFILE=1024
NoNewPrivileges=yes
#OOMScoreAdjust=-900
#PrivateTmp=yes
Type=notify
TimeoutStartSec=5
TimeoutStopSec=5
UMask=0077
#User=redis
#Group=redis
#WorkingDirectory=/var/lib/redis

[Install]
WantedBy=multi-user.target
```

### 常见报错

为了定位错误原因，需要开启redis日志，在redis的配置文件中配置字段：`logfile "/var/log/redis.log"`

#### 报错1：

`The TCP backlog setting of 511 cannot be enforced because /proc/sys/net/core/somaxconn is set to the lower value of 128`

解决：

```shell
vim /etc/sysctl.conf
......
# 添加内容
net.core.somaxconn = 1024
vm.overcommit_memory = 1

/sbin/sysctl -p # 添加完成后，刷新内核参数，立即生效
```

#### 报错2：

`systemd supervision requested or auto-detected, but Redis is compiled without libsystemd support!`

解决：

```shell
yum -y install systemd-devel
make USE_SYSTEMD=yes install # 添加编译参数
```

其他报错请先排查日志文件中指定的唯一性参数比如`logfile`、`pidfile`等等

#### 报错3：

`Increased maximum number of open files to 10032 (it was originally set to 1024)`

解决：

```shell
vim /etc/security/limits.conf
# 添加或修改如下
* soft nofile 65535
* hard nofile 65535

# 重新登录后查看是否生效
ulimit -n 
```



### 参考链接

1. https://www.cnblogs.com/ifme/p/13903017.html
2. https://blog.csdn.net/weixin_42315393/article/details/123610656
3. [Redis启动警告解决方法](https://www.jianshu.com/p/0048af19a8cb)

