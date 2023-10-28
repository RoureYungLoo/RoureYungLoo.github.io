# 安装依赖

```bash
sudo apt install libpcre3-dev libssl-dev perl make build-essential curl libpq zlib1g-dev
tar -zxvf openresty-1.21.4.1.tar.gz
cd openresty-1.21.4.1/
sudo ./configure --prefix=/opt/openresty \
            --with-luajit \
            --without-http_redis2_module \
            --with-http_iconv_module \
            --with-http_postgres_module
sudo make
sudo make install
```