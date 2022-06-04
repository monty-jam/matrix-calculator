cmake_minimum_required(VERSION 3.16)
project(semwork)

set(CMAKE_CXX_STANDARD 14)

add_executable(semwork src/main.cpp src/Calculator/CCalculator.cpp src/Calculator/CCalculator.h src/Matrix/CMatrix.cpp src/Matrix/CMatrix.h src/Matrix/CMatrixDense.cpp src/Matrix/CMatrixDense.h src/Matrix/CMatrixSparse.cpp src/Matrix/CMatrixSparse.h src/Command/Common/CCommand.cpp src/Command/Common/CCommand.h src/Command/Common/CHelp.cpp src/Command/Common/CHelp.h src/Command/Common/CExit.cpp src/Command/Common/CExit.h src/Command/Common/CHelpCmd.cpp src/Command/Common/CHelpCmd.h src/Command/Common/CVars.cpp src/Command/Common/CVars.h src/Command/Common/CDel.cpp src/Command/Common/CDel.h)
