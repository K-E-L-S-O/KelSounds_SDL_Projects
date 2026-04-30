//Digital Volume Knob
//practice 4_29_2026

#include <iostream>
#include <algorithm>

double setGain();//prototype

int main() {

	const int size = 100;//Maximum amount
	double soundWaves[size];//our array to hold out values
	int count = 0;//'count' will be used to read the amount of values entered
	double gainValue;//user will set the gain value
	double value;//user enter a value for the array
	bool isClipping = false;//our 'flag' red light indicator to tell


	gainValue = setGain();//getting the gain value

	std::cout << "Enter a value\n";
	std::cout << "Enter '-1' to exit\n\n";
	std::cin >> value;

	//we are going to use 'std::cin' as a virtual knob. Even though
	//we cannot implement a knob yet...
	while (value != -1 && count < size) {
		soundWaves[count] = value;
		count++;

		std::cout << "Enter a value\n";
		std::cout << "Enter '-1' to exit\n\n";
		std::cin >> value;//our 'Virtual Knob' :)
	}

	for (int i = 0; i < count; i++) {//multiply by 'gainValue'
		soundWaves[i] *= gainValue;
	}

	for (int i = 0; i < count; i++) {//displaying the values
		std::cout << soundWaves[i] << "\n";
		if (soundWaves[i] > 1.0 || soundWaves[i] < -1.0) {
			isClipping = true;
		}
		
	}

	if (isClipping) {//if any the values are above '1.0' or '-1' this warning will pop up
		std::cout << "WARNING: Signal is clipping. Adjust the volume\n";
	}

	return 0;
}

double setGain() {

	double gain;//user set the gain
	
	std::cout << "Set the gain\n";
	std::cout << "Enter a value between (0.0 - 2.0)\n";
	std::cin >> gain;
	return std::clamp(gain, 0.0, 2.0);//limiter 
}