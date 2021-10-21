# ConcreteMixingSimulator

## Installation

1. Download the latest version of either the Win or Mac version of the game from the releases page:
https://github.com/bph-tuwien/ConcreteMixingSimulator/releases
2. Extract the archive to the desired folder.
3. Start the game by running the `ConcreteMixing.exe` or on Mac the `ConcreteMixing.app`.

## How to Play

 * You can move around with the WASD keys and turn by moving the mouse.
 * An object can be picked up by pointing the red crosshair to it and clicking the right mouse button while being relatively close to the object.
 * While holding the object you can still move and turn, and by scrolling with the mouse wheel the picked up object can be moved further or closer to you.
 * You can drop an object by clicking the right mouse button.
 * You can use an object by aiming with the crosshair for another (target) object and clicking the left mouse button while holding the object. For example, pick up the spoon and aim for a labeled ingredient jar (except oil) to take ingredients out of the jar. Some objects don't require another object to be used. 
 * The game can be restarted by pressing the R key, and excited by pressing the Escape key.

## How to Define Concrete Recipes

The concrete recipes can be found and edited in a JSON file under ConcreteMixing/Content/recipesConfig.json. This is a text based config file following the JSON format which list the concrete recipes in a list. A recipe in the recipes list has the following structure.
```
{
   "id": 0,
   "ok": true,
   "name": "Simple Mixture",
   "description": "So simple, it makes everything perfect!",
   "cementMin": 80,
   "cementMax": 90,
   "flyAshMin": 10,
   "flyAshMax": 15,
   "recycledConcreteMin": 60,
   "recycledConcreteMax": 65,
   "sandMin": 240,
   "sandMax": 260,
   "waterMin": 60,
   "waterMax": 70,
   "juteFibersMin": 50,
   "juteFibersMax": 60
}
```
To define a new one, duplicate a config section like this one in the config file, and don't forget to put a comma after the `}` character, except if it's the last recipe in the list.

A recipe has the following values:
 * id: A unique identification number of each recipe which should be different for each recipe. (However, currently not used.)
 * ok: A `true` or `false` value which defines if a recipe is a good one or a bad one.
 * name: The name of the recipe. This one will be displayed in the book on evaluation. If too long and it's hanging off of the book then `<br>` tags can be used to create a new line.
 * description: The description of the recipe. This one will be displayed in the book on evaluation. If too long and it's hanging off of the book then `<br>` tags can be used to create a new line.
 * cementMin: The minimum (inclusive) amount of cement that needs to be in the mixture to qualify for the given recipe.
 * cementMax: The maximum (inclusive) amount of cement that needs to be in the mixture to qualify for the given recipe.
 * flyAshMin: The minimum (inclusive) amount of fly ash that needs to be in the mixture to qualify for the given recipe.
 * flyAshMax: The maximum (inclusive) amount of fly ash that needs to be in the mixture to qualify for the given recipe.
 * recycledConcreteMin: The minimum (inclusive) amount of recycled concrete that needs to be in the mixture to qualify for the given recipe.
 * recycledConcreteMax: The maximum (inclusive) amount of recycled concrete that needs to be in the mixture to qualify for the given recipe.
 * sandMin: The minimum (inclusive) amount of sand that needs to be in the mixture to qualify for the given recipe.
 * sandMax: The maximum (inclusive) amount of sand that needs to be in the mixture to qualify for the given recipe.
 * waterMin: The minimum (inclusive) amount of water that needs to be in the mixture to qualify for the given recipe.
 * waterMax: The maximum (inclusive) amount of water that needs to be in the mixture to qualify for the given recipe.
 * juteFibersMin: The minimum (inclusive) amount of jute fibers that needs to be in the mixture to qualify for the given recipe.
 * juteFibersMax: The maximum (inclusive) amount of jute fibers that needs to be in the mixture to qualify for the given recipe.
 

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
    Containing mostly the given object's visual feedback for interactions, but in some cases the game logic bled into them.


