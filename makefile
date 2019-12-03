Cheaters: readDir.o hashTable.o chunk.o
	g++ -o Cheaters readDir.o hashTable.o chunk.o
readDir.o: readDir.cpp .h chunk.h hashTable.h
	g++ -c readDir.cpp
hashTable.o: hashTable.cpp hashTable.h chunk.h
	g++ -c hashTable.cpp
chunk.o: chunk.cpp chunk.h
	g++ -c chunk.cpp

