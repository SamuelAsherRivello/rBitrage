

## TODO LIST

- PERFORMANCE
  - TODO: Why does the ball flicker when moving (this started when I added the camera follow)
- CODING STANDARDS
  - TODO: Make a new "rBitrage.h" that contains every 'h' so users only need to include that ONE thing?
  - TODO: Do a full pass over all methods per pointers. Pointers as arguments? Pointers as return values? Efficient + Standardized?
- NEW FEATURES
  - TODO: Draw items by SceneGraph first (more work), then position.z second (easier). Instead as currently, by  _actors[index]
  - TODO: Add hot reloading
  - TODO: Add pooling (of arbitrary type perhaps, but Actor is the key use case for bullets)
- SYSTEMS
  - TODO: Split CameraSystem into CameraSystem2D and CameraSystem3D and remove the CameraSystemMode?
- IMPROVEMENTS
  - TODO: Scope how much physics we want. Alot? Import 3rd party. A little, then add concept of CollisionGroups to existing IsColliding() and be done.
  - TODO: Change System:OnInitialize to System:OnInitializeAsync and have game wait for it
- TYPES
  - TODO: rotation is now stored in radians. Convert SOME/ALL to degrees? Make wrap from -360 to 360?
- RENDERING
  - TODO: Add 3d Lights (via shaders) as an actor subclass? https://www.raylib.com/examples/shaders/loader.html?name=shaders_basic_lighting

- PHILOSOPHY
  - EAST TO LEARN
    - TODO: Make doxygen with github actions to show full API
  - EAST TO USE
    - TODO: ...
  - HARD TO MISUSE
    - TODO: Anytime an asset key is missing, put in a runtime substitute (e.g. draw actor bounds if texture fails to load)
- POOLING
  - TODO: Think about a factory for actors. ActorPool.Create(ActorType) or ??


## CONCEPTUAL OVERVIEW

```

Main file
└── Demo file
    └── Window
        └── Game
            ├── Screen
            ├── World
            └── Systems (with lifecycle)
                ├── ...
                ├── AssetLoaderSystem
                ├── CameraSystem
                │   ├── Camera2D (on)
                │   └── Camera3D (off)
                └── SceneSystem
                    └── Scene
                        └── Actor (with lifecycle) ex. Sprite2D, Model3D
                └── ...
```


## GENERAL C++ SYNTAX NOTES

### Return types

What is the best way to return something from a function?

Here is an arbitrary example of various syntax;

1. `Bounds Actor::GetBounds()`

This function returns a copy of the actor's bounds, allowing the caller to modify or use the returned value independently without affecting the original bounds in the actor. This approach is suitable when the caller needs a temporary copy of the bounds, but it can lead to unnecessary memory allocation and copying.

2. `Bounds& Actor::GetBounds()`

This function returns a reference to the actor's bounds, providing direct access to the original value within the actor. By using a reference, the caller can modify or read the actor's bounds without creating an extra copy, which is essential when working with complex data structures that need to be updated in place.

3. `Bounds Actor::GetBounds()*` or is it `Bounds* Actor::GetBounds()`?

This function returns a pointer to the actor's bounds, allowing the caller to access and potentially modify the original value within the actor. However, using pointers can lead to ownership issues, dangling pointers, or memory leaks if not managed properly. Pointers should be used with caution and only when necessary, as they require more care to ensure memory safety.

| **Return Type** | Read         | Write        | Must Mem. Manage |
| --- | --- | --- | --- |
| `Bounds`    | •              |                    |                  |
| `Bounds&`   | •              | •                |                   |
| `Bounds*`   | •              | •                | •                 |
