CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic
TRGDIR= ./test_lazika
OBJ= ./obj

___start___: ${TRGDIR}/test_lazikap
	${TRGDIR}/test_lazikap

${TRGDIR}:
	mkdir -p ${TRGDIR}

${OBJ}:
	mkdir -p ${OBJ}

${TRGDIR}/test_lazikap: ${OBJ} ${OBJ}/main.o ${OBJ}/Wektor3D.o ${OBJ}/Macierz3D.o
	g++ -o ${TRGDIR}/test_lazikap ${OBJ}/main.o ${OBJ}/Wektor3D.o ${OBJ}/Macierz3D.o

${OBJ}/main.o: src/main.cpp inc/Wektor3D.hh inc/Macierz3D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Wektor3D.o src/Wektor3D.cpp

${OBJ}/Macierz3D.o: src/Macierz3D.cpp
	g++ ${CXXFLAGS} -o ${OBJ}/Macierz3D.o src/Macierz3D.cpp

