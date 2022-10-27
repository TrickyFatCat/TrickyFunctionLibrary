# TrickyFunctionLibrary

 A collection of blueprint function libraries.

## Installation

The plugin can be used in both C++ and Blueprint projects.

### Blueprint projects

**At the moment, the package is compatible only with Unreal Engine 4.**

1. Download [**package file**](https://github.com/TrickyFatCat/TrickyFunctionLibrary/releases/tag/v1.0);
2. Unzip the package to the Plugins folder in engine folder, e.g. `C:\Program Files\Epic Games\UE_4.27\Engine\Plugins`;
3. Restart the project;

In this case the plugin can be used for any blueprint project.

### C++ projects

1. Create the Plugins folder in the project directory;
2. Create the TrickyAnimationComponents folder in the Plugins folder;
3. Download the plugin source code into that folder;
4. Rebuild the project;

## Functions

1. `ConvertTimeSeconds` - converts given time in seconds to different time formats;
2. `SetTimelineRateToTime` - sets timeline play rate to play as long as target time;
3. `GetPlayerCharacterViewPoint` - returns player characters viewpoint location and rotation;
4. `ApproachInt32` - changes the given int32 variable  by a given delta value up to a target value.
5. `ApproachFloat` - changes the given float variable  by a given delta value up to a target value.
4. `ApproachInt32` - changes the given vector variable  by a given delta value up to a target value.
