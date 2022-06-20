CXXFLAGS = -Wall -pedantic -std=c++17

HEADERS = $(wildcard src/*.h src/*/*.h src/*/*/*.h)
SOURCES = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=build/%.o)

.PHONY: all
all: compile doc

.PHONY: run
run: compile
	./popovle1

.PHONY: compile
compile: popovle1

popovle1: build/main
	cp $< $@

build/main: $(OBJECTS)
	mkdir -p $(@D)
	g++ $^ -o $@

build/%.o: src/%.cpp
	mkdir -p $(@D)
	g++ $(CXXFLAGS) $< -c -o $@

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile
	touch doc/index.html
	echo '<meta http-equiv="REFRESH" content="0;URL=html/index.html">' > doc/index.html

.PHONY: clean
clean:
	rm -rf popovle1 build/ debug/ doc/ 2>/dev/null

# dependencies:

build/main.o: src/main.cpp src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h src/Command/CCommand.h
build/CMatrixDense.o: src/Matrix/CMatrixDense.cpp src/Matrix/CMatrixDense.h \
 src/Matrix/CMatrix.h
build/CMatrix.o: src/Matrix/CMatrix.cpp src/Matrix/CMatrix.h \
 src/Matrix/CMatrixDense.h src/Matrix/CMatrixSparse.h
build/CMatrixSparse.o: src/Matrix/CMatrixSparse.cpp src/Matrix/CMatrixSparse.h \
 src/Matrix/CMatrix.h src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h src/Calculator/CHistory.h \
 src/Command/CCommand.h
build/CHistory.o: src/Calculator/CHistory.cpp src/Calculator/CHistory.h \
 src/Command/CCommand.h src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h
build/CCalculator.o: src/Calculator/CCalculator.cpp \
 src/Calculator/CCalculator.h src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h src/Calculator/CHistory.h \
 src/Command/CCommand.h \
 src/Command/Basic/CHelp.h \
 src/Command/Basic/CExit.h \
 src/Command/Basic/CVars.h \
 src/Command/Memory/CScan.h \
 src/Command/Memory/CPrint.h \
 src/Command/Operation/CAdd.h \
 src/Command/Operation/CSub.h \
 src/Command/Operation/CMul.h \
 src/Command/Operation/CTrans.h \
 src/Command/Operation/CMerge.h \
 src/Command/Operation/CCut.h \
 src/Command/Basic/CUndo.h \
 src/Command/Basic/CHelpCmd.h \
 src/Command/Math/CGem.h \
 src/Command/Basic/CDel.h \
 src/Command/Math/CRank.h \
 src/Command/Math/CDet.h \
 src/Command/Math/CInv.h \
 src/Command/Math/CAdj.h \
 src/Command/Memory/CSave.h \
 src/Command/Memory/CLoad.h
build/CMemory.o: src/Calculator/CMemory.cpp src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h
build/CCommand.o: src/Command/CCommand.cpp src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h
build/CSave.o: src/Command/Memory/CSave.cpp src/Command/Memory/CSave.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h
build/CScan.o: src/Command/Memory/CScan.cpp src/Command/Memory/CScan.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h \
 src/Matrix/CMatrixSparse.h \
 src/Matrix/CMatrixDense.h
build/CLoad.o: src/Command/Memory/CLoad.cpp src/Command/Memory/CLoad.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h \
 src/Matrix/CMatrixSparse.h
build/CPrint.o: src/Command/Memory/CPrint.cpp src/Command/Memory/CPrint.h \
 src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CHistory.h
build/CSub.o: src/Command/Operation/CSub.cpp src/Command/Operation/CSub.h \
 src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CHistory.h
build/CCut.o: src/Command/Operation/CCut.cpp src/Command/Operation/CCut.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h
build/CMul.o: src/Command/Operation/CMul.cpp src/Command/Operation/CMul.h \
 src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CHistory.h
build/CMerge.o: src/Command/Operation/CMerge.cpp src/Command/Operation/CMerge.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h
build/CAdd.o: src/Command/Operation/CAdd.cpp src/Command/Operation/CAdd.h \
 src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CHistory.h
build/CTrans.o: src/Command/Operation/CTrans.cpp src/Command/Operation/CTrans.h \
 src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CHistory.h
build/CUndo.o: src/Command/Basic/CUndo.cpp src/Command/Basic/CUndo.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h
build/CHelpCmd.o: src/Command/Basic/CHelpCmd.cpp src/Command/Basic/CHelpCmd.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h
build/CDel.o: src/Command/Basic/CDel.cpp src/Command/Basic/CDel.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h
build/CVars.o: src/Command/Basic/CVars.cpp src/Command/Basic/CVars.h \
 src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CHistory.h
build/CExit.o: src/Command/Basic/CExit.cpp src/Command/Basic/CExit.h \
 src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CHistory.h
build/CHelp.o: src/Command/Basic/CHelp.cpp src/Command/Basic/CHelp.h \
 src/Command/CCommand.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CHistory.h
build/CRank.o: src/Command/Math/CRank.cpp src/Command/Math/CRank.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h \
 src/Command/Math/CGem.h src/Command/Basic/CDel.h
build/CAdj.o: src/Command/Math/CAdj.cpp src/Command/Math/CAdj.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h \
 src/Command/Math/CDet.h src/Command/Operation/CTrans.h
build/CDet.o: src/Command/Math/CDet.cpp src/Command/Math/CDet.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h \
 src/Command/Math/CGem.h src/Command/Basic/CDel.h \
 src/Calculator/CCalculator.h
build/CInv.o: src/Command/Math/CInv.cpp src/Command/Math/CInv.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h \
 src/Command/Math/CDet.h src/Command/Operation/CTrans.h \
 src/Command/Math/CAdj.h
build/CGem.o: src/Command/Math/CGem.cpp src/Command/Math/CGem.h \
 src/Calculator/CCalculator.h \
 src/Calculator/CMemory.h \
 src/Matrix/CMatrix.h \
 src/Calculator/CHistory.h \
 src/Command/CCommand.h