#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>

#define TRIALS 1000000000000

#define WINNER 0x00
#define SINGLE 0x33
#define DOUBLE 0x77
#define TRIPLE 0xff

std::vector<unsigned char> pool;
bool draw(){
	int tick = 0;
	pool = {TRIPLE, TRIPLE, TRIPLE, TRIPLE, TRIPLE, TRIPLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, SINGLE, SINGLE, SINGLE, SINGLE, WINNER};
	while(tick < 10){
		int pick = rand() % (pool.size());
		unsigned char CURRTICK = pool[pick];
		pool.erase(pool.begin()+pick);
		if(CURRTICK == WINNER){
			return true;	
		}
		else if(CURRTICK == SINGLE){
			tick += 1;
		}
		else if(CURRTICK == DOUBLE){
			tick += 2;
		}
		else if(CURRTICK == TRIPLE){
			tick += 3;
		}
		else{
			std::cout << "ERROR: I don't understand this ticket" << std::endl;
		}
	}
	return false;
}

int main(){
	int successes = 0;
	srand(time(NULL));
	std::cout << std::setprecision(30) << std::fixed;
	for(int i=0; i < TRIALS; i++){
		successes += (int)draw();
		std::cout << "\r" << ((double)successes/(i+1));
	}
	return 0;
}