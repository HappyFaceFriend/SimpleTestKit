#include "CountingEntity.h"


uint32_t CountingEntity::DefaultConstructorCount = 0;
uint32_t CountingEntity::ParameterConstructorCount = 0;
uint32_t CountingEntity::CopyConstructorCount = 0;
uint32_t CountingEntity::CopyAssignmentCount = 0;
uint32_t CountingEntity::MoveConstructorCount = 0;
uint32_t CountingEntity::MoveAssignmentCount = 0;
uint32_t CountingEntity::DestructorCount = 0;