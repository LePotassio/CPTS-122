#include "Queue.h"

/*
Questions:

Dynamic allocation and delete
Passing by ref &


*/


int main(void) {
	//Behold, the great variable clown fiesta
	//	||
	//	||
	//	\/
	int timeMax = 0;
	int totalTime = 0;
	std::cout << "How many mins ?" << std::endl;
	std::cin >> timeMax;
	srand(time(NULL));
	//if time = 60*24
	int time = 0;
	int express = 0;
	int expressA = 0;
	int normal = 0;
	int normalA = 0;
	int cNum = 1;
	int lineLengthE = 0;
	int lineLengthN = 0;
	int steE = 0;
	int steN = 0;
	Queue Express;
	Queue Normal;

	//End variable clown fiesta
	expressA = rand() % 5 + 1;
	normalA = rand() % 6 + 3;
	while (timeMax != totalTime) {
		//Sleep(1000);
		if (time == expressA) {
			Express.enqueue("Express", cNum);
			lineLengthE += Express.getPTail()->getPData()->getServiceTime();
			std::cout << "Arriving in Express";
			Express.getPTail()->printqueuenode("Express");
			cNum++;
			expressA = (rand() % 5 + 1) + time;
			Express.getPTail()->getPData()->setTotalTime(lineLengthE);
		}

		if (time == normalA) {
			Normal.enqueue("Normal", cNum);
			lineLengthN += Normal.getPTail()->getPData()->getServiceTime();
			std::cout << "Arriving in Normal";
			Normal.getPTail()->printqueuenode("Normal");
			cNum++;
			normalA = (rand() % 6 + 3) + time;
			Normal.getPTail()->getPData()->setTotalTime(lineLengthN);
		}
		steE++;
		steN++;
		if (Express.getPHead() == nullptr) {
			steE = 0;
		}
		if (Normal.getPHead() == nullptr) {
			steN = 0;
		}
		//add to total time when dequeueing
		if (Express.getPHead() != nullptr && steE == Express.getPHead()->getPData()->getServiceTime()) {
			std::cout << "Leaving in " << "Express" << " Customer: " << Express.getPHead()->getPData()->getCustomerNumber() << std::endl;
			lineLengthE -= Express.getPHead()->getPData()->getServiceTime();
			Express.dequeue();
			steE = 0;
		}
		if (Normal.getPHead() != nullptr && steN == Normal.getPHead()->getPData()->getServiceTime()) {
			std::cout << "Leaving in " << "Normal" << " Customer: " << Normal.getPHead()->getPData()->getCustomerNumber() << std::endl;
			lineLengthN -= Normal.getPHead()->getPData()->getServiceTime();
			Normal.dequeue();
			steN = 0;
		}

		time++;
		totalTime++;
		if (time % 10 == 0) {
			std::cout << std::endl << "10 min queue view----------------" << std::endl;
			std::cout << "Express:" << std::endl;
			Express.printqueue("Express");
			std::cout << "Normal:" << std::endl;
			Normal.printqueue("Normal");
			std::cout << "End of recap---------------------" << std::endl << std::endl;
		}
		if (time == 60 * 24) {
			time = 0;
			expressA = rand() % 5 + 1;
			normalA = rand() % 6 + 3;
			cNum = 1;
		}
	}


	return 0;
}