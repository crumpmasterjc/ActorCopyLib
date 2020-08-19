#include "ActorUtil.h"
#include "PerkUtil.h"

namespace ActorUtil {
	ActorCopier::ActorCopier(Actor* destination, Actor* source) {
		this->destination = destination;
		this->source = source;
		TESNPC* destinationBase = destination->GetActorBase();
		TESNPC* sourceBase = source->GetActorBase();
		baseCopier = NPCUtil::NPCCopier(destinationBase, sourceBase);
	}

	void ActorCopier::AddSkillPerks() {
		if (!source)
			return;
		for (BGSPerk* perk : GetSkillPerks(source))
			destination->AddPerk(perk);
	}

	void ActorCopier::AddSpells() {
		AddSpellsFromList(destination, source->addedSpells);
	}

	void ActorCopier::CopyBodyTintColor() {
		baseCopier.CopyBodyTintColor();
	}

	void ActorCopier::CopyFaceData() {
		baseCopier.CopyFaceData();
	}

	void ActorCopier::CopyGenderAnimations() {
		baseCopier.CopyGenderAnimations();
	}

	void ActorCopier::CopyHeadParts() {
		baseCopier.CopyHeadParts();
	}

	void ActorCopier::CopyHeadRelatedData() {
		baseCopier.CopyHeadRelatedData();
	}

	void ActorCopier::CopyHeight() {
		baseCopier.CopyHeight();
	}

	void ActorCopier::CopyRace() {
		destination->RE::Actor::SwitchRace(source->race, false);
		baseCopier.CopyRace();
	}

	void ActorCopier::CopySex() {
		baseCopier.CopySex();
	}

	void ActorCopier::CopySkin() {
		baseCopier.CopySkin();
	}

	void ActorCopier::CopyWeight() {
		baseCopier.CopyWeight();
	}	

	ActorCopier::~ActorCopier() {
		baseCopier.~NPCCopier();
	}
	
	void AddItem(Actor* actor, TESForm* item, uint32_t count) {
		using func_t = decltype(&AddItem);
		REL::Relocation<func_t> func{ REL::ID(55616) };
		func(actor, item, count);
	}

	void AddSpellsFromList(Actor* actor, BSTArray<SpellItem*> spells) {
		for (SpellItem* spell : spells)
			actor->AddSpell(spell);
	}

	void AddSpellsFromList(Actor* actor, BSTSmallArray<SpellItem*> spells) {
		for (SpellItem* spell : spells)
			actor->AddSpell(spell);
	}

	BSTArray<BGSPerk*> GetSkillPerks(Actor* actor) {
		BSTArray<BGSPerk*> actorSkillPerks;
		if (!actor)
			return actorSkillPerks;
		BSTArray<BGSPerk*> allSkillPerks = PerkUtil::GetAllSkillPerks();
		for (BGSPerk* perk : allSkillPerks) {
			if (actor->HasPerk(perk))
				actorSkillPerks.push_back(perk);
		}
		return actorSkillPerks;
	}

	BSTArray<SpellItem*> GetSpells(Actor* actor) {
		BSTArray<SpellItem*> spells;
		if (actor) {
			for (SpellItem* spell : actor->addedSpells)
				spells.push_back(spell);
			for (SpellItem* spell : NPCUtil::GetSpells(actor->GetActorBase()))
				spells.push_back(spell);
		}
		
		return spells;
	}

	void RemoveAllAddedSpells(Actor* actor) {
		if (!actor)
			return;
		for (SpellItem* spell : actor->addedSpells)
			actor->RemoveSpell(spell);
	}

	void RemoveSkillPerks(Actor* actor) {
		for (BGSPerk* perk : GetSkillPerks(actor))
			actor->RemovePerk(perk);
	}

	void RemoveSpellsExceptWhitelisted(Actor* actor, BSTArray<SpellItem*> whitelist) {
		// TODO
	}

	void RemoveBlacklistedSpells(Actor* actor, BSTArray<SpellItem*> blacklist) {
		for (SpellItem* spell : blacklist)
			actor->RemoveSpell(spell);
	}

	void ResetSkeleton(Actor* actor) {
		if (actor->currentProcess) {
			actor->currentProcess->Set3DUpdateFlag(RESET_3D_FLAGS::kSkeleton);
		}
	}

	void SexChange(Actor* actor) {
		NPCUtil::SexChange(actor->GetActorBase());
	}

	void UpdateAppearance(Actor* actor) {
		using func_t = decltype(&UpdateAppearance);
		REL::Relocation<func_t> func{ REL::ID(37831) };
		return func(actor);
	}
}