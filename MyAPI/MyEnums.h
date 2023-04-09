#pragma once


enum class eSceneType
{
	Title,
	Stage1_1,
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
	Rectangle,
	Monster,
	Effect,
	MonsterSkill,
	Skill,
	Air,
	Star,
	UI,
	fade,
	Portal,
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