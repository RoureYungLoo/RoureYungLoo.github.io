# Java安装配置

## 版本选择

老项目：jdk8

新项目：jdk17

特殊项目：jdk11

主要还是看spring boot 依赖的jdk版本

## 免费商用版本

下载地址：https://www.oracle.com/java/technologies/javase/javase8-archive-downloads.html

jdk 8u202

jdk 11.0.2

jdk 17+

## Linux安装

```bash
yum install  https://download.oracle.com/java/17/latest/jdk-17_linux-x64_bin.rpm
```

或者

```bash
yum install -y java-17-openjdk
```

## 环境变量

### Windows

```bash
JAVA_HOME：D:\Program Files\Java\jdk1.8.0_251
CLASSPATH：.;%JAVA_HOME%\lib\dt.jar;%JAVA_HOME%\lib\tools.jar;%JAVA_HOME%\jre\lib\rt.jar

新增一条PATH变量：%JAVA_HOME%\bin
```

### Linux

`vim /etc/profile`

```bash
JAVA_HOME=/usr/local/jdk1.8.0_251/
CLASSPATH=.:$JAVA_HOME/jre/lib/rt.jar:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar
PATH=$PATH:$JAVA_HOME/bin

export PATH JAVA_HOME CLASSPATH  
```

或者

```bash

export JAVA_HOME=/usr/local/devs/jdk/jdk-17.0.9
export CLASSPATH=.:$JAVA_HOME/jre/lib/rt.jar:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar 
export PATH=$PATH:$JAVA_HOME/bin

```

