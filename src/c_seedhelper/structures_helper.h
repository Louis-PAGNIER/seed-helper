#ifndef STRUCTURES_HELPER_H_
#define STRUCTURES_HELPER_H_

#define END_CITY_REGION_CHUNK_SIZE 20
#define REGION_SIZE (20*16)
#endif

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#include "../cubiomes/generator.h"
#include "../cubiomes/finders.h"
#include "../cubiomes/util.h"

struct find_elytras_arguments {
    uint64_t seed;
    char* mc_version;
    int x;
    int z;
    int r;
};

DLLEXPORT Piece* get_elytras_positions(struct find_elytras_arguments* arguments, int *n_ships);