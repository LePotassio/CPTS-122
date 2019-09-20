#include "test.h"

void testempty() {
	snek queue;
	std::cout << queue.issnekshed();
}

void testensnek() {
	snek queue;
	bool success;
	success = queue.ensnek("wut");
	std::cout << success;
}

void testdesnek() {
	snek queue;
	string removed;
	queue.ensnek("wut");
	removed = queue.desnek();
	std::cout << removed;
}

void testprint() {
	snek queue;
	string removed;
	queue.ensnek("wut");
	queue.ensnek("da");
	queue.ensnek("fuq");
	queue.printsnekre(queue.getsnekhead());
}