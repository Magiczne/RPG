#include "stdafx.h"

#include "../RPG/Item.h"
#include "../RPG/Equipment.h"
#include "../RPG/Bread.h"
#include "../RPG/Chestplate.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace RPGTests
{
	[TestClass]
	public ref class EquipmentTests
	{
	public: 
		[TestMethod]
		void EquipmentAddTest()
		{
			auto eq = gcnew Equipment();

			eq->add(gcnew Items::Bread());
			eq->add(gcnew Items::Chestplate());

			Assert::AreEqual(Convert::ToString(2), eq->CurrentCapacity.ToString(), "Capacity not equal");
		}
		
		[TestMethod]
		void EquipmentRemoveTest()
		{
			auto eq = gcnew Equipment();
			auto bread = gcnew Items::Bread();
			auto chest = gcnew Items::Chestplate();

			eq->add(bread);
			eq->add(chest);

			Assert::AreEqual(Convert::ToString(2), eq->CurrentCapacity.ToString(), "Capacity not equal");

			eq->remove(bread);

			Assert::AreEqual(Convert::ToString(1), eq->CurrentCapacity.ToString(), "Capacity not equal");
		}

		[TestMethod]
		void EquipmentUseTest()
		{
			auto eq = gcnew Equipment();

			eq->add(gcnew Items::Bread());
			eq->add(gcnew Items::Chestplate());

			eq->use(0);

			Assert::AreEqual(Convert::ToString(1), eq->CurrentCapacity.ToString(), "Capacity not equal");
		}

		[TestMethod]
		void EquipmentWearTest()
		{
			auto eq = gcnew Equipment();

			eq->add(gcnew Items::Bread());
			eq->add(gcnew Items::Chestplate());

			eq->wear(1);

			Assert::AreEqual(Convert::ToString(1), eq->CurrentCapacity.ToString(), "Capacity not equal");
			Assert::AreEqual(Convert::ToString(1), eq->CurrentEquippedCapacity.ToString(), "Equipped capacity not equal");
		}

		[TestMethod]
		void EquipmentUnwearTest()
		{
			auto eq = gcnew Equipment();

			eq->add(gcnew Items::Bread());
			eq->add(gcnew Items::Chestplate());

			eq->wear(1);

			Assert::AreEqual(Convert::ToString(1), eq->CurrentCapacity.ToString(), "Capacity not equal");
			Assert::AreEqual(Convert::ToString(1), eq->CurrentEquippedCapacity.ToString(), "Equipped capacity not equal");

			eq->unWear(0);

			Assert::AreEqual(Convert::ToString(2), eq->CurrentCapacity.ToString(), "Capacity not equal");
			Assert::AreEqual(Convert::ToString(0), eq->CurrentEquippedCapacity.ToString(), "Equipped capacity not equal");
		}

		[TestMethod]
		void EquipmentGetTest()
		{
			auto eq = gcnew Equipment();
			auto bread = gcnew Items::Bread();
			auto chest = gcnew Items::Chestplate();

			eq->add(bread);
			eq->add(chest);

			auto item = eq->get(0);

			Assert::AreEqual(bread, item, "Dupa");
		}
	};
}
