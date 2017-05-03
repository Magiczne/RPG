#include "stdafx.h"

#include "../RPG/Statistics.h"
#include "../RPG/Character.h"
#include "../RPG/OrcFactory.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace RPGTests
{
	[TestClass]
	public ref class CharacterTests
	{
	public: 
		[TestMethod]
		void OrcFactoryTest()
		{
			auto factory = gcnew OrcFactory();

			Character^ ch = gcnew Character("Character", gcnew Statistics(1, 1, 1, 1, 1, 1, 1, 1));

			auto character = factory->createCharacter();

			Assert::IsInstanceOfType(character, ch->GetType());
		}

		[TestMethod]
		void CharacterMaxHpAndManaTest()
		{
			Character^ ch = gcnew Character("Character", gcnew Statistics(1, 1, 3, 1, 1, 2, 1, 1));

			Assert::AreEqual(Convert::ToString(5 * 3), ch->getMaxMana().ToString(), "Mana not equal");
			Assert::AreEqual(Convert::ToString(5 * 2), ch->getMaxHp().ToString(), "HP not equal");
		}

		[TestMethod]
		void CharacterAttacksTest()
		{
			Character^ ch = gcnew Character("Character", gcnew Statistics(1, 1, 3, 1, 5, 2, 1, 1));

			//Strenth * 2
			Assert::AreEqual(Convert::ToString(5 * 2), ch->baseMeleeAttack().ToString(), "Melee not equal");
			//Agi * 2
			Assert::AreEqual(Convert::ToString(1 * 2), ch->baseRangeAttack().ToString(), "Ranged not equal");
		}
	};
}
