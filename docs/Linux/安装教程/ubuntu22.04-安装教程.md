# Ubuntu2204安装教程

## 分区方案

> 在主引导记录（MBR）分区表中，最多可以有四个主分区，或者三个主分区和一个扩展分区。扩展分区可以包含多个逻辑分区，如果需要更多的分区，可以将其中一些设置为逻辑分区；
>
> 在GUID分区表（GPT）中，没有主分区或扩展分区的限制（可以有128个主分区），因此可以创建更多的分区。

### MBR分区表

1、最简单的分区方案：

- / (主)
- swap （逻辑）

2、单独/boot分区：

- /boot （主）
-  / （逻辑）
- swap （逻辑）

3、较常见的分区方案：

- /boot （主）
- / （逻辑）
- /home （逻辑）
- swap （逻辑）

4、单独安装ubuntu到全新磁盘：

- 方案一：/boot 主分区，/ 逻辑分区
- 方案二：/ 主分区

**若/boot单独分区，则/boot为主分区；否则/ 为主分区**

#### 方案一

以128GB硬盘为例

| 分区  | 分区类型 | 分区容量              |
| ----- | -------- | --------------------- |
| /boot | primary  | 2GB                   |
| /     | logical  | 24GB                  |
| /home | logical  | 52GB                  |
| /opt  | logical  | 10GB                  |
| /srv  | logical  | 10GB                  |
| /var  | logical  | 20GB                  |
| swap  | logical  | 8GB（物理内存1～2倍） |

#### 方案二

以128GB硬盘为例

| 分区  | 分区类型 | 分区容量              |
| ----- | -------- | --------------------- |
| /     | primary  | 24GB                  |
| /home | logical  | 40GB                  |
| /opt  | logical  | 24GB                  |
| /srv  | logical  | 10GB                  |
| /usr  | logical  | 10GB                  |
| /var  | logical  | 10GB                  |
| swap  | logical  | 8GB（物理内存1～2倍） |

### GPT分区表

以128GB硬盘为例：

| 分区  | 分区类型 | 分区容量              |
| ----- | -------- | --------------------- |
| /efi  | logical  | 2GB                   |
| /     | primary  | 24GB                  |
| /home | primary  | 52GB                  |
| /opt  | primary  | 10GB                  |
| /srv  | primary  | 10GB                  |
| /var  | primary  | 20GB                  |
| swap  | primary  | 8GB（物理内存1～2倍） |



## [修改软件源](https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/)

1、备份`sudo cp /etc/apt/sources.list /etc/apt/sources.list.backup  `

2、修改`/etc/apt/sources.list`内容如下

```
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic-backports main restricted universe multiverse

# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic-security main restricted universe multiverse
# # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic-security main restricted universe multiverse

deb http://security.ubuntu.com/ubuntu/ kinetic-security main restricted universe multiverse
# deb-src http://security.ubuntu.com/ubuntu/ kinetic-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic-proposed main restricted universe multiverse
# # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ kinetic-proposed main restricted universe multiverse
```

3、更新

```bash
sudo apt update 
sudo apt upgrade （根据个人情况）
```



## 卸载snap软件包

1、查看已经安装的snap软件包

```bash
[user@localhost ~]$ sudo snap list
Name                       Version           Rev    Tracking         Publisher   Notes
bare                       1.0               5      latest/stable    canonical✓  base
core20                     20220826          1623   latest/stable    canonical✓  base
firefox                    106.0-1           1969   latest/stable/…  mozilla✓    -
gnome-3-38-2004            0+git.6f39565     119    latest/stable/…  canonical✓  -
gtk-common-themes          0.1-81-g442e511   1535   latest/stable/…  canonical✓  -
snap-store                 41.3-64-g512c0ff  599    latest/stable/…  canonical✓  -
snapd                      2.57.4            17336  latest/stable    canonical✓  snapd
snapd-desktop-integration  0.1               14     latest/stable/…  canonical✓  -
```

2、删除snap软件包

```bash
sudo snap remove --purge firefox
sudo snap remove --purge snap-store
sudo snap remove --purge gnome-3-38-2004
sudo snap remove --purge gtk-common-themes
sudo snap remove --purge snapd-desktop-integration
sudo snap remove --purge bare
sudo snap remove --purge core20
sudo snap remove --purge snapd
```

3、删除snap服务

```bash
sudo apt remove --autoremove snapd
```

4、关闭apt触发器

```bash
sudo gedit /etc/apt/preferences.d/nosnap.pref
```

写入以下内容：

```
Package: snapd
Pin: release a=*
Pin-Priority: -10
```

5、最后一步

```bash
sudo apt update
```

## 软件安装

|   类别   | 名称                                              |
| :------: | :------------------------------------------------ |
|  浏览器  | Edge，Google Chrome                               |
| 聊天办公 | QQ，微信，飞书，Xmind，向日葵，亿图图示，WPS 2019 |
| 编程开发 | Visual Studio Code，Vim，Typora，Wireshark        |
| 虚拟软件 | Virtual Box，VMware Workstation Pro               |
| 电子阅读 | Calibre                                           |
| 影音娱乐 | OBS Studio，QQ音乐，VLC播放器，Steam              |
| 系统工具 | GParted，FSearch                                  |
|   云盘   | 百度网盘                                          |

> 因为软件官方更新或CDN的缘故，以下链接极有可能会失效，只是时间问题，为此，已将下载好的deb包压缩并上传至网盘。

### 安装[Microsoft Edge](https://www.microsoft.com/zh-cn/edge/download)

```bash
curl -O https://packages.microsoft.com/repos/edge/pool/main/m/microsoft-edge-stable/microsoft-edge-stable_112.0.1722.48-1_amd64.deb

sudo dpkg -i microsoft-edge-stable_112.0.1722.48-1_amd64.deb
```

### 安装[Google Chrome](https://www.google.cn/chrome/)

```bash
curl -O https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome-stable_current_amd64.deb
```

### 安装[WPS 2019](https://linux.wps.cn/)

```bash
curl -O https://wps-linux-personal.wpscdn.cn/wps/download/ep/Linux2019/11691/wps-office_11.1.0.11691_amd64.deb

sudo dpkg -i wps-office_11.1.0.11691_amd64.deb
```

### 安装[Visual Studio Code](https://code.visualstudio.com/download)

```bash
curl -O https://az764295.vo.msecnd.net/stable/704ed70d4fd1c6bd6342c436f1ede30d1cff4710/code_1.77.3-1681292746_amd64.deb

sudo dpkg -i code_1.77.3-1681292746_amd64.deb
```

### 安装[Vim](https://www.vim.org/download.php)

```bash
sudo apt install vim
```

### 安装[QQ](https://im.qq.com/linuxqq/index.shtml)

```bash
curl -O https://dldir1.qq.com/qqfile/qq/QQNT/2355235c/linuxqq_3.1.1-11223_amd64.deb
sudo dpkg -i linuxqq_3.1.1-11223_amd64.deb
```

### 安装[Oracle VM Virtual Box](https://download.virtualbox.org/virtualbox)

```bash
curl -O https://download.virtualbox.org/virtualbox/7.0.0/virtualbox-7.0_7.0.0-153978~Ubuntu~jammy_amd64.deb
curl -O https://download.virtualbox.org/virtualbox/7.0.0/Oracle_VM_VirtualBox_Extension_Pack-7.0.0.vbox-extpack

sudo dpkg -i virtualbox-7.0_7.0.0-153978~Ubuntu~jammy_amd64.deb
sudo VBoxManage extpack install Oracle_VM_VirtualBox_Extension_Pack-7.0.0.vbox-extpack 
```

### 安装[百度网盘](https://pan.baidu.com/download#linux)

```bash
curl -O https://112-50-156-165-yfd6c95e.cdnnode.cn:2269/fs698f85d5.a.bdydns.com/bdydns_7576f687a325f1e529e9fcf086ffae5f815bdfae/baidunetdisk_4.17.7_amd64.deb

sudo dpkg -i baidunetdisk_4.17.7_amd64.deb
```

### 安装[微信](https://www.ubuntukylin.com/applications/106-cn.html)

在[优麒麟商店](https://www.ubuntukylin.com/applications/)搜索"微信"

```bash
curl -O https://archive.ubuntukylin.com/software/pool/partner/weixin_2.1.1_amd64.deb
sudo dpkg -i weixin_2.1.1_amd64.deb
```

### 安装[飞书](https://www.feishu.cn/)

```bash
curl -O https://sf3-cn.feishucdn.com/obj/ee-appcenter/399c2025/Feishu-linux_x64-5.30.15.deb

sudo dpkg -i Feishu-linux_x64-5.30.15.deb
```

### 安装[Typora](https://www.typoraio.cn/#linux)

```bash
curl -O https://download2.typoraio.cn/linux/typora_1.5.10_amd64.deb
sudo dpkg -i typora_1.5.10_amd64.deb
```

### 安装[OBS Studio](https://obsproject.com/)

```bash
sudo add-apt-repository ppa:obsproject/obs-studio
sudo apt update
sudo apt install ffmpeg obs-studio
```

### 安装[向日葵](https://sunlogin.oray.com/download)

```bash
curl -O https://down.oray.com/sunlogin/linux/SunloginClient_11.0.1.44968_amd64.deb
sudo dpkg -i SunloginClient_11.0.1.44968_amd64.deb
```

### 安装[Steam](https://store.steampowered.com/about/)

```bash
curl -O https://repo.steampowered.com/steam/archive/precise/steam_latest.deb
sudo dpkg -i steam_latest.deb
```

### 安装[亿图图示](https://www.edrawsoft.cn/download-edrawmax.html)

```bash
curl -O https://cc-download.edrawsoft.cn/EdrawMax_12.0.6_cn.deb
sudo dpkg -i EdrawMax_12.0.6_cn.deb
```

### 安装FSearch

```bash
sudo apt install fsearch
```

### 安装Xmind

```bash
curl -O https://dl2.xmind.cn/Xmind-for-Linux-amd64bit-22.11.3656.deb
sudo dpkg -i Xmind-for-Linux-amd64bit-22.11.3656.deb
```

### 安装[QQ音乐](https://y.qq.com/download/download.html)

```bash
curl -O https://68704497b4143c83511ee468e56ef784.rdt.tfogc.com:49156/dldir1.qq.com/music/clntupate/linux/deb/qqmusic_1.1.5_amd64.deb

sudo dpkg -i qqmusic_1.1.5_amd64.deb
```

### 安装[QT Creator](https://download.qt.io/official_releases/qtcreator/)

```bash
curl -O https://download.qt.io/official_releases/qtcreator/8.0/8.0.0/qt-creator-opensource-linux-x86_64-8.0.0.run

sudo chmod +x qt-opensource-linux-x64-5.12.9.run
sudo ./qt-opensource-linux-x64-5.12.9.run
```

### 安装VLC播放器

```bash
sudo apt install vlc browser-plugin-vlc ubuntu-restricted-extras
```

### 安装[Wireshark](https://www.wireshark.org/download.html)

```bash
sudo add-apt-repository ppa:wireshark-dev/stable
sudo apt update
sudo apt install wireshark
sudo usermod -aG wireshark $USER
```

### 安装[Calibre](https://calibre-ebook.com/download_linux)

```bash
sudo -v && wget -nv -O- https://download.calibre-ebook.com/linux-installer.sh | sudo sh /dev/stdin install_dir=/opt
```

### 安装Gparted

```bash
sudo apt install gparted
```

