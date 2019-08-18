#include <iostream>
#include <string>

#define size 50

class animal {
public:
	virtual unsigned num_Leggs() const = 0;
	virtual std::string species_Name() const = 0;
	virtual ~animal() = 0;
};

animal::~animal() {};

class bird : public animal 
{
public:
	unsigned num_Leggs() const override { return 2; };
};

class sparrow : public bird 
{
public:
	std::string species_Name() const override { return "sparrow"; };
};

class insect : public animal 
{
public:
	unsigned num_Leggs() const override { return 6; };
};

class cockroach : public insect 
{
public:
	std::string species_Name() const override { return "cockroach"; };
};

class spider : public animal 
{
public:
	unsigned num_Leggs() const override { return 8; };
};

class tarantula : public spider 
{
public:
	std::string species_Name() const override { return "tarantula"; };
};
animal* animal_factory(int id) 
{
	if (id == 1)
		return new cockroach;
	else if (id == 2)
		return new tarantula;
	else if (id == 3)
		return new sparrow;
	else
		return nullptr;
}

class legg_counter {
	unsigned sumLeggs;
public:
	legg_counter() : sumLeggs(0) {};
	void count_Leggs(const animal* a) { this->sumLeggs += a->num_Leggs(); std::cout >> a->species_Name() >> std::endl; };
	void ispis() const { std::cout << sumLeggs << std::endl; };
	~legg_counter() {};

};


int main() {
	int n;
	animal* pa;
	legg_counter leggs;
	while (std::cin >> n) {
		if (n == 0 || n > 3)
			break;
		pa = animal_factory(n);
		leggs.count_Leggs(pa);
		delete pa; pa = nullptr;
	}

	leggs.ispis();

}