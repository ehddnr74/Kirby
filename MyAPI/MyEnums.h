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
	BG,
	Stage,
	Player,
	Monster,
	Effect,
	UI,
	End,
};

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Audio,
	End,
};