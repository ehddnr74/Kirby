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
<<<<<<< HEAD
	MapStar,
=======
>>>>>>> 794934d37ca2edf575818af029f6a6424b07de41
	Rectangle,
	Monster,
	Effect,
	Air,
	Star,
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