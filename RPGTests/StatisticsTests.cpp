#include "stdafx.h"
#include "../RPG/Statistics.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace RPGTests
{
	[TestClass]
	public ref class StatisticsTests
	{
	public: 
		[TestMethod]
		void StatisticsAddTest()
		{
			Statistics^ s1 = gcnew Statistics(1, 1, 1, 1, 1, 1, 1, 1);
			Statistics^ s2 = gcnew Statistics(2, 3, 4, 5, 6, 7, 8, 9);

			s1->add(s2);

			Assert::AreEqual(Convert::ToString(3), s1->HP.ToString(), false, "Hp not equal");
			Assert::AreEqual(Convert::ToString(4), s1->Mana.ToString(), false, "Mana not equal");
			Assert::AreEqual(Convert::ToString(5), s1->Intelligence.ToString(), false, "Int not equal");
			Assert::AreEqual(Convert::ToString(6), s1->Agility.ToString(), false, "Agi not equal");
			Assert::AreEqual(Convert::ToString(7), s1->Strength.ToString(), false, "Str not equal");
			Assert::AreEqual(Convert::ToString(8), s1->Toughness.ToString(), false, "Toughness not equal");
			Assert::AreEqual(Convert::ToString(9), s1->Wisdom.ToString(), false, "Wisdom not equal");
			Assert::AreEqual(Convert::ToString(10), s1->Gold.ToString(), false, "Gold not equal");
		}

		[TestMethod]
		void StatisticsSubstractTest()
		{
			Statistics^ s1 = gcnew Statistics(10, 10, 10, 10, 10, 10, 10, 10);
			Statistics^ s2 = gcnew Statistics(2, 3, 4, 5, 6, 7, 8, 9);

			s1->substract(s2);

			Assert::AreEqual(Convert::ToString(8), s1->HP.ToString(), false, "Hp not equal");
			Assert::AreEqual(Convert::ToString(7), s1->Mana.ToString(), false, "Mana not equal");
			Assert::AreEqual(Convert::ToString(6), s1->Intelligence.ToString(), false, "Int not equal");
			Assert::AreEqual(Convert::ToString(5), s1->Agility.ToString(), false, "Agi not equal");
			Assert::AreEqual(Convert::ToString(4), s1->Strength.ToString(), false, "Str not equal");
			Assert::AreEqual(Convert::ToString(3), s1->Toughness.ToString(), false, "Toughness not equal");
			Assert::AreEqual(Convert::ToString(2), s1->Wisdom.ToString(), false, "Wisdom not equal");
			Assert::AreEqual(Convert::ToString(1), s1->Gold.ToString(), false, "Gold not equal");
		}
	};
}
