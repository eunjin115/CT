#include <iostream>
#include <memory>

class Weapon
{
public:
	virtual int Power() = 0;
};
class Bow : public Weapon
{
	int Power() override { return 200; }
};
class Sword : public Weapon
{
	int Power() override { return 50; }
};
class Armor
{
	virtual int Defence() = 0;
};
class Leather : public Armor
{
	int Defence() override { return 50; }
};
class Plate : public Armor
{
	int Defence() override { return 200; }
};


class EquipmentAbstractFactory
{
public:
	virtual std::shared_ptr<Weapon>CreateWeapon() = 0;
	virtual std::shared_ptr<Armor>CreateArmor() = 0;
}; // ������ ���� �������̽� �������� � ��ü�� ������ �����մϴ�. 


class ArcherEquipment : public EquipmentAbstractFactory
{
	virtual std::shared_ptr<Weapon> CreateWeapon()
	{
		std::shared_ptr<Weapon> bow = std::make_shared<Bow>();
		return bow;
	}
	virtual std::shared_ptr<Armor> CreateArmor()
	{
		std::shared_ptr<Armor> leather = std::make_shared<Leather>();
		return leather;
	}
};
class WarriorEquipment : public EquipmentAbstractFactory
{
	virtual std::shared_ptr<Weapon> CreateWeapon()
	{
		std::shared_ptr<Weapon> sword = std::make_shared<Sword>();
		return sword;
	}
	virtual std::shared_ptr<Armor> CreateArmor()
	{
		std::shared_ptr<Armor> plate = std::make_shared<Plate>();
		return plate;
	}
};

class Character
{
public:
	Character(std::shared_ptr <EquipmentAbstractFactory> equipment)
	{
		mWeapon = equipment->CreateWeapon();
		mArmor = equipment->CreateArmor();
	}
	virtual void Attack() = 0;
protected: // �������� ��ü�� �����մϴ�. 
	//Weapon* mWeapon;
	//Armor* mArmor;

	std::shared_ptr<Weapon> mWeapon;
	std::shared_ptr<Armor> mArmor;
};

class Archer : public Character
{
public:
	Archer(std::shared_ptr <EquipmentAbstractFactory> equipment) : Character(equipment) {}
	void Attack() override
	{
		printf("Ȱ�� ��Ƽ� %d �������մϴ�.\n", mWeapon->Power());
	}
};

class Warrior : public Character
{
public:
	Warrior(std::shared_ptr <EquipmentAbstractFactory> equipment) : Character(equipment) {}
	void Attack() override
	{
		printf("���� �ֵѷ��� %d �������մϴ�.\n", mWeapon->Power());
	}
};

int main()
{
	std::shared_ptr <EquipmentAbstractFactory> archerequip = std::make_shared<ArcherEquipment>();
	std::shared_ptr <EquipmentAbstractFactory> warriorequip = std::make_shared<WarriorEquipment>();

	Character* archer = new Archer(archerequip);
	Character* warrior = new Warrior(warriorequip);

	archer->Attack();
	warrior->Attack();
	return 0;
}