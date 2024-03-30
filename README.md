# Seed Helper

Seed Helper is a python library that help to find specific Minecraft structures or biomes for a given seed.
The package is currently in very early development, so currently only the get_elytras_positions function is available (in the structure module).

Example:
```py
import seedhelper.structure as sth

seed = 123456789
ships = sth.get_elytras_positions(seed, r=5000, mc_version="1.20")
for ship in ships:
    print(f"Elytra Ship found at: {ship.pos.x}, {ship.pos.z}")
```

## Credits
The project uses the [Cubiomes](https://github.com/Cubitect/cubiomes) C library, which help to work with Minecraft seeds.
