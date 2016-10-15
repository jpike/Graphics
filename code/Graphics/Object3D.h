#pragma once

#include <vector>
#include "Graphics/Vertex.h"
#include "Math/Matrix4.h"

namespace GRAPHICS
{
    /// A generic object that exists in a 3D space.
    class Object3D
    {
    public:
        /// The vertices of the object, in the local coordinate space of the object.
        std::vector<Vertex> Vertices = {};
        /// The world transform of the object.
        MATH::Matrix4x4f WorldTransform = MATH::Matrix4x4f::Identity();
    };
}
