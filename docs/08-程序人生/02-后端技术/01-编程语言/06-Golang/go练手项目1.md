**Go练手项目1**

**1、cache2go**

比较简单的一个缓存库, 可以学习到锁、goroutines等

starts: 2k

地址：https://github.com/muesli/cache2go

**2、groupcache**

memcached作者写的memcached的go版本实现

stars: 12.5k

site: https://github.com/golang/groupcache

**3、nsq**

消息分发平台，阅读代码可以了解到很多**分布式**、**负载均衡**等方面的编程

stars: 24k

site: https://github.com/nsqio/nsq

**4、grpc-go**

高性能、开源和通用的 RPC 框架，面向移动和 HTTP/2 设计

stars: 19.3k

site: https://github.com/grpc/grpc-go

**5.boom测试工具**

类似apache ab的性能测试工具

stars: 4.7k

site: https://github.com/rakyll/boom

stars: 16.7k

site: https://github.com/rakyll/hey

**6.FishChat**

FishChat（鱼传——鱼传尺素）分布式可伸缩 IM 服务器，是一款纯 golang 编写优秀的即时通讯软件(IM),

stars: 873

stie: https://github.com/oikomi/FishChatServer

**7.MailSlurper**

SMTP 邮件服务器

stars: 1.3k

site: https://github.com/mailslurper/mailslurper

**8.Meizar**

图片爬虫程序，默认抓取煎蛋网的图片

stars: 56

site: https://github.com/qibin0506/Meizar

**9.Pholcus**

Pholcus（幽灵蛛）是一款纯 Go 语言编写的支持分布式的高并发爬虫软件，仅用于编程学习与研究。

stars: 7.5k

site: https://github.com/andeya/pholcus

**10.****goim**

支持集群的im及实时推送服务（支持websocket，http和tcp协议）

stars: 7k

site: https://github.com/Terry-Mao/goim

**11.fasthttp**

Fast HTTP package for Go. Tuned for high performance. Zero memory allocations in hot paths. Up to 10x faster than net/http

stars: 20.5k

site: https://github.com/valyala/fasthttp

**12.gohttp**

The best HTTP Static File Server, write with golang+vue

stars: 2.3k

site: https://github.com/codeskyblue/gohttpserver

**13.****bosun**

Bosun is a time series alerting framework developed by Stack Exchange. Scollector is a metric collection agent.

stars: 3.4k

site: https://github.com/bosun-monitor/bosun

**14.beego**

用Go开发的应用框架，思路来自于tornado，路由设计来源于sinatra

stars: 30.5k

site: https://github.com/beego/beego

**15.tinode**

开源的即时通讯软件tinode的服务端

stars: 11k

site: https://github.com/tinode/chat

**16.jupiter**

Jupiter 是斗鱼开源的一套微服务治理框架，提供丰富的后台功能，管理应用的资源、配置，应用的性能、配置等可视化。

stars: 4.3k

site: https://github.com/douyu/jupiter

doc: https://jupiter.douyu.com/

features:

- **gRPC**：基于官方 gRPC 开发，集成流控和多数据中心方式的服务注册，支持多种 roundrobin，p2c 等负载均衡策略；
- **配置**：使用 toml、yaml 方式管理配置，规范化核心配置，结合远程配置中心，实现配置版本管理和更新，查看配置依赖关系；
- **日志**：基于 zap 日志类库，实现高性能日志库，并对不同环境和条件，实现日志库的自动降级，并对服务端，客户端的慢日志通过配置条件，实现全部慢日志接入；
- **监控**：基于 prometheus go sdk 类库，实现对服务端，客户端的数据监控，并与 prometheus、confd、etcd 数据打通，实现应用自动化数据采集；
- **数据库**：基于 gorm 的封装，将数据库的 trace，慢日志，监控进行了采集；
- **缓存**：基于 go-redis 的封装，将数据库的 trace，慢日志，监控进行了采集，并实现了单个 redis、多从库 redis，客户端 redis 分片，服务端 redis 分片的 api；
- **系统错误码**：区分框架和业务的错误码，将框架错误码文档自动生成，自动化的错误码 SRE 分析工具；
- **工程化**：基于服务标准、创建、开发、运行、治理等生命周期，完成了Jupiter对项目的工程化；
- **服务治理**：基于监控，etcd，配置中心，对服务实现了良好的可观测性，可控制性；

**17. DocHub**

参考百度文库，使用**Beego**（Golang）开发的开源文库系统

stars: 2.9k

site: https://github.com/TruthHun/DocHub

**18.beego-demo**

A web demo using **Beego** framework, with MongoDB, MySQL and Redis support.

stars: 245

site: https://github.com/gwduan/beego-demo

**19.beego_blog**

stars: 536

site: https://github.com/Echosong/beego_blog