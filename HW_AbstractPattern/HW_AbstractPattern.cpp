
#include <iostream>
#include <vector>

class Herbivore
{
public:
	virtual ~Herbivore() {}
	virtual void eatGrass() = 0;
	virtual void kill() = 0;
	virtual int getWeight() = 0;
};

class wildebeest : public Herbivore
{
private:
	int weight;
	bool life;
public:
	wildebeest()
	{
		weight = 10;
		life = true;
	}
	void eatGrass() override
	{
		if (life)
		{
			weight += 10;
			std::cout << "weldebeest eat\n";
		}
	}
	void kill() override
	{
		life = false;
		std::cout << "weldebeest die\n";
	}
	int getWeight() override
	{
		return weight;
	}
};
class Bison : public Herbivore
{
private:
	int weight;
	bool life;
public:
	Bison()
	{
		weight = 10;
		life = true;
	}
	void eatGrass() override
	{
		if (life)
		{
			weight += 10;
			std::cout << "BisonEat eat\n";
		}
	}
	void kill() override
	{
		life = false;
		std::cout << "Bison die\n";
	}
	int getWeight() override
	{
		return weight;
	}
};
class Elk : public Herbivore
{
private:
	int weight;
	bool life;
public:
	Elk()
	{
		weight = 10;
		life = true;
	}
	void eatGrass() override
	{
		if (life)
		{
			weight += 10;
			std::cout << "Elk eat\n";
		}
	}
	void kill() override
	{
		life = false;
		std::cout << "Elk die\n";
	}
	int getWeight() override
	{
		return weight;
	}
};

class Carnivires
{
public:
	virtual ~Carnivires() {}
	virtual void eatHerbivore(Herbivore& obj) = 0;
};

class Lion : public Carnivires
{
private:
	int power;
public:
	Lion()
	{
		power = 70;
	}
	void eatHerbivore(Herbivore& welbeest) override
	{
		if (welbeest.getWeight() < power)
		{
			power += 10;
			std::cout << "Lion eat\n";
		}
		else
		{
			power -= 10;
			std::cout << "Lion starve\n";
		}
	}
};
class Wolf : public Carnivires
{
private:
	int power;
public:
	Wolf()
	{
		power = 30;
	}
	void eatHerbivore(Herbivore& Bison) override
	{
		if (Bison.getWeight() < power)
		{
			power += 10;
			std::cout << "Wolf eat\n";
		}
		else
		{
			power -= 10;
			std::cout << "Wolf starve\n";
		}
	}
};
class Tiger : public Carnivires
{
private:
	int power;
public:
	Tiger()
	{
		power = 40;
	}
	void eatHerbivore(Herbivore& Elk) override
	{
		if (Elk.getWeight() < power)
		{
			power += 10;
			std::cout << "Tiger eat\n";
		}
		else
		{
			power -= 10;
			std::cout << "Tiger starve\n";
		}
	}
};

class Continent
{
public:
	virtual void createHerbivore() = 0;
	virtual void createCarnivires() = 0;
	virtual void feedHerb() = 0;
	virtual void feedCarn() = 0;
};

class Africa : public Continent
{
private:
	std::vector<Herbivore*> herb;
	std::vector<Carnivires*> carn;
public:
	void createHerbivore() override
	{
		herb.push_back(new wildebeest);
	}
	void createCarnivires() override
	{
		carn.push_back(new Lion);
	}
	void feedHerb() override
	{
		if (!herb.empty())
		{
			for (auto& it : herb)
			{
				it->eatGrass();
			}
		}
	}
	void feedCarn() override
	{
		if (!carn.empty() && !herb.empty())
		{
			for (auto& it : carn)
			{
				for (auto& second : herb)
				{
					it->eatHerbivore(*second);
				}
			}
		}
	}
};
class NorthAmerica : public Continent
{
private:
	std::vector<Herbivore*> herb;
	std::vector<Carnivires*> carn;
public:
	void createHerbivore() override
	{
		herb.push_back(new Bison);
	}
	void createCarnivires() override
	{
		carn.push_back(new Wolf);
	}
	void feedHerb() override
	{
		if (!herb.empty())
		{
			for (auto& it : herb)
			{
				it->eatGrass();
			}
		}
	}
	void feedCarn() override
	{
		if (!carn.empty() && !herb.empty())
		{
			for (auto& it : carn)
			{
				for (auto& second : herb)
				{
					it->eatHerbivore(*second);
				}
			}
		}
	}
};
class Eurasia : public Continent
{
private:
	std::vector<Herbivore*> herb;
	std::vector<Carnivires*> carn;
public:
	void createHerbivore() override
	{
		herb.push_back(new Elk);
	}
	void createCarnivires() override
	{
		carn.push_back(new Tiger);
	}
	void feedHerb() override
	{
		if (!herb.empty())
		{
			for (auto& it : herb)
			{
				it->eatGrass();
			}
		}
	}
	void feedCarn() override
	{
		if (!carn.empty() && !herb.empty())
		{
			for (auto& it : carn)
			{
				for (auto& second : herb)
				{
					it->eatHerbivore(*second);
				}
			}
		}
	}
};

class World
{
public:
	void createHerb(Continent* &cont)
	{
		cont->createHerbivore();
	}
	void createCarn(Continent* &cont)
	{
		cont->createCarnivires();
	}
	void feedHerb(Continent* &cont)
	{
		cont->feedHerb();
	}
	void feedCarn(Continent* &cont)
	{
		cont->feedCarn();
	}
	void massFeed(Continent* &cont)
	{
		cont->feedCarn();
		cont->feedHerb();
	}
};

int main()
{
	World world;
	Continent* cont = new Africa;
	world.createCarn(cont);
	world.createHerb(cont);
	world.feedCarn(cont);
	delete cont;
}