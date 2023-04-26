#include "gtest/gtest.h"
#include "uniquePtr.h"

TEST(UniquePtrArrayTest, Initialize_WithInt_Succsesful)
{
	EXPECT_NO_THROW(UniquePtr<int[]>(new int[3](1,2,3)));
}

TEST(UniquePtrArrayTest, Initialize_WithNullptr_Succsesful)
{
	EXPECT_NO_THROW(UniquePtr<int[]>(nullptr));
}

TEST(UniquePtrArrayTest, MoveConstruct_Succsesful)
{
	UniquePtr<int[]> ptr(new int(5));
	int* ptrTemp = ptr.get();

	UniquePtr<int[]> anotherPtr(std::move(ptr));

	EXPECT_EQ(5, *anotherPtr);
	EXPECT_EQ(ptrTemp, anotherPtr.get());
	EXPECT_THROW(*ptr, std::runtime_error);
	EXPECT_EQ(nullptr, ptr.get());
}

TEST(UniquePtrArrayTest, Release_Ptr_Succsesful)
{
	UniquePtr<int[]> ptr(new int[3](1, 2, 3));

	int* ptrTemp = ptr.release();

	EXPECT_EQ(1, *ptrTemp);
	EXPECT_EQ(nullptr, ptr.get());

	delete ptrTemp;
}

TEST(UniquePtrArrayTest, Reset_Ptr_Succsesful)
{
	UniquePtr<int[]> ptr(new int[3](1, 2, 3));

	ptr.reset(new int[4](2, 2, 3, 4));

	EXPECT_EQ(2, *ptr);
}

TEST(UniquePtrArrayTest, Get_Ptr_Succsesful)
{
	int* tempPtr = new int[3](1, 2, 3);
	UniquePtr<int[]> ptr(tempPtr);

	EXPECT_EQ(tempPtr, ptr.get());
}

TEST(UniquePtrArrayTest, Swap_Ptr_Succsesful)
{
	UniquePtr<int[]> ptr(new int[3](1, 2, 3));
	UniquePtr<int[]> ptrOther(new int[3](3, 2, 1));

	ptr.swap(ptrOther);

	EXPECT_EQ(1, *ptrOther);
	EXPECT_EQ(3, *ptr);
}