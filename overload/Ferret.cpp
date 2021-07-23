// define functions

Ferret::Ferret(string arg)
	:name{arg} {}

bool Ferret::operator==(const Ferret &rhs) const{
	return (std::strcmp(str, rhs.str) == 0)
}


Ferret Ferret::operator-() const{
	char *buff = new char[std::strlen(name) + 1];
	std::strcpy(buff, name);
	for(size_t i=0; i < std::strlen(buff); i++){
		buff[i] = std::tolower(buff[i]);
	}
	Ferret temp{buff};
	delete [] buff;
	return temp;
}


Ferret Ferret::operator+(const Ferret &rhs) const{
	char *buff = new char[std::strlen(name) + std::strlen(rhs.name) + 1];
	std::strcpy(buff, name);
	std::strcat(buff, rhs.name);
	Ferret temp{buff};
	delete [] buff;
	return temp;
}
