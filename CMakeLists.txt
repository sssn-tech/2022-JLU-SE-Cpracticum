cmake_minimum_required(VERSION 3.24)
project(jlu_bar_v1_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headfiles)
link_libraries(EasyX.a)

add_executable(jlu_bar_v1_0
        Headfiles/CartChain.h
        Headfiles/ChainOpt.h
        Headfiles/ClientChain.h
        Headfiles/CommodityChain.h
        Headfiles/GetTime.h
        Headfiles/GraphPage.h
        Headfiles/InputCheck.h
        Headfiles/LinearRegression.h
        Headfiles/loginFunction.h
        Headfiles/MD5.h
        Headfiles/RecordChain.h
        Headfiles/StrSimilar.h
        Sources/CartChain.cpp
        Sources/ChainOpt.cpp
        Sources/ClientChain.cpp
        Sources/CommodityChain.cpp
        Sources/GraphPage.cpp
        Sources/GteTime.cpp
        Sources/InputCheck.cpp
        Sources/loginFunction.cpp
        Sources/MD5.cpp
        Sources/RecordChain.cpp
        Sources/StrSimilar.cpp
        main.cpp)
