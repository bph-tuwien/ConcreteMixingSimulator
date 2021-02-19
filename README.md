# ConcreteMixingSimulator

## Installation

1. Download the latest version of either the Win or Mac version of the game from the releases page:
https://github.com/bph-tuwien/ConcreteMixingSimulator/releases
2. Extract the archive to a desired folder.
3. Start the game by running the `ConcreteMixing.exe` or on Mac the `ConcreteMixing.app`.

## How to Play

 * You can move around with the WASD keys and turn by moving the mouse.
 * An object can be picked up by pointing the red crosshair to it and clicking the right mouse button while being relatively close to the object.
 * While holding the object you can still move and turn, and by scrolling with the mouse wheel the picked up object can be moved further or closer to you.
 * You can drop an object by clicking the right mouse button.
 * You can use an object by aiming with the crosshair for another (target) object and clicking the left mouse button while holding the object. For example, pick up the spoon and aim for a labeled ingredient jar (except oil) to take ingredients out of the jar. Some objects don't require another object to be used. 
 * The game can be restarted by pressing the R key, and excited by pressing the Escape key.

## Developer Guide

### Software requirements

 * The project is using Unreal Engine version 4.26.0
 * Voxel models were made in an open source voxel editor, MagicaVoxel.
 * Obj exports were pivot corrected (due to MagicaVoxel issue) in Blender.

### Blueprint settings

The entire logic of the game is implemented in Unreal Blueprints. These were formatted with the assumption that the Blueprint curves are flattened out to linear lines. 
This can be achieved by going into Preferences/Editor Preferences/Content Editors/Graph Editors/Splines and expanding the advanced settings with the arrow, and setting the 4 vector2-s that are mentioning Tangents to 0 vectors. Without these settings, Blueprints might look suboptimal in formatting making it difficult to comprehend.

### Logic Structure

The implementation is split into 3 different types of Blueprints:
 1. FirstPersonCharacter: (Content/FirstPersonBP/Blueprints/FirstPersonCharacter)
    Containing the Player Controller logic, like input handling, moving, and object pick up.
 2. GameLogic: (Content/Logics/GameLogic)
    Containing object interaction logics, like what happens when the spoon is used on the cement jar. Also the checks are implemented in this blueprint to handle the attempt on the instructions in the book.
 3. Object Blueprints: (Content/Objects/ObjectBP)
    Containing mostly the given object's visual feedback for interactions.
