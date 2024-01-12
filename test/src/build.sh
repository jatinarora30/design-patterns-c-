rm -rf build
mkdir build 
cd build
cmake ..
make -j8
./object_counter_test
