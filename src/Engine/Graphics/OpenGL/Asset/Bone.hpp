#pragma once
#include "../../../common.hpp"
#include "../Maths.hpp"
#include "../SceneNode.hpp"

namespace KG
{

	/*! \class
	*/
	struct BoneTransform
	{
		glm::dmat4 offset;
		glm::dmat4 final;
	};

	typedef Vec4i VertexIDs;
	typedef Vec4i BoneIDs;
	typedef Vec4f BoneWeights;


	/*! \class

	*/
	class Skeleton
		: public KG::SceneNode
	{
	public:
		std::vector<std::string>	names;				// bone names
		std::vector<float>			weights;			// positon would be index to vertex. value is the weight.
		std::vector<BoneTransform>	bone_transforms;	// offset and final transform for each bone.
		
	public:
		Skeleton(const KE::EntityID p_EntityID = KE::EntityIDGenerator::NewID(), const KG::RenderPass p_RenderPass = KG::RenderPass::Null)
			: KG::SceneNode(p_EntityID, p_RenderPass)
		{}

		KG::SceneNodeList & GetChildren(void)
		{
			return m_ChildSceneNodeList;
		}

		void Reserve(const unsigned p_Size)
		{
			names.reserve(p_Size);
			weights.reserve(p_Size);
			bone_transforms.reserve(p_Size);
		}

	};


	typedef std::shared_ptr<KG::Skeleton>	Skeleton_SmartPtr;
	typedef std::weak_ptr<KG::Skeleton>		Skeleton_WeakPtr;
} // KG ns