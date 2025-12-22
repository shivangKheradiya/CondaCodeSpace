mkdir build
cd build
cmake -G Ninja -DCMAKE_PREFIX_PATH=$CONDA_PREFIX ..
ninja