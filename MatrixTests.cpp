#include <gtest/gtest.h>
#include "Matrix.h"
#include "Generator.h"
#include "IStreamGenerator.h"
#include "RandomGenerator.h"
#include "VariantExercise.h"
#include <sstream>
#include <vector>
#include <random>

using namespace MATRIX;

class MatrixTest : public ::testing::Test {
protected:
    void SetUp() override {
        // §³§à§Ù§Õ§Ñ§Ö§Þ §ä§Ö§ã§ä§à§Ó§í§Ö §Þ§Ñ§ã§ã§Ú§Ó§í §Õ§Ý§ñ §â§Ñ§Ù§ß§í§ç §ã§è§Ö§ß§Ñ§â§Ú§Ö§Ó
        empty_array = Matrix<int>();

        positive_array = Matrix<int>(5);
        positive_array[0] = 1;
        positive_array[1] = 5;
        positive_array[2] = 3;
        positive_array[3] = 8;
        positive_array[4] = 2;

        mixed_array = Matrix<int>(6);
        mixed_array[0] = -1;
        mixed_array[1] = 10;
        mixed_array[2] = -5;
        mixed_array[3] = 15;
        mixed_array[4] = -3;
        mixed_array[5] = 7;

        with_ones_array = Matrix<int>(5);
        with_ones_array[0] = 10;   // §ã§à§Õ§Ö§â§Ø§Ú§ä 1
        with_ones_array[1] = 25;   // §ß§Ö §ã§à§Õ§Ö§â§Ø§Ú§ä 1
        with_ones_array[2] = 131;  // §ã§à§Õ§Ö§â§Ø§Ú§ä 1
        with_ones_array[3] = 7;    // §ß§Ö §ã§à§Õ§Ö§â§Ø§Ú§ä 1
        with_ones_array[4] = 100;  // §ã§à§Õ§Ö§â§Ø§Ú§ä 1

        task3_test_array = Matrix<int>(6);
        for (int i = 0; i < 6; ++i) {
            task3_test_array[i] = i + 1; // [1, 2, 3, 4, 5, 6]
        }
    }

    Matrix<int> empty_array;
    Matrix<int> positive_array;
    Matrix<int> mixed_array;
    Matrix<int> with_ones_array;
    Matrix<int> task3_test_array;
};

// §´§Ö§ã§ä§í §Ü§à§ß§ã§ä§â§å§Ü§ä§à§â§à§Ó
TEST_F(MatrixTest, DefaultConstructor) {
    Matrix<int> arr;
    EXPECT_EQ(arr.getSize(), 0);
}

TEST_F(MatrixTest, SizeConstructor) {
    Matrix<int> arr(5);
    EXPECT_EQ(arr.getSize(), 5);

    for (size_t i = 0; i < arr.getSize(); ++i) {
        EXPECT_EQ(arr[i], 0);
    }
}

TEST_F(MatrixTest, CopyConstructor) {
    Matrix<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;

    Matrix<int> copy(original);
    EXPECT_EQ(copy.getSize(), 3);
    EXPECT_EQ(copy[0], 1);
    EXPECT_EQ(copy[1], 2);
    EXPECT_EQ(copy[2], 3);
}

TEST_F(MatrixTest, AssignmentOperator) {
    Matrix<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;

    Matrix<int> assigned;
    assigned = original;
    EXPECT_EQ(assigned.getSize(), 3);
    EXPECT_EQ(assigned[0], 1);
    EXPECT_EQ(assigned[1], 2);
    EXPECT_EQ(assigned[2], 3);
}

// §´§Ö§ã§ä§í §à§á§Ö§â§Ñ§ä§à§â§à§Ó §Õ§à§ã§ä§å§á§Ñ
TEST_F(MatrixTest, IndexOperator) {
    Matrix<int> arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
}

TEST_F(MatrixTest, IndexOperatorOutOfRange) {
    Matrix<int> arr(3);
    EXPECT_THROW(arr[5], std::out_of_range);
}

TEST_F(MatrixTest, ConstIndexOperator) {
    const Matrix<int> arr = positive_array;
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 5);
    EXPECT_THROW(arr[10], std::out_of_range);
}

// §´§Ö§ã§ä§í §Ñ§â§Ú§æ§Þ§Ö§ä§Ú§é§Ö§ã§Ü§Ú§ç §à§á§Ö§â§Ñ§è§Ú§Û
TEST_F(MatrixTest, Addition) {
    Matrix<int> arr1(3);
    arr1[0] = 1; arr1[1] = 2; arr1[2] = 3;

    Matrix<int> arr2(3);
    arr2[0] = 4; arr2[1] = 5; arr2[2] = 6;

    Matrix<int> result = arr1 + arr2;
    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 9);
}

TEST_F(MatrixTest, AdditionSizeMismatch) {
    Matrix<int> arr1(3);
    Matrix<int> arr2(2);
    EXPECT_THROW(arr1 + arr2, std::invalid_argument);
}

TEST_F(MatrixTest, Subtraction) {
    Matrix<int> arr1(3);
    arr1[0] = 5; arr1[1] = 8; arr1[2] = 10;

    Matrix<int> arr2(3);
    arr2[0] = 1; arr2[1] = 2; arr2[2] = 3;

    Matrix<int> result = arr1 - arr2;
    EXPECT_EQ(result[0], 4);
    EXPECT_EQ(result[1], 6);
    EXPECT_EQ(result[2], 7);
}

TEST_F(MatrixTest, ScalarMultiplication) {
    Matrix<int> arr(3);
    arr[0] = 2; arr[1] = 4; arr[2] = 6;

    Matrix<int> result = arr * 3;
    EXPECT_EQ(result[0], 6);
    EXPECT_EQ(result[1], 12);
    EXPECT_EQ(result[2], 18);
}

TEST_F(MatrixTest, ScalarMultiplicationWithDouble) {
    Matrix<int> arr(3);
    arr[0] = 2; arr[1] = 4; arr[2] = 6;

    Matrix<int> result = arr * 2.5;
    EXPECT_EQ(result[0], 5);  // 2 * 2.5 = 5
    EXPECT_EQ(result[1], 10); // 4 * 2.5 = 10
    EXPECT_EQ(result[2], 15); // 6 * 2.5 = 15
}

TEST_F(MatrixTest, FriendScalarMultiplication) {
    Matrix<int> arr(3);
    arr[0] = 2; arr[1] = 4; arr[2] = 6;

    Matrix<int> result = 3 * arr;
    EXPECT_EQ(result[0], 6);
    EXPECT_EQ(result[1], 12);
    EXPECT_EQ(result[2], 18);
}

// §´§Ö§ã§ä§í §Õ§Ý§ñ §©§¡§¥§¡§¹§ª 1: replaceLastPositiveWithSecond
TEST_F(MatrixTest, Task1_ReplaceLastPositiveWithSecond) {
    Matrix<int> test_array = mixed_array;
    test_array.replaceLastPositiveWithSecond();

    EXPECT_EQ(test_array[5], 10); // §á§à§ã§Ý§Ö§Õ§ß§Ú§Û §á§à§Ý§à§Ø§Ú§ä§Ö§Ý§î§ß§í§Û (7) §Ù§Ñ§Þ§Ö§ß§Ö§ß §ß§Ñ §Ó§ä§à§â§à§Û (10)
    EXPECT_EQ(test_array[1], 10); // §Ó§ä§à§â§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä §ß§Ö §Ú§Ù§Þ§Ö§ß§Ú§Ý§ã§ñ
    EXPECT_EQ(test_array[0], -1);
    EXPECT_EQ(test_array[2], -5);
    EXPECT_EQ(test_array[3], 15);
    EXPECT_EQ(test_array[4], -3);
}

TEST_F(MatrixTest, Task1_NoPositiveElements) {
    Matrix<int> negative_array(3);
    negative_array[0] = -5;
    negative_array[1] = -2;
    negative_array[2] = -8;

    negative_array.replaceLastPositiveWithSecond();

    EXPECT_EQ(negative_array[0], -5);
    EXPECT_EQ(negative_array[1], -2);
    EXPECT_EQ(negative_array[2], -8);
}

TEST_F(MatrixTest, Task1_SingleElementArray) {
    Matrix<int> single(1);
    single[0] = 5;

    single.replaceLastPositiveWithSecond();
    EXPECT_EQ(single[0], 5); 
}

TEST_F(MatrixTest, Task1_EmptyArray) {
    Matrix<int> empty;
    EXPECT_NO_THROW(empty.replaceLastPositiveWithSecond());
}

TEST_F(MatrixTest, Task1_OnlyOnePositiveElement) {
    Matrix<int> arr(4);
    arr[0] = -1;
    arr[1] = 5;  // §Ó§ä§à§â§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä
    arr[2] = -2;
    arr[3] = 3;  // §á§à§ã§Ý§Ö§Õ§ß§Ú§Û §á§à§Ý§à§Ø§Ú§ä§Ö§Ý§î§ß§í§Û

    arr.replaceLastPositiveWithSecond();
    EXPECT_EQ(arr[3], 5); // §Ù§Ñ§Þ§Ö§ß§Ö§ß §ß§Ñ §Ó§ä§à§â§à§Û §ï§Ý§Ö§Þ§Ö§ß§ä
}

// §´§Ö§ã§ä§í §Õ§Ý§ñ §©§¡§¥§¡§¹§ª 2: insertMaxBeforeOnes
TEST_F(MatrixTest, Task2_InsertMaxBeforeOnes) {
    Matrix<int> test_array = with_ones_array;
    test_array.insertMaxBeforeOnes();

    EXPECT_EQ(test_array[0], 131); // 10 -> 131
    EXPECT_EQ(test_array[2], 131); // 131 -> 131
    EXPECT_EQ(test_array[4], 131); // 100 -> 131
    EXPECT_EQ(test_array[1], 25);  // §Ò§Ö§Ù §Ú§Ù§Þ§Ö§ß§Ö§ß§Ú§Û
    EXPECT_EQ(test_array[3], 7);   // §Ò§Ö§Ù §Ú§Ù§Þ§Ö§ß§Ö§ß§Ú§Û
}

TEST_F(MatrixTest, Task2_NoOnesInArray) {
    Matrix<int> no_ones(3);
    no_ones[0] = 2;
    no_ones[1] = 3;
    no_ones[2] = 4;

    no_ones.insertMaxBeforeOnes();

    EXPECT_EQ(no_ones[0], 2);
    EXPECT_EQ(no_ones[1], 3);
    EXPECT_EQ(no_ones[2], 4);
}

TEST_F(MatrixTest, Task2_AllElementsContainOnes) {
    Matrix<int> all_ones(3);
    all_ones[0] = 10;
    all_ones[1] = 131;
    all_ones[2] = 100;

    all_ones.insertMaxBeforeOnes();

    int max_val = 131;
    EXPECT_EQ(all_ones[0], max_val);
    EXPECT_EQ(all_ones[1], max_val);
    EXPECT_EQ(all_ones[2], max_val);
}

// §´§Ö§ã§ä§í §Õ§Ý§ñ §©§¡§¥§¡§¹§ª 3: createNewArray
TEST_F(MatrixTest, Task3_CreateNewArray) {
    Matrix<int> result = task3_test_array.createNewArray();

    EXPECT_EQ(result[0], -1);   // -1 * (0+1) = -1
    EXPECT_EQ(result[1], -4);   // -2 * (1+1) = -4
    EXPECT_EQ(result[2], 6);    // 2 * 3 = 6
    EXPECT_EQ(result[3], -16);  // -4 * (3+1) = -16
    EXPECT_EQ(result[4], -25);  // -5 * (4+1) = -25
    EXPECT_EQ(result[5], 30);   // 5 * 6 = 30
}

TEST_F(MatrixTest, Task3_EmptyArray) {
    Matrix<int> empty;
    Matrix<int> result = empty.createNewArray();
    EXPECT_EQ(result.getSize(), 0);
}

TEST_F(MatrixTest, Task3_SingleElement) {
    Matrix<int> single(1);
    single[0] = 5;

    Matrix<int> result = single.createNewArray();
    EXPECT_EQ(result[0], -5); // -5 * (0+1) = -5
}

// §´§Ö§ã§ä§í §Ó§ã§á§à§Þ§à§Ô§Ñ§ä§Ö§Ý§î§ß§í§ç §Þ§Ö§ä§à§Õ§à§Ó
TEST_F(MatrixTest, FindMax) {
    EXPECT_EQ(positive_array.findMax(), 8);
    EXPECT_EQ(mixed_array.findMax(), 15);

    Matrix<int> negative_array(3);
    negative_array[0] = -5;
    negative_array[1] = -1;
    negative_array[2] = -3;
    EXPECT_EQ(negative_array.findMax(), -1);
}

TEST_F(MatrixTest, FindLastPositive) {
    EXPECT_EQ(mixed_array.findLastPositive(), 5); // §ï§Ý§Ö§Þ§Ö§ß§ä 7
    EXPECT_EQ(positive_array.findLastPositive(), 4); // §ï§Ý§Ö§Þ§Ö§ß§ä 2

    Matrix<int> negative_array(3);
    negative_array[0] = -5;
    negative_array[1] = -2;
    negative_array[2] = -8;
    EXPECT_EQ(negative_array.findLastPositive(), static_cast<size_t>(-1));
}

TEST_F(MatrixTest, ContainsDigitOne) {
    Matrix<int> arr(1);

    Matrix<int> test_arr(2);
    test_arr[0] = 10;
    test_arr[1] = 25;
    test_arr.insertMaxBeforeOnes();

    EXPECT_EQ(test_arr[0], 25); 
}

// §´§Ö§ã§ä§í §Ó§í§Ó§à§Õ§Ñ §Ó §á§à§ä§à§Ü
TEST_F(MatrixTest, OutputOperator) {
    Matrix<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    std::stringstream ss;
    ss << arr;

    EXPECT_EQ(ss.str(), "1 2 3 ");
}

TEST_F(MatrixTest, OutputOperatorEmptyArray) {
    Matrix<int> empty;
    std::stringstream ss;
    ss << empty;
    EXPECT_TRUE(ss.str().empty());
}

class GeneratorTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(GeneratorTest, IStreamGenerator_ReadsCorrectly) {
    std::stringstream ss;
    ss << "10 20 30 40 50";

    IStreamGenerator<int> generator(ss);

    EXPECT_EQ(generator.generate(), 10);
    EXPECT_EQ(generator.generate(), 20);
    EXPECT_EQ(generator.generate(), 30);
    EXPECT_EQ(generator.generate(), 40);
    EXPECT_EQ(generator.generate(), 50);
}

TEST_F(GeneratorTest, IStreamGenerator_WithDifferentTypes) {
    std::stringstream ss;
    ss << "1 2 3";

    IStreamGenerator<int> generator(ss);
    EXPECT_EQ(generator.generate(), 1);
    EXPECT_EQ(generator.generate(), 2);
    EXPECT_EQ(generator.generate(), 3);
}

TEST_F(GeneratorTest, RandomGenerator_GeneratesInRange) {
    const int min = 1;
    const int max = 10;
    RandomGenerator<int> generator(min, max);

    for (int i = 0; i < 50; ++i) {
        int value = generator.generate();
        EXPECT_GE(value, min);
        EXPECT_LE(value, max);
    }
}

TEST_F(GeneratorTest, RandomGenerator_SingleValueRange) {
    RandomGenerator<int> generator(5, 5);

    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(generator.generate(), 5);
    }
}

TEST_F(GeneratorTest, RandomGenerator_NegativeRange) {
    RandomGenerator<int> generator(-10, -1);

    for (int i = 0; i < 30; ++i) {
        int value = generator.generate();
        EXPECT_GE(value, -10);
        EXPECT_LE(value, -1);
    }
}

TEST_F(GeneratorTest, RandomGenerator_LargeRange) {
    RandomGenerator<int> generator(-1000, 1000);

    for (int i = 0; i < 20; ++i) {
        int value = generator.generate();
        EXPECT_GE(value, -1000);
        EXPECT_LE(value, 1000);
    }
}

class ExerciseTest : public ::testing::Test {
protected:
    void SetUp() override {
        test_data1 = "1 5 3 8 2";
        ss1 = std::make_unique<std::stringstream>(test_data1);
        generator1 = std::make_unique<IStreamGenerator<int>>(*ss1);

        test_data2 = "10 25 131 7 100";
        ss2 = std::make_unique<std::stringstream>(test_data2);
        generator2 = std::make_unique<IStreamGenerator<int>>(*ss2);

        test_data3 = "1 2 3 4 5 6";
        ss3 = std::make_unique<std::stringstream>(test_data3);
        generator3 = std::make_unique<IStreamGenerator<int>>(*ss3);
    }

    std::string test_data1, test_data2, test_data3;
    std::unique_ptr<std::stringstream> ss1, ss2, ss3;
    std::unique_ptr<IStreamGenerator<int>> generator1, generator2, generator3;
};

TEST_F(ExerciseTest, Task1Exercise_Execute) {
    Task1Exercise<int> exercise(generator1.get(), 5);

    Matrix<int> original_array = exercise.get_array();
    EXPECT_EQ(original_array[0], 1);
    EXPECT_EQ(original_array[1], 5);
    EXPECT_EQ(original_array[2], 3);
    EXPECT_EQ(original_array[3], 8);
    EXPECT_EQ(original_array[4], 2);

    exercise.execute();

    Matrix<int> result_array = exercise.get_array();
    EXPECT_EQ(result_array[4], 5); // §á§à§ã§Ý§Ö§Õ§ß§Ú§Û §ï§Ý§Ö§Þ§Ö§ß§ä §Ù§Ñ§Þ§Ö§ß§Ö§ß §ß§Ñ §Ó§ä§à§â§à§Û
}

TEST_F(ExerciseTest, Task1Exercise_Task1Method) {
    Task1Exercise<int> exercise(generator1.get(), 5);

    exercise.Task1();

    Matrix<int> result_array = exercise.get_array();
    EXPECT_EQ(result_array[4], 5);
}

TEST_F(ExerciseTest, Task2Exercise_Execute) {
    Task2Exercise<int> exercise(generator2.get(), 5);

    exercise.execute();

    Matrix<int> result_array = exercise.get_array();
    EXPECT_EQ(result_array[0], 131); // 10 -> 131
    EXPECT_EQ(result_array[2], 131); // 131 -> 131
    EXPECT_EQ(result_array[4], 131); // 100 -> 131
    EXPECT_EQ(result_array[1], 25);  // §Ò§Ö§Ù §Ú§Ù§Þ§Ö§ß§Ö§ß§Ú§Û
    EXPECT_EQ(result_array[3], 7);   // §Ò§Ö§Ù §Ú§Ù§Þ§Ö§ß§Ö§ß§Ú§Û
}

TEST_F(ExerciseTest, Task2Exercise_Task2Method) {
    Task2Exercise<int> exercise(generator2.get(), 5);

    exercise.Task2();

    Matrix<int> result_array = exercise.get_array();
    EXPECT_EQ(result_array[0], 131);
}

TEST_F(ExerciseTest, Task3Exercise_Execute) {
    Task3Exercise<int> exercise(generator3.get(), 6);

    exercise.execute();

    Matrix<int> result = exercise.getTask3Result();
    EXPECT_EQ(result.getSize(), 6);

    // §±§â§à§Ó§Ö§â§ñ§Ö§Þ §á§â§Ñ§Ó§Ú§Ý§î§ß§à§ã§ä§î §Ó§í§é§Ú§ã§Ý§Ö§ß§Ú§Û
    EXPECT_EQ(result[0], -1);   // -1 * (0+1) = -1
    EXPECT_EQ(result[2], 6);    // 2 * 3 = 6
    EXPECT_EQ(result[5], 30);   // 5 * 6 = 30
}

TEST_F(ExerciseTest, Task3Exercise_Task3Method) {
    Task3Exercise<int> exercise(generator3.get(), 6);

    Matrix<int> result = exercise.Task3();

    EXPECT_EQ(result.getSize(), 6);
    EXPECT_EQ(exercise.getTask3Result().getSize(), 0); // execute §Ö§ë§Ö §ß§Ö §Ó§í§Ù§í§Ó§Ñ§Ý§ã§ñ
}

TEST_F(ExerciseTest, Task3Exercise_GetTask3Result) {
    Task3Exercise<int> exercise(generator3.get(), 6);

    // §¥§à §Ó§í§á§à§Ý§ß§Ö§ß§Ú§ñ execute §â§Ö§Ù§å§Ý§î§ä§Ñ§ä §Õ§à§Ý§Ø§Ö§ß §Ò§í§ä§î §á§å§ã§ä§í§Þ
    Matrix<int> initial_result = exercise.getTask3Result();
    EXPECT_EQ(initial_result.getSize(), 0);

    exercise.execute();

    // §±§à§ã§Ý§Ö §Ó§í§á§à§Ý§ß§Ö§ß§Ú§ñ §Õ§à§Ý§Ø§Ö§ß §Ò§í§ä§î §â§Ö§Ù§å§Ý§î§ä§Ñ§ä
    Matrix<int> final_result = exercise.getTask3Result();
    EXPECT_EQ(final_result.getSize(), 6);
}

TEST_F(ExerciseTest, ExerciseBaseFunctionality) {
    Task1Exercise<int> exercise(generator1.get(), 5);

    Matrix<int> array = exercise.get_array();
    EXPECT_EQ(array.getSize(), 5);
    EXPECT_EQ(array[0], 1);
}

// §´§Ö§ã§ä §á§à§Ý§Ú§Þ§à§â§æ§ß§à§Ô§à §á§à§Ó§Ö§Õ§Ö§ß§Ú§ñ
TEST_F(ExerciseTest, PolymorphicBehavior) {
    std::stringstream ss("1 2 3");
    IStreamGenerator<int> gen(ss);

    // §³§à§Ù§Õ§Ñ§Ö§Þ §â§Ñ§Ù§ß§í§Ö §å§á§â§Ñ§Ø§ß§Ö§ß§Ú§ñ §é§Ö§â§Ö§Ù §å§Ü§Ñ§Ù§Ñ§ä§Ö§Ý§î §ß§Ñ §Ò§Ñ§Ù§à§Ó§í§Û §Ü§Ý§Ñ§ã§ã
    std::unique_ptr<Exercise<int>> exercise1 = std::make_unique<Task1Exercise<int>>(&gen, 3);
    std::unique_ptr<Exercise<int>> exercise2 = std::make_unique<Task2Exercise<int>>(&gen, 3);
    std::unique_ptr<Exercise<int>> exercise3 = std::make_unique<Task3Exercise<int>>(&gen, 3);

    // §¥§à§Ý§Ø§ß§í §â§Ñ§Ò§à§ä§Ñ§ä§î §Ò§Ö§Ù §à§ê§Ú§Ò§à§Ü
    EXPECT_NO_THROW(exercise1->execute());
    EXPECT_NO_THROW(exercise2->execute());
    EXPECT_NO_THROW(exercise3->execute());

    // §®§Ö§ä§à§Õ§í Task1, Task2, Task3 §Õ§à§Ý§Ø§ß§í §Ò§í§ä§î §Õ§à§ã§ä§å§á§ß§í
    EXPECT_NO_THROW(exercise1->Task1());
    EXPECT_NO_THROW(exercise2->Task2());
    EXPECT_NO_THROW(exercise3->Task3());
}

TEST(IntegrationTest, CompleteWorkflow) {
    // §´§Ö§ã§ä §á§à§Ý§ß§à§Ô§à §â§Ñ§Ò§à§é§Ö§Ô§à §á§â§à§è§Ö§ã§ã§Ñ
    std::stringstream ss("5 -3 10 15 -8 20");
    IStreamGenerator<int> generator(ss);

    // §³§à§Ù§Õ§Ñ§Ö§Þ §å§á§â§Ñ§Ø§ß§Ö§ß§Ú§ñ
    Task1Exercise<int> task1(&generator, 6);
    Task2Exercise<int> task2(&generator, 6);
    Task3Exercise<int> task3(&generator, 6);

    // §£§í§á§à§Ý§ß§ñ§Ö§Þ §Ù§Ñ§Õ§Ñ§ß§Ú§ñ
    task1.execute();
    task2.execute();
    task3.execute();

    // §±§â§à§Ó§Ö§â§ñ§Ö§Þ, §é§ä§à §â§Ö§Ù§å§Ý§î§ä§Ñ§ä§í §á§à§Ý§å§é§Ö§ß§í
    Matrix<int> result1 = task1.get_array();
    Matrix<int> result2 = task2.get_array();
    Matrix<int> result3 = task3.getTask3Result();

    EXPECT_EQ(result1.getSize(), 6);
    EXPECT_EQ(result2.getSize(), 6);
    EXPECT_EQ(result3.getSize(), 6);
}

TEST(IntegrationTest, RandomGeneratorWithExercise) {
    // §ª§ß§ä§Ö§Ô§â§Ñ§è§Ú§à§ß§ß§í§Û §ä§Ö§ã§ä §ã RandomGenerator
    RandomGenerator<int> random_generator(-100, 100);
    Task1Exercise<int> exercise(&random_generator, 10);

    Matrix<int> array = exercise.get_array();
    EXPECT_EQ(array.getSize(), 10);

    // §£§ã§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§í §Õ§à§Ý§Ø§ß§í §Ò§í§ä§î §Ó §Õ§Ú§Ñ§á§Ñ§Ù§à§ß§Ö [-100, 100]
    for (size_t i = 0; i < array.getSize(); ++i) {
        EXPECT_GE(array[i], -100);
        EXPECT_LE(array[i], 100);
    }

    exercise.execute();
    EXPECT_EQ(exercise.get_array().getSize(), 10);
}

TEST(EdgeCaseTest, VeryLargeArray) {
    // §´§Ö§ã§ä §ã §Ò§à§Ý§î§ê§Ú§Þ §Þ§Ñ§ã§ã§Ú§Ó§à§Þ
    std::stringstream ss;
    for (int i = 0; i < 1000; ++i) {
        ss << i << " ";
    }

    IStreamGenerator<int> generator(ss);
    Task1Exercise<int> exercise(&generator, 1000);

    EXPECT_EQ(exercise.get_array().getSize(), 1000);
    EXPECT_NO_THROW(exercise.execute());
}

TEST(EdgeCaseTest, ArrayWithZeros) {
    // §´§Ö§ã§ä §ã §ß§å§Ý§Ö§Ó§í§Þ§Ú §Ù§ß§Ñ§é§Ö§ß§Ú§ñ§Þ§Ú
    std::stringstream ss("0 0 0 0 0");
    IStreamGenerator<int> generator(ss);

    Task1Exercise<int> task1(&generator, 5);
    Task2Exercise<int> task2(&generator, 5);
    Task3Exercise<int> task3(&generator, 5);

    EXPECT_NO_THROW(task1.execute());
    EXPECT_NO_THROW(task2.execute());
    EXPECT_NO_THROW(task3.execute());

    Matrix<int> result3 = task3.getTask3Result();
    EXPECT_EQ(result3.getSize(), 5);

    for (size_t i = 0; i < result3.getSize(); ++i) {
        EXPECT_EQ(result3[i], 0);
    }
}

TEST(EdgeCaseTest, ArrayWithLargeNumbers) {
    // §´§Ö§ã§ä §ã §Ò§à§Ý§î§ê§Ú§Þ§Ú §é§Ú§ã§Ý§Ñ§Þ§Ú
    std::stringstream ss("1000000 -1000000 999999 -999999");
    IStreamGenerator<int> generator(ss);

    Task1Exercise<int> exercise(&generator, 4);
    EXPECT_NO_THROW(exercise.execute());

    Matrix<int> result = exercise.get_array();
    EXPECT_EQ(result.getSize(), 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}