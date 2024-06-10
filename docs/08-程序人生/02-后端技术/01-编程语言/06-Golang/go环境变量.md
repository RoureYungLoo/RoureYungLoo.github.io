go环境变量

GO111MODULE：用来控制使用 go mod 模式还是 GOPATH 模式，值为 off, on 或 auto。

GCCGO：gccgo 命令运行'go build -compiler=gccgo'。

GOARCH：当前架构，例如 amd64, 386, arm, ppc64等。

GOBIN：Go 命令的默认二进制目录，即'go install'将安装命令的目录。

GOCACHE：Go 命令的缓存目录。

GOMODCACHE：go命令将存储下载模块的目录。

GODEBUG：启用各种调试工具，参见'go doc runtime'。

GOENV：Go 环境变量配置文件的位置。

GOFLAGS：Go 命令的标志位参数。

GOINSECURE：用于指定哪些域名下的仓库不校验CA证书。

GOOS：当前操作系统，例如 linux，darwin，windows，netbsd 等。

GOPATH：Go 项目的根目录。

GOPROXY：Go module 代理的 URL。

GOROOT：Golang 安装的根目录。

GOSUMDB：要使用的校验数据库的名称以及可选的公钥和URL

GOTMPDIR：go 命令写入的目录，临时的源文件、包和二进制文件。

GOVCS：列出可能与匹配服务器一起使用的版本控制命令。

GOWORK：workspace 设置。