Cheaters: Cheaters.o hashTable.o chunk.o
	g++ -std=c++0x -o plagiarismCatcher Cheaters.o hashTable.o chunk.o
Cheaters.o: Cheaters.cpp hashTable.h chunk.h
	g++ -std=c++0x -c Cheaters.cpp
hashTable.o: hashTable.cpp hashTable.h chunk.h
	g++ -std=c++0x -c hashTable.cpp
chunk.o: chunk.cpp chunk.h
	g++ -std=c++0x -c chunk.cpp

