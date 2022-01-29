#include <iostream>

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
	virtual Weapon *CreateWeapon() = 0;
	virtual Armor *CreateArmor() = 0;
}; // 다음과 같이 인터페이스 구현으로 어떤 객체를 만들지 결정합니다. 


class ArcherEquipment : public EquipmentAbstractFactory 
{ 
	Weapon* CreateWeapon() override 
	{ 
		return new Bow(); 
	} 
	Armor* CreateArmor() override 
	{ 
		return new Leather();
	} 
}; 
class WarriorEquipment : public EquipmentAbstractFactory 
{ 
	Weapon* CreateWeapon() override 
	{ 
		return new Sword(); 
	} 
	Armor* CreateArmor() override 
	{ return new Plate(); 
	} 
}; 
class Character 
{ 
	public: 
		Character(EquipmentAbstractFactory* equipment) 
		{ 
			mWeapon = equipment->CreateWeapon(); 
			mArmor = equipment->CreateArmor(); 
		} 
	virtual void Attack() = 0; 
	protected: // 구성으로 객체를 생성합니다. 
		Weapon* mWeapon; 
		Armor* mArmor; 
}; 
class Archer : public Character 
{ 
	public: 
	Archer(EquipmentAbstractFactory* equipment) : Character(equipment) {} 
	void Attack() override 
	{ 
		printf("활을 쏘아서 %d 공격을합니다.\n", mWeapon->Power()); 
	} 
}; 
class Warrior : public Character 
{ 
	public: 
	Warrior(EquipmentAbstractFactory* equipment) : Character(equipment) {} 
	void Attack() override 
	{ 
		printf("검을 휘둘러서 %d 공격을합니다.\n", mWeapon->Power()); 
	} 
}; 

int main() 
{ 
	Character* archer = new Archer(new ArcherEquipment()); 
	Character* warrior = new Warrior(new WarriorEquipment()); 
	archer->Attack(); 
	warrior->Attack();
	return 0;
}

