The Cheaters Program By Jeffery Wallace and Darren Nguyen
12/6/2019

To make project:
Type in: "make"

To run project:
Type in: "./Cheaters (filepath to document set) (size of word chunks) (plagerism threshold)"
Example: "./Cheaters /home/ecelrc/students/ftark10/doc_set 6 200"
	This will check the document and report if there are more than 200 6 word chunks that are similar between documents

Running with valgrind:
When running in valgrind, you will need to include "--max-stackframe=24593984" as a flag after "valgrind"

Structure of the program:
The program works by first receiving a document from the set and seperating the words into chunk objects of the size specified.
These chunks are then filtered so only the words remain in uppercase format. These word chunks are then put through
a hash function to be put onto a hash. The hash table consists of a array of linked lists. This hash table is then checked for collisions which are put on a collision table.
The collision table is then used to check is the similarites are above the threshold required. If so they are put in a sorted list. This continues for every document in the directory.
At the end the similarities are printed out onto the screen.
 