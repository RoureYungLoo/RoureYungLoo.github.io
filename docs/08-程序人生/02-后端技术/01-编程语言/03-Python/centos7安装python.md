**01-CentOS7 安装Python3.8**

[Centos 7 安装python 3.8_centos python安装_水木子_的博客-CSDN博客](https://blog.csdn.net/qq_41261251/article/details/105407495)

```shell
yum -y install wget
wget https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tgz
tar zxpf Python-3.8.0.tgz
cd Python-3.8.0/
yum groupinstall -y 'Development Tools'
yum install -y gcc openssl-devel bzip2-devel libffi-devel
# 加上--enable-optimizations参数需要升级gcc版本
./configure prefix=/usr/local/python3 (--enable-optimizations)
make && make install
#修改链接 python pip
which python
ls -la /usr/bin/python*
ln -sf /usr/local/python3/bin/python3.8 /usr/bin/python3
ln -sf /usr/bin/python3 /usr/bin/python
which pip
ln -s /usr/local/python3/bin/pip3.8 /usr/bin/pip3
ln -s /usr/bin/pip3 /usr/bin/pip

#修改yum相关脚本 "#!/usr/bin/python"-->"#!/usr/bin/python2"
ls -la /usr/bin/yum*
-rwxr-xr-x. 1 root root   801 Oct  2  2020 /usr/bin/yum
-rwxr-xr-x. 1 root root 10189 May 13  2020 /usr/bin/yum-builddep
-rwxr-xr-x. 1 root root  9579 May 13  2020 /usr/bin/yum-config-manager
-rwxr-xr-x. 1 root root  8538 May 13  2020 /usr/bin/yum-debug-dump
-rwxr-xr-x. 1 root root  7903 May 13  2020 /usr/bin/yum-debug-restore
-rwxr-xr-x. 1 root root 11115 May 13  2020 /usr/bin/yumdownloader
-rwxr-xr-x. 1 root root 11031 May 13  2020 /usr/bin/yum-groups-manager
vim /usr/libexec/urlgrabber-ext-down ### "#!/usr/bin/python"-->"#!/usr/bin/python2"
```

sed 命令替换

```shell
sed 's/python/python2/' /usr/bin/yum* # 仅替换一次
sed 's/python/python2/g' /usr/bin/yum* # 全局替换
```

[Linux 输入输出重定向 2＞/dev/null和＞/dev/null 2＞&1和2＞&1＞/dev/nul_擒贼先擒王的博客-CSDN博客](https://blog.csdn.net/freeking101/article/details/81212207)

[Linux shell中2>&1的含义解释 （全网最全，看完就懂）_一个行走的民的博客-CSDN博客](https://blog.csdn.net/zhaominpro/article/details/82630528)

1.  **2>/dev/null****黑洞**
2.  **>/dev/null 2>&1** **1>/dev/null 2>&1** ，
3.  **2>&1 >/dev/null**