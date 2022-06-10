CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic
TRGDIR= ./test_lazika
OBJ= ./obj

___start___: ${TRGDIR}/test_lazikap
	${TRGDIR}/test_lazikap

${TRGDIR}:
	mkdir -p ${TRGDIR}

${OBJ}:
	mkdir -p ${OBJ}

${TRGDIR}/test_lazikap: ${OBJ} ${OBJ}/main.o ${OBJ}/Wektor3D.o ${OBJ}/Macierz3D.o ${OBJ}/OperacjeMat.o ${OBJ}/ObiektGeom.o ${OBJ}/lacze_do_gnuplota.o ${OBJ}/PowierzchniaMarsa.o ${OBJ}/Lazik.o ${OBJ}/Scena.o ${OBJ}/ProbkaRegolitu.o ${OBJ}/ObrysXY.o
	g++ -o ${TRGDIR}/test_lazikap ${OBJ}/main.o ${OBJ}/Wektor3D.o ${OBJ}/Macierz3D.o ${OBJ}/OperacjeMat.o ${OBJ}/ObiektGeom.o ${OBJ}/lacze_do_gnuplota.o ${OBJ}/PowierzchniaMarsa.o ${OBJ}/Lazik.o ${OBJ}/Scena.o ${OBJ}/ProbkaRegolitu.o ${OBJ}/ObrysXY.o

${OBJ}/main.o: src/main.cpp inc/Wektor3D.hh inc/Macierz3D.hh inc/ObiektGeom.hh inc/lacze_do_gnuplota.hh inc/PowierzchniaMarsa.hh inc/ProbkaRegolitu.hh
	g++ ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Scena.o: src/Scena.cpp inc/Lazik.hh inc/lacze_do_gnuplota.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Scena.o src/Scena.cpp

${OBJ}/ProbkaRegolitu.o: src/ProbkaRegolitu.cpp inc/ObiektGeom.hh inc/Lazik.hh
	g++ ${CXXFLAGS} -o ${OBJ}/ProbkaRegolitu.o src/ProbkaRegolitu.cpp

${OBJ}/Lazik.o: src/Lazik.cpp inc/ObiektGeom.hh inc/OperacjeMat.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Lazik.o src/Lazik.cpp

${OBJ}/ObiektGeom.o: src/ObiektGeom.cpp inc/Wektor3D.hh inc/Macierz3D.hh inc/ObrysXY.hh
	g++ ${CXXFLAGS} -o ${OBJ}/ObiektGeom.o	src/ObiektGeom.cpp

${OBJ}/ObrysXY.o: src/ObrysXY.cpp inc/Wektor2D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/ObrysXY.o src/ObrysXY.cpp

${OBJ}/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Wektor3D.o src/Wektor3D.cpp

${OBJ}/Macierz3D.o: src/Macierz3D.cpp inc/OperacjeMat.hh
	g++ ${CXXFLAGS} -o ${OBJ}/Macierz3D.o src/Macierz3D.cpp

${OBJ}/OperacjeMat.o: src/OperacjeMat.cpp
	g++ ${CXXFLAGS} -o ${OBJ}/OperacjeMat.o src/OperacjeMat.cpp

${OBJ}/PowierzchniaMarsa.o: src/PowierzchniaMarsa.cpp inc/lacze_do_gnuplota.hh
	g++ ${CXXFLAGS} -o ${OBJ}/PowierzchniaMarsa.o src/PowierzchniaMarsa.cpp

${OBJ}/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp
	g++ ${CXXFLAGS} -o ${OBJ}/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp
