set BOOST_ROOT=C:/local/boost_1_88_0
REM set BOOST_INCLUDEDIR=C:/local/boost_1_88_0/lib64-msvc-14.3
REM set BOOST_LIBRARYDIR=C:/local/boost_1_88_0/lib64-msvc-14.3
cd rtamt/rtamt
mkdir build
cd build
REM -DBOOST_ROOT:PATHNAME=C:/local/boost_1_88_0/lib64-msvc-14.3
REM -DBoost_NO_BOOST_CMAKE=TRUE
REM -DBoost_NO_SYSTEM_PATHS=TRUE
REM cmake --fresh --trace -Wno-dev -DPythonVersion=3 -DBOOST_ROOT=%BOOST_ROOT% -DBoost_DEBUG=ON ../ -G"Visual Studio 17 2022"
cmake --fresh --trace -Wno-dev -DPythonVersion=3 -DBOOST_ROOT=%BOOST_ROOT% -DBoost_DEBUG=ON ../
