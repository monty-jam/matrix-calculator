cmake_minimum_required(VERSION 3.16)
project(semwork)

set(CMAKE_CXX_STANDARD 14)

add_executable(semwork main.cpp Calculator/CCalculator.cpp Calculator/CCalculator.h Calculator/CEvaluator.cpp Calculator/CEvaluator.h Matrix/CMatrix.cpp Matrix/CMatrix.h Matrix/CMatrixDense.cpp Matrix/CMatrixDense.h Matrix/CMatrixSparse.cpp Matrix/CMatrixSparse.h)
