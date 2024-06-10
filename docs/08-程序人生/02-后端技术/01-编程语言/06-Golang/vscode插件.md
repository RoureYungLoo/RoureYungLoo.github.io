visual studio code 插件安装不上：

go env -w GO111MODULE=on 

go env -w GOPROXY=https://proxy.golang.com.cn,direct

切换toolchain版本

go get toolchain@