Cheaters: readDir.o hashTable.o chunk.o
	g++ -std=c++0x -o Cheaters readDir.o hashTable.o chunk.o
readDir.o: readDir.cpp hashTable.h chunk.h
	g++ -std=c++0x -c readDir.cpp
hashTable.o: hashTable.cpp hashTable.h chunk.h
	g++ -std=c++0x -c hashTable.cpp
chunk.o: chunk.cpp chunk.h
	g++ -std=c++0x -c chunk.cpp

