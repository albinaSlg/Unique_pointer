#include "gtest/gtest.h"
#include "uniquePtr.h"

TEST(UniquePtrTest, Initialize_WithInt_Succsesful)
{
	EXPECT_NO_THROW(UniquePtr(new int(3)));
}

TEST(UniquePtrTest, Initialize_WithNullptr_Succsesful)
{
	EXPECT_NO_THROW(UniquePtr<char>(nullptr));
}

TEST(UniquePtrTest, MoveConstruct_Succsesful)
{
	UniquePtr<int> ptr(new int(5));
	int* ptrTemp = ptr.get();

	UniquePtr<int> anotherPtr(std::move(ptr));

	EXPECT_EQ(*anotherPtr, 5);
	EXPECT_EQ(anotherPtr.get(), ptrTemp);
	EXPECT_THROW(*ptr, std::runtime_error);
	EXPECT_EQ(ptr.get(), nullptr);
}

TEST(UniquePtrTest, Release_Ptr_Succsesful)
{
	UniquePtr<int> ptr(new int(5));

	int* ptrTemp = ptr.release();

	EXPECT_EQ(*ptrTemp, 5);
	EXPECT_EQ(ptr.get(), nullptr);

	delete ptrTemp;
}

TEST(UniquePtrTest, Reset_Ptr_Succsesful)
{
	UniquePtr<int> ptr(new int(5));

	ptr.reset(new int(6));

	EXPECT_EQ(*ptr, 6);
}

TEST(UniquePtrTest, Get_Ptr_Succsesful)
{
	int* tempPtr = new int(5);
	UniquePtr<int> ptr(tempPtr);

	EXPECT_EQ(ptr.get(), tempPtr);
}

TEST(UniquePtrTest, Swap_Ptr_Succsesful)
{
	UniquePtr<int> ptr(new int(1));
	UniquePtr<int> ptrOther(new int(2));

	ptr.swap(ptrOther);

	EXPECT_EQ(1, *ptrOther);
	EXPECT_EQ(2, *ptr);
}