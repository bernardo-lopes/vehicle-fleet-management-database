cmake_minimum_required(VERSION 3.21)
project(MFConnect)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Debug)
include_directories(x64)
include_directories(x64/Debug)

add_executable(MFConnect
        Debug/MFConnect.pch
        x64/Debug/MFConnect.pch
        framework.h
        MFConnect.cpp
        MFConnect.h
        MFConnectDlg.cpp
        MFConnectDlg.h
        myconnectorclassDB.cpp
        myconnectorclassDB.h
        pch.cpp
        pch.h
        resource.h
        targetver.h)
