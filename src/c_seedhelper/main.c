#include <stdbool.h>
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "structures_helper.h"


const char *argp_program_version = "seed-helper 1.0";


#define DEFAULT_MC_VERSION "latest"
#define LATEST_MC_VERSION "1.20"
#define DEFAULT_X 0
#define DEFAULT_Z 0
#define DEFAULT_R 10000


int get_find_elytras_arguments(struct find_elytras_arguments* arguments, int argc, char* argv[]) {
    arguments->seed = 0;
    arguments->mc_version = LATEST_MC_VERSION;
    arguments->x = DEFAULT_X;
    arguments->z = DEFAULT_Z;
    arguments->r = DEFAULT_R;

    static struct option long_options[] = {
        {"seed", required_argument, 0, 's'},
        {"mc-version", required_argument, 0, 'v'},
        {"x", required_argument, 0, 'x'},
        {"z", required_argument, 0, 'z'},
        {"r", required_argument, 0, 'r'},
        {0, 0, 0, 0}
    };

    int opt;
    int option_index = 0;
    while ((opt = getopt_long(argc, argv, "s:v:x:z:r:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 's':
                arguments->seed = strtoull(optarg, NULL, 10);
                break;
            case 'v':
                if (!strcmp(optarg, "latest"))
                    arguments->mc_version = LATEST_MC_VERSION;
                else
                    arguments->mc_version = optarg;
                break;
            case 'x':
                arguments->x = atoi(optarg);
                break;
            case 'z':
                arguments->z = atoi(optarg);
                break;
            case 'r':
                arguments->r = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s --find-elytras --seed [uint64_t required] --mc-version [str default 'latest'] -x [default 0] -z [default 0] -r [default 10000]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (arguments->seed == 0) {
        fprintf(stderr, "Seed is required\n");
        exit(EXIT_FAILURE);
    }

    printf("Parsed arguments:\n");
    printf("Seed: %llu\n", arguments->seed);
    printf("Minecraft Version: %s\n", arguments->mc_version);
    printf("X coordinate: %d\n", arguments->x);
    printf("Z coordinate: %d\n", arguments->z);
    printf("Radius: %d\n", arguments->r);

    return 0;
}


int main(int argc, char* argv[]) {
    struct find_elytras_arguments arguments;

    for (int i = optind; i < argc; i++) {
        if (strcmp(argv[i], "--find-elytras") == 0) {
            struct find_elytras_arguments args;
            get_find_elytras_arguments(&args, argc - i, argv + i);

            int n_ships;
            Piece* ships = get_elytras_positions(&args, &n_ships);

            for (int i = 0; i < 10; i++)
                printf("x: %d y: %d z: %d\n", ships[i].pos.x, ships[i].pos.y, ships[i].pos.z);
            break;
        }
    }

    return 0;
}

