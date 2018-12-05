# SDK
## 目录组织

- **Solver/**
  中心选址问题的 Visual C++ 项目.
  核心算法.

- **Protocol/**
  - PCenter.proto
    中心选址问题的输入输出数据定义文件.

- **Simulator/**
  提供算法交互接口的 Visual C++ 项目.
  实现批量测试与结果展示等功能.

- **Checker/**
  中心选址问题计算结果检查程序的 Visual C++ 项目.

- **Analyzer/**
  中心选址问题算例/结果/日志分析程序的 Visual C# 项目.

- **Deploy/**
  开发阶段程序部署目录, 包含程序运行所需要的所有可执行文件和数据.
  - **Instance/**
    输入数据.
  - **Solution/**
    求解结果.
  - **Visualization/**
    结果可视化.

- **Doc/**
  项目文档.
  - **ProblemDescription.md**
    中心选址问题描述文档.

- **Lib/**
  第三方库.
  - **protobuf**
    由 Google 开发的数据交换格式.
    访问 https://github.com/google/protobuf/releases 下载最新版本.
    - **bin/**
      生成对消息进行序列化与反序列化的代码的工具.
    - **include/**
      头文件. 应被设置为 "附加包含文件".
    - **lib/**
      静态链接库. 应被设置为 "附加库目录".
      该文件夹下的库文件应被设置为 "附加依赖项".



## 编译链接

### 修改代码

1. 在 `Solver.cpp` 中搜索 `TODO[0]`, 并在对应位置添加求解算法的代码.
2. 在 `Problem.h` 中搜索 `TODO[0]`, 并在对应位置修改提交至测评系统的信息.


### 编译链接

1. 自己编译 protobuf 或者在群共享下载 `解压至Lib目录(protobuf3.6.1_vs2017_MT+MTd_x64).zip` 并解压至 `Lib` 目录.
2. 运行 `Protocol/` 目录下的 `generate.bat` (未更改 `*.proto` 文件可跳过该步骤).
3. 打开根目录下的 Visual Studio 2017 解决方案文件 `PCenter.sln`, 设置输出选项为 Release x64, 生成解决方案.

------------------

# 问题描述

## 问题背景

- P-center问题，在给定N个节点的网络中选择P个节点作为服务设施。
- P中心设备选址问题是著名的离散选址问题，属于NP-hard，其一般具有多约束、大规模、多目标和不确定性等特点。
- P-center问题有着广泛的现实应用场景，如消防站选址、物流运输网络、服务器网络等。
- 物流对于企业来说是第三利润源泉，因此为物流配送中心 选好位址可以提高企业整体效益，节约企业成本是企业发展的新战略。

## 概述

在给定的 $N$ 个节点的网络中选择 $P$ 个节点作为服务设施, 为剩余 $(N - P)$ 个节点提供服务, 要求所有用户节点的服务边中的最长边最短.


## 已知

- 无向图
  - 若干无向边
- 中心节点数


## 约束

- 选取的中心节点数不超过给定值


## 目标

最小化最长服务边的边长.


## 决策

在哪些节点设置中心.



## 数据接口

### 输入数据格式

### 基本情况

见 `Protocol/PCenter.proto`.

#### 数据约定

- 节点数不超过 5000
- 中心数不超过 5000
- 节点编号为从 0 开始的连续整数


### 输出数据格式

### 基本情况
见 `Protocol/PCenter.proto`.

---------------

# 求解算法描述
- **neighbor_move.cpp**
核心算法
  - **serveS**
  服务节点集合
  - **node**
  F表和D表的数据结构
    - F表代表最近和次近节点序号
    - D表代表最近和次近节点距离
  - **Algorithm_paraments**
  算法参数
  - **P_center_action**
  核心搜索过程和禁忌策略
