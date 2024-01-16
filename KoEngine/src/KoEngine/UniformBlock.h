#pragma once

#include <Utilities/Math/MathTypes.h>
#include <Application/Interfaces/ICameraController.h>
struct UniformBlock
{
	CameraMatrix mProjectView;
	mat4 mModelMatCapsule;
	mat4 mModelMatCube;
};
  