#include <iostream>
#include <string>
#include <cmath>

int converter10(std::string num, int baseO);
int converterBase(std::string num, int baseO);

int main(){

	int baseI, baseO;
	std::string num;

	std::cout<<"Base: ";
	std::cin>>baseI;

	std::cout<<"Numero: ";
	std::cin>>num;

	std::cout<<"Base de saida: ";
	std::cin>>baseO;

	int buf = converter10(num, baseI);

	if (baseI <= 1 || baseO <= 1){
		std::cout<<"base invalida\n";
		return;
	}


	if (baseO == 10)
		std::cout<<buf <<"\n";
	
	else{
		std::cout<<converterBase(std::to_string(buf), baseO) <<"\n";
	}

}


int converter10(std::string num, int baseI){
	int buf = 0;
	std::string::iterator it = num.end() - 1;
	int exp = 0;

	while(it != num.begin() - 1){
		buf += ((*it) - 48) * pow(baseI, exp);
		exp++;
		it--;
	}
	return buf;
}


int converterBase(std::string num, int baseO){
	int quo = stoi(num);
	std::string buf;
	int resto = 0;	
	while (quo != 0){
		resto = quo % baseO;
		quo /= baseO;		
		buf.insert(0, std::to_string(resto));
	}
	return stoi(buf);

}