#include <iostream>
#include <string>
#include <cmath>

int converter10(std::string num, int baseO);
std::string converterBase(std::string num, int baseO);

int main(){

	int baseI, baseO;
	std::string num;

	std::cout<<"Base: ";
	std::cin>>baseI;

	std::cout<<"Numero: ";
	std::cin>>num;

	std::cout<<"Base de saida: ";
	std::cin>>baseO;

	if (baseI <= 1 || baseO <= 1){
		std::cout<<"base invalida\n";
		return 0;
	}

	int buf = converter10(num, baseI);

	if (baseO == 10)
		std::cout<< buf <<"\n";
	
	else{
		std::cout<<converterBase(std::to_string(buf), baseO) <<"\n";
	}

}

int converter10(std::string num, int baseI){
	int buf = 0;
	std::string::iterator it = num.end() - 1;
	int exp = 0;
	
	while(it != num.begin() - 1){
		if(*it>64&&*it<91)
		buf += ((*it) - 55) * pow(baseI, exp);
		else
		buf += ((*it) - 48) * pow(baseI, exp);
		exp++;
		it--;
	}

	return buf;
}


std::string converterBase(std::string num, int baseO){
	int quo = stoi(num);
	std::string buf;
	int resto = 0;
	char conv;
	while (quo != 0){
		resto = quo % baseO;
		quo /= baseO;
		if(resto<10)		
		buf.insert(0, std::to_string(resto));
		else{
		conv = resto + 55;	
		buf.insert(0, 1, conv);
		}
	}
	
	
	return buf;
}
