#pragma once
#include "Math/MathTypes.h"
#include "Core/Serializable.h"

namespace nc
{
	struct Transform : public ISerializable
	{
		glm::vec3 position{ 0 };
		float rotation = 0;
		glm::vec3 scale{ 1 };

		glm::vec3 localPosition{ 0 };
		float localRotation = 0;
		glm::vec3 localScale{ 1 };

		glm::mat4 matrix;

		Transform() {}
		Transform(const glm::vec3& position, float rotation = 0, const glm::vec3& scale = glm::vec3{ 1 }) :
			position{ position }, rotation{ rotation }, scale{ scale } {}

		void Update();
		void Update(const glm::mat4& mx);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};
}