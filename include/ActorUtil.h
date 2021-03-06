#pragma once

#include "NPCUtil.h"
#include "SpellUtil.h"

namespace ActorUtil {
	class ActorCopier {
	public:
		ActorCopier(Actor* destination, Actor* source);

		void AddSkillPerks();
		void CopyAttributes();
		void CopyBodyTintColor();
		void CopyFaceData();
		void CopyFactions();
		void CopyGenderAnimations();
		void CopyHeadParts();
		void CopyHeadRelatedData();
		void CopyHeight();
		void CopyRace();
		void CopySex();
		void CopySkills();
		void CopySkin();
		void CopyWeight();
		
		~ActorCopier();
	private:
		Actor* destination;
		Actor* source;
		NPCUtil::NPCCopier baseCopier;
	};

	void AddItem(Actor* actor, TESForm* item, uint32_t count);
	void AddSpellsFromList(Actor* actor, BSTArray<SpellItem*> spells);
	BSTArray<BGSPerk*> GetSkillPerks(Actor* actor);
	BSTArray<SpellItem*> GetSpells(Actor* actor);
	void RemoveAllAddedSpells(Actor* actor);
	void RemoveSkillPerks(Actor* actor);
	void RemoveSpellsExceptWhitelisted(Actor* actor, BSTArray<SpellItem*> whitelist);
	void RemoveBlacklistedSpells(Actor* actor, BSTArray<SpellItem*> blacklist);
	void ResetSkeleton(Actor* actor);
	void SexChange(Actor* actor);
}