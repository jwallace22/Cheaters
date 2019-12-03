Cheaters: readDir.o hashTable.o chunk.o
	g++ -o Cheaters readDir.o hashTable.o chunk.o
readDir.o: readDir.cpp chunk.h hashTable.h
	g++ -std=c++0x readDir.cpp
hashTable.o: hashTable.cpp hashTable.h chunk.h
	g++ -std=c++0x hashTable.cpp
chunk.o: chunk.cpp chunk.h
	g++ -std=c++0x chunk.cpp

