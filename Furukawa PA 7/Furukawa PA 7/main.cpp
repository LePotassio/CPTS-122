#include "BST.h"

int main(void) {
	BST morseKey(true);

	morseKey.inOrderTraversal();

	morseKey.convertFile();

	//delets with destructor when leaving scope
	return 0;
}