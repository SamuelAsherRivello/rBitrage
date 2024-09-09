

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
  - TODO: Actor DrawTexturePro supports pivot. Add it to actor and set to center by default? -- See https://docs.unity3d.com/ScriptReference/Sprite-pivot.html
- SYSTEMS
  - TODO: Split CameraSystem into CameraSystem2D and CameraSystem3D and remove the CameraSystemMode?
- IMPROVEMENTS
  - TODO: Scope how much physics we want. Alot? Import 3rd party. A little, then add concept of CollisionGroups to existing IsCollididing() and be done.
  - TODO: Change System:OnInitialize to System:OnInitializeAsync and have game wait for it
- TYPES
  - TODO: rotation is now stored in radians. Convert SOME/ALL to degrees? Make wrap from -360 to 360?
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
