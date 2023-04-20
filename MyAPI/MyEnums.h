#pragma once


enum class eSceneType
{
	Title,
	Stage1_1,
	SecretRoomScene,
	Stage1_2,
	Stage1_3,
	TreeScene,
	Ending,
	End,
};


enum class eLayerType
{
	Ground,
	BG,
	Stage,
	Player,
	MapStar,
	Monster,
	Boss,
	Branch,
	MonsterSkill,
	BossSkill,
	Apple,
	Effect,
	Skill,
	Air,
	Star,
	Box,
	Item,
	Portal,
	fade,
	UI,
	Rectangle,
	End,
};

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	RigidBody,
	Audio,
	End,
};