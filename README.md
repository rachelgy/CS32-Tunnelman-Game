# CS32-Tunnelman-Game

### Project Summary

This project involves the development of a game engine implemented in C++ for a 2D game similar to Boulder Dash. The engine includes various classes representing game entities such as actors (including Tunnelman and protesters), earth, boulders, goodies (like gold nuggets and barrels of oil), and more. The game world is managed by the `StudentWorld` class which handles initialization, movement, and cleanup.

### Key Features

- **Actor Hierarchy**: The `Actor` class serves as the base class for various game entities, with subclasses such as `Tunnelman`, `Protester`, and more. Each subclass has its own specific behaviors and attributes.

- **Game World Management**: The `StudentWorld` class manages the game world, handling initialization, movement, and cleanup of game entities. It also includes methods for digging earth, checking proximity of entities, and adding new protesters.

- **AI for Protesters**: Protester entities, including `RegularProtester` and `HardcoreProtester`, have AI algorithms implemented for behaviors such as finding the shortest path to the player (`Tunnelman`), reacting to player actions, and deciding when to leave the game field.

- **Game Items**: Various game items such as gold nuggets, barrels of oil, sonar kits, and water pools are implemented with specific behaviors for interaction with the player and other entities.

### Bugs and Design Decisions

- **Bugs**: Several bugs are noted, such as occasional issues with boulders' collision detection and behavior, boulder falling distances, and protester behavior when hit by squirt.

- **Design Decisions**: Assumptions were made regarding the game environment, entity interactions, and implementation choices. For example, the use of breadth-first search for pathfinding, immediate removal of earth by Tunnelman, and handling of game item visibility and pickup mechanics.

### Testing Descriptions

- **Tunnelman Testing**: Testing involves verifying player controls, movement, interactions with entities, and game over conditions.

- **Entity Testing**: Detailed testing descriptions are provided for various game entities including earth, squirts, barrels of oil, gold nuggets, protesters, boulders, and more. This includes behaviors, interactions, and reactions to player actions.

- **StudentWorld Testing**: Testing includes initialization of the game world, distribution of game items, appearance of new entities, and handling of level completion.

### Conclusion

The project encompasses a comprehensive game engine implementation with various classes representing game entities and behaviors. Testing descriptions cover a wide range of scenarios to ensure proper functionality and interaction within the game environment. Ongoing bug fixes and adjustments may be necessary to refine the game mechanics and user experience.
