# VideoToChar
c++实现的视频转字符画

## 使用说明
- 源码版本使用需要配置 OpenCV.
- Release版本使用时，在程序所在目录放置视频 `video.mp4` 即可.

## 简要环境配置教程

### 下载 OpenCV 

1. 访问 [OpenCV 官网](https://opencv.org/releases/)，下载 Windows 版本 Release. 

   文件名类似于 `opencv-4.5.5-vc14_vc15.exe`

2. 这个文件其实是自解压程序，双击解压到合适的位置，比如：`D:\`。

3. 解压后将得到一个目录：`D:\opencv`。


### 配置环境变量

将 OpenCV 的 "bin" 文件夹路径添加到环境变量，否则可能出现 "xxx.dll 无法找到" 一类的错误。

本例中为 `D:\opencv\build\bin` 以及 `D:\opencv\build\x64\vc15\bin`。

注意，示例中的 "vc15" 需要根据 visual studio 版本进行修改，你可以参考下列表格：

| VS 版本 | VC 版本 |
| ------- | ------- |
| VS2003  | VC7     |
| VS2005  | VC8     |
| VS2008  | VC9     |
| VS2010  | VC10    |
| VS2012  | VC11    |
| VS2013  | VC12    |
| VS2015  | VC14    |
| VS2017  | VC15    |

多提一句，".dll" 后缀之前有 "d" 的是 "debug" 版本，否则为 "release" 版本。

另外，添加环境变量后可能要重启后才能生效。

### 编写 CMakeList.txt

以本项目为例：

```cmake
cmake_minimum_required (VERSION 3.8)
add_executable (VideoToChar "VideoToChar.cpp" "VideoToChar.h")
set(OpenCV_DIR D:/opencv/build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
target_link_libraries(VideoToChar ${OpenCV_LIBS})
```

注意到以下几点：

- 第 3 行 需要配置 OpenCV_DIR 为 "`你刚刚解压的路径\build`"
- 第 7 行 记得将 lib 链接到项目

### ==END==

至此，OpenCV 环境配置完成。