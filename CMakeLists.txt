cmake_minimum_required(VERSION 3.16)
project(semwork)

set(CMAKE_CXX_STANDARD 14)

add_executable(semwork src/main.cpp src/Calculator/CCalculator.cpp src/Calculator/CCalculator.h src/Matrix/CMatrix.cpp src/Matrix/CMatrix.h src/Matrix/CMatrixDense.cpp src/Matrix/CMatrixDense.h src/Matrix/CMatrixSparse.cpp src/Matrix/CMatrixSparse.h src/Command/CCommand.cpp src/Command/CCommand.h src/Command/Common/CHelp.cpp src/Command/Common/CHelp.h src/Calculator/CMemory.cpp src/Calculator/CMemory.h src/Calculator/CHistory.cpp src/Calculator/CHistory.h)
