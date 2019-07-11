#pragma once

#define INTEL_ROUNDS_NUM 4

typedef struct __intelCompRound intelCompRound;
typedef struct __intel intel;

intelCompRound * intelCompRound_new () ;
void intelCompRound_free (intelCompRound * self) ;
intelCompRound * intelCompRound_newFilled (unsigned short id, unsigned short energy) ;
unsigned short intelCompRound_id (intelCompRound * self) ;
unsigned short intelCompRound_energy (intelCompRound * self) ;
void intelCompRound_set_id (intelCompRound * self, unsigned short id) ;
void intelCompRound_set_energy (intelCompRound * self, unsigned short energy) ;

intel * intel_new () ;
void intel_free (intel * self) ;
void intel_set (intel * self, const unsigned short numOfRound, intelCompRound * toSet) ;
intelCompRound * intel_at (intel * self, const unsigned short numOfRound) ;
