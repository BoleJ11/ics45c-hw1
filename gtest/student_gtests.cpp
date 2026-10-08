// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Stack module. It is graded: the autograder runs it against
// a correct Stack and against several Stacks with one bug each. A test is worth something only
// when it passes on the correct Stack and fails on a broken one, so a test that always fails
// (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for pop, push_all, pop_all, and the edges
// (an empty stack, a stack of one character, a full stack).
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTests, NewStackIsEmptyAndNotFull) {
    Stack stk;
    EXPECT_TRUE(stk.isEmpty());
    EXPECT_FALSE(stk.isFull());
}

TEST(StackTests, PushThenTopSeesTheCharacter) {
    Stack stk;
    stk.push('z');
    EXPECT_EQ(stk.top(), 'z');
}

// ADD YOUR TESTS HERE:

TEST(StackTests, PopRemovesTopElement) {
    Stack stk;
    stk.push('a');
    stk.push('b');
    stk.pop();
    EXPECT_EQ(stk.top(), 'a');
    stk.pop();
    EXPECT_TRUE(stk.isEmpty());
}

TEST(StackTests, PushAllAddsCharactersInOrder) {
    Stack stk;
    push_all(stk, "hello");
    EXPECT_EQ(stk.top(), 'o');
    EXPECT_FALSE(stk.isEmpty());
}

TEST(StackTests, PopAllEmptiesStack) {
    Stack stk;
    push_all(stk, "abc");
    pop_all(stk);
    EXPECT_TRUE(stk.isEmpty());
}

TEST(StackTests, PopAllOnEmptyStack) {
    Stack stk;
    pop_all(stk);
    EXPECT_TRUE(stk.isEmpty());
}

TEST(StackTests, SingleElementStack) {
    Stack stk;
    stk.push('x');
    EXPECT_FALSE(stk.isEmpty());
    EXPECT_EQ(stk.top(), 'x');
    stk.pop();
    EXPECT_TRUE(stk.isEmpty());
}

TEST(StackTests, FullStackBecomesFull) {
    Stack stk;
    for (int i = 0; i < STK_MAX; ++i) {
        EXPECT_FALSE(stk.isFull());
        stk.push('a' + (i % 26));
    }
    EXPECT_TRUE(stk.isFull());
}

TEST(StackTests, MultiplePushPopSequence) {
    Stack stk;
    stk.push('1');
    stk.push('2');
    stk.push('3');
    EXPECT_EQ(stk.top(), '3');
    stk.pop();
    EXPECT_EQ(stk.top(), '2');
    stk.push('4');
    EXPECT_EQ(stk.top(), '4');
    stk.pop();
    EXPECT_EQ(stk.top(), '2');
    stk.pop();
    EXPECT_EQ(stk.top(), '1');
    stk.pop();
    EXPECT_TRUE(stk.isEmpty());
}
