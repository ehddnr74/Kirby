#pragma once


enum class eSceneType
{
	Title,
	Stage1_1,
	Stage1_2,
	Ending,
	End,
};


enum class eLayerType
{
	Ground,
	BG,
	Stage,
	Player,
	Monster,
	Effect,
	UI,
	fade,
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