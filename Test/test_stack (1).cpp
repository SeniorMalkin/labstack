#include "..\Stack\TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack)
{
  EXPECT_NO_THROW(TStack<int> bf(20));
}
TEST(TStack, can_push_element)
{
	TStack<int> bf(20);
	ASSERT_NO_THROW(bf.Push(5));
}
TEST(TStack, can_pull_top_element)
{
	TStack<int> bf(20);
	bf.Push(5);
	EXPECT_EQ(bf.Top() , 5);
}
TEST(TStack, stack_is_full)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	bf.Push(2);
	EXPECT_TRUE(bf.IsFull());
}
TEST(TStack, stack_is_not_full)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	EXPECT_FALSE(bf.IsFull());
}
TEST(TStack, can_push_element_in_full_stack)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	bf.Push(2);
	EXPECT_ANY_THROW(bf.Push(25));
}
TEST(TStack, stack_is_empty)
{
	TStack<int> bf(3);
	EXPECT_TRUE(bf.IsEmpty());
}
TEST(TStack, stack_is_not_empty)
{
	TStack<int> bf(3);
	bf.Push(13);
	EXPECT_FALSE(bf.IsEmpty());
}
TEST(TStack, can_clear_stack)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	bf.Push(2);
	bf.Clear();
	EXPECT_TRUE(bf.IsEmpty());
}
TEST(TStack, can_pop_element_out_stack)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	int eq = bf.Top();
	EXPECT_EQ(eq,bf.Pop());
}
TEST(TStack, can_change_top_element_at_pop_element)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	int eq = bf.Top();
	bf.Pop();
	EXPECT_NE(eq,bf.Top());
}
TEST(TStack, can_change_top_element_at_push_element)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	int eq = bf.Top();
	bf.Push(13);
	EXPECT_NE(eq, bf.Top());
}
TEST(TStack, can_assign_stack_of_equal_size)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	TStack<int> bf1(3);
	bf1 = bf;
	EXPECT_EQ(bf,bf1);
}
TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	TStack<int> bf1(bf);
	bf = bf;
	EXPECT_EQ(bf, bf1);
}
TEST(TStack, can_assign_stack_of_different_size)
{
	TStack<int> bf(3);
	bf.Push(5);
	bf.Push(7);
	TStack<int> bf1(6);
	bf1 = bf;
	EXPECT_EQ(bf, bf1);
}