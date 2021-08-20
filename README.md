# doudizhu

斗地主机器人

## 使用方法

使用以下指令克隆本仓库

```bash
git clone https://gitee.com/qb435/doudizhu.git --recursive
cd doudizhu
# 更新 mirai-cpp 到最新
git submodule update --init --force --remote
```

然后使用 Visual Studio 或 Visual Studio Code 直接打开整个文件夹即可。

头文件请添加到 **include** 目录中

源文件请添加到 **src** 目录中，并且不要忘记修改 **CMakeLists.txt**。（参考CMakeLists.txt中的注释进行修改）


mirai-cpp 的说明文档：[使用说明](https://github.com/cyanray/mirai-cpp/blob/master/doc/%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E.md)

## 切换 mirai-cpp 版本

### 1. 更新到最新版 mirai-cpp

直接在本项目根目录执行以下指令:

```bash
# 更新 mirai-cpp 到最新
git submodule update --init --force --remote
```
### 2. 使用特定版本的 mirai-cpp

如果你目前使用的是旧版本的 mirai/mirai-console/mirai-api-http，请根据 **mirai-api-http** 的版本号选择对应的 **mirai-cpp** 版本，以保证兼容性。

例如，mirai-api-http 的版本为 **1.8.4**，那么请使用 **mirai-cpp v1.8.4**。

切换方法如下：

```bash
cd mirai-cpp
git pull
git checkout v1.8.4
```
