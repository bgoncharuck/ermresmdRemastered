#pragma once

#include <stdbool.h>

typedef enum __seriliazationType {
	booleanType,
	integerType,
	floatType,
	stringType,
	objectType,
	arrayType
} serializationType;
typedef struct __serializationObject serializationObject;
typedef struct __serializationPoint serializationPoint;

// data must be dynamic
serializationPoint * serializationPoint_new
(const char * title, serializationType type, void * value) ;

void serializationPoint_free (serializationPoint * self) ;

// data must be dynamic
void serializationPoint_change
(serializationPoint * self, const char * title, serializationType type, void * value) ;

const char * serializationPoint_title (serializationPoint * self) ;
serializationType serializationPoint_type (serializationPoint * self) ;
void * serializationPoint_value (serializationPoint * self) ;
