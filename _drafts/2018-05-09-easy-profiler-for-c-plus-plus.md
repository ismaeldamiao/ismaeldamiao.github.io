---
published: false
title: easy_profiler for c++
classes: wide
categories:
  - Tools
tags:
  - c++
  - performance
---

The real-time performance is really important in self-driving software developments. A easy-to-use, accurate program profiler is very useful for improving the existing software. The `easy_profiler` seems decent.

### Build and Install
```
git clone https://github.com/yse/easy_profiler.git
cd easy_profiler
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE="Release" ..
make -j4
sudo make install
```

### Use it with CMake
In CMakelist file, add
```cmake
project(app_for_profiling)

set(SOURCES
    main.cpp
)

find_package(easy_profiler REQUIRED)

add_executable(app_for_profiling ${SOURCES})

target_link_libraries(app_for_profiling easy_profiler)

```
Trick: have to put an `EASY_END_BLOCK` before the `profiler::dumpBlocksToFile("gd_profile.prof")`, or the gui can not open the profile file.

If you want to disable the profiler, just compile the project
