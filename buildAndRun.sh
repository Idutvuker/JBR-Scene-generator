mkdir build_$1
cd build_$1

cmake .. &&
make &&
make install &&
./SceneGen
