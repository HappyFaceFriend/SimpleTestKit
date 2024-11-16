#include <iostream>

struct CountingEntity
{
    static uint32_t DefaultConstructorCount;
    static uint32_t ParameterConstructorCount;
    static uint32_t CopyConstructorCount;
    static uint32_t CopyAssignmentCount;
    static uint32_t MoveConstructorCount;
    static uint32_t MoveAssignmentCount;
    static uint32_t DestructorCount;

    static void PrintAllCounts()
    {
        std::cout << "Default Constructor: " << DefaultConstructorCount <<
            "\nParameter Constructor: " << ParameterConstructorCount <<
            "\nCopy Constructor: " << CopyConstructorCount <<
            "\nCopyAssignment: " << CopyAssignmentCount <<
            "\nMoveConstructor: " << MoveConstructorCount <<
            "\nMove Assignment: " << MoveAssignmentCount <<
            "\nDestructor: " << DestructorCount << "\n";
    }
    static void ResetAllCounts()
    {
        DefaultConstructorCount = 0;
        ParameterConstructorCount = 0;
        CopyConstructorCount = 0;
        CopyAssignmentCount = 0;
        MoveConstructorCount = 0;
        MoveAssignmentCount = 0;
        DestructorCount = 0;
    }
    int x = 0;

    CountingEntity()
    {
        ++DefaultConstructorCount;
    }
    CountingEntity(int x) : x(x)
    {
        ++ParameterConstructorCount;
    }

    CountingEntity(const CountingEntity& other)
    {
        MoveConstructorCount;
        x = other.x;
    }

    CountingEntity(CountingEntity&& other) noexcept
    {
        ++MoveConstructorCount;
        x = other.x;
        other.x = 0;
    }

    CountingEntity& operator=(const CountingEntity& other)
    {
        ++CopyConstructorCount;
        if (this != &other)
        {
            x = other.x;
        }
        return *this;
    }

    CountingEntity& operator=(CountingEntity&& other) noexcept
    {
        ++MoveAssignmentCount;
        if (this != &other)
        {
            x = other.x;
            other.x = 0;
        }
        return *this;
    }

    ~CountingEntity()
    {
        ++DestructorCount;
    }
};
