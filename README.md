# lencey

C11 小型项目。

## 构建

    mkdir -p build && cd build
    cmake ..
    make -j$(nproc)

产物：`bin/lencey`

## 测试

    cd build && ctest --output-on-failure
