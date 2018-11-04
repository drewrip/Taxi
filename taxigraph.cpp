#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include <fstream>

#define TRIALS 1000000

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
	std::ofstream data;
  	data.open("data/graph.dat");
	int successes = 0;
	srand(time(NULL));
	std::cout << std::setprecision(30) << std::fixed;
	data << std::setprecision(30) << std::fixed;
	for(int i=0; i < TRIALS; i++){
		successes += (int)draw();
		data << i+1 << "\t" << ((double)successes/(i+1)) << std::endl;
	}
	std::cout << "Individual Drawn: " << successes << "\tNumber Of Trials: " << TRIALS << "\tFrequency: " << ((double)successes/TRIALS) << std::endl;
	std::cout << "Time Series Written to data/graph.dat" << std::endl;
	data.close();
	return 0;
}