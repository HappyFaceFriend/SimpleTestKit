#include <iostream>

#include "TestKit/LoggingEntity.h"
#include "TestKit/CountingEntity.h"
#include "TestKit/Instrumentor.h"


#include <map>
#include <unordered_map>
#include <random>

int main()
{
	constexpr int InsertCount = 2000000;

	PROFILE_BEGIN_SESSION("test", "test.json");

	std::map<int, CountingEntity> countingMap;
	{
		PROFILE_SCOPE("std::map insertion")

		for (int i = 0; i < InsertCount; i++) {
			countingMap[i] = CountingEntity(i);
		}
	}
	std::cout << "std::map insertion\n";
	CountingEntity::PrintAllCounts();
	CountingEntity::ResetAllCounts();
	std::cout << '\n';

	std::unordered_map<int, CountingEntity> countingUnorderedMap;
	std::cout << "Bucket:" << countingUnorderedMap.bucket_count()<<'\n';
	{
		PROFILE_SCOPE("std::unordered_map insertion")

		for (int i = 0; i < InsertCount; i++) {
			countingUnorderedMap[i] = CountingEntity(i);
		}
	}
	std::cout << "std::unordered_map insertion\n";
	std::cout << "Bucket:" << countingUnorderedMap.bucket_count() << '\n';
	CountingEntity::PrintAllCounts();
	CountingEntity::ResetAllCounts();

	{
		PROFILE_SCOPE("std::map lookup")

			for (int i = 0; i < InsertCount; i++) {
				int x = countingMap[i].x;
			}
	}
	{
		PROFILE_SCOPE("std::unordered_map lookup")

			for (int i = 0; i < InsertCount; i++) {
				int x = countingUnorderedMap[i].x;
			}
	}

	CountingEntity::ResetAllCounts();

	countingUnorderedMap.reserve(InsertCount);
	std::cout << "std::unordered_map reserve\n";
	std::cout << "Bucket:" << countingUnorderedMap.bucket_count() << '\n';
	std::cout << '\n';
	CountingEntity::PrintAllCounts();
	CountingEntity::ResetAllCounts();





	PROFILE_END_SESSION();
	return 0;
}