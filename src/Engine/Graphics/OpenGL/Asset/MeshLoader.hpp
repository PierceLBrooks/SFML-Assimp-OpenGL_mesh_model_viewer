#pragma once
#include "../../../common.hpp"

namespace KG
{
	class Mesh;
	typedef std::shared_ptr<KG::Mesh>	Mesh_SmartPtr;
	class Meshes;
	typedef std::shared_ptr<KG::Meshes> Meshes_SmartPtr;
	typedef std::weak_ptr<KG::Meshes>	Meshes_WeakPtr;
	class Texture;
	typedef std::shared_ptr<KG::Texture>	Texture_SmartPtr;
	class Skeleton;
	typedef std::shared_ptr<KG::Skeleton>	Skeleton_SmartPtr;
	typedef std::weak_ptr<KG::Skeleton>		Skeleton_WeakPtr;
	class BoneNode;
	typedef std::shared_ptr<KG::BoneNode> BoneNode_SmartPtr;
	typedef std::weak_ptr<KG::BoneNode> BoneNode_WeakPtr;


	/*! \class MeshLoader
	*/
	class MeshLoader
	{

	private:
		Assimp::Importer		m_Importer;
		const aiScene	*		m_pScene;

		std::vector<KG::Texture_SmartPtr> m_Textures;

	public:
		MeshLoader(void);
		/*! Return nullptr if loading fails. */
		Meshes_SmartPtr Load(const std::string & p_rPath);

	private:
		bool LoadScene(const std::string & p_rPath);

		Meshes_SmartPtr LoadMeshes(const std::string & p_rPath);
		Meshes_SmartPtr InitFromScene(const aiScene * p_pScene, const std::string & p_rPath);
		Mesh_SmartPtr InitMesh(const aiMesh * const p_AiMesh);
		void InitSkeleton(Mesh_SmartPtr p_spMesh, const aiMesh * const p_AiMesh);
		void ConstructSkeleton(KG::Skeleton_SmartPtr p_spSkeleton, const aiNode * const p_AiNode);
		/*! recursively find a bone with specified name and compute it's depth. */
		const bool FindBoneDepth(unsigned & p_Depth, const aiNode * const p_pAiNode, const std::string & p_BoneName);
		const aiNode * const FindAiNodeByName(const std::string & p_rNodeName, const aiNode * const p_pAiNode);
		void GrowBoneTree(KG::BoneNode_SmartPtr p_spBoneNode, const aiNode * const p_pAiNode);
		const bool InitMaterial(Mesh_SmartPtr p_spMesh, const aiMesh * const p_pAiMesh, const aiScene * const p_pAiScene, const std::string & p_Path);
		
	};

} // KG ns
