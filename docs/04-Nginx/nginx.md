nginx1.13.1 源码编译安装

切换到代码根目录

```bash
sudo ./auto/configure #否则可能会报错Can't open auto/options
#可能缺少的依赖  
sudo apt install gcc make pcre pcre-devel   openssl  openssl-devel zlib  zlib-devel
#修改objs/Makefile 去掉-Werr
sudo make
sudo make install
```

