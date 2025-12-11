#include <gtest/gtest.h>
#include "Matrix.h"
#include "IStreamGenerator.h"
#include "RandomGenerator.h"
#include "VariantExercise.h"
#include <sstream>

using namespace MATRIX;

TEST(MatrixTest, ConstructorsAndAccess) {
    Matrix<int> empty;
    EXPECT_EQ(empty.getSize(), 0);
    
    Matrix<int> sized(3);
    EXPECT_EQ(sized.getSize(), 3);
    EXPECT_EQ(sized[0], 0);
    
    sized[0] = 1; sized[1] = 2; sized[2] = 3;
    EXPECT_EQ(sized[1], 2);
    
    Matrix<int> copy(sized);
    EXPECT_EQ(copy[2], 3);
    
    EXPECT_THROW(sized[5], std::out_of_range);
}

TEST(MatrixTest, ArithmeticOperations) {
    Matrix<int> a(3), b(3);
    a[0]=1; a[1]=2; a[2]=3;
    b[0]=4; b[1]=5; b[2]=6;
    
    Matrix<int> sum = a + b;
    EXPECT_EQ(sum[0], 5);
    EXPECT_EQ(sum[1], 7);
    EXPECT_EQ(sum[2], 9);
    
    Matrix<int> diff = a - b;
    EXPECT_EQ(diff[0], -3);
    
    Matrix<int> scaled = a * 2;
    EXPECT_EQ(scaled[1], 4);
}

TEST(MatrixTasksTest, Task1_ReplaceLastPositive) {
    Matrix<int> arr(5);
    arr[0] = -1; arr[1] = 10; arr[2] = -5; arr[3] = 15; arr[4] = 7;
    
    arr.replaceLastPositiveWithSecond();
    
    EXPECT_EQ(arr[4], 10); // последний положительный (7) заменен на второй (10)
    EXPECT_EQ(arr[1], 10); // второй элемент без изменений
}

TEST(MatrixTasksTest, Task1_NoPositiveElements) {
    Matrix<int> arr(3);
    arr[0] = -5; arr[1] = -2; arr[2] = -8;
    
    arr.replaceLastPositiveWithSecond();
    
    EXPECT_EQ(arr[0], -5); // массив не изменился
    EXPECT_EQ(arr[2], -8);
}

TEST(MatrixTasksTest, Task2_InsertMaxBeforeOnes) {
    Matrix<int> arr(4);
    arr[0] = 10;   // содержит 1
    arr[1] = 25;   // не содержит 1  
    arr[2] = 131;  // содержит 1 (максимальный)
    arr[3] = 7;    // не содержит 1
    
    arr.insertMaxBeforeOnes();
    
    EXPECT_EQ(arr[0], 131); // заменен на максимальный
    EXPECT_EQ(arr[2], 131); // уже был максимальным
    EXPECT_EQ(arr[1], 25);  // без изменений
    EXPECT_EQ(arr[3], 7);   // без изменений
}

TEST(MatrixTasksTest, Task3_CreateNewArray) {
    Matrix<int> original(4);
    original[0] = 1; original[1] = 2; original[2] = 3; original[3] = 4;
    
    Matrix<int> result = original.createNewArray();
    
    EXPECT_EQ(result[0], -1);   // -1 * (0+1) = -1
    EXPECT_EQ(result[1], -4);   // -2 * (1+1) = -4  
    EXPECT_EQ(result[2], 6);    // 2 * 3 = 6
    EXPECT_EQ(result[3], -16);  // -4 * (3+1) = -16
}

TEST(GeneratorTest, IStreamGenerator) {
    std::stringstream ss("100 200 300");
    IStreamGenerator<int> generator(ss);
    
    EXPECT_EQ(generator.generate(), 100);
    EXPECT_EQ(generator.generate(), 200);
    EXPECT_EQ(generator.generate(), 300);
}

TEST(GeneratorTest, RandomGenerator) {
    RandomGenerator<int> generator(1, 10);
    
    for (int i = 0; i < 10; ++i) {
        int value = generator.generate();
        EXPECT_GE(value, 1);
        EXPECT_LE(value, 10);
    }
}

TEST(ExerciseTest, Task1Exercise) {
    std::stringstream ss("5 -3 8 12 -1");
    IStreamGenerator<int> generator(ss);
    
    Task1Exercise<int> exercise(&generator, 5);
    exercise.execute();
    
    Matrix<int> result = exercise.get_array();
    EXPECT_EQ(result[4], 8); // последний положительный (12) заменен на второй (8)
}

TEST(ExerciseTest, Task2Exercise) {
    std::stringstream ss("15 20 105 30");
    IStreamGenerator<int> generator(ss);
    
    Task2Exercise<int> exercise(&generator, 4);
    exercise.execute();
    
    Matrix<int> result = exercise.get_array();
    EXPECT_EQ(result[0], 105); // 15 содержит 1 -> заменен на максимум 105
    EXPECT_EQ(result[2], 105); // 105 содержит 1 -> остается максимумом
}

TEST(ExerciseTest, Task3Exercise) {
    std::stringstream ss("2 4 6 8");
    IStreamGenerator<int> generator(ss);
    
    Task3Exercise<int> exercise(&generator, 4);
    exercise.execute();
    
    Matrix<int> result = exercise.getTask3Result();
    EXPECT_EQ(result.getSize(), 4);
    EXPECT_EQ(result[2], 12); // 2 * 6 = 12 (третий элемент)
}

TEST(IntegrationTest, CompleteWorkflow) {
    std::stringstream ss("3 7 11 4 9");
    IStreamGenerator<int> generator(ss);
    
    // Тестируем все три задания последовательно
    Task1Exercise<int> task1(&generator, 5);
    task1.execute();
    
    Task2Exercise<int> task2(&generator, 5); 
    task2.execute();
    
    Task3Exercise<int> task3(&generator, 5);
    task3.execute();
    
    // Проверяем что все выполнено без ошибок
    EXPECT_EQ(task1.get_array().getSize(), 5);
    EXPECT_EQ(task2.get_array().getSize(), 5);
    EXPECT_EQ(task3.getTask3Result().getSize(), 5);
}

TEST(IntegrationTest, RandomGeneratorIntegration) {
    RandomGenerator<int> generator(-50, 50);
    Task1Exercise<int> exercise(&generator, 8);
    
    Matrix<int> array = exercise.get_array();
    EXPECT_EQ(array.getSize(), 8);
    
    // Проверяем что все элементы в диапазоне
    for (size_t i = 0; i < array.getSize(); ++i) {
        EXPECT_GE(array[i], -50);
        EXPECT_LE(array[i], 50);
    }
    
    exercise.execute();
    EXPECT_EQ(exercise.get_array().getSize(), 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
