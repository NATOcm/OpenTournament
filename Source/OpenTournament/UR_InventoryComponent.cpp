// Copyright 2019 Open Tournament Project, All Rights Reserved.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "UR_InventoryComponent.h"

#include "UnrealNetwork.h"
#include "Engine.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

UUR_InventoryComponent::UUR_InventoryComponent()
{
	bReplicates = true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void UUR_InventoryComponent::Add(AUR_Weapon* weapon)
{
	if (!InventoryW.Contains(weapon)) {
		InventoryW.Add(weapon);
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, FString::Printf(TEXT("You picked the %s"), *weapon->WeaponName));
	}
	else 
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, FString::Printf(TEXT("You already have the %s"), *weapon->WeaponName));
}

void UUR_InventoryComponent::Add(AUR_Ammo* ammo)
{
	InventoryA.Add(ammo);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("You picked the %s"), *ammo->AmmoName));
}


void UUR_InventoryComponent::ShowInventory()
{
	for (auto& weapon : InventoryW)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Weapons in inventory: %s"), *weapon->WeaponName));
	}

	for (auto& ammo : InventoryA)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Ammo in inventory: %s"), *ammo->AmmoName));
	}

}

int32 UUR_InventoryComponent::SelectWeapon(int number)
{

	FString name = "null weapon";
	int32 result = 0;

		for (auto& weapon : InventoryW)
		{
			if (number == 1 && weapon->WeaponName == "Assault Rifle") 
			{ 
				result = 1; 
				name = weapon->WeaponName;
				weapon->AttachMeshToPawn();
				ActiveWeapon = weapon;
				weapon->setEquipped(true);
			}
			else if (number == 2 && weapon->WeaponName == "Shotgun")
			{
				result = 2;
				name = weapon->WeaponName;
				weapon->AttachMeshToPawn();
				ActiveWeapon = weapon;
				weapon->setEquipped(true);
			}
			else if (number == 3 && weapon->WeaponName == "Rocket Launcher")
			{
				result = 3;
				name = weapon->WeaponName;
				weapon->AttachMeshToPawn();
				ActiveWeapon = weapon;
				weapon->setEquipped(true);
			}
			else if (number == 4 && weapon->WeaponName == "Grenade Launcher")
			{
				result = 4;
				name = weapon->WeaponName;
				weapon->AttachMeshToPawn();
				ActiveWeapon = weapon;
				weapon->setEquipped(true);
			}
			else if (number == 5 && weapon->WeaponName == "Sniper Rifle")
			{
				result = 5;
				name = weapon->WeaponName;
				weapon->AttachMeshToPawn();
				ActiveWeapon = weapon;
				weapon->setEquipped(true);
			}
			else if (number == 0 && weapon->WeaponName == "Pistol")
			{
				result = 0;
				name = weapon->WeaponName;
				weapon->AttachMeshToPawn();
				ActiveWeapon = weapon;
				weapon->setEquipped(true);
			}
			else {
				weapon->DetachMeshFromPawn();
			}
		}
	
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Yellow, FString::Printf(TEXT("Weapon name -> %s \n"), *name));
	return result;
}

AUR_Weapon * UUR_InventoryComponent::SelectWeaponG(int number)
{

	FString name = "null weapon";
	int32 result = 0;

	for (auto& weapon : InventoryW)
	{
		if (number == 1 && weapon->WeaponName == "Assault Rifle")
		{
			result = 1;
			name = weapon->WeaponName;
			weapon->AttachMeshToPawn();
			ActiveWeapon = weapon;
			weapon->setEquipped(true);
		}
		else if (number == 2 && weapon->WeaponName == "Shotgun")
		{
			result = 2;
			name = weapon->WeaponName;
			weapon->AttachMeshToPawn();
			ActiveWeapon = weapon;
			weapon->setEquipped(true);
		}
		else if (number == 3 && weapon->WeaponName == "Rocket Launcher")
		{
			result = 3;
			name = weapon->WeaponName;
			weapon->AttachMeshToPawn();
			ActiveWeapon = weapon;
			weapon->setEquipped(true);
		}
		else if (number == 4 && weapon->WeaponName == "Grenade Launcher")
		{
			result = 4;
			name = weapon->WeaponName;
			weapon->AttachMeshToPawn();
			ActiveWeapon = weapon;
			weapon->setEquipped(true);
		}
		else if (number == 5 && weapon->WeaponName == "Sniper Rifle")
		{
			result = 5;
			name = weapon->WeaponName;
			weapon->AttachMeshToPawn();
			ActiveWeapon = weapon;
			weapon->setEquipped(true);
		}
		else if (number == 0 && weapon->WeaponName == "Pistol")
		{
			result = 0;
			name = weapon->WeaponName;
			weapon->AttachMeshToPawn();
			ActiveWeapon = weapon;
			weapon->setEquipped(true);
		}
		else {
			weapon->DetachMeshFromPawn();
		}
	}

	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Yellow, FString::Printf(TEXT("Weapon name -> %s \n"), *name));
	return ActiveWeapon;
}