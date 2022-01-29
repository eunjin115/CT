#include <iostream>
#include <string>
#include <memory>

class Squad99 //Product
{
private:
	std::string name;
	std::string position;
	bool marriged; 

public:
	void SetName(std::string _name)
	{
		name = _name;
	}

	void SetPosition(std::string _position)
	{
		position = _position;
	}

	void SetMarriged(bool _marriged)
	{
		marriged = _marriged;
	}

	void Show()
	{
		std::cout << "Name : " << name << " Position : " << position << " Marriged : ";
		if (marriged)
			std::cout << "Yes \n";
		else
			std::cout << "No \n";
	}
};

class Squad99Builder //abstact builder
{
public:
	virtual void SetName(std::string _name) = 0;
	virtual void SetPosition(std::string _position) = 0;
	virtual void SetMarriged(bool _marriged) = 0;

	virtual std::shared_ptr<Squad99> GetSquad99() = 0;
};

class DetectiveBuilder : public Squad99Builder //형사 builder
{
private:
	std::shared_ptr<Squad99> detective;
public:

	DetectiveBuilder()
	{
		detective = std::make_shared<Squad99>();
	}

	virtual void SetName(std::string _name)
	{
		detective->SetName(_name);
	}
	
	virtual void SetPosition(std::string _position)
	{
		detective->SetPosition(_position);
	}

	virtual void SetMarriged(bool _marriged)
	{
		detective->SetMarriged(_marriged);
	}

	virtual std::shared_ptr<Squad99> GetSquad99()
	{
		return detective;
	}
};


class NypdBuilder : public Squad99Builder //형사 이상 builder (이름이 생각 안남.. 반장급..?)
{
private:
	std::shared_ptr<Squad99> Nypd;

public:
	NypdBuilder()
	{
		Nypd = std::make_shared<Squad99>();
	}

	virtual void SetName(std::string _name)
	{
		Nypd->SetName(_name);
	}
	
	virtual void SetPosition(std::string _position)
	{
		Nypd->SetPosition(_position);
	}

	virtual void SetMarriged(bool _marriged)
	{
		Nypd->SetMarriged(_marriged);
	}
	
	virtual std::shared_ptr<Squad99> GetSquad99()
	{
		return Nypd;
	}
}; 

class Squad99Director //Client가 Product를 전달받기 위한 director
{
private:
	std::shared_ptr<Squad99Builder> squadBuilder;

public:
	void SetSquad99Builder(std::shared_ptr<Squad99Builder> _squadBuilder) //어떤 builder인지에 따라서 다르게 전달받음 
	{
		squadBuilder = _squadBuilder;
	}

	std::shared_ptr<Squad99> MakeNYPD(std::string _name, std::string _position, bool _marriged)
	{
		squadBuilder->SetName(_name);
		squadBuilder->SetPosition(_position);
		squadBuilder->SetMarriged(_marriged);
		
		return squadBuilder->GetSquad99();
	}

};

int main()
{
	std::shared_ptr<Squad99Director> NYPDdirector = std::make_shared<Squad99Director>();

	std::shared_ptr<DetectiveBuilder> detective_builder = std::make_shared<DetectiveBuilder>(); 
	NYPDdirector->SetSquad99Builder(detective_builder); //형사 builder로 형사 Product 가져옴 

	std::shared_ptr<Squad99> NYPD_1 = NYPDdirector->MakeNYPD("Jake Peralta", "Detective", 1);
	NYPD_1->Show();

	std::shared_ptr<Squad99> NYPD_2 = NYPDdirector->MakeNYPD("Rosa Diaz", "Detective", 0);
	NYPD_2->Show();

	std::shared_ptr<NypdBuilder> not_detective_builder = std::make_shared<NypdBuilder>();
	NYPDdirector->SetSquad99Builder(not_detective_builder); //형사 이외의 builder로 Product 가져옴 
	
	std::shared_ptr<Squad99> NYPD_3 = NYPDdirector->MakeNYPD("Raymond Holt", "Captain", 1);
	NYPD_3->Show();

	std::shared_ptr<Squad99> NYPD_4 = NYPDdirector->MakeNYPD("Terry Jeffords", "Lieutenant", 1);
	NYPD_4->Show();

	return 0;
}